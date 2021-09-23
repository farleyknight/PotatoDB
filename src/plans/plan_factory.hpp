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

// TODO
// (6/26/2021)
//
// A new way to handle Plan building:
// Let us use a vector of ptr<BasePlan>
// Instead of using `move` all over the place,
// we just append to this one vector, and then
// iterate/move through it like a heap.
//
// As Plans are placed into the list, they are
// given a `plan_index` which is just the index
// they are given.
//
// At the moment, almost all of PlanFactory is
// static methods. Instead, let PlanFactory
// have one instance, with one main instance
// variable: vector<ptr<BasePlan>>
//
// The PlanFactory then has to process all of the plans
// according to the corresponding executor.
//
// Come to think of it, why is the executor separate
// from the plan anyways? It's kind of an extra
// layer at this point?
//
// We can likely generate tuples here! Maybe that
// makes this a TupleFactory, not a PlanFactory?
//
// I think we should maybe find a way to combine
// Plan & Exec into Operator?
//
// The reason I saw this is because ExecFactory is,
// at this point, a little redundant? It's moving
// pointers around? But I don't really see what work
// it's doing?
//
// I think we can collapse Plan & Exec into Operator
//
// I also think this class could be called DB Engine
// after all is said and done?
//

class PlanFactory {
public:
  static ptr<BasePlan>
  create(const SchemaMgr& schema_mgr,
         ptr<BaseExpr>&& expr);

  static ptr<BasePlan>
  from_expr(const CreateTableExpr& expr);

  static ptr<BasePlan>
  from_expr(const SchemaMgr& schema_mgr,
            const ShowTablesExpr& expr);

  static ptr<BasePlan>
  from_expr(const SchemaMgr& schema_mgr,
            const DescribeTableExpr& expr);

  static ptr<BasePlan>
  from_expr(const SchemaMgr& schema_mgr,
            const InsertExpr& expr);

  static ptr<BasePlan>
  from_expr(const SchemaMgr& schema_mgr,
            const UpdateExpr& expr);

  static ptr<BasePlan>
  from_expr(const SchemaMgr& schema_mgr,
            const DeleteFromExpr& expr);

  static ptr<BasePlan>
  from_expr(const SchemaMgr& schema_mgr,
            const SelectExpr& expr);

  static ptr<BasePlan>
  from_expr(const SchemaMgr& schema_mgr,
            const CompoundSelectExpr& expr);

  static vector<QueryColumn>
  find_columns(const table_name_t& table_name,
               const SchemaMgr& schema_mgr,
               const vector<ColumnExpr>& col_exprs);

  static vector<QueryColumn>
  find_columns(const table_name_t& table_name,
               const SchemaMgr& schema_mgr,
               const vector<AggExpr>& agg_exprs);

  static ptr<BasePlan>
  make_scan_plan(const SchemaMgr& schema_mgr,
                 const SelectExpr& expr);

  static const QuerySchema
  make_projection_schema(const SchemaMgr& schema_mgr,
                         const SelectExpr& expr);

  static ptr<BasePlan>
  make_sort_plan(const SchemaMgr& schema_mgr,
                 const SelectExpr& expr);

  static ptr<BasePlan>
  make_agg_plan(const SchemaMgr& schema_mgr,
                const SelectExpr& expr);

  static
  std::tuple<ptr<BaseQuery>, vector<QueryColumn>>
  to_query_node(const SchemaMgr& schema_mgr,
                const table_name_t name,
                const ptr<BaseExpr>& expr);

  static
  std::tuple<ptr<QueryWhere>, vector<QueryColumn>>
  to_query_where(const SchemaMgr& schema_mgr,
                 const table_name_t name,
                 const WhereClauseExpr* clause);
};
