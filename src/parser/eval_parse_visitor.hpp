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
#include "exprs/update_expr.hpp"
#include "exprs/delete_from_expr.hpp"
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
using UpdateStmtContext         = PotatoSQLParser::Update_stmtContext;
using DeleteStmtContext         = PotatoSQLParser::Delete_stmtContext;

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

  Any visitUpdate_stmt(UpdateStmtContext *ctx) override {
    assert(ctx->qualified_table_name());

    UpdateExpr update_expr;

    TableExpr table_expr(ctx->qualified_table_name()->getText());
    update_expr.set_table(table_expr);

    for (index_t i = 0; i < ctx->column_name().size(); ++i) {
      auto column_name = ctx->column_name()[i]->getText();
      auto expr        = make_expr(ctx->expr()[i]);
      update_expr.set_pair(column_name, move(expr));
    }

    if (ctx->where_clause()) {
      auto where_clause = make_where_clause_expr(ctx->where_clause());
      update_expr.set_where(move(where_clause));
    }

    exprs_.emplace_back(make_unique<UpdateExpr>(move(update_expr)));

    return visitChildren(ctx);
  }

  Any visitDelete_stmt(DeleteStmtContext *ctx) override {
    assert(ctx->qualified_table_name());

    DeleteFromExpr delete_from_expr;

    TableExpr table_expr(ctx->qualified_table_name()->getText());
    delete_from_expr.set_table(table_expr);

    if (ctx->where_clause()) {
      auto where_clause = make_where_clause_expr(ctx->where_clause());
      delete_from_expr.set_where(move(where_clause));
    }

    exprs_.emplace_back(make_unique<DeleteFromExpr>(move(delete_from_expr)));

    return visitChildren(ctx);
  }

  Any visitSelect_stmt(SelectStmtContext *ctx) override;

  Any visitShow_tables_stmt(ShowTablesStmtContext *ctx) override {
    exprs_.emplace_back(make_unique<ShowTablesExpr>());

    return visitChildren(ctx);
  }

  Any visitDescribe_table_stmt(DescribeTableStmtContext *ctx) override;
  Any visitCreate_table_stmt(CreateTableStmtContext *ctx) override;
  Any visitInsert_stmt(InsertStmtContext *ctx) override;
  Any visitCompound_select_stmt(CompoundSelectStmtContext *ctx) override;
  Any visitFactored_select_stmt(FactoredSelectStmtContext *ctx) override;
  Any visitSimple_select_stmt(SimpleSelectStmtContext *ctx) override;

  ValueExpr make_value_expr(ExprContext* expr_ctx) const;

  ptr<SelectExpr> make_select_expr(SelectCoreContext *ctx);
  ptr<BaseExpr> make_expr(ExprContext *ctx);

  ptr<WhereClauseExpr> make_where_clause_expr(WhereClauseContext *ctx);
  ColumnExpr make_col_expr(FunctionArgsContext* ctx);

  Any visitExpr(ExprContext *ctx) override {
    return visitChildren(ctx);
  }

private:
  vector<string> results_;
  vector<ptr<BaseExpr>> exprs_;
};
