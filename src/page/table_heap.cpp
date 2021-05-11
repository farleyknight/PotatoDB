#include <cassert>

#include "common/config.hpp"

#include "page/table_heap.hpp"
#include "page/table_page.hpp"
#include "page/slotted_table_page.hpp"
#include "page/table_iterator.hpp"

#include "txns/txn.hpp"

#include "tuple/rid.hpp"
#include "tuple/tuple.hpp"

TableHeap::TableHeap(file_id_t file_id,
                     table_oid_t table_oid,
                     PageId first_page_id,
                     BuffMgr& buff_mgr,
                     LockMgr& lock_mgr,
                     LogMgr& log_mgr,
                     Txn& txn)
  : file_id_       (file_id),
    table_oid_     (table_oid),
    first_page_id_ (first_page_id),
    lock_mgr_      (lock_mgr),
    log_mgr_       (log_mgr),
    buff_mgr_      (buff_mgr)
{
  SlottedTablePage first_page(buff_mgr_.fetch_page(first_page_id));

  first_page.wlatch();
  first_page.init(first_page_id_,
                  PageId::STOP_ITERATING(file_id),
                  txn,
                  log_mgr_);
  first_page.wunlatch();

  buff_mgr_.unpin(first_page_id_, true);
}

bool TableHeap::insert_tuple(Tuple& tuple,
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

  auto curr_page = SlottedTablePage(maybe_page);

  // Insert into the first page with enough space.
  // If no such page exists, create a new page and insert into that.
  while (!curr_page.insert_tuple(tuple)) {
    auto next_page_id = curr_page.next_page_id();

    // If the next page is a valid page,
    if (next_page_id != PageId::STOP_ITERATING(file_id_)) {
      // Unlatch and unpin the current page.
      buff_mgr_.unpin(curr_page.table_page_id(), false);
      // And repeat the process with the next page.
      curr_page = SlottedTablePage(buff_mgr_.fetch_page(next_page_id));
    } else {
      // Otherwise we have run out of valid pages.
      // We need to create a new page.
      auto page_id = curr_page.page_id();
      auto next_block_id = page_id.block_id() + 1;
      auto next_page_id = PageId(file_id_, next_block_id);
      curr_page.set_next_page_id(next_page_id);

      auto maybe_new_page = buff_mgr_.fetch_page(next_page_id);
      // If we could not create a new page,
      if (maybe_new_page == nullptr) {
        // Then life sucks and we abort the txn.
        buff_mgr_.unpin(curr_page.table_page_id(), false);
        txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
        return false;
      }

      auto new_page = SlottedTablePage(maybe_new_page);

      // Otherwise we were able to create a new page. We initialize it now.
      curr_page.set_next_page_id(new_page.page_id());
      new_page.init(new_page.page_id(),
                    curr_page.table_page_id(),
                    txn,
                    log_mgr_);
      buff_mgr_.unpin(curr_page.table_page_id(), true);
      curr_page = new_page;
    }
  }

  buff_mgr_.unpin(curr_page.table_page_id(), true);

  txn.write_set().emplace_back(tuple.rid(),
                               WType::INSERT,
                               Tuple(),
                               table_oid_);
  return true;
}

bool TableHeap::mark_delete(const RID& rid, Txn& txn) {
  // TODO(student): remove empty page

  // Find the page which contains the tuple.
  auto maybe_page = buff_mgr_.fetch_page(rid.page_id());
  // If the page could not be found, then abort the txn.
  if (maybe_page == nullptr) {
    // NOTE: I've added this, not BusTub original
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto page = SlottedTablePage(maybe_page);

  page.wlatch();
  page.mark_delete(rid, txn, lock_mgr_, log_mgr_);
  page.wunlatch();

  buff_mgr_.unpin(page.table_page_id(), true);

  txn.write_set().emplace_back(rid,
                               WType::DELETE,
                               Tuple(),
                               table_oid_);
  return true;
}

bool TableHeap::update_tuple(Tuple& new_tuple,
                             const RID& rid,
                             Txn& txn) {

  // Find the page which contains the tuple.
  Page *maybe_page = buff_mgr_.fetch_page(rid.page_id());
  // If the page could not be found, then abort the txn.
  if (maybe_page == nullptr) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto page = SlottedTablePage(maybe_page);
  // Update the tuple; but first save the old value for rollbacks.
  Tuple old_tuple;
  old_tuple.reset(new_tuple.size());
  page.wlatch();
  bool is_updated = page.update_tuple(new_tuple, old_tuple, rid);
  page.wunlatch();

  buff_mgr_.unpin(page.table_page_id(), is_updated);

  if (is_updated && txn.state() != TxnState::ABORTED) {
    txn.write_set().emplace_back(rid,
                                 WType::UPDATE,
                                 old_tuple,
                                 table_oid_);
  }

  return is_updated;
}

bool TableHeap::apply_delete(RID& rid, Txn& txn) {
  // Find the page which contains the tuple.
  auto maybe_page = buff_mgr_.fetch_page(rid.page_id());
  if (maybe_page == nullptr) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto page = SlottedTablePage(maybe_page);

  // Delete the tuple from the page.
  page.wlatch();
  page.apply_delete(rid, txn, log_mgr_);
  page.wunlatch();

  buff_mgr_.unpin(page.table_page_id(), true);
  return true;
}

void TableHeap::rollback_delete(const RID& rid, Txn& txn) {
  auto maybe_page = buff_mgr_.fetch_page(rid.page_id());
  assert(maybe_page);

  auto page = SlottedTablePage(maybe_page);

  page.wlatch();
  page.rollback_delete(rid, txn, log_mgr_);
  page.wunlatch();

  buff_mgr_.unpin(page.page_id(), true);
}

Tuple TableHeap::find_tuple(const RID& rid, Txn& txn) const {
  // Find the page which contains the tuple.

  auto maybe_page = buff_mgr_.fetch_page(rid.page_id());

  // If the page could not be found, then abort the txn.
  if (maybe_page == nullptr) {
    std::cout << "Maybe Page was NULL! No valid tuple!" << std::endl;
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return Tuple();
  }

  SlottedTablePage page(maybe_page);

  page.rlatch();
  Tuple tuple = page.find_tuple(rid);
  page.runlatch();
  buff_mgr_.unpin(rid.page_id(), false);

  return tuple;
}

TableIterator TableHeap::begin(Txn& txn) {
  auto page_id = first_page_id_;
  RID rid(page_id, 0);

  while (page_id != PageId::STOP_ITERATING(file_id_)) {
    auto maybe_page = buff_mgr_.fetch_page(page_id);
    assert(maybe_page);

    SlottedTablePage page(maybe_page);

    auto maybe_rid = page.first_tuple_rid();

    buff_mgr_.unpin(page_id, false);
    if (maybe_rid.has_value()) {
      rid = maybe_rid.value();
      std::cout << "Got RID: " << rid << std::endl;
      break;
    }
    page_id = page.next_page_id();
  }

  assert(rid.page_id().is_valid());

  return TableIterator(*this, rid, txn);
}

TableIterator TableHeap::end(Txn& txn) {
  return TableIterator(*this, RID(), txn);
}
