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
 *  index_oid_t     (4)
 *  table_oid_t     (4)
 *  root_page_id    (4) // NOTE: This does NOT need to be an actual page ID
 *                      // In reality, we only need the block_id
 *  columns_count_t (4)
 *  columns_start_t (4) => Where Schema Columns will start
 *                         To be computed after string w/ length is written
 *  string_length_t (4)
 *  index_name_t (var)
 *
 *  Schema Columns:
 *  ===============
 *  column_size_t (4)
 *  ColumnData (var) [Based on column_size_t]
 *
 */

class IndexHeaderPage : public PageLayout {
public:
  IndexHeaderPage(Page* page)
    : PageLayout (page)
  {}

  void allocate(UNUSED PageId header_page_id, UNUSED PageId root_page_id) {
    // TODO
  }

  IndexSchema read_schema();

};
