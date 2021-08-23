#pragma once

#include "plans/base_plan.hpp"
#include "exprs/column_def_list_expr.hpp"

class CreateTablePlan : public BasePlan {
public:
  // NOTE: DO NOT turn these variables into references!
  // Memory issues will bite you here!
  CreateTablePlan(const table_name_t table_name,
                  bool if_not_exists,
                  ColumnDefListExpr column_list)
    : BasePlan       (PlanType::CREATE_TABLE),
      if_not_exists_ (if_not_exists),
      table_name_    (table_name),
      column_list_   (column_list)
  {}

  const string& table_name() {
    return table_name_;
  }

  const string& primary_key() {
    return primary_key_;
  }

  const ColumnDefListExpr& column_list() {
    return column_list_;
  }

  bool is_query() const {
    return false;
  }

  bool if_not_exists() const {
    return if_not_exists_;
  }

private:
  bool if_not_exists_;
  const column_name_t primary_key_;
  const table_name_t table_name_;
  ColumnDefListExpr column_list_;
};
