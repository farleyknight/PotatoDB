#pragma once

#include "PotatoSQLBaseVisitor.h"

#include "common/types.hpp"

#include "exprs/show_tables_expr.hpp"
#include "exprs/insert_expr.hpp"
#include "exprs/select_expr.hpp"
#include "exprs/where_clause_expr.hpp"
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
using WhereClauseContext     = PotatoSQLParser::Where_clauseContext;

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
        // std::cout << "CONSTRAINT " << constraint->getText() << std::endl;

        if (constraint->not_null()) {
          col_def.is_not_null(true);
        }

        if (constraint->primary_key()) {
          col_def.is_primary_key(true);
          //std::cout << "----------" << std::endl;
          //std::cout << "Found primary key " << col_def.name() << std::endl;
          //std::cout << "----------" << std::endl;
          create_table.set_primary_key(col_def.name());
        }

        if (constraint->autoincrement()) {
          col_def.is_auto_increment(true);
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

  ValueExpr make_value_expr(ExprContext* expr_ctx) const {
    if (expr_ctx->literal_value() != nullptr) {
      auto literal_ctx = expr_ctx->literal_value();

      if (literal_ctx->NUMERIC_LITERAL() != nullptr) {
        return ValueExpr(ValueType::NUMERIC, literal_ctx->getText());
      } else if (literal_ctx->STRING_LITERAL() != nullptr) {
        auto text = literal_ctx->getText();
        return ValueExpr(ValueType::STRING, text.substr(1, text.size()-2));
      } else {
        return ValueExpr(expr_ctx->getText());
      }
    } else {
      return ValueExpr(expr_ctx->getText());
    }
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
        tuple.push_back(make_value_expr(expr_ctx));
      }
      tuples.push_back(tuple);
    }
    insert.set_tuples(tuples);

    exprs_.emplace_back(make_unique<InsertExpr>(insert));

    return visitChildren(ctx);
  }

  ptr<BaseExpr> make_expr(ExprContext *ctx) {
    // TODO:
    // Check for case where the expr is:
    // 1) Table Column name
    // 2) Integer Value
    // 3) String value

    if (ctx->column_name()) {
      return make_unique<ColumnExpr>(ctx->column_name()->getText());
    } else if (ctx->literal_value()) {
      auto value_ctx = ctx->literal_value();
      if (value_ctx->NUMERIC_LITERAL()) {
        return make_unique<ValueExpr>(ValueType::NUMERIC, value_ctx->getText());
      } else if (value_ctx->STRING_LITERAL()) {
        auto string_value = value_ctx->getText();
        return make_unique<ValueExpr>(ValueType::STRING, string_value.substr(1, string_value.size()-2));
      }
    }

    throw Exception("not all of it implemented yet :/");
  }

  WhereClauseExpr make_where_clause_expr(WhereClauseContext *ctx) {
    auto expr = ctx->expr();

    assert(expr->expr()[0]);
    assert(expr->expr()[1]);

    auto left_expr  = make_expr(expr->expr()[0]);
    auto right_expr = make_expr(expr->expr()[1]);

    std::cout << "expr as string " << expr->getText() << std::endl;
    if (expr->EQ()) {
      return WhereClauseExpr(move(left_expr),
                             CompType::EQ,
                             move(right_expr));
    } else if (expr->NOT_EQ1() || expr->NOT_EQ2()) {
      return WhereClauseExpr(move(left_expr),
                             CompType::NE,
                             move(right_expr));
    } else {
      // TODO: Some types of exprs should not be allowed!
      // For example, the assignment expression:
      // > WHERE (a = 5)
      // should not show up in a WHERE clause
      // It should instead be
      // > WHERE (a == 5)
      // Find a way to weed them out
      // Perhaps just throw an error? We have a way to catch it
      // and send it back to the user.
      throw Exception("Other types of WHERE clauses are not yet implemented! :/");
    }
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

    if (ctx->where_clause() != nullptr) {
      auto where_clause = make_where_clause_expr(ctx->where_clause());
      auto where_clause_ptr = make_unique<WhereClauseExpr>(move(where_clause));
      select.set_where(move(where_clause_ptr));
    }
    auto select_ptr = make_unique<SelectExpr>(move(select));
    exprs_.emplace_back(move(select_ptr));

    return visitChildren(ctx);
  }

  Any visitExpr(ExprContext *ctx) override {
    return visitChildren(ctx);
  }
};
