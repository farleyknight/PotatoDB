#pragma once

#include "exprs/create_table_expr.hpp"
#include "exprs/select_expr.hpp"
#include "exprs/insert_expr.hpp"
#include "exprs/show_tables_expr.hpp"

#include "plans/plan_builder.hpp"

class PlanFactory {
public:
  static ptr<BasePlan> create(Catalog& catalog_,
                              ptr<BaseExpr>&& expr)
  {
    switch (expr->expr_type()) {
    case ExprType::CREATE_TABLE: {
      auto create_table_expr = dynamic_cast<CreateTableExpr*>(expr.get());
      return PlanBuilder(catalog_).from_expr(create_table_expr);
    }
    case ExprType::SELECT: {
      auto select_expr = dynamic_cast<SelectExpr*>(expr.get());
      return PlanBuilder(catalog_).from_expr(select_expr);
    }
    case ExprType::INSERT: {
      auto insert_expr = dynamic_cast<InsertExpr*>(expr.get());
      return PlanBuilder(catalog_).from_expr(insert_expr);
    }
    case ExprType::SHOW_TABLES: {
      auto show_tables_expr = dynamic_cast<ShowTablesExpr*>(expr.get());
      return PlanBuilder(catalog_).from_expr(show_tables_expr);
    }
    default:
      throw NotImplementedException("Not finished :(");
    }
  }
};
