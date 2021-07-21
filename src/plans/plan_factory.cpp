#include "plans/plan_factory.hpp"

ptr<BasePlan>
PlanFactory::create(const PotatoDB& db,
                    ptr<BaseExpr>&& expr)
{
  switch (expr->expr_type()) {
  case ExprType::CREATE_TABLE: {
    auto create_table_expr = dynamic_cast<CreateTableExpr*>(expr.get());
    return from_expr(*create_table_expr);
  }
  case ExprType::SELECT: {
    auto select_expr = dynamic_cast<SelectExpr*>(expr.get());
    return from_expr(db.catalog(), *select_expr);
  }
  case ExprType::COMPOUND_SELECT: {
    auto compound_expr = dynamic_cast<CompoundSelectExpr*>(expr.get());
    return from_expr(db.catalog(), *compound_expr);
  }
  case ExprType::INSERT: {
    auto insert_expr = dynamic_cast<InsertExpr*>(expr.get());
    return from_expr(db.catalog(), *insert_expr);
  }
  case ExprType::SHOW_TABLES: {
    auto object_type = SystemCatalog::table_type();
    return db.sql_to_plan("SELECT * FROM system_catalog WHERE object_type == " + object_type);
  }
  case ExprType::DESCRIBE_TABLE: {
    auto object_type = SystemCatalog::column_type();
    auto describe_table_expr = dynamic_cast<DescribeTableExpr*>(expr.get());
    auto table_name = "'" + describe_table_expr->table().name() + "'";
    auto sql = "SELECT * FROM system_catalog WHERE object_type = " \
      + object_type + " AND table_name = " + table_name;
    return db.sql_to_plan(sql);
  }
  case ExprType::UPDATE: {
    auto update_expr = dynamic_cast<UpdateExpr*>(expr.get());
    return from_expr(db.catalog(), *update_expr);
  }
  case ExprType::DELETE_FROM: {
    auto delete_from_expr = dynamic_cast<DeleteFromExpr*>(expr.get());
    return from_expr(db.catalog(), *delete_from_expr);
  }
  default:
    throw NotImplementedException("Not finished :(");
  }
}

ptr<BasePlan>
PlanFactory::from_expr(const CreateTableExpr& expr) {
  auto table_name = expr.table().name();
  auto column_def_list = expr.column_defs();
  auto if_not_exists = expr.if_not_exists();

  // std::cout << "PLAN FACTORY CREATING TABLE " << table_name << std::endl;

  return make_unique<CreateTablePlan>(table_name,
                                      if_not_exists,
                                      expr.primary_key(),
                                      column_def_list);
}


ptr<BasePlan>
PlanFactory::from_expr(const Catalog& catalog,
                       const UpdateExpr& expr)
{
  auto table_name = expr.table().name();
  auto table_oid = catalog.table_oid_for(table_name);
  auto [maybe_pred, cols] = to_query_where(catalog, table_name, expr.pred().get());

  auto schema = catalog.query_schema_for(table_name);

  auto scan_plan = make_unique<SeqScanPlan>(schema,
                                            table_oid,
                                            move(maybe_pred));

  map<column_oid_t, ptr<BaseQuery>> update_values;
  for (const auto &[name, expr] : expr.update_values()) {
    auto oid = catalog.query_column_for(table_name, name).column_oid();
    auto [query_where_ptr, cols] = to_query_node(catalog, table_name, expr);
    update_values[oid] = move(query_where_ptr);
  }

  return make_unique<UpdatePlan>(schema,
                                 table_oid,
                                 move(scan_plan),
                                 move(update_values));
}

ptr<BasePlan>
PlanFactory::from_expr(const Catalog& catalog,
                       const DeleteFromExpr& expr)
{
  auto table_name = expr.table().name();
  auto table_oid = catalog.table_oid_for(table_name);
  auto [maybe_pred, cols] = to_query_where(catalog, table_name,
                                           expr.pred().get());

  auto schema = catalog.query_schema_for(table_name);

  auto scan_plan = make_unique<SeqScanPlan>(schema,
                                            table_oid,
                                            move(maybe_pred));

  return make_unique<DeletePlan>(schema,
                                 table_oid,
                                 move(scan_plan));
}

