
#include "parser/eval_parse_visitor.hpp"

Any EvalParseVisitor::visitDescribe_table_stmt(DescribeTableStmtContext *ctx) {
  auto describe_table = make_unique<DescribeTableExpr>();
  assert(ctx->table_name());

  TableExpr table(ctx->table_name()->getText());
  describe_table->set_table(table);

  exprs_.emplace_back(move(describe_table));

  return visitChildren(ctx);
}

Any EvalParseVisitor::visitCreate_table_stmt(CreateTableStmtContext *ctx) {
  CreateTableExpr create_table;
  assert(ctx->table_name());

  auto table_name = ctx->table_name()->getText();
  TableExpr table(table_name);
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
      std::cout << table_name << " :: " << col_def.name() << std::endl;
      std::cout << "CONSTRAINT CONSTRAINT " << constraint->getText() << std::endl;

      if (constraint->not_null()) {
        col_def.is_not_null(true);
      }

      if (constraint->primary_key()) {
        std::cout << "SETTING PRIMARY KEY " << col_def.name() << std::endl;
        col_def.is_primary_key(true);
        create_table.set_primary_key(col_def.name());
      }

      if (constraint->autoincrement()) {
        col_def.is_auto_increment(true);
      }
    }
  }

  if (table_name == "todos") {
    assert(create_table.primary_key() != "");
  }

  create_table.set_column_defs(def_list);

  exprs_.emplace_back(make_unique<CreateTableExpr>(create_table));

  return visitChildren(ctx);
}

ValueExpr EvalParseVisitor::make_value_expr(ExprContext* expr_ctx) const {
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
  } else if (expr_ctx->function_name() != nullptr) {
    using namespace std::chrono;
    auto now = system_clock::now();
    uint64_t secs = time_point_cast<seconds>(now).time_since_epoch().count();
    return ValueExpr(secs);
  } else {
    return ValueExpr(expr_ctx->getText());
  }
}

Any EvalParseVisitor::visitInsert_stmt(InsertStmtContext *ctx) {
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

ptr<BaseExpr> EvalParseVisitor::make_expr(ExprContext *ctx) {
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
  } else if (ctx->EQ()) {
    auto left_expr  = make_expr(ctx->expr()[0]);
    auto right_expr = make_expr(ctx->expr()[1]);

    return make_unique<CompExpr>(move(left_expr),
                                 CompareType::EQ,
                                 move(right_expr));
  }

  throw Exception("not all of it implemented yet :/");
}

WhereClauseExpr EvalParseVisitor::make_where_clause_expr(WhereClauseContext *ctx) {
  auto expr = ctx->expr();

  std::cout << "expr as string " << expr->getText() << std::endl;

  // NOTE: We may have to support WHERE (a = 5)
  // I believe MySQL treats this as (a == 5)
  if (expr->EQ()) {
    auto left_expr  = make_expr(expr->expr()[0]);
    auto right_expr = make_expr(expr->expr()[1]);

    auto comp_expr = make_unique<CompExpr>(move(left_expr),
                                           CompareType::EQ,
                                           move(right_expr));
    return WhereClauseExpr(move(comp_expr));

  } else if (expr->NOT_EQ1() || expr->NOT_EQ2()) {
    auto left_expr  = make_expr(expr->expr()[0]);
    auto right_expr = make_expr(expr->expr()[1]);

    auto comp_expr = make_unique<CompExpr>(move(left_expr),
                                           CompareType::NE,
                                           move(right_expr));
    return WhereClauseExpr(move(comp_expr));
  } else if (expr->K_AND()) {
    auto left_expr  = make_expr(expr->expr()[0]);
    auto right_expr = make_expr(expr->expr()[1]);

    return WhereClauseExpr(move(left_expr),
                           LogicalType::AND,
                           move(right_expr));
  } else {
    throw Exception("Other types of WHERE clauses are not yet implemented! :/");
  }
}

ColumnExpr EvalParseVisitor::make_col_expr(FunctionArgsContext* ctx) {
  if (ctx->expr().size() == 0 && ctx->getText() == "*") {
    return ColumnExpr("*");
  }

  auto expr = ctx->expr()[0];
  if (expr->table_name()) {
    return ColumnExpr(expr->table_name()->getText(),
                      expr->column_name()->getText());
  }

  return ColumnExpr(expr->column_name()->getText());
}

OrderByExpr EvalParseVisitor::make_order_by(OrderingTermContext *ctx) {
  // TODO: Allow multiple ordering terms
  auto col_name = ctx->expr()->getText();
  OrderByExpr order_by;
  order_by.set_column(ColumnExpr(col_name));

  if (ctx->K_ASC()) {
    order_by.set_direction("asc");
  } else if (ctx->K_DESC()) {
    order_by.set_direction("desc");
  } else {
    order_by.set_direction("asc"); // NOTE: DEFAULT!
  }

  return order_by;
}


