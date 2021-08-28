#pragma once

#include "plans/base_plan.hpp"
#include "exprs/create_table_expr.hpp"

class CreateTablePlan : public BasePlan {
public:
  // NOTE: DO NOT turn these variables into references!
  // Memory issues will bite you here!
  CreateTablePlan(const CreateTableExpr expr)
    : BasePlan       (PlanType::CREATE_TABLE),
      expr_          (expr)
  {}

  const CreateTableExpr& expr() {
    return expr_;
  }

  const table_name_t& table_name() {
    return expr_.table().name();
  }

  const string primary_key() {
    return expr_.primary_key();
  }

  const ColumnDefListExpr& column_list() {
    return expr_.column_defs();
  }

  bool is_query() const {
    return false;
  }

  bool if_not_exists() const {
    return expr_.if_not_exists();
  }

private:
  const CreateTableExpr expr_;
};