ptr<BasePlan>
PlanFactory::make_scan_plan(const Catalog& catalog,
                            const SelectExpr& expr)
{
  // TODO: A SELECT statement can have multiple tables!
  // Need to support this at some point.
  auto table_name = expr.table_list().front().name();
  auto table_oid  = catalog.table_oid_for(table_name);
  auto schema     = catalog.query_schema_for(table_name);

  auto [maybe_pred, cols] = to_query_where(catalog, table_name,
                                           expr.pred().get());

  return make_unique<SeqScanPlan>(schema,
                                  table_oid,
                                  move(maybe_pred));
}

vector<QueryColumn>
PlanFactory::find_columns(const table_name_t& table_name,
                          const Catalog& catalog,
                          const vector<ColumnExpr>& col_exprs)
{
  vector<QueryColumn> cols;
  for (const auto& col_expr : col_exprs) {
    auto column_name = col_expr.name();
    if (column_name == "*") {
      auto schema     = catalog.query_schema_for(table_name);
      auto table_cols = schema.all();
      cols.insert(std::end(cols), std::begin(table_cols), std::end(table_cols));
    } else {
      cols.push_back(catalog.query_column_for(table_name,
                                              column_name));
    }
  }
  return cols;
}


vector<QueryColumn>
PlanFactory::find_columns(const table_name_t& table_name,
                          const Catalog& catalog,
                          const vector<AggExpr>& agg_exprs)
{
  vector<QueryColumn> cols;
  for (const auto& agg_expr : agg_exprs) {
    auto column_name = agg_expr.column_expr().name();
    if (column_name == "*") {
      cols.push_back(QueryColumn::splat());
    } else {
      cols.push_back(catalog.query_column_for(table_name,
                                              column_name));
    }
  }
  return cols;
}

ptr<BasePlan>
PlanFactory::from_expr(const Catalog& catalog,
                       const CompoundSelectExpr& expr)
{
  // TODO LATER
  // * Add support for UNION, INTERSECTION
  // * Use right_select appropriately

  auto left_select_ptr = expr.left_select().get();
  auto left_scan_plan = make_scan_plan(catalog, *left_select_ptr);
  auto order_by = expr.order_by();

  auto schema = dynamic_cast<SchemaPlan*>(left_scan_plan.get())->schema();
  return make_unique<SortPlan>(schema,
                               order_by,
                               move(left_scan_plan));
}

const QuerySchema
PlanFactory::make_projection_schema(const Catalog& catalog,
                                    const SelectExpr& expr)
{
  auto table_name = expr.table_list().front().name();
  vector<QueryColumn> cols;
  // TODO: We are overdue for a Projection operator
  // We should only worry about the shape of the tuple AFTER
  // we have finished with the rest of the query.
  // In other words, lets pass around the entire tuple for now.
  // And only at the end will we bother with exposing only
  // those columns the user asked for.

  // TODO: TO implement a proper Projection operator,
  // you'll need to wrap almost every plan in PlanFactory with
  // a ProjectionPlan, if the SELECT is not "*".
  // Which could be a lot!

  // NOTE: Columns found in SELECT
  auto select_cols = find_columns(table_name, catalog, expr.column_list().list());
  cols.insert(std::end(cols),
              std::begin(select_cols), std::end(select_cols));

  // NOTE: Columns found in SUM, COUNT, etc
  auto agg_cols = find_columns(table_name, catalog, expr.agg_list().list());
  cols.insert(std::end(cols),
              std::begin(agg_cols), std::end(agg_cols));

  // NOTE: Columns found in WHERE
  auto [maybe_pred, pred_cols] = to_query_where(catalog, table_name,
                                                expr.pred().get());
  cols.insert(std::end(cols),
              std::begin(pred_cols), std::end(pred_cols));

  return QuerySchema(cols);
}

