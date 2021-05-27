#pragma once

#include "PotatoSQLBaseVisitor.h"

#include "common/types.hpp"

#include "exprs/show_tables_expr.hpp"
#include "exprs/describe_table_expr.hpp"
#include "exprs/insert_expr.hpp"
#include "exprs/select_expr.hpp"
#include "exprs/compound_select_expr.hpp"
#include "exprs/where_clause_expr.hpp"
#include "exprs/create_table_expr.hpp"
#include "exprs/comp_expr.hpp"
#include "exprs/agg_expr.hpp"

using antlrcpp::Any;
using potatosql::PotatoSQLBaseVisitor;
using potatosql::PotatoSQLParser;

// TODO: Rename these! Not a fan of underscores in class names
using SelectStmtContext         = PotatoSQLParser::Select_stmtContext;
using CreateTableStmtContext    = PotatoSQLParser::Create_table_stmtContext;
using ShowTablesStmtContext     = PotatoSQLParser::Show_tables_stmtContext;
using DescribeTableStmtContext  = PotatoSQLParser::Describe_table_stmtContext;
using InsertStmtContext         = PotatoSQLParser::Insert_stmtContext;
using SelectCoreContext         = PotatoSQLParser::Select_coreContext;
using FunctionArgsContext       = PotatoSQLParser::Function_argsContext;
using ExprContext               = PotatoSQLParser::ExprContext;
using WhereClauseContext        = PotatoSQLParser::Where_clauseContext;
using CompoundSelectStmtContext = PotatoSQLParser::Compound_select_stmtContext;
using OrderingTermContext       = PotatoSQLParser::Ordering_termContext;
using ResultColumnContext       = PotatoSQLParser::Result_columnContext;
using TableOrSubqueryContext    = PotatoSQLParser::Table_or_subqueryContext;
using FactoredSelectStmtContext = PotatoSQLParser::Factored_select_stmtContext;
using SimpleSelectStmtContext   = PotatoSQLParser::Simple_select_stmtContext;

class EvalParseVisitor : public PotatoSQLBaseVisitor {
public:
  vector<string>&& results() {
    return move(results_);
  }

  vector<ptr<BaseExpr>>&& exprs() {
    return move(exprs_);
  }

  std::tuple<ColumnListExpr, AggListExpr>
  make_select_list(vector<ResultColumnContext*> ctxs);

  OrderByExpr make_order_by(OrderingTermContext *ctx);

  TableListExpr make_table_list(vector<TableOrSubqueryContext*> table_list_ctxs) {
    TableListExpr tables;
    for (auto &table_ctx : table_list_ctxs) {
      if (table_ctx->table_name() != nullptr) {
        auto table_name = table_ctx->table_name()->getText();
        auto table = TableExpr(table_name);
        tables.push_back(table);
      }
    }
    return tables;
  }

  Any visitSelect_stmt(SelectStmtContext *ctx) override {
    // TODO! This is another place where need to do an ORDER BY
    SelectExpr select_expr;

    // TODO: Support select_or_values().size() > 0!
    assert(ctx->select_or_values().size() > 0);
    auto select_or_values = ctx->select_or_values()[0];

    auto tables = make_table_list(select_or_values->table_or_subquery());

    auto [cols, aggs] = make_select_list(select_or_values->result_column());

    select_expr.set_columns(cols);
    select_expr.set_aggs(aggs);
    select_expr.set_tables(tables);

    if (ctx->ordering_term().size() > 0) {
      // NOTE: Only using first column for now
      auto order_by = make_order_by(ctx->ordering_term()[0]);
      select_expr.set_order_by(order_by);
    }

    exprs_.emplace_back(make_unique<SelectExpr>(move(select_expr)));

    return visitChildren(ctx);
  }

  Any visitShow_tables_stmt(ShowTablesStmtContext *ctx) override {
    exprs_.emplace_back(make_unique<ShowTablesExpr>());

    return visitChildren(ctx);
  }

  Any visitDescribe_table_stmt(DescribeTableStmtContext *ctx) override;
  Any visitCreate_table_stmt(CreateTableStmtContext *ctx) override;
  Any visitInsert_stmt(InsertStmtContext *ctx) override;
  Any visitSelect_core(SelectCoreContext *ctx) override;
  Any visitCompound_select_stmt(CompoundSelectStmtContext *ctx) override;
  Any visitFactored_select_stmt(FactoredSelectStmtContext *ctx) override;
  Any visitSimple_select_stmt(SimpleSelectStmtContext *ctx) override;

  ValueExpr make_value_expr(ExprContext* expr_ctx) const;

  ptr<SelectExpr> make_select_expr(SelectCoreContext *ctx);
  ptr<BaseExpr> make_expr(ExprContext *ctx);

  WhereClauseExpr make_where_clause_expr(WhereClauseContext *ctx);
  ColumnExpr make_col_expr(FunctionArgsContext* ctx);

  Any visitExpr(ExprContext *ctx) override {
    return visitChildren(ctx);
  }

private:
  vector<string> results_;
  vector<ptr<BaseExpr>> exprs_;
};
