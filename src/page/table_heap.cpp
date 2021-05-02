#include <cassert>

#include "common/config.hpp"

#include "page/table_heap.hpp"
#include "page/table_page.hpp"
#include "page/slotted_table_page.hpp"
#include "page/table_iterator.hpp"

#include "txns/txn.hpp"

#include "tuple/rid.hpp"
#include "tuple/tuple.hpp"

TableHeap::TableHeap(BuffMgr& buff_mgr,
                     LockMgr& lock_mgr,
                     LogMgr& log_mgr,
                     PageId first_page_id)
  : buff_mgr_      (buff_mgr),
    lock_mgr_      (lock_mgr),
    log_mgr_       (log_mgr),
    first_page_id_ (first_page_id) {}

TableHeap::TableHeap(BuffMgr& buff_mgr,
                     LockMgr& lock_mgr,
                     LogMgr& log_mgr,
                     Txn& txn)
  : buff_mgr_ (buff_mgr),
    lock_mgr_ (lock_mgr),
    log_mgr_  (log_mgr)
{
  Page* maybe_first_page = buff_mgr.create_page();
  assert(maybe_first_page);

  auto &first_page = SlottedTablePage(*maybe_first_page);
  first_page_id_ = first_page.page_id();

  first_page.wlatch();
  first_page.init(first_page_id_,
                  PAGE_SIZE,
                  PageId::INVALID(),
                  txn,
                  log_mgr_);
  first_page.wunlatch();

  buff_mgr_.unpin(first_page_id_, true);
}

bool TableHeap::insert_tuple(CRef<Tuple> tuple,
                             Txn& txn)
{
  // Tuple Header is 32 bytes I think?
  if (tuple.size() + 32 > PAGE_SIZE) {  // larger than one page size
    txn.abort_with_reason(AbortReason::TUPLE_TOO_BIG);
    return false;
  }

  Page* maybe_page = buff_mgr_.fetch_page(first_page_id_);
  if (maybe_page == nullptr) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto curr_page = SlottedTablePage(*maybe_page);

  // Insert into the first page with enough space.
  // If no such page exists, create a new page and insert into that.
  while (!curr_page.insert_tuple(tuple)) {
    auto next_page_id = curr_page.get().next_page_id();

    // If the next page is a valid page,
    if (next_page_id != INVALID_PAGE_ID) {
      // Unlatch and unpin the current page.
      buff_mgr_.unpin(curr_page.get().table_page_id(), false);
      // And repeat the process with the next page.
      maybe_page = buff_mgr_.fetch_page(next_page_id);
      assert(maybe_page);
      curr_page = SlottedTablePage(*maybe_page);
    } else {
      // Otherwise we have run out of valid pages.
      // We need to create a new page.
      auto maybe_new_page = buff_mgr_.create_page();
      // If we could not create a new page,
      if (maybe_new_page == nullptr) {
        // Then life sucks and we abort the txn.
        buff_mgr_.unpin(curr_page.get().table_page_id(), false);
        txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
        return false;
      }

      auto new_page = SlottedTablePage(*maybe_new_page);

      // Otherwise we were able to create a new page. We initialize it now.
      curr_page.set_next_page_id(new_page.id());
      new_page.init(new_page.id(),
                    PAGE_SIZE,
                    curr_page.get().table_page_id(),
                    txn,
                    log_mgr_);
      buff_mgr_.unpin(curr_page.get().table_page_id(), true);
      curr_page = new_page
    }
  }

  buff_mgr_.unpin(curr_page.get().table_page_id(), true);

  txn.write_set().emplace_back(tuple.rid(),
                               WType::INSERT,
                               Tuple {},
                               *this);
  return true;
}

bool TableHeap::mark_delete(CRef<RID> rid, Txn& txn) {
  // TODO(student): remove empty page

  // Find the page which contains the tuple.
  auto maybe_page = buff_mgr_.fetch_table_page(rid.page_id());
  // If the page could not be found, then abort the txn.
  if (maybe_page == std::nullopt) {
    // NOTE: I've added this, not BusTub original
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  // Otherwise, mark the tuple as deleted.
  auto &page = maybe_page.value().get();

  page.wlatch();
  page.mark_delete(rid, txn, lock_mgr_, log_mgr_);
  page.wunlatch();

  buff_mgr_.unpin(page.table_page_id(), true);

  txn.write_set().emplace_back(rid, WType::DELETE, Tuple(), *this);
  return true;
}

bool TableHeap::update_tuple(CRef<Tuple> new_tuple,
                             CRef<RID> rid,
                             Txn& txn) {

  // Find the page which contains the tuple.
  Page *maybe_page = buff_mgr_.fetch_page(rid.page_id());
  // If the page could not be found, then abort the txn.
  if (maybe_page == nullptr) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto &page = TablePage(*maybe_page);
  // Update the tuple; but first save the old value for rollbacks.
  Tuple old_tuple;
  old_tuple.reset(new_tuple.size());
  page.wlatch();
  bool is_updated = page.update_tuple(new_tuple, old_tuple, rid);
  page.wunlatch();

  buff_mgr_.unpin(page.table_page_id(), is_updated);

  if (is_updated && txn.state() != TxnState::ABORTED) {
    txn.write_set().emplace_back(rid, WType::UPDATE, old_tuple, *this);
  }

  return is_updated;
}

bool TableHeap::apply_delete(MRef<RID> rid, MRef<Txn> txn) {
  // Find the page which contains the tuple.
  auto maybe_page = buff_mgr_.fetch_table_page(rid.page_id());
  if (!maybe_page.has_value()) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto &page = maybe_page.value().get();

  // Delete the tuple from the page.
  page.wlatch();
  page.apply_delete(rid, txn, log_mgr_);
  page.wunlatch();

  buff_mgr_.unpin(page.table_page_id(), true);
  return true;
}

void TableHeap::rollback_delete(Ref<RID> rid, MRef<Txn> txn) {
  auto maybe_page = buff_mgr_.fetch_table_page(rid.page_id());
  assert(maybe_page.has_value());

  auto &page = maybe_page.value().get();

  page.wlatch();
  page.rollback_delete(rid, txn, log_mgr_);
  page.wunlatch();

  buff_mgr_.unpin(page.id(), true);
}

Option<Tuple>
TableHeap::find_tuple(Ref<RID> rid, MRef<Txn> txn) const {
  // Find the page which contains the tuple.

  auto maybe_page =
    buff_mgr_.fetch_table_page(rid.page_id());

  // If the page could not be found, then abort the txn.
  if (!maybe_page.has_value()) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return std::nullopt;
  }

  auto &page = maybe_page.value().get();

  page.rlatch();

  Tuple tuple;
  page.find_tuple(rid, tuple);
  page.runlatch();

  buff_mgr_.unpin(rid.page_id(), false);
  return tuple;
}

TableIterator TableHeap::begin(MRef<Txn> txn) {
  auto page_id = first_page_id_;
  RID rid;

  while (page_id != INVALID_PAGE_ID) {
    auto maybe_page = buff_mgr_.fetch_table_page(page_id);
    assert(maybe_page.has_value());

    auto &page = maybe_page.value().get();

    auto maybe_rid = page.first_tuple_rid();

    buff_mgr_.unpin(page_id, false);
    if (maybe_rid.has_value()) {
      // NOTE: This uses copy-assign constructor
      rid = maybe_rid.value();
      break;
    }
    page_id = page.next_page_id();
  }

  return TableIterator(*this, rid, txn);
}

TableIterator TableHeap::end(MRef<Txn> txn) const {
  return TableIterator(*this, RID(), txn);
}
