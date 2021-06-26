#pragma once

#include "server/potatodb.hpp"

#include "exprs/create_table_expr.hpp"
#include "exprs/select_expr.hpp"
#include "exprs/compound_select_expr.hpp"
#include "exprs/insert_expr.hpp"
#include "exprs/update_expr.hpp"
#include "exprs/delete_from_expr.hpp"
#include "exprs/show_tables_expr.hpp"
#include "exprs/describe_table_expr.hpp"
#include "exprs/comp_expr.hpp"

#include "server/system_catalog.hpp"

class PlanFactory {
public:
  static ptr<BasePlan> create(const PotatoDB& db,
                              ptr<BaseExpr>&& expr);

  static ptr<BasePlan> from_expr(const CreateTableExpr& expr);

  static ptr<BasePlan> from_expr(const Catalog& catalog,
                                 const InsertExpr& expr);

  static ptr<BasePlan> from_expr(const Catalog& catalog,
                                 const UpdateExpr& expr);

  static ptr<BasePlan> from_expr(const Catalog& catalog,
                                 const DeleteFromExpr& expr);

  static ptr<BasePlan> from_expr(const Catalog& catalog,
                                 const SelectExpr& expr);

  static ptr<BasePlan> from_expr(const Catalog& catalog,
                                 const CompoundSelectExpr& expr);

  static vector<QueryColumn> find_columns(const table_name_t& table_name,
                                          const Catalog& catalog,
                                          const vector<ColumnExpr>& col_exprs);

  static vector<QueryColumn> find_columns(const table_name_t& table_name,
                                          const Catalog& catalog,
                                          const vector<AggExpr>& agg_exprs);


  static ptr<BasePlan> make_seq_scan_plan(const Catalog& catalog,
                                          const SelectExpr& expr);

  static const QuerySchema make_projection_schema(const Catalog& catalog,
                                                  const SelectExpr& expr);

  static ptr<BasePlan> make_sort_plan(const Catalog& catalog,
                                      const SelectExpr& expr);

  static ptr<BasePlan> make_agg_plan(const Catalog& catalog,
                                     const SelectExpr& expr);

  static std::tuple<ptr<BaseQuery>,
                    vector<QueryColumn>>
  to_query_node(const Catalog& catalog,
                const table_name_t name,
                const ptr<BaseExpr>& expr);

  static
  std::tuple<ptr<QueryWhere>, vector<QueryColumn>>
  to_query_where(const Catalog& catalog,
                 const table_name_t name,
                 const WhereClauseExpr* clause);
};
