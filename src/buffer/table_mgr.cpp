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
  assert(next_page_id == PageId::STOP_ITERATING(file_id)); buff_mgr_.unpin(first_page_id, true);
}

// NOTE: This should be called on every table during start-up, to load the
// schema into in-memory data structures.
TableSchema TableMgr::read_table_schema(file_id_t file_id) const {
  return table_headers_.at(file_id).read_schema();
}

table_name_t TableMgr::read_table_name(file_id_t file_id) const {
  return table_headers_.at(file_id).read_table_name();
}

void TableMgr::create_table_file(const table_name_t& table_name,
                                 const TableSchema& schema,
                                 table_oid_t table_oid,
                                 Txn& txn)
{
  file_id_t file_id = file_mgr_.create_table_file(table_name);
  allocate_header_and_first_page(file_id, txn);

  load_table(file_id, table_oid, table_name, schema);

  write_table_schema(file_id, schema);
}

void TableMgr::write_table_schema(UNUSED file_id_t file_id,
                                  UNUSED TableSchema schema)
{
  // TODO
}

void TableMgr::load_table_header(file_id_t file_id) {
  auto page_id            = file_mgr_.table_header_page(file_id);
  auto page_ptr           = buff_mgr_.fetch_page(page_id);
  assert(page_ptr);
  table_headers_.emplace(file_id, TableHeaderPage(page_ptr));
}

void TableMgr::load_table(file_id_t file_id,
                          table_oid_t table_oid,
                          const table_name_t table_name,
                          const TableSchema& schema)
{
  load_table_oid_to_file_id(table_oid, file_id);
  load_table_header(file_id);
  load_table_name(table_oid, table_name);
  load_table_schema(table_oid, schema);

  auto heap = make_unique<TableHeap>(file_id,
                                     table_oid,
                                     buff_mgr_,
                                     lock_mgr_,
                                     log_mgr_);

  table_heaps_.emplace(table_oid, move(heap));
}