ptr<BasePlan>
PlanFactory::from_expr(const Catalog& catalog,
                       const SelectExpr& expr)
{
  // TODO: NOW
  // All of the projection logic should be wrapped up in the
  // ProjectionExec and ProjectionPlan classes.

  if (expr.agg_list().list().size() > 0) {
    return make_agg_plan(catalog, expr);
  } else if (expr.order_by().is_valid()) {
    logger->debug("[PlanFactory] ORDER BY is valid! " + expr.order_by().to_string());
    return make_sort_plan(catalog, expr);
  } else {
    auto schema = make_projection_schema(catalog, expr);
    auto plan = make_scan_plan(catalog, expr);

    return make_unique<ProjectionPlan>(schema, move(plan));
  }
}

ptr<BasePlan>
PlanFactory::make_sort_plan(const Catalog& catalog,
                            const SelectExpr& expr)
{
  auto scan_plan = make_scan_plan(catalog, expr);
  auto order_by = expr.order_by();

  auto schema = dynamic_cast<SchemaPlan*>(scan_plan.get())->schema();
  return make_unique<SortPlan>(schema,
                               order_by,
                               move(scan_plan));
}

ptr<BasePlan>
PlanFactory::make_agg_plan(const Catalog& catalog,
                           const SelectExpr& expr)
{
  // TODO!
  // AggExpr will have ColumnExpr inside it
  // Convert AggExpr to QueryAgg and ColumnExpr to QueryColumn
  // Check the function_name to determine which AggType it is.
  auto table_name = expr.table_list().front().name();
  vector<QueryAgg> agg_nodes;
  for (const auto& agg : expr.agg_list().list()) {
    auto col_name = agg.column_expr().name();

    // TODO! We don't always need to be pulling the QueryColumn!
    //
    // If it's a column splat ("*") then we don't actually need to.
    // We can maybe find a way to represent a "thunk" in QueryColumn
    //
    // Perhaps QueryColumnName is a good substitute for QueryColumn
    // when things MUST be implied by the query context
    // Perhaps QueryColumName + QueryContext = QueryColumn?
    //
    // Maybe QueryContext is just the table_name_t plus the Catalog,
    // for looking up further metadata.
    if (col_name == "*") {
      auto query_col = QueryColumn::splat();
      agg_nodes.push_back(QueryAgg(query_col, agg.agg_type()));
    } else {
      auto query_col = catalog.query_column_for(table_name, col_name);
      agg_nodes.push_back(QueryAgg(query_col, agg.agg_type()));
    }
  }

  vector<QueryColumn> agg_cols;
  for (const auto& agg_node : agg_nodes) {
    agg_cols.push_back(agg_node.to_query_column());
  }
  auto agg_schema = QuerySchema(agg_cols);

  auto scan_plan = make_scan_plan(catalog, expr);
  assert(scan_plan != nullptr);

  return make_unique<AggPlan>(agg_schema,
                              move(scan_plan),
                              agg_nodes);
}

