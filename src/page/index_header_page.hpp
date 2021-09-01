#pragma once

#include "catalog/column_data.hpp"
#include "catalog/index_schema.hpp"

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
 *  column_oids_start (4 bytes, int32_t)
 *                      => Where Schema Column OIDS will start
 *                         To be computed after string w/ length is written
 *  string_length     (4 bytes, int32_t)
 *  index_name_t      (var, string chars based on prev value)
 *
 *  Schema Columns:
 *  ===============
 *  column_size_t     (4 bytes, int32_t)
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
  IndexHeaderPage(Page* page)
    : PageLayout (page)
  {}

  void allocate(UNUSED PageId header_page_id, UNUSED PageId root_page_id) {
    // TODO
  }

  // NOTE: We will need the catalog object because we need to transform
  // the column_oids into TableColumn objects.
  IndexSchema read_schema(const Catalog& catalog) {
    auto index_oid         = read_index_oid();
    auto table_oid         = read_table_oid();
    auto root_page_id      = read_root_page_id();

    auto column_oids_start = read_column_oids_start();
    auto column_oids       = read_table_oids(column_oids_start);

    auto table_name        = catalog.table_name_for(table_oid);
    auto columns           = catalog.columns_for(column_oids);

    return IndexSchema(columns,
                       index_name,   table_name,
                       index_oid,    table_oid,
                       column_oids_, key_size);
  }

  index_oid_t read_index_oid() const {
    return page_->read_int32(INDEX_OID_OFFSET);
  }

  void write_index_oid(index_oid_t index_oid) {
    page_->write_int32(INDEX_OID_OFFSET, index_oid);
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
    write_column_oids(column_oids_start, schema.columns());
  }
};
