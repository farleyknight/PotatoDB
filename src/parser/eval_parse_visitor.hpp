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

// TODO: Rename these! Not a fan of underscores in class names
using SelectStmtContext      = PotatoSQLParser::Select_stmtContext;
using CreateTableStmtContext = PotatoSQLParser::Create_table_stmtContext;
using ShowTablesStmtContext  = PotatoSQLParser::Show_tables_stmtContext;
using InsertStmtContext      = PotatoSQLParser::Insert_stmtContext;
using SelectCoreContext      = PotatoSQLParser::Select_coreContext;
using ExprContext            = PotatoSQLParser::ExprContext;

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

  Any visitCreate_table_stmt(CreateTableStmtContext *ctx) override {
    CreateTableExpr create_table;
    assert(ctx->table_name());

    TableExpr table(ctx->table_name()->getText());
    create_table.set_table(table);

    ColumnDefListExpr def_list;

    for (auto &col_def_ctx : ctx->column_def()) {
      auto col_name = col_def_ctx->column_name()->getText();
      auto type_name_ctx = col_def_ctx->type_name();
      auto type_name = type_name_ctx->name()[0]->getText();
      auto type_id = Type::type_id_for(type_name);

      if (type_name == "VARCHAR") {
        auto signed_number_ctx = type_name_ctx->signed_number();
        auto signed_number = signed_number_ctx[0]->getText();
        uint32_t number = std::stoi(signed_number);
        def_list.push_back(ColumnDefExpr(col_name, type_id, number));
      } else {
        def_list.push_back(ColumnDefExpr(col_name, type_id));
      }

      auto &col_def = def_list.back();

      for (auto &constraint : col_def_ctx->column_constraint()) {
        if (constraint->getText() == "NOTNULL") {
          col_def.is_not_null(true);
        } else if (constraint->getText() == "PRIMARYKEY") {
          col_def.is_primary_key(true);
        }
      }
    }

    create_table.set_column_defs(def_list);

    exprs_.emplace_back(make_unique<CreateTableExpr>(create_table));

    return visitChildren(ctx);
  }

  Any visitShow_tables_stmt(ShowTablesStmtContext *ctx) override {
    ShowTablesExpr show_tables;
    exprs_.emplace_back(make_unique<ShowTablesExpr>());

    return visitChildren(ctx);
  }

  Any visitInsert_stmt(InsertStmtContext *ctx) override {
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

    exprs_.emplace_back(make_unique<InsertExpr>(insert));

    return visitChildren(ctx);
  }

  Any visitSelect_core(SelectCoreContext *ctx) override {
    const auto &col_list_ctx = ctx->column_list();

    ColumnListExpr cols;
    for (auto &col_ctx : col_list_ctx->result_column()) {
      if (col_ctx->table_name() == nullptr) {
        cols.push_back(ColumnExpr(col_ctx->getText()));
      } else {
        if (col_ctx->column_name() == nullptr) {
          cols.push_back(ColumnExpr("*",
                                    col_ctx->table_name()->getText()));
        } else {
          cols.push_back(ColumnExpr(col_ctx->column_name()->getText(),
                                    col_ctx->table_name()->getText()));
        }
      }
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

    exprs_.emplace_back(make_unique<SelectExpr>(select));

    return visitChildren(ctx);
  }

  Any visitExpr(ExprContext *ctx) override {
    return visitChildren(ctx);
  }
};
