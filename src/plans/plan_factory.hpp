#pragma once

#include "exprs/create_table_expr.hpp"
#include "exprs/select_expr.hpp"
#include "exprs/insert_expr.hpp"
#include "exprs/show_tables_expr.hpp"

class PlanFactory {
public:
  static ptr<BasePlan> create(const Catalog& catalog_,
                              ptr<BaseExpr>&& expr)
  {
    switch (expr->expr_type()) {
    case ExprType::CREATE_TABLE: {
      auto create_table_expr = dynamic_cast<CreateTableExpr*>(expr.get());
      return from_expr(create_table_expr);
    }
    case ExprType::SELECT: {
      auto select_expr = dynamic_cast<SelectExpr*>(expr.get());
      return from_expr(catalog_, select_expr);
    }
    case ExprType::INSERT: {
      auto insert_expr = dynamic_cast<InsertExpr*>(expr.get());
      return from_expr(catalog_, insert_expr);
    }
    case ExprType::SHOW_TABLES: {
      auto show_tables_expr = dynamic_cast<ShowTablesExpr*>(expr.get());
      return from_expr(catalog_, show_tables_expr);
    }
    case ExprType::DESCRIBE_TABLE: {
      auto describe_table_expr = dynamic_cast<DescribeTableExpr*>(expr.get());
      return from_expr(catalog_, describe_table_expr);
    }
    default:
      throw NotImplementedException("Not finished :(");
    }
  }

  static ptr<BasePlan> from_expr(CreateTableExpr* expr) {
    auto table_name = expr->table().name();
    auto column_def_list = expr->column_defs();

    return make_unique<CreateTablePlan>(table_name,
                                        expr->primary_key(),
                                        column_def_list);
  }

  static ptr<BasePlan> make_agg_plan(const Catalog& catalog, SelectExpr* expr) {
    // TODO!
    // AggExpr will have ColumnExpr inside it
    // Convert AggExpr to QueryAgg and ColumnExpr to QueryColumn
    // Check the function_name to determine which AggType it is.
  }

  static ptr<BasePlan> make_seq_scan_plan(const Catalog& catalog, SelectExpr* expr) {
    // TODO: A SELECT statement can have multiple tables!
    // Need to support this at some point.
    auto table_name = expr->table_list().front().name();
    auto table_oid = catalog.table_oid_for(table_name);

    auto schema = catalog.query_schema_for(table_name,
                                           expr->column_list());

    auto maybe_pred = to_query_where(catalog, table_name, expr->pred());

    return make_unique<SeqScanPlan>(schema,
                                    table_oid,
                                    move(maybe_pred));
  }

  static ptr<BasePlan> from_expr(const Catalog& catalog, SelectExpr* expr) {
    if (expr->aggs().size() > 0) {
      return make_agg_plan(catalog, expr);
    } else {
      return make_seq_scan_plan(catalog, expr);
    }
  }

  static ptr<BaseQuery> to_query_node(const Catalog& catalog,
                                      const table_name_t name,
                                      const ptr<BaseExpr>& expr)
  {
    if (expr == nullptr) {
      return ptr<BaseQuery>(nullptr);
    }

    switch (expr->expr_type()) {
    case ExprType::COLUMN: {
      auto column_expr = dynamic_cast<ColumnExpr*>(expr.get());
      auto query_col = catalog.query_column_for(name, column_expr->name());
      return make_unique<QueryColumn>(query_col);
    }
    case ExprType::VALUE: {
      auto value_expr = dynamic_cast<ValueExpr*>(expr.get());
      return make_unique<QueryConst>(value_expr->to_value());
    }
    case ExprType::COMPARE: {
      auto comp_expr = dynamic_cast<CompExpr*>(expr.get());
      auto left_node  = to_query_node(catalog, name, comp_expr->left_expr());
      auto right_node = to_query_node(catalog, name, comp_expr->right_expr());
      return make_unique<QueryComp>(move(left_node),
                                    comp_expr->comp_type(),
                                    move(right_node));
    }
    default:
      throw Exception("this part not implemented yet :/ Expr to_string = " + expr->to_string());
    }
  }

  // TODO: Fix this!
  // Needs to return QueryWhere, which can take either:
  // Single comparison:
  // > WHERE a = 5
  // Or takes multiple comparisons, connected by logical combinators
  // > WHERE a = 5 AND foo = "bar"
  static ptr<QueryWhere> to_query_where(const Catalog& catalog,
                                        const table_name_t name,
                                        ptr<WhereClauseExpr>& clause)
  {
    if (clause == nullptr) {
      return ptr<QueryWhere>(nullptr);
    }
    auto left_query = to_query_node(catalog, name, clause->left_expr());
    auto right_query = to_query_node(catalog, name, clause->right_expr());

    return make_unique<QueryWhere>(move(left_query),
                                   clause->logical_type(),
                                   move(right_query));
  }

  static ptr<BasePlan> from_expr(const Catalog& catalog, UNUSED ShowTablesExpr* expr) {
    auto table_name = "system_catalog";
    auto table_oid = catalog.table_oid_for(table_name);
    auto schema = catalog.query_schema_for(table_name);

    auto type_col = make_unique<QueryColumn>(schema["type"]);

    auto value = Value::make(static_cast<int32_t>(SystemCatalogTypes::TABLE));
    auto query_const = make_unique<QueryConst>(value);

    auto table_comp = make_unique<QueryComp>(move(type_col),
                                             CompType::EQ,
                                             move(query_const));

    auto table_pred = make_unique<QueryWhere>(move(table_comp));

    return make_unique<SeqScanPlan>(schema,
                                    table_oid,
                                    move(table_pred));
  }

  static ptr<BasePlan> from_expr(const Catalog& catalog, DescribeTableExpr* expr) {
    auto system_table_name = "system_catalog";
    auto table_oid = catalog.table_oid_for(system_table_name);
    auto schema = catalog.query_schema_for(system_table_name);

    auto type_col = make_unique<QueryColumn>(schema["type"]);

    auto column_value = Value::make(static_cast<int32_t>(SystemCatalogTypes::COLUMN));
    auto column_const = make_unique<QueryConst>(column_value);

    auto column_comp = make_unique<QueryComp>(move(type_col),
                                              CompType::EQ,
                                              move(column_const));

    auto table_value = Value::make(expr->table().name());
    auto table_name = make_unique<QueryConst>(table_value);

    auto name_col = make_unique<QueryColumn>(schema["table_name"]);

    auto table_comp = make_unique<QueryComp>(move(name_col),
                                             CompType::EQ,
                                             move(table_name));

    auto table_pred = make_unique<QueryWhere>(move(column_comp),
                                              LogicalType::AND,
                                              move(table_comp));

    return make_unique<SeqScanPlan>(schema,
                                    table_oid,
                                    move(table_pred));
  }

  static ptr<BasePlan> from_expr(const Catalog& catalog, InsertExpr* expr) {
    auto table_name = expr->table_name();
    auto table_oid = catalog.table_oid_for(table_name);

    auto schema = catalog.query_schema_for(table_name,
                                           expr->column_list());
    assert(schema.column_count() > 0);
    // TODO: For now, we only support INSERT with it's own raw tuples.
    // However, we need to support SQL of the form:
    // > INSERT INTO ... (SELECT ...)

    auto raw_tuples = RawTuples(expr->tuple_list());
    auto child_plan = make_unique<RawTuplesPlan>(schema, raw_tuples);

    return make_unique<InsertPlan>(schema,
                                   table_oid,
                                   move(child_plan));
  }

};
