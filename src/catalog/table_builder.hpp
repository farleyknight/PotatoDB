#pragma once

#include "catalog/schema_ref.hpp"

class Catalog;

class TableBuilder {
public:
  TableBuilder(const Catalog& catalog)
    : catalog_ (catalog) {}

  TableBuilder& name(table_name_t name) {
    table_name_ = name;
  }

  TableBuilder& column(column_name_t name, TypeId type_id);

  TableBuilder&
  column(column_name_t name, TypeId type_id, size_t length);

  TableBuilder& not_null();
  TableBuilder& auto_increment();
  TableBuilder& primary_key();

  ptr<BasePlan> to_plan();

private:
  table_name_t table_name_;
  vector<TableColumn> table_columns_;
  const Catalog& catalog_;
};

