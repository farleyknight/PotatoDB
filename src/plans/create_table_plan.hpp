#pragma once

#include "plans/base_plan.hpp"
#include "exprs/column_def_list_expr.hpp"

class CreateTablePlan : public BasePlan {
public:
  CreateTablePlan(string table_name,
                  string primary_key,
                  ColumnDefListExpr column_list)
    : BasePlan     (PlanType::CREATE_TABLE),
      primary_key_ (primary_key),
      table_name_  (table_name),
      column_list_ (column_list)
  {
    if (table_name == "todos") {
      assert(primary_key != "");
    }
  }

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

private:
  string primary_key_;
  string table_name_;
  ColumnDefListExpr column_list_;
};
