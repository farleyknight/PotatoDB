#pragma once

#include "catalog/catalog.hpp"
#include "catalog/table_column.hpp"
#include "catalog/table_builder.hpp"

#include "plans/base_plan.hpp"
#include "plans/create_table_plan.hpp"
#include "exprs/column_def_expr.hpp"

class TableBuilder {
public:
  TableBuilder(const Catalog& catalog)
    : catalog_ (catalog) {}

  TableBuilder& table_name(table_name_t name) {
    table_name_ = name;
    return *this;
  }

  TableBuilder& column(column_name_t name, TypeId type_id) {
    column_defs_.push_back(ColumnDefExpr(name, type_id));
    return *this;
  }

  TableBuilder& column(column_name_t name, TypeId type_id, length_t length) {
    column_defs_.push_back(ColumnDefExpr(name, type_id, length));
    return *this;
  }

  TableBuilder& not_null() {
    column_defs_.back().is_not_null();
    return *this;
  }

  TableBuilder& auto_increment() {
    column_defs_.back().is_auto_increment(true);
    return *this;
  }

  TableBuilder& primary_key() {
    column_defs_.back().is_primary_key(true);
    primary_key_ = column_defs_.back().name();
    return *this;
  }

  ptr<BasePlan> to_plan() {
    return make_unique<CreateTablePlan>(table_name_,
                                        true,
                                        primary_key_,
                                        ColumnDefListExpr(column_defs_));
  }

private:
  string primary_key_;
  table_name_t table_name_;
  vector<ColumnDefExpr> column_defs_;
  UNUSED const Catalog& catalog_;
};
