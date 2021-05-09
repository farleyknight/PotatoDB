#include "parser/sql_parser.hpp"

TEST(ParserTest, SimpleSelectTest) {
  string query = "SELECT *, * FROM foobar";

  auto exprs = SQLParser::as_exprs(query);
  EXPECT_EQ(exprs.size(), 1);
  const auto expr = dynamic_cast<SelectExpr*>(exprs[0].get());

  const auto &table_list = expr->table_list();
  EXPECT_EQ(table_list.list().size(), 1);
  EXPECT_EQ(table_list.list()[0].to_string(), "foobar");

  const auto &col_list = expr->column_list();
  EXPECT_EQ(col_list.list().size(), 2);
  EXPECT_EQ(col_list.list()[0].to_string(), "*");
  EXPECT_EQ(col_list.list()[1].to_string(), "*");
}

TEST(ParserTest, SelectTableColumNameTest) {
  string query = "SELECT foo.bar, baz.* FROM foo, baz";

  auto exprs = SQLParser::as_exprs(query);
  EXPECT_EQ(exprs.size(), 1);
  const auto expr = dynamic_cast<SelectExpr*>(exprs[0].get());

  auto &table_list = expr->table_list();
  EXPECT_EQ(table_list.list().size(), 2);
  EXPECT_EQ(table_list.list()[0].to_string(), "foo");
  EXPECT_EQ(table_list.list()[1].to_string(), "bar");

  auto &col_list = expr->column_list();
  EXPECT_EQ(col_list.list().size(), 1);
  EXPECT_EQ(col_list.list()[0].to_string(), "*");
}

TEST(ParserTest, SelectMultipleTablesTest) {
  string query = "SELECT * FROM foo, bar";

  auto exprs = SQLParser::as_exprs(query);
  EXPECT_EQ(exprs.size(), 1);
  const auto expr = dynamic_cast<SelectExpr*>(exprs[0].get());

  auto &table_list = expr->table_list();
  EXPECT_EQ(table_list.list().size(), 2);
  EXPECT_EQ(table_list.list()[0].to_string(), "foo");
  EXPECT_EQ(table_list.list()[1].to_string(), "bar");

  auto &col_list = expr->column_list();
  EXPECT_EQ(col_list.list().size(), 1);
  EXPECT_EQ(col_list.list()[0].to_string(), "*");
}

TEST(ParserTest, InsertTest) {
  string query = "INSERT INTO foobar VALUES (1,2)";

  auto exprs = SQLParser::as_exprs(query);
  EXPECT_EQ(exprs.size(), 1);
  const auto expr = dynamic_cast<InsertExpr*>(exprs[0].get());

  EXPECT_EQ(expr->table_name(), "foobar");

  auto &tuple_list = expr->tuple_list();
  EXPECT_EQ(tuple_list.list().size(), 1);
  auto &tuple = tuple_list.list()[0];

  auto &values = tuple.list();
  EXPECT_EQ(values.size(), 2);
  EXPECT_EQ(values[0].to_string(), "1");
  EXPECT_EQ(values[1].to_string(), "2");
}

TEST(ParserTest, InsertWithColumnsTest) {
  string query = "INSERT INTO foobar (a, b) VALUES (1,2), (3,4)";

  auto exprs = SQLParser::as_exprs(query);
  EXPECT_EQ(exprs.size(), 1);
  const auto expr = dynamic_cast<InsertExpr*>(exprs[0].get());

  EXPECT_EQ(expr->table_name(), "foobar");

  auto &col_list = expr->column_list();
  EXPECT_EQ(col_list.list().size(), 2);
  EXPECT_EQ(col_list.list()[0].to_string(), "a");
  EXPECT_EQ(col_list.list()[1].to_string(), "b");

  auto &tuple_list = expr->tuple_list();
  EXPECT_EQ(tuple_list.list().size(), 2);

  auto &first_tuple = tuple_list.front();
  auto &first_values = first_tuple.list();
  EXPECT_EQ(first_values.size(), 2);
  EXPECT_EQ(first_values[0].to_string(), "1");
  EXPECT_EQ(first_values[1].to_string(), "2");

  auto &second_tuple = tuple_list.list()[1];
  auto &second_values = second_tuple.list();
  EXPECT_EQ(second_values.size(), 2);
  EXPECT_EQ(second_values[0].to_string(), "3");
  EXPECT_EQ(second_values[1].to_string(), "4");
}

TEST(ParserTest, CreateTableTest) {
  const string statement
    = "CREATE TABLE foobar (id INTEGER PRIMARY KEY, name VARCHAR(10) NOT NULL)";

  auto exprs = SQLParser::as_exprs(statement);
  EXPECT_EQ(exprs.size(), 1);
  const auto expr = dynamic_cast<CreateTableExpr*>(exprs[0].get());

  EXPECT_EQ(expr->table().name(), "foobar");

  auto &col_list = expr->column_defs().list();
  EXPECT_EQ(col_list.size(), 2);

  auto &id_col = col_list[0];
  EXPECT_EQ(id_col.name(), "id");
  EXPECT_EQ(id_col.type_name(), "INTEGER");
  EXPECT_EQ(id_col.is_primary_key(), true);

  auto &name_col = col_list[1];
  EXPECT_EQ(name_col.name(), "name");
  EXPECT_EQ(name_col.type_name(), "VARCHAR");
  EXPECT_EQ(name_col.type_length(), 10);
  EXPECT_EQ(name_col.is_not_null(), true);
}

