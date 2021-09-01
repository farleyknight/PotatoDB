#pragma once

#include "catalog/column_data.hpp"
#include "catalog/table_schema.hpp"

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

  static constexpr size_t TABLE_OID_OFFSET     = 0;
  static constexpr size_t COLUMN_COUNT_OFFSET  = 4;
  static constexpr size_t COLUMNS_START_OFFSET = 8;
  static constexpr size_t TABLE_NAME_OFFSET    = 12;

  TableHeaderPage(Page* page)
    : PageLayout (page)
  {}

  TableSchema read_schema() const {
    auto table_oid     = read_table_oid();
    auto column_count  = read_column_count();
    auto columns_start = read_columns_start();
    auto table_name    = read_table_name();
    auto cols          = read_columns(columns_start, column_count);

    return TableSchema(cols,
                       table_name,
                       table_oid);
  }

  void write_schema(const TableSchema& schema) {
    auto columns_start = write_metadata(schema);
    write_columns(columns_start, schema.columns());
  }

  int32_t write_metadata(const TableSchema& schema) {
    buffer_offset_t offset = 0;

    write_table_oid(schema.table_oid());
    offset += sizeof(table_oid_t);

    write_column_count(schema.columns().size());
    offset += sizeof(columns_count_t);

    write_table_name(schema.table_name());
    offset += sizeof(string_length_t) + schema.table_name().size();

    auto columns_start = offset + sizeof(buffer_offset_t);
    write_columns_start(offset);

    return columns_start;
  }

  table_oid_t read_table_oid() const {
    return page_->read_int32(TABLE_OID_OFFSET);
  }

  void write_table_oid(table_oid_t table_oid) {
    page_->write_int32(TABLE_OID_OFFSET, table_oid);
  }

  buffer_offset_t read_columns_start() const {
    return page_->read_int32(COLUMNS_START_OFFSET);
  }

  void write_columns_start(columns_start_t table_oid) {
    page_->write_int32(COLUMNS_START_OFFSET, table_oid);
  }

  columns_count_t read_column_count() const {
    return page_->read_int32(COLUMN_COUNT_OFFSET);
  }

  void write_column_count(columns_count_t column_count) {
    return page_->write_int32(COLUMN_COUNT_OFFSET, column_count);
  }

  table_name_t read_table_name() const {
    return page_->read_string(TABLE_NAME_OFFSET);
  }

  void write_table_name(table_name_t table_name) {
    page_->write_string(TABLE_NAME_OFFSET, table_name);
  }

  vector<TableColumn> read_columns(buffer_offset_t start_offset,
                                   int32_t column_count) const
  {
    buffer_offset_t offset = start_offset;

    vector<TableColumn> cols;
    for (int32_t i = 0; i < column_count; ++i) {
      auto size = page_->read_int32(offset);
      offset += sizeof(int32_t);

      auto col_data_buffer = page_->read_buffer(offset, size);
      // TODO: Use col_data_buffer to create the TableColumn
      offset += size;
    }

    return cols;
  }

  void write_columns(buffer_offset_t start_offset,
                     const vector<TableColumn>& columns)
  {
    buffer_offset_t offset = start_offset;
    for (const auto &col : columns) {
      auto col_data_buffer = col.data();
      auto size = col_data_buffer.size();

      page_->write_int32(offset, size);
      offset += sizeof(int32_t);

      page_->write_buffer(offset, col_data_buffer);
      offset += size;
    }
  }
};
