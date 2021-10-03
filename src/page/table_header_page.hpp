#pragma once

#include "catalog/column_data.hpp"
#include "catalog/schema_mgr.hpp"
#include "catalog/table_schema.hpp"

#include "page/page_layout.hpp"

// TODO: Each table & index file should have a FileHeaderPage
// The TableHeaderPage should be a subclass of FileHeaderPage

/*
 *  Table Header Page format (size in bytes):
 *
 *  Table Metadata:
 *  ===============
 *  table_oid_t     (4)
 *  columns_count_t (4)
 *  columns_start_t (4) => Where Schema Columns will start
 *                         To be computed after string w/ length is written
 *  string_length_t (4)
 *  table_name_t (var)
 *
 *  Schema Columns:
 *  ===============
 *  column_size_t (4)
 *  ColumnData (var) [Based on column_size_t]
 *
 */

class TableHeaderPage : public PageLayout {
public:
  using columns_start_t = buffer_offset_t;
  using columns_count_t = int32_t;
  using string_length_t = int32_t;

  static constexpr buffer_offset_t TABLE_OID_OFFSET     = 0;
  static constexpr buffer_offset_t COLUMN_COUNT_OFFSET  = 4;
  static constexpr buffer_offset_t COLUMNS_START_OFFSET = 8;
  static constexpr buffer_offset_t TABLE_NAME_OFFSET    = 12;

  TableHeaderPage(Page* page,
                  SchemaMgr& schema_mgr)
    : PageLayout  (page),
      schema_mgr_ (schema_mgr)
  {}


  void
  write_schema(const TableSchema& schema) {
    auto columns_start = write_metadata(schema);
    write_columns(columns_start, schema.columns());
  }

  int32_t
  write_metadata(const TableSchema& schema);

  table_oid_t
  read_table_oid() const {
    return page_->read_int32(TABLE_OID_OFFSET);
  }

  void
  write_table_oid(table_oid_t table_oid) {
    page_->write_int32(TABLE_OID_OFFSET, table_oid);
  }

  buffer_offset_t
  read_columns_start() const {
    return page_->read_int32(COLUMNS_START_OFFSET);
  }

  void
  write_columns_start(columns_start_t columns_start) {
    page_->write_int32(COLUMNS_START_OFFSET, columns_start);
  }

  columns_count_t
  read_column_count() const {
    return page_->read_int32(COLUMN_COUNT_OFFSET);
  }

  void
  write_column_count(columns_count_t column_count) {
    return page_->write_int32(COLUMN_COUNT_OFFSET, column_count);
  }

  table_name_t
  read_table_name() const {
    return page_->read_string(TABLE_NAME_OFFSET);
  }

  void
  write_table_name(table_name_t table_name) {
    page_->write_string(TABLE_NAME_OFFSET, table_name);
  }

  vector<TableColumn>
  read_columns(buffer_offset_t columns_start,
               int32_t column_count) const;

  void
  write_columns(buffer_offset_t columns_start,
                const vector<TableColumn>& columns);
};
