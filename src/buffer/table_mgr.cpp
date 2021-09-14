#include "buffer/table_mgr.hpp"

void TableMgr::allocate_header_and_first_page(file_id_t file_id, Txn& txn) {
  auto first_page_id  = disk_mgr_.first_table_page(file_id);
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

TableSchema
TableMgr::read_table_schema(file_id_t file_id) const {
  assert(table_headers_.contains(file_id));
  return table_headers_.at(file_id).read_schema();
}

table_name_t
TableMgr::read_table_name(file_id_t file_id) const {
  assert(table_headers_.contains(file_id));
  return table_headers_.at(file_id).read_table_name();
}

table_oid_t
TableMgr::read_table_oid(file_id_t file_id) const {
  assert(table_headers_.contains(file_id));
  return table_headers_.at(file_id).read_table_oid();
}

TableSchema
TableMgr::make_schema_from(table_oid_t table_oid,
                           const CreateTableExpr& expr)
{
  auto table_name  = expr.table().name();
  auto column_list = expr.column_defs();

  auto columns = column_mgr_.make_columns(table_oid, table_name, column_list);
  return TableSchema(columns, table_name, table_oid);
}

table_oid_t
TableMgr::create_table(const CreateTableExpr& expr, Txn& txn)
{
  auto table_name = expr.table().name();
  auto table_oid  = next_table_oid_++;
  auto schema     = make_schema_from(table_oid, expr);
  auto file_id    = disk_mgr_.create_table(table_name);
  allocate_header_and_first_page(file_id, txn);

  load_table(file_id, table_oid, table_name, schema);
  write_schema(file_id, schema);

  return table_oid;
}

void
TableMgr::open_table_header(file_id_t file_id) {
  auto page_id   = disk_mgr_.table_header_page(file_id);
  auto page_ptr  = buff_mgr_.fetch_page(page_id);
  assert(page_ptr);
  load_table_header(file_id, page_ptr);
}

void
TableMgr::open_all_tables() {
  disk_mgr_.open_table_files();
  std::cout << "Now loading all Tables into the TableMgr" << std::endl;
  for (const auto file_id : disk_mgr_.table_file_ids()) {
    std::cout << "Opening TableHeaderPage" << std::endl;
    open_table_header(file_id);
    std::cout << "file_id: " << file_id << std::endl;
    auto table_oid    = read_table_oid(file_id);
    std::cout << "table_oid: " << table_oid << std::endl;
    auto table_name   = read_table_name(file_id);
    std::cout << "table_name: " << table_name << std::endl;
    auto table_schema = read_table_schema(file_id);
    load_table(file_id, table_oid, table_name, table_schema);
  }
}

void
TableMgr::load_table(file_id_t file_id,
                     table_oid_t table_oid,
                     const table_name_t& table_name,
                     const TableSchema& schema)
{
  load_table_name(table_oid, table_name);
  load_table_schema(table_oid, schema);
  load_table_heap(file_id, table_oid);

  auto page_id   = disk_mgr_.table_header_page(file_id);
  auto page_ptr  = buff_mgr_.fetch_page(page_id);
  assert(page_ptr);
  load_table_header(file_id, page_ptr);
}

void
TableMgr::load_table_heap(file_id_t file_id,
                          table_oid_t table_oid)
{
  auto heap = make_unique<TableHeap>(file_id,
                                     table_oid,
                                     disk_mgr_,
                                     buff_mgr_,
                                     lock_mgr_,
                                     log_mgr_);

  table_heaps_.emplace(table_oid, move(heap));
}

