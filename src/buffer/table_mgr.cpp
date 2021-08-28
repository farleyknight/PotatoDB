#include "buffer/table_mgr.hpp"

void TableMgr::allocate_header_and_first_page(file_id_t file_id, Txn& txn) {
  auto first_page_id  = file_mgr_.first_table_page(file_id);
  auto first_page_ptr = buff_mgr_.fetch_page(first_page_id);
  assert(first_page_ptr != nullptr);
  auto first_page = SlottedTablePage(first_page_ptr, txn, log_mgr_, lock_mgr_);

  // TODO: If `allocate` fails (run out of disk space?) then we
  // need to abort the transaction.
  first_page.wlatch();
  auto prev_page_id = PageId::STOP_ITERATING(file_id);
  first_page.allocate(first_page_id, prev_page_id);
  first_page.wunlatch();

  auto next_page_id = first_page.next_page_id();
  logger->debug("[TableMgr] next_page_id: " + next_page_id.to_string());
  assert(next_page_id == PageId::STOP_ITERATING(file_id));

  buff_mgr_.unpin(first_page_id, true);
}

// NOTE: This should be called on every table during start-up, to load the
// schema into in-memory data structures.
TableSchema TableMgr::read_table_schema(table_oid_t table_oid) {
  assert(file_ids_.count(table_oid) > 0);
  auto file_id           = file_ids_.at(table_oid);
  auto page_id           = file_mgr_.table_header_page(file_id);
  auto page              = buff_mgr_.fetch_page(page_id);
  auto table_header_page = TableHeaderPage(page);

  return table_header_page.read_schema();
}

