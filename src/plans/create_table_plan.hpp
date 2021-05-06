#pragma once

#include "plans/base_plan.hpp"
#include "exprs/column_def_list_expr.hpp"

class CreateTablePlan : public BasePlan {
public:
  CreateTablePlan(string table_name,
                  ColumnDefListExpr column_list)
    : BasePlan     (PlanType::CREATE_TABLE),
      table_name_  (table_name),
      column_list_ (column_list)
  {}

  const string& table_name() {
    return table_name_;
  }

  const ColumnDefListExpr& column_list() {
    return column_list_;
  }

private:
  string table_name_;
  ColumnDefListExpr column_list_;
};