std::tuple<ptr<BaseQuery>, vector<QueryColumn>>
PlanFactory::to_query_node(const Catalog& catalog,
                           const table_name_t name,
                           const ptr<BaseExpr>& expr)
{
  if (expr == nullptr) {
    auto base_query_null = ptr<BaseQuery>(nullptr);
    return std::make_tuple(move(base_query_null), vector<QueryColumn>());
  }

  switch (expr->expr_type()) {
  case ExprType::COLUMN: {
    auto column_expr = dynamic_cast<ColumnExpr*>(expr.get());
    auto query_col = catalog.query_column_for(name, column_expr->name());
    auto query_col_ptr = make_unique<QueryColumn>(query_col);
    auto query_cols = vector<QueryColumn> { query_col };
    return std::make_tuple(move(query_col_ptr), move(query_cols));
  }
  case ExprType::AGG: {
    auto agg_expr = dynamic_cast<AggExpr*>(expr.get());
    auto col_name = agg_expr->column_expr().name();
    auto query_col = catalog.query_column_for(name, col_name);
    auto query_agg_ptr = make_unique<QueryAgg>(query_col, agg_expr->agg_type());
    auto query_cols = vector<QueryColumn> { query_col };
    return std::make_tuple(move(query_agg_ptr), move(query_cols));
  }
  case ExprType::VALUE: {
    auto value_expr = dynamic_cast<ValueExpr*>(expr.get());
    auto query_const_ptr = make_unique<QueryConst>(value_expr->to_value());
    return std::make_tuple(move(query_const_ptr), vector<QueryColumn>());
  }
  case ExprType::COMPARE: {
    auto comp_expr = dynamic_cast<CompExpr*>(expr.get());
    auto [left_node, left_cols]   = to_query_node(catalog, name,
                                                  comp_expr->left_expr());
    auto [right_node, right_cols] = to_query_node(catalog, name,
                                                  comp_expr->right_expr());

    auto query_comp_ptr = make_unique<QueryComp>(move(left_node),
                                                 comp_expr->compare_type(),
                                                 move(right_node));

    vector<QueryColumn> cols;
    cols.insert(std::end(cols), std::begin(left_cols), std::end(left_cols));
    cols.insert(std::end(cols), std::begin(right_cols), std::end(right_cols));

    return std::make_tuple(move(query_comp_ptr), move(cols));
  }
  case ExprType::WHERE: {
    auto where_expr = dynamic_cast<WhereClauseExpr*>(expr.get());
    return to_query_where(catalog, name, where_expr);
  }
  default:
    throw Exception("this part not implemented yet :/ Expr to_string = " + expr->to_string());
  }
}


std::tuple<ptr<QueryWhere>, vector<QueryColumn>>
PlanFactory::to_query_where(const Catalog& catalog,
                            const table_name_t name,
                            const WhereClauseExpr* clause)
{
  if (clause == nullptr) {
    auto null_where = ptr<QueryWhere>(nullptr);
    auto empty_cols = vector<QueryColumn>();
    return std::make_tuple(move(null_where), move(empty_cols));
  }

  // TODO: Not sure I really want WhereClauseExpr to have TWO children.
  // I'd rather it have only ONE child, and that child itself can have TWO children.
  // Because most likely the ONE child will be something like a `LogicalExpr`

  auto [left_query, left_cols]   = to_query_node(catalog, name, clause->left_expr());
  auto [right_query, right_cols] = to_query_node(catalog, name, clause->right_expr());

  auto query_where = make_unique<QueryWhere>(move(left_query),
                                             clause->logical_type(),
                                             move(right_query));

  vector<QueryColumn> cols;
  cols.insert(std::end(cols), std::begin(left_cols), std::end(left_cols));
  cols.insert(std::end(cols), std::begin(right_cols), std::end(right_cols));

  return std::make_tuple(move(query_where), move(cols));
}

ptr<BasePlan>
PlanFactory::from_expr(const Catalog& catalog,
                       const InsertExpr& expr)
{
  auto table_name = expr.table_name();
  auto table_oid = catalog.table_oid_for(table_name);

  auto schema = catalog.query_schema_for(table_name,
                                         expr.column_list());
  assert(schema.column_count() > 0);
  // TODO: For now, we only support INSERT with it's own raw tuples.
  // However, we need to support SQL of the form:
  // > INSERT INTO ... (SELECT ...)

  auto raw_tuples = RawTuples(expr.tuple_list());
  auto child_plan = make_unique<RawTuplesPlan>(schema, raw_tuples);

  return make_unique<InsertPlan>(schema,
                                 table_oid,
                                 move(child_plan));
}
