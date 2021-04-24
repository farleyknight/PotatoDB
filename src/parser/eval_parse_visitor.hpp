#pragma once

#include "PotatoSQLBaseVisitor.h"

#include "common/types.hpp"
#include "parser/expr.hpp"

using antlrcpp::Any;
using potatosql::PotatoSQLBaseVisitor;
using potatosql::PotatoSQLParser;

class EvalParseVisitor : public PotatoSQLBaseVisitor {
public:
  MutVec<MutString> results;
  MutVec<MutPtr<Expr>> exprs;

  Any visitSql_stmt(PotatoSQLParser::Sql_stmtContext *ctx)
    override
  {
    return visitChildren(ctx);
  }

  Any visitSelect_stmt(PotatoSQLParser::Select_stmtContext *ctx)
    override
  {
    return visitChildren(ctx);
  }

  Any visitInsert_stmt(PotatoSQLParser::Insert_stmtContext *ctx)
    override
  {
    InsertExpr insert;
    assert(ctx->table_name());

    TableExpr table(ctx->table_name()->getText());
    insert.set_table(table);

    if (ctx->insert_columns() != nullptr) {
      const auto &cols_ctx = ctx->insert_columns();

      ColumnListExpr cols;
      for (auto &col_ctx : cols_ctx->column_name()) {
        cols.push_back(ColumnExpr(col_ctx->getText()));
      }
      insert.set_columns(cols);
    }

    assert(ctx->insert_tuples());

    const auto &tuple_list_ctx = ctx->insert_tuples();
    TupleListExpr tuples;
    for (auto &tuple_ctx : tuple_list_ctx->insert_tuple()) {
      TupleExpr tuple;
      for (auto &expr_ctx : tuple_ctx->expr()) {
        ValueExpr value(expr_ctx->getText());
        tuple.push_back(value);
      }
      tuples.push_back(tuple);
    }
    insert.set_tuples(tuples);

    exprs.emplace_back(make_unique<InsertExpr>(insert));

    return visitChildren(ctx);
  }

  Any visitSelect_core(PotatoSQLParser::Select_coreContext *ctx)
    override
  {
    const auto &col_list_ctx = ctx->column_list();

    ColumnListExpr cols;
    for (auto &col_ctx : col_list_ctx->result_column()) {
      cols.push_back(ColumnExpr(col_ctx->getText()));
    }

    const auto &table_list_ctxs = ctx->table_or_subquery();

    TableListExpr tables;
    for (auto &table_ctx : table_list_ctxs) {
      if (table_ctx->table_name() != nullptr) {
        auto table_name = table_ctx->table_name()->getText();
        auto table = TableExpr(table_name);
        tables.push_back(table);
      }
    }

    SelectExpr select;
    select.set_columns(cols);
    select.set_tables(tables);

    exprs.emplace_back(make_unique<SelectExpr>(select));

    return visitChildren(ctx);
  }

  Any visitExpr(PotatoSQLParser::ExprContext *ctx)
    override
  {
    return visitChildren(ctx);
  }
};
