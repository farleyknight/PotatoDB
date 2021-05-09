#pragma once

#include "catalog/catalog.hpp"
#include "query/query_column.hpp"
#include "query/query_comp.hpp"

class QueryTable {
public:

  QueryTable(const Catalog* catalog,
             table_oid_t table_oid,
             const table_name_t table_name)
    : table_oid_  (table_oid),
      table_name_ (table_name),
      catalog_    (catalog)
  {}

  // TODO: We don't have to have a reference or pointer to the
  // catalog if we have a copy of the table schema?
  // Not sure if it's worth making a copy, but it's an idea.
  QueryColumn operator[](const column_name_t& column_name) {
    return catalog_->query_column_for(table_name_, column_name);
  }

  table_oid_t table_oid() const {
    return table_oid_;
  }

private:
  table_oid_t table_oid_;
  table_name_t table_name_;
  const Catalog* catalog_;
};
