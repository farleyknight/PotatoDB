#include "parser/sql_parser.hpp"

TEST(ParserTest, SimpleSelectTest) {
  String query = "SELECT *, * FROM foobar";

  auto exprs = SQLParser::as_exprs(query);
  EXPECT_EQ(exprs.size(), 1);
  const auto expr = dynamic_cast<SelectExpr*>(exprs[0].get());

  const auto &table_list = expr->table_list();
  EXPECT_EQ(table_list.tables().size(), 1);
  EXPECT_EQ(table_list.tables()[0].to_string(), "foobar");

  const auto &col_list = expr->column_list();
  EXPECT_EQ(col_list.columns().size(), 2);
  EXPECT_EQ(col_list.columns()[0].to_string(), "*");
  EXPECT_EQ(col_list.columns()[1].to_string(), "*");
}

TEST(ParserTest, SelectMultipleTablesTest) {
  String query = "SELECT * FROM foo, bar";

  auto exprs = SQLParser::as_exprs(query);
  EXPECT_EQ(exprs.size(), 1);
  const auto expr = dynamic_cast<SelectExpr*>(exprs[0].get());

  auto &table_list = expr->table_list();
  EXPECT_EQ(table_list.tables().size(), 2);
  EXPECT_EQ(table_list.tables()[0].to_string(), "foo");
  EXPECT_EQ(table_list.tables()[1].to_string(), "bar");

  auto &col_list = expr->column_list();
  EXPECT_EQ(col_list.columns().size(), 1);
  EXPECT_EQ(col_list.columns()[0].to_string(), "*");
}

TEST(ParserTest, InsertTest) {
  String query = "INSERT INTO foobar VALUES (1,2)";

  auto exprs = SQLParser::as_exprs(query);
  EXPECT_EQ(exprs.size(), 1);
  const auto expr = dynamic_cast<InsertExpr*>(exprs[0].get());

  EXPECT_EQ(expr->table_name(), "foobar");

  auto &tuple_list = expr->tuple_list();
  EXPECT_EQ(tuple_list.tuples().size(), 1);
  auto &tuple = tuple_list.tuples()[0];

  auto &values = tuple.values();
  EXPECT_EQ(values.size(), 2);
  EXPECT_EQ(values[0].to_string(), "1");
  EXPECT_EQ(values[1].to_string(), "2");
}

TEST(ParserTest, InsertWithColumnsTest) {
  String query = "INSERT INTO foobar (a, b) VALUES (1,2), (3,4)";

  auto exprs = SQLParser::as_exprs(query);
  EXPECT_EQ(exprs.size(), 1);
  const auto expr = dynamic_cast<InsertExpr*>(exprs[0].get());

  EXPECT_EQ(expr->table_name(), "foobar");

  auto &col_list = expr->column_list();
  EXPECT_EQ(col_list.columns().size(), 2);
  EXPECT_EQ(col_list.columns()[0].to_string(), "a");
  EXPECT_EQ(col_list.columns()[1].to_string(), "b");

  auto &tuple_list = expr->tuple_list();
  EXPECT_EQ(tuple_list.tuples().size(), 2);

  auto &first_tuple = tuple_list.tuples()[0];
  auto &first_values = first_tuple.values();
  EXPECT_EQ(first_values.size(), 2);
  EXPECT_EQ(first_values[0].to_string(), "1");
  EXPECT_EQ(first_values[1].to_string(), "2");

  auto &second_tuple = tuple_list.tuples()[1];
  auto &second_values = second_tuple.values();
  EXPECT_EQ(second_values.size(), 2);
  EXPECT_EQ(second_values[0].to_string(), "3");
  EXPECT_EQ(second_values[1].to_string(), "4");
}


TEST(ParserTest, DISABLED_CreateTableTest) {
  // TODO: Test using SQLParser::as_exprs()

  String statement = "CREATE TABLE foobar (id INT, name VARCHAR(10))";

  // auto expr = dynamic_cast<CreateTableExpr*>(exprs[0].get());
}