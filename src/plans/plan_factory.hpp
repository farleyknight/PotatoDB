#pragma once

class PlanFactory {
public:
  static ptr<BasePlan> create(Catalog& catalog_,
                              ptr<BaseExpr&& expr)
  {
    switch (expr->expr_type()) {

    case ExprType::CREATE_TABLE:
      auto create_table_expr = dynamic_cast<CreateTableExpr*>(expr.get());
      auto table_name = create_table_expr->table().name();
      auto column_def_list = create_table_expr->column_defs();
      return make_unique<CreateTablePlan>(table_name, column_def_list);

    case ExprType::SELECT_FROM:
      auto select_from_expr = dynamic_cast<SelectFromExpr*>(expr.get());
      auto table_name = select_from_expr->table().name();

      auto table_oid = catalog_.table_oid_for(table_name);
      auto schema = catalog_.query_schema_for(table_names,
                                              select_from_expr->columns());
      auto maybe_pred = select_from_expr->pred();

      return make_unique<SeqScanPlan>(schema,
                                      table_oid,
                                      maybe_pred);
    case ExprType::INSERT_INTO:
      auto insert_into_expr = dynamic_cast<InsertIntoExpr*>(expr.get());


      return make_unique<InsertPlan>(schema,
                                     seq_scan_plan);


    }
  }
}
