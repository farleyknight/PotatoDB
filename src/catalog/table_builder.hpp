#pragma once

#include "catalog/catalog.hpp"
#include "catalog/table_column.hpp"

class TableBuilder {
public:
  TableBuilder(const Catalog& catalog)
    : catalog_ (catalog) {}

  TableBuilder& name(table_name_t name) {
    table_name_ = name;
  }

  TableBuilder& column(column_name_t name, TypeId type_id) {
    column_names_.push_back(name);
    type_ids_.push_back(type_id);
  }

  TableBuilder&
  column(column_name_t name, TypeId type_id, size_t length);

  TableBuilder& not_null();
  TableBuilder& auto_increment();
  TableBuilder& primary_key();

  ptr<BasePlan> to_plan() {
    // TODO:
    // 1) Take the metadata given so far
    // 2) Turn it into a ColumnDefListExpr
    // 3)
  }

private:
  table_name_t table_name_;
  vector<TableColumn> table_columns_;
  const Catalog& catalog_;
};