Any EvalParseVisitor::visitFactored_select_stmt(FactoredSelectStmtContext *ctx) {
  std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
  std::cout << "Got factored select stmt : " << ctx->getText() << std::endl;

  auto select_expr = make_select_expr(ctx->select_core()[0]);

  if (ctx->ordering_term().size() > 0) {
    // NOTE: Only using first column for now
    std::cout << "()()()()()()() ORDERING TERM " << ctx->ordering_term()[0]->getText() << std::endl;

    auto order_by = make_order_by(ctx->ordering_term()[0]);
    select_expr->set_order_by(order_by);
  } else {
    std::cout << "()()()()()()() NO ORDERING TERM!" << std::endl;
  }
  std::cout << "SELECT expr " << select_expr->to_string() << std::endl;

  exprs_.emplace_back(move(select_expr));

  return visitChildren(ctx);
}

Any EvalParseVisitor::visitSimple_select_stmt(SimpleSelectStmtContext *ctx) {
  std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
  std::cout << "Got simple select stmt : " << ctx->getText() << std::endl;
  return visitChildren(ctx);
}


Any EvalParseVisitor::visitCompound_select_stmt(CompoundSelectStmtContext *ctx) {
  // TODO:
  //
  // `select_core` DOES NOT capture the ORDER BY part of a query
  //
  // It looks like `compount_select_stmt` DOES capture it

  CompoundSelectExpr stmt_expr;

  assert(ctx->select_core().size() > 0);

  auto left_select = make_select_expr(ctx->select_core()[0]);
  stmt_expr.set_left(move(left_select));

  if (ctx->select_core().size() == 2) {
    // TODO:
    // * Compounds have a left_select & right_select
    // * If only the left_select exists, then the type == CompoundType::NONE
    // * If only the left_select & right_select exists, then the type MUST BE one of:
    //   - CompoundType::UNION
    //   - CompoundType::UNION_ALL
    //   - CompoundType::INTERSECTION
    //   - CompoundType::EXCEPT

    throw Exception("FIXME");
  }

  if (ctx->ordering_term().size() > 0) {
    // NOTE: Only using first column for now
    auto order_by = make_order_by(ctx->ordering_term()[0]);
    stmt_expr.set_order_by(order_by);
  }

  // TODO:
  // Add LIMIT .. OFFSET ..

  auto compound_ptr = make_unique<CompoundSelectExpr>(move(stmt_expr));
  exprs_.emplace_back(move(compound_ptr));

  return visitChildren(ctx);
}

std::tuple<ColumnListExpr, AggListExpr>
EvalParseVisitor::make_select_list(vector<ResultColumnContext*> ctxs)
{
  ColumnListExpr cols;
  AggListExpr aggs;

  for (auto &col_ctx : ctxs) {
    if (col_ctx->getText() == "*") {
      cols.push_back(ColumnExpr("*"));
    } else if (col_ctx->table_name() == nullptr && col_ctx->column_name() == nullptr) {
      assert(col_ctx->expr());
      auto expr = col_ctx->expr();

      if (expr->function_name()) {
        auto func_name = expr->function_name()->getText();
        if (func_name == "COUNT" || func_name == "SUM" ||
            func_name == "MIN" || func_name == "MAX") {
          auto col_expr = make_col_expr(expr->function_args());
          aggs.push_back(AggExpr(func_name, col_expr));
        } else {
          throw Exception("Other types of functions are not yet implemented! :/");
        }
      } else {
        cols.push_back(ColumnExpr(col_ctx->getText()));
      }
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

  return std::make_tuple(cols, aggs);
}

ptr<SelectExpr> EvalParseVisitor::make_select_expr(SelectCoreContext *ctx) {
  const auto &col_list_ctx = ctx->column_list();

  auto [cols, aggs] = make_select_list(col_list_ctx->result_column());

  auto tables = make_table_list(ctx->table_or_subquery());

  SelectExpr select;
  select.set_columns(cols);
  select.set_aggs(aggs);
  select.set_tables(tables);

  if (ctx->where_clause() != nullptr) {
    auto where_clause = make_where_clause_expr(ctx->where_clause());
    auto where_clause_ptr = make_unique<WhereClauseExpr>(move(where_clause));
    select.set_where(move(where_clause_ptr));
  }

  return make_unique<SelectExpr>(move(select));
}

Any EvalParseVisitor::visitSelect_core(SelectCoreContext *ctx) {
  exprs_.emplace_back(make_select_expr(ctx));
  return visitChildren(ctx);
}
