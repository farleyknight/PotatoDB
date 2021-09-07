#pragma once

#include "disk/file_mgr.hpp"

#include "buffer/buff_mgr.hpp"

#include "catalog/table_schema.hpp"
#include "catalog/column_mgr.hpp"

#include "exprs/create_table_expr.hpp"

#include "page/table_heap.hpp"
#include "page/table_header_page.hpp"

// TODO: I created TableMgr because I wanted to have a place to do ALTER TABLE commands,
// and the like.
//
// I would like TableMgr to only be owned by SystemCatalog, however that is not the case
// at the moment. Once that happens, we can then begin working on file locks, which are
// a pre-requisite to changing the schema.
class TableMgr {
public:
  TableMgr(FileMgr& file_mgr,
           LockMgr& lock_mgr,
           LogMgr& log_mgr,
           BuffMgr& buff_mgr)
    : file_mgr_ (file_mgr),
      lock_mgr_ (lock_mgr),
      log_mgr_  (log_mgr),
      buff_mgr_ (buff_mgr)
  {
    std::cout << "Creating an instance of TableMgr" << std::endl;
  }

  void
  allocate_header_and_first_page(file_id_t file_id,
                                 Txn& txn);

  void
  assert_header_and_first_page_exist(file_id_t file_id,
                                     Txn& txn);

  TableSchema
  read_table_schema(file_id_t file_id) const;

  table_name_t
  read_table_name(file_id_t file_id) const;

  void
  write_table_schema(file_id_t file_id, TableSchema schema);

  void
  create_table_file(const table_name_t& table_name,
                    const TableSchema& schema,
                    table_oid_t table_oid,
                    Txn& txn);

  // TODO: I'm thinking this class is where we can make
  // TableCursor objects?
  void
  load_table_file(table_oid_t table_oid,
                  const table_name_t& table_name,
                  Txn& txn)
  {
    load_table_name(table_oid, table_name);

    file_id_t file_id = file_mgr_.load_table_file(table_name);
    assert_header_and_first_page_exist(table_oid, txn);

    load_table_oid_to_file_id(table_oid, file_id);

    auto heap = make_unique<TableHeap>(file_id,
                                       table_oid,
                                       buff_mgr_,
                                       lock_mgr_,
                                       log_mgr_);

    table_heaps_.emplace(table_oid, move(heap));

    auto schema = read_table_schema(file_id);
    load_table_schema(table_oid, schema);
  }

  TableHeap&
  table_heap_for(table_oid_t table_oid) const {
    assert(table_heaps_.contains(table_oid));
    return *table_heaps_.at(table_oid);
  }

  table_oid_t
  table_oid_for(file_id_t file_id) const {
    assert(file_id_to_table_oid_.contains(file_id));
    return file_id_to_table_oid_.at(file_id);
  }

  table_oid_t
  table_oid_for(const table_name_t& table_name) const {
    assert(table_oids_.contains(table_name));
    return table_oids_.at(table_name);
  }

  file_id_t
  file_id_for(table_oid_t table_oid) const {
    assert(table_oid_to_file_id_.contains(table_oid));
    return table_oid_to_file_id_.at(table_oid);
  }

  table_name_t
  table_name_for(table_oid_t table_oid) const {
    assert(table_names_.contains(table_oid));
    return table_names_.at(table_oid);
  }

  table_oid_t
  create_table_schema(const CreateTableExpr& expr)
  {
    auto table_name = expr.table().name();
    assert(!table_oids_.contains(table_name));
    auto table_oid = next_table_oid_++;
    assert(!table_schemas_.contains(table_oid));
    auto schema = make_schema_from(table_oid, expr);

    load_table_schema(table_oid, schema);
    return table_oid;
  }

  TableSchema
  make_schema_from(table_oid_t table_oid,
                   const CreateTableExpr& expr)
  {
    auto table_name  = expr.table().name();
    auto column_list = expr.column_defs();

    auto columns = column_mgr_.make_columns(table_oid, table_name, column_list);
    return TableSchema(columns, table_name, table_oid);
  }

  void load_table(file_id_t file_id,
                  table_oid_t table_oid,
                  const table_name_t table_name,
                  const TableSchema& schema);

  void load_table_name(table_oid_t table_oid, table_name_t table_name) {
    table_names_[table_oid] = table_name;
    table_oids_[table_name] = table_oid;
  }

  void load_table_oid_to_file_id(table_oid_t table_oid, file_id_t file_id) {
    table_oid_to_file_id_[table_oid] = file_id;
    file_id_to_table_oid_[file_id]   = table_oid;
  }

  void load_table_schema(table_oid_t table_oid, const TableSchema& table_schema) {
    table_schemas_.emplace(table_oid, table_schema);
  }

  void load_table_header(file_id_t file_id);

  bool
  table_has_column_named(const table_name_t& table_name,
                         const column_name_t& column_name)
  {
    return column_mgr_.table_has_column_named(table_name, column_name);
  }

  TableColumn
  column_for(column_oid_t column_oid) {
    return column_mgr_.column_for(column_oid);
  }

  const TableSchema&
  table_schema_for(table_oid_t table_oid) const {
    assert(table_schemas_.contains(table_oid));
    return table_schemas_.at(table_oid);
  }

  TableSchema&
  table_schema_for(table_oid_t table_oid) {
    assert(table_schemas_.contains(table_oid));
    return table_schemas_.at(table_oid);
  }

  bool
  has_table_named(const table_name_t& table_name) const {
    return table_oids_.contains(table_name);
  }

  bool
  table_has_column_named(const table_name_t& table_name,
                         const column_name_t& column_name) const {
    return column_mgr_.table_has_column_named(table_name, column_name);
  }

private:
  FileMgr& file_mgr_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;

  ColumnMgr column_mgr_;

  map<table_oid_t, table_name_t> table_names_;
  map<table_name_t, table_oid_t> table_oids_;

  map<file_id_t, TableHeaderPage> table_headers_;

  map<table_oid_t, ptr<TableHeap>> table_heaps_;

  map<table_oid_t, TableSchema> table_schemas_;

  atomic<table_oid_t> next_table_oid_ = FIRST_TABLE_OID;


  // TODO: I think we should make a TableFileMgr class
  // I think that is a reasonable answer to: Where do we store these variables?
  map<table_oid_t, file_id_t> table_oid_to_file_id_;
  map<file_id_t, table_oid_t> file_id_to_table_oid_;
};
