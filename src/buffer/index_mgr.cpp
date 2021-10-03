#include "buffer/index_mgr.hpp"

IndexSchema
IndexMgr::make_schema_from(index_oid_t index_oid,
                           table_oid_t table_oid,
                           const vector<column_oid_t> column_oids,
                           const ColumnMgr& col_mgr,
                           const CreateIndexExpr& expr) const
{
  auto index_name   = expr.index().name();
  auto table_name   = expr.table().name();

  file_id_t file_id = disk_mgr_.create_index(index_name);

  int32_t key_size = 8; // NOTE: Fixed for now.
  // Update to be configurable later

  auto root_page_id = default_root_page_id(file_id);

  return IndexSchema(index_oid,   index_name,
                     column_oids, col_mgr,
                     key_size,    root_page_id);
}


index_oid_t
IndexMgr::create_index(table_oid_t table_oid,
                       const vector<column_oid_t> column_oids,
                       const CreateIndexExpr& expr)
{
  auto index_name = expr.index().name();
  auto index_oid  = next_index_oid_++;
  auto schema
    = make_schema_from(index_oid,
                       table_oid,
                       column_oids,
                       expr);

  auto file_id = disk_mgr_.create_index(index_name);
  load_index(file_id, index_oid, index_name, schema);

  return index_oid;
}


void
IndexMgr::create_index_file(index_oid_t index_oid,
                            const index_name_t index_name,
                            const IndexSchema& index_schema,
                            const TableSchema& table_schema)
{
  auto file_id = disk_mgr_.create_index(index_name);
  allocate_header_and_first_page(file_id);

  auto comp = IndexComp(index_schema.layout());

  auto index_header_page =
    disk_mgr_.index_header_page(file_id);

  auto btree = BTree<IndexKey, RID, IndexComp>::make_unique(index_name,
                                                            file_id,
                                                            index_header_page,
                                                            comp,
                                                            buff_mgr_);

  btree_indexes_.emplace(index_oid, move(btree));
}

void
IndexMgr::open_all_indexes() {
  disk_mgr_.open_index_files();
  // TODO: Need to call `open_all_index_files` here first.
  // Then we can get their file_id
  // Then all of the other stuff
  for (const auto file_id : disk_mgr_.index_file_ids()) {
    auto index_oid    = read_index_oid(file_id);
    auto index_name   = read_index_name(file_id);
    auto index_schema = read_index_schema(file_id);
    load_index(file_id, index_oid, index_name, index_schema);
  }
}

void
IndexMgr::allocate_header_and_first_page(file_id_t file_id) {
  auto header_page_id =
    disk_mgr_.index_header_page(file_id);
  // NOTE: By default, root page ID is the first page ID
  auto root_page_id =
    disk_mgr_.first_index_page(file_id);

  // TODO: We should allocate the block with the
  // following info:
  // * file_id of this file
  // * file_name to associate with the file_id
  //   - This gives us an opportunity to be sure it didn't get moved or renamed
  //   - The mapping of file_id to file_name is created by iterating over all files and mapping
  //     these two things together.
  // * root_page_id should be stored
  //    - An initially be set to (file_id, 1)
  //    - NOT static, it can change.
  //      - Why? BC deleting enough pages forces us to move the root page ID
  // * index_name should be stored in the header page
  // * index_schema (as IndexSchema) should be stored
  //    - Will probably need it's own custom
  //     serialize/deserialize
  auto header_page_ptr = buff_mgr_.fetch_page(root_page_id);
  assert(header_page_ptr != nullptr);
  auto header_page = IndexHeaderPage(header_page_ptr);
  header_page.wlatch();
  header_page.allocate(header_page_id, root_page_id);

  header_page.to_schema();


  header_page.wunlatch();

  auto root_page_ptr = buff_mgr_.fetch_page(root_page_id);
  assert(root_page_ptr != nullptr);
  auto root_page = BTreeInternalPage<IndexKey, RID, IndexComp>(root_page_ptr);
  // must call initialize method after "create" a new node
  header_page.wlatch();
  root_page.allocate(root_page_id,
                     PageId::STOP_ITERATING(file_id));
  header_page.wunlatch();

  buff_mgr_.unpin(root_page_id, true);
}

void
IndexMgr::load_index_header(file_id_t file_id) {
  auto page_id
    = disk_mgr_.index_header_page(file_id);
  auto page_ptr
    = buff_mgr_.fetch_page(page_id);
  assert(page_ptr);
  index_headers_.emplace(file_id,
                         IndexHeaderPage(page_ptr));
}

