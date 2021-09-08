#pragma once

#include "disk/file_mgr.hpp"

#include "btree/b_tree.hpp"

#include "buffer/buff_mgr.hpp"
#include "catalog/index_schema.hpp"

#include "index/index_key.hpp"
#include "index/index_comp.hpp"
#include "exprs/create_index_expr.hpp"

#include "page/index_header_page.hpp"

class IndexMgr : public FileMgr {
public:
  using BPlusTree = BTree<IndexKey, RID, IndexComp>;

  IndexMgr(DiskMgr& file_mgr,
           BuffMgr& buff_mgr)
    : disk_mgr_ (disk_mgr),
      buff_mgr_ (buff_mgr)
  {}

  IndexSchema
  make_schema_from(index_oid_t index_oid,
                   table_oid_t table_oid,
                   const vector<column_oid_t> column_oids,
                   const CreateIndexExpr& expr) const
  {
    auto index_name   = expr.index().name();
    auto table_name   = expr.table().name();

    file_id_t file_id = file_mgr_.create_index_file(index_name);

    int32_t key_size = 8; // NOTE: Fixed for now.
    // Update to be configurable later

    auto root_page_id = default_root_page_id(file_id);

    return IndexSchema(index_oid,   table_oid,
                       index_name,  table_name,
                       column_oids, key_size,
                       root_page_id);
  }

  index_oid_t
  create_index(table_oid_t table_oid,
               const vector<column_oid_t> column_oids,
               const CreateIndexExpr& expr)
  {
    auto index_name = expr.index().name();
    index_oid_t index_oid = next_index_oid_;
    next_index_oid_++;
    auto schema = make_schema_from(index_oid, table_oid, column_oids, expr);

    auto file_id = file_mgr_.file_id_for_index(index_name);

    load_index(file_id, index_oid, index_name, schema);

    return index_oid;
  }

  IndexSchema
  read_index_schema(file_id_t file_id) {
    return index_headers_.at(file_id).read_schema();
  }

  void
  create_index_file(index_oid_t index_oid,
                    const index_name_t& index_name,
                    const IndexSchema& index_schema,
                    const TableSchema& table_schema)
  {
    file_id_t file_id = file_mgr_.create_index_file(index_name);
    allocate_header_and_first_page(file_id);

    auto comp = IndexComp(index_schema, table_schema);

    auto btree = make_unique<BPlusTree>(index_name,
                                        file_id,
                                        FileMgr::index_header_page(file_id),
                                        comp,
                                        buff_mgr_);

    btree_indexes_.emplace(index_oid, move(btree));
  }

  BPlusTree&
  btree_index_for(index_oid_t index_oid) {
    assert(btree_indexes_.contains(index_oid));
    return *btree_indexes_.at(index_oid);
  }

  index_oid_t
  index_oid_for(const index_name_t& index_name) const {
    assert(index_oids_.contains(index_name));
    return index_oids_.at(index_name);
  }

  IndexSchema&
  index_schema_for(index_oid_t index_oid) {
    assert(index_schemas_.contains(index_oid));
    return index_schemas_.at(index_oid);
  }

  const IndexSchema&
  index_schema_for(index_oid_t index_oid) const {
    assert(index_schemas_.contains(index_oid));
    return index_schemas_.at(index_oid);
  }

  void
  open_all_indexes() {
    // TODO: Move this for-loop into index_mgr_
    for (const auto file_id : file_mgr_.index_file_ids()) {
      auto index_oid    = read_index_oid(file_id);
      auto index_name   = read_index_name(file_id);
      auto index_schema = read_index_schema(file_id);
      load_index(file_id, index_oid, index_name, index_schema);
    }
  }

  IndexSchema
  read_index_schema(file_id_t file_id) const {
    return index_headers_.at(file_id).read_schema();
  }

  index_name_t
  read_index_name(file_id_t file_id) const {
    return index_headers_.at(file_id).read_index_name();
  }

  index_oid_t
  read_index_oid(file_id_t file_id) const {
    return index_headers_.at(file_id).read_index_oid();
  }

private:
  PageId
  default_root_page_id(file_id_t file_id) const {
    return PageId(file_id, FileMgr::INDEX_CONTENT_BLOCK_NUM);
  }

  void
  allocate_header_and_first_page(file_id_t file_id) {
    auto header_page_id = FileMgr::index_header_page(file_id);
    // NOTE: By default, root page ID is the first page ID
    auto root_page_id   = FileMgr::first_index_page(file_id);

    // TODO: We should allocate the block with the following info:
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
    //    - Will probably need it's own custom serialize/deserialize
    auto header_page_ptr = buff_mgr_.fetch_page(root_page_id);
    assert(header_page_ptr != nullptr);
    auto header_page = IndexHeaderPage(header_page_ptr);
    header_page.wlatch();
    header_page.allocate(header_page_id, root_page_id);
    header_page.wunlatch();

    auto root_page_ptr = buff_mgr_.fetch_page(root_page_id);
    assert(root_page_ptr != nullptr);
    auto root_page = BTreeInternalPage<IndexKey, RID, IndexComp>(root_page_ptr);
    // must call initialize method after "create" a new node
    header_page.wlatch();
    root_page.allocate(root_page_id, PageId::STOP_ITERATING(file_id));
    header_page.wunlatch();

    buff_mgr_.unpin(root_page_id, true);
  }

  void
  load_index(file_id_t file_id,
             index_oid_t index_oid,
             const index_name_t& index_name,
             const IndexSchema& schema)
  {
    load_index_header(file_id);
    load_index_name(index_oid, index_name);
    load_index_schema(index_oid, schema);
  }

  void
  load_index_schema(index_oid_t index_oid, const IndexSchema& schema)
  {
    index_schemas_.emplace(index_oid, schema);
  }

  void
  load_index_name(index_oid_t index_oid,
                  const index_name_t& index_name)
  {
    index_oids_[index_name] = index_oid;
    index_names_[index_oid] = index_name;
  }

  void
  load_index_header(file_id_t file_id) {
    auto page_id            = file_mgr_.index_header_page(file_id);
    auto page_ptr           = buff_mgr_.fetch_page(page_id);
    assert(page_ptr);
    index_headers_.emplace(file_id, IndexHeaderPage(page_ptr));
  }


  DiskMgr& disk_mgr_;
  BuffMgr& buff_mgr_;

  map<index_name_t, index_oid_t> index_oids_;
  map<index_oid_t, index_name_t> index_names_;

  map<index_oid_t, IndexSchema> index_schemas_;
  map<index_oid_t, ptr<BPlusTree>> btree_indexes_;

  atomic<index_oid_t> next_index_oid_ = FIRST_INDEX_OID;

  map<file_id_t, IndexHeaderPage> index_headers_;
};
