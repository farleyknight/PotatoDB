#pragma once

#include "PotatoSQLBaseVisitor.h"

#include "common/types.hpp"

#include "exprs/show_tables_expr.hpp"
#include "exprs/describe_table_expr.hpp"
#include "exprs/insert_expr.hpp"
#include "exprs/select_expr.hpp"
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
using ExprContext               = PotatoSQLParser::ExprContext;
using WhereClauseContext        = PotatoSQLParser::Where_clauseContext;

class EvalParseVisitor : public PotatoSQLBaseVisitor {
private:
  vector<string> results_;
  vector<ptr<BaseExpr>> exprs_;

public:
  vector<string>&& results() {
    return move(results_);
  }

  vector<ptr<BaseExpr>>&& exprs() {
    return move(exprs_);
  }

  Any visitSelect_stmt(SelectStmtContext *ctx) override {
    // TODO?
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

  ValueExpr make_value_expr(ExprContext* expr_ctx) const;

  ptr<BaseExpr> make_expr(ExprContext *ctx);
  WhereClauseExpr make_where_clause_expr(WhereClauseContext *ctx);
  ColumnExpr make_col_expr(ExprContext* ctx);

  Any visitExpr(ExprContext *ctx) override {
    return visitChildren(ctx);
  }
};
