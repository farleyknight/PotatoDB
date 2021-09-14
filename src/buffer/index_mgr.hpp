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
  IndexMgr(DiskMgr& disk_mgr,
           BuffMgr& buff_mgr)
    : disk_mgr_ (disk_mgr),
      buff_mgr_ (buff_mgr)
  {}

  IndexSchema
  make_schema_from(index_oid_t index_oid,
                   table_oid_t table_oid,
                   const vector<column_oid_t> column_oids,
                   const CreateIndexExpr& expr) const;

  IndexSchema
  read_index_schema(file_id_t file_id) {
    return index_headers_.at(file_id).read_schema();
  }

  index_oid_t
  create_index(table_oid_t table_oid,
               const vector<column_oid_t> column_oids,
               const CreateIndexExpr& expr);

  void
  create_index_file(index_oid_t index_oid,
                    const index_name_t index_name,
                    const IndexSchema& index_schema,
                    const TableSchema& table_schema);

  BTree<IndexKey, RID, IndexComp>&
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
  open_all_indexes();

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
  allocate_header_and_first_page(file_id_t file_id);

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
  load_index_schema(index_oid_t index_oid,
                    const IndexSchema& schema)
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
  load_index_header(file_id_t file_id);

  DiskMgr& disk_mgr_;
  BuffMgr& buff_mgr_;

  map<index_oid_t, index_name_t> index_names_;
  map<index_name_t, index_oid_t> index_oids_;

  map<index_oid_t, IndexHeaderPage> index_headers_;
  map<index_oid_t, IndexSchema> index_schemas_;
  map<index_oid_t, ptr<BTree<IndexKey, RID, IndexComp>>> btree_indexes_;

  atomic<index_oid_t> next_index_oid_ = FIRST_INDEX_OID;
};
