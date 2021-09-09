#include "page/index_header_page.hpp"
#include "catalog/catalog.hpp"

// NOTE: We will need the catalog object because we need to transform
// the column_oids into TableColumn objects.
IndexSchema IndexHeaderPage::read_schema() const {
  auto index_oid         = read_index_oid();
  auto table_oid         = read_table_oid();
  auto root_page_id      = read_root_page_id();
  auto index_name        = read_index_name();

  auto column_oids_count = read_column_oids_count();
  auto column_oids_start = read_column_oids_start();
  auto column_oids       = read_column_oids(column_oids_start,
                                            column_oids_count);

  int32_t key_size = 8; // Constant for now

  return IndexSchema(index_oid,  table_oid,
                     index_name, column_oids,
                     key_size,   root_page_id);
}
