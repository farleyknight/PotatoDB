#pragma once

#include "catalog/column_data.hpp"
#include "catalog/index_schema.hpp"

#include "page/page_layout.hpp"

// TODO: Each table & index file should have a FileHeaderPage
// The IndexHeaderPage should be a subclass of FileHeaderPage

/*
 *  Index Header Page format (size in bytes):
 *
 *  Index Metadata:
 *  ===============
 *  index_oid_t       (4 bytes, int32_t)
 *  table_oid_t       (4 bytes, int32_t)
 *  root_page_id      (4 bytes, int32_t)
 *                 NOTE: root_page_id does NOT need to be an
 *                       actual page ID.
 *                       In reality, we only need the block_id
 *
 *  column_oids_count    (4 bytes, int32_t)
 *  column_oids_start    (4 bytes, int32_t)
 *                    => Where Schema Column OIDS will start
 *                       To be computed after string w/ length is written
 *  string_length        (4 bytes, int32_t)
 *  index_name_t         (var, string chars based on prev value)
 *
 *  string_length        (4 bytes, int32_t)
 *  table_name_t         (var, string chars based on prev value)
 *
 *  Schema Columns:
 *  ===============
 *  column_size_t        (4 bytes, int32_t)
 *  vector<column_oid_t> (var, vector of int32_t's based on prev value)
 *
 *                 NOTE: These are the column OIDs for each
 *                       column we are indexing. At the moment
 *                       we only support indexing one table
 *                       but in the future, we will likely
 *                       support more.
 *
 */

class Catalog;

class IndexHeaderPage : public PageLayout {
public:
  using column_oids_start_t = buffer_offset_t;
  using column_oids_count_t = int32_t;
  using string_length_t     = int32_t;

  static constexpr size_t INDEX_OID_OFFSET         = 0;
  static constexpr size_t TABLE_OID_OFFSET         = 4;
  static constexpr size_t ROOT_PAGE_ID_OFFSET      = 8;
  static constexpr size_t COLUMN_OIDS_COUNT_OFFSET = 12;
  static constexpr size_t COLUMN_OIDS_START_OFFSET = 16;
  static constexpr size_t INDEX_NAME_OFFSET        = 20;

  IndexHeaderPage(Page* page)
    : PageLayout (page)
  {}

  void allocate(UNUSED PageId header_page_id, UNUSED PageId root_page_id) {
    // TODO
  }

  IndexSchema read_schema() const;

  vector<column_oid_t>
  read_column_oids(buffer_offset_t start_offset,
                   int32_t column_oid_count) const
  {
    buffer_offset_t offset = start_offset;

    vector<column_oid_t> column_oids;
    for (int32_t i = 0; i < column_oid_count; ++i) {
      auto column_oid = page_->read_int32(offset);
      column_oids.push_back(column_oid);
      offset += sizeof(column_oid);
    }
    return column_oids;
  }

  void
  write_column_oids(buffer_offset_t column_oids_start,
                    const vector<column_oid_t> column_oids)
  {
    buffer_offset_t offset = column_oids_start;
    for (auto column_oid : column_oids) {
      page_->write_int32(offset, column_oid);
      offset += sizeof(column_oid);
    }
  }

  buffer_offset_t
  read_column_oids_start() const {
    return page_->read_int32(COLUMN_OIDS_START_OFFSET);
  }

  void write_column_oids_start(column_oids_start_t column_oids_start) {
    page_->write_int32(COLUMN_OIDS_START_OFFSET, column_oids_start);
  }

  buffer_offset_t read_column_oids_count() const {
    return page_->read_int32(COLUMN_OIDS_COUNT_OFFSET);
  }

  void write_column_oids_count(column_oids_count_t column_oids_count) {
    page_->write_int32(COLUMN_OIDS_COUNT_OFFSET, column_oids_count);
  }

  PageId read_root_page_id() const {
    return page_->read_page_id(ROOT_PAGE_ID_OFFSET);
  }

  void write_root_page_id(PageId page_id) {
    page_->write_int32(ROOT_PAGE_ID_OFFSET, page_id.as_int32());
  }

  index_oid_t read_index_oid() const {
    return page_->read_int32(INDEX_OID_OFFSET);
  }

  void write_index_oid(index_oid_t index_oid) {
    page_->write_int32(INDEX_OID_OFFSET, index_oid);
  }

  table_oid_t read_table_oid() const {
    return page_->read_int32(TABLE_OID_OFFSET);
  }

  void write_table_oid(table_oid_t table_oid) {
    page_->write_int32(TABLE_OID_OFFSET, table_oid);
  }

  index_name_t read_index_name() const {
    return page_->read_string(INDEX_NAME_OFFSET);
  }

  void write_index_name(index_name_t index_name) {
    page_->write_string(INDEX_NAME_OFFSET, index_name);
  }

  int32_t write_metadata(const IndexSchema& schema) {
    buffer_offset_t offset = 0;

    write_index_oid(schema.index_oid());
    offset += sizeof(index_oid_t);

    write_table_oid(schema.table_oid());
    offset += sizeof(table_oid_t);

    write_root_page_id(schema.root_page_id());
    assert(sizeof(PageId) == 4); // TODO: Delete if this passes
    offset += sizeof(PageId);

    write_index_name(schema.index_name());
    offset += sizeof(string_length_t) + schema.index_name().size();

    auto column_oids_start = offset + sizeof(buffer_offset_t);
    write_column_oids_start(column_oids_start);

    return column_oids_start;
  }

  void write_schema(const IndexSchema& schema) {
    auto column_oids_start = write_metadata(schema);
    write_column_oids(column_oids_start, schema.column_oids());
  }
};
