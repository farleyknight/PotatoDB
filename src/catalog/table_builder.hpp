#pragma once

#include "catalog/schema_ref.hpp"

class Catalog;

class TableBuilder {
public:
  TableBuilder(Ref<Catalog> catalog)
    : catalog_ (catalog) {}

  using Self = MRef<TableBuilder>;
  Self table_name(String table_name);

  Self add_column(String name, TypeId type_id);
  Self add_column(String name, TypeId type_id, size_t length);

  Self not_null();
  Self auto_increment();
  Self primary_keys(Vec<String> names);

  SchemaRef to_schema();

private:
  Ref<Catalog> catalog_;
};

