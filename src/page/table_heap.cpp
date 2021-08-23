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
                     BuffMgr& buff_mgr,
                     LockMgr& lock_mgr,
                     LogMgr& log_mgr)
  : file_id_       (file_id),
    table_oid_     (table_oid),
    first_page_id_ (FileMgr::first_table_page(file_id)),
    buff_mgr_      (buff_mgr),
    log_mgr_       (log_mgr),
    lock_mgr_      (lock_mgr)
{}

table_oid_t TableHeap::table_oid() const {
  return table_oid_;
}

SlottedTablePage TableHeap::first_page(Txn& txn) {
  auto first_page_ptr = buff_mgr_.fetch_page(first_page_id_);
  assert(first_page_ptr != nullptr);
  auto first_page = SlottedTablePage(first_page_ptr, txn, log_mgr_, lock_mgr_);

  return first_page;
}


bool TableHeap::insert_tuple(Tuple& tuple, Txn& txn) {
  // Tuple Header is 32 bytes I think?
  if (tuple.size() + 32 > PAGE_SIZE) {
    txn.abort_with_reason(AbortReason::TUPLE_TOO_BIG);
    return false;
  }

  auto curr_page_ptr = buff_mgr_.fetch_page(first_page_id_);
  if (curr_page_ptr == nullptr) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto curr_page = SlottedTablePage(curr_page_ptr, txn,
                                    log_mgr_, lock_mgr_);

  // Insert into the first page with enough space.
  // If no such page exists, create a new page and insert into that.
  while (!curr_page.insert_tuple(tuple)) {
    auto next_page_id = curr_page.next_page_id();

    // If the next page is a valid page,
    if (next_page_id != PageId::STOP_ITERATING(file_id_)) {
      // Unlatch and unpin the current page.
      buff_mgr_.unpin(curr_page.table_page_id(), false);
      // And repeat the process with the next page.
      auto curr_page_ptr = buff_mgr_.fetch_page(next_page_id);
      curr_page.update_ptr(curr_page_ptr);
    } else {
      // Otherwise we have run out of valid pages.
      // We need to create a new page.
      auto page_id = curr_page.page_id();
      auto next_block_id = page_id.block_id() + 1;
      auto next_page_id = PageId(file_id_, next_block_id);
      curr_page.set_next_page_id(next_page_id);

      auto new_page_ptr = buff_mgr_.fetch_page(next_page_id);
      // If we could not create a new page,
      if (new_page_ptr == nullptr) {
        // Then life sucks and we abort the txn.
        buff_mgr_.unpin(curr_page.table_page_id(), false);
        txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
        return false;
      }

      auto new_page = SlottedTablePage(new_page_ptr, txn, log_mgr_, lock_mgr_);

      // Otherwise we were able to create a new page. We initialize it now.
      curr_page.set_next_page_id(new_page.page_id());
      new_page.allocate(new_page.page_id(),
                        curr_page.table_page_id());
      buff_mgr_.unpin(curr_page.table_page_id(), true);
      curr_page.update_ptr(new_page_ptr);
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
  // TODO: If page is empty, we should do DiskMgr::deallocate_page()

  // Find the page which contains the tuple.
  auto page_ptr = buff_mgr_.fetch_page(rid.page_id());
  // If the page could not be found, then abort the txn.
  if (page_ptr == nullptr) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto page = SlottedTablePage(page_ptr, txn, log_mgr_, lock_mgr_);

  page.wlatch();
  page.mark_delete(rid);
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
  auto page_ptr = buff_mgr_.fetch_page(rid.page_id());
  // If the page could not be found, then abort the txn.
  if (page_ptr == nullptr) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto page = SlottedTablePage(page_ptr, txn, log_mgr_, lock_mgr_);
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

bool TableHeap::apply_delete(const RID& rid, Txn& txn) {
  // Find the page which contains the tuple.
  auto page_ptr = buff_mgr_.fetch_page(rid.page_id());
  if (page_ptr == nullptr) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto page = SlottedTablePage(page_ptr, txn, log_mgr_, lock_mgr_);

  // Delete the tuple from the page.
  page.wlatch();
  page.apply_delete(rid);
  page.wunlatch();

  buff_mgr_.unpin(page.table_page_id(), true);
  return true;
}

bool TableHeap::rollback_delete(const RID& rid, Txn& txn) {
  auto page_ptr = buff_mgr_.fetch_page(rid.page_id());
  if (page_ptr == nullptr) {
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return false;
  }

  auto page = SlottedTablePage(page_ptr, txn, log_mgr_, lock_mgr_);

  page.wlatch();
  page.rollback_delete(rid);
  page.wunlatch();

  buff_mgr_.unpin(page.page_id(), true);
  return true;
}

ptr<Tuple> TableHeap::find_tuple(const RID& rid, Txn& txn) const {
  auto page_ptr = buff_mgr_.fetch_page(rid.page_id());

  if (page_ptr == nullptr) {
    logger->debug("[TableHeap] page_ptr was NULL! No valid tuple!");
    txn.abort_with_reason(AbortReason::PAGE_NOT_AVAILABLE);
    return unique_ptr<Tuple>(nullptr);
  }

  SlottedTablePage page(page_ptr, txn, log_mgr_, lock_mgr_);

  page.rlatch();
  auto tuple = page.find_tuple(rid);
  page.runlatch();
  buff_mgr_.unpin(rid.page_id(), false);

  return tuple;
}

TableIterator TableHeap::begin(Txn& txn) {
  auto page_id = first_page_id_;
  RID rid(page_id, 0);

  auto stop_iterating = PageId::STOP_ITERATING(file_id_);
  logger->debug("[TableHeap] stop_iterating: " + stop_iterating.to_string());

  while (page_id != stop_iterating) {
    logger->debug("[TableHeap] page_id is now: " + page_id.to_string());
    auto page_ptr = buff_mgr_.fetch_page(page_id);
    assert(page_ptr != nullptr);

    SlottedTablePage page(page_ptr, txn, log_mgr_, lock_mgr_);

    auto maybe_rid = page.first_tuple_rid();

    buff_mgr_.unpin(page_id, false);
    if (maybe_rid.has_value()) {
      rid = maybe_rid.value();
      break;
    }
    auto next_page_id = page.next_page_id();
    if (next_page_id == page_id) {
      logger->debug("[TableHeap] next_page_id == page_id, breaking out of loop");
      break; // NOTE: Prevent infinite loop
    }
    page_id = next_page_id;
  }

  assert(rid.page_id().is_valid());

  return TableIterator(*this, rid, txn, log_mgr_, lock_mgr_);
}

TableIterator TableHeap::end(Txn& txn) {
  return TableIterator(*this, RID(), txn, log_mgr_, lock_mgr_);
}
