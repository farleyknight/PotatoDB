#include "page/table_header_page.hpp"

int32_t
TableHeaderPage::write_metadata(const TableSchema& schema) {
  buffer_offset_t offset = 0;

  write_table_oid(schema.table_oid());
  offset += sizeof(schema.table_oid());

  write_column_count(schema.columns().size());
  offset += sizeof(schema.columns().size());

  write_table_name(schema.table_name());
  offset += sizeof(string_length_t) + schema.table_name().size();

  auto columns_start = offset;
  write_columns_start(columns_start);

  return columns_start;
}

vector<TableColumn>
TableHeaderPage::read_columns(buffer_offset_t columns_start,
                              int32_t column_count) const
{
  logger->debug("[TableHeaderPage] Reading columns at offset " +
                std::to_string(columns_start));

  buffer_offset_t offset = columns_start;
  vector<TableColumn> cols;
  for (int32_t i = 0; i < column_count; ++i) {
    // read_type_id          - 4 bytes (int32)
    auto type_id = page_->read_type_id(offset);
    offset += sizeof(type_id);

    // read_table_oid        - 4 bytes (int32)
    auto table_oid = page_->read_int32(offset);
    offset += sizeof(table_oid);

    // read_column_oid       - 4 bytes (int32)
    auto column_oid = page_->read_int32(offset);
    offset += sizeof(column_oid);

    // read_fixed_length     - 4 bytes (int32)
    auto fixed_length = page_->read_int32(offset);
    offset += sizeof(fixed_length);

    // read_variable_length  - 4 bytes (int32)
    auto variable_length = page_->read_int32(offset);
    offset += sizeof(variable_length);

    // read_is_inlined       - 1 byte  (bool)
    auto is_inlined = page_->read_bool(offset);
    offset += sizeof(is_inlined);

    // read_is_primary_key   - 1 byte  (bool)
    auto is_primary_key = page_->read_bool(offset);
    offset += sizeof(is_primary_key);

    // read_is_autoincrement - 1 byte  (bool)
    auto is_autoincrement = page_->read_bool(offset);
    offset += sizeof(is_autoincrement);

    // read_is_nullable      - 1 byte  (bool)
    auto is_nullable = page_->read_bool(offset);
    offset += sizeof(is_nullable);

    // read_column_name      - var num of bytes (string)
    auto column_name = page_->read_string(offset);
    offset += sizeof(string_length_t) + column_name.size();

    if (type_id == TypeId::VARCHAR) {
      auto col = TableColumn(table_oid,
                             column_oid,
                             column_name,
                             variable_length,
                             type_id,
                             is_nullable,
                             is_primary_key,
                             is_autoincrement);
      cols.push_back(col);
    } else {
      auto col = TableColumn(table_oid,
                             column_oid,
                             column_name,
                             type_id,
                             is_nullable,
                             is_primary_key,
                             is_autoincrement);
      cols.push_back(col);
    }
  }

  return cols;
}

void
TableHeaderPage::write_columns(buffer_offset_t columns_start,
                               const vector<TableColumn>& columns)
{
  logger->debug("[TableHeaderPage] Writing columns at offset " + std::to_string(columns_start));

  buffer_offset_t offset = columns_start;
  for (const auto &col : columns) {
    // write_type_id          - 4 bytes (int32)
    page_->write_type_id(offset, col.type_id());
    offset += sizeof(col.type_id());

    // write_table_oid        - 4 bytes (int32)
    page_->write_int32(offset, col.table_oid());
    offset += sizeof(col.table_oid());

    // write_column_oid       - 4 bytes (int32)
    page_->write_int32(offset, col.oid());
    offset += sizeof(col.table_oid());

    // write_fixed_length     - 4 bytes (int32)
    page_->write_int32(offset, col.fixed_length());
    offset += sizeof(col.fixed_length());

    // write_variable_length  - 4 bytes (int32)
    page_->write_int32(offset, col.variable_length());
    offset += sizeof(col.variable_length());

    // write_is_inlined       - 1 byte  (bool)
    page_->write_bool(offset, col.is_inlined());
    offset += sizeof(col.is_inlined());

    // write_is_primary_key   - 1 byte  (bool)
    page_->write_bool(offset, col.is_primary_key());
    offset += sizeof(col.is_primary_key());

    // write_is_autoincrement - 1 byte  (bool)
    page_->write_bool(offset, col.is_autoincrement());
    offset += sizeof(col.is_primary_key());

    // write_is_nullable      - 1 byte  (bool)
    page_->write_bool(offset, col.is_nullable());
    offset += sizeof(col.is_nullable());

    // write_column_name      - var num of bytes (string)
    page_->write_string(offset, col.name());
    offset += sizeof(string_length_t) + col.name().size();
  }
}
