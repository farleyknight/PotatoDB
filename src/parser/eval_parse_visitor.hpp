#pragma once

#include "PotatoSQLBaseVisitor.h"

#include "common/types.hpp"
#include "exprs/show_tables_expr.hpp"
#include "exprs/insert_expr.hpp"
#include "exprs/select_expr.hpp"
#include "exprs/create_table_expr.hpp"

using antlrcpp::Any;
using potatosql::PotatoSQLBaseVisitor;
using potatosql::PotatoSQLParser;
using PotatoSQLParser;

class EvalParseVisitor : public PotatoSQLBaseVisitor {
private:
  vector<string> results_;
  vector<ptr<BaseExpr>> exprs_;

public:
  const vector<string> results() {
    return results_;
  }

  const vector<ptr<BaseExpr>>& exprs() {
    return exprs_;
  }

  Any visitSelect_stmt(Select_stmtContext *ctx) override {
    // TODO?
    return visitChildren(ctx);
  }

  Any visitCreate_table_stmt(Create_table_stmtContext *ctx) override {
    CreateTableExpr create_table;
    assert(ctx->table_name());

    TableExpr table(ctx->table_name()->getText());
    create_table.set_table(table);

    const auto &col_def_list_ctx = ctx->column_def();
    ColumnDefListExpr def_list;
    for (auto &col_def_ctx : col_def_list_ctx) {
      auto col_name = col_def_ctx->column_name()->getText();
      auto type_name = col_def_ctx->type_name()->getText();
      def_list.push_back(ColumnDefExpr(col_name, type_name));
    }

    create_table.set_column_defs(def_list);

    exprs_.emplace_back(make_unique<CreateTableExpr>(create_table));

    return visitChildren(ctx);
  }

  Any visitShow_tables_stmt(Show_tables_stmtContext *ctx) override {
    ShowTablesExpr show_tables;
    exprs.emplace_back
  }

  Any visitInsert_stmt(Insert_stmtContext *ctx) override {
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

  Any visitSelect_core(Select_coreContext *ctx) override {
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

  Any visitExpr(ExprContext *ctx) override {
    return visitChildren(ctx);
  }
};
