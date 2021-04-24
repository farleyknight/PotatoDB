


TEST(ParserTest, DISABLED_SimpleSelectTest) {
  // TODO: Test using SQLParser::as_exprs()

  String query = "SELECT *, * FROM foobar";

  // TEST:
  // 1. Two ColumnExpr (*, *)
  // 2. Table names = [foobar]
}

TEST(ParserTest, DISABLED_SelectMultipleTablesTest) {
  // TODO: Test using SQLParser::as_exprs()

  String query = "SELECT * FROM foo, bar";

  // TEST:
  // 1. One ColumnExpr (*)
  // 2. Table names = [foo, bar]
}


TEST(ParserTest, DISABLED_InsertTest) {
  // TODO: Test using SQLParser::as_exprs()

  String query = "INSERT INTO foobar VALUES (1,2)";

  // TEST:
  // 1. Table name
  // 2. Tuple list
}



TEST(ParserTest, DISABLED_InsertWithColumnsTest) {
  // TODO: Test using SQLParser::as_exprs()

  String query = "INSERT INTO foobar (a, b) VALUES (1,2), (3,4)";

  // TEST:
  // 1. Table name
  // 2. Columns
  // 3. Tuple list
}


TEST(ParserTest, DISABLED_CreateTableTest) {
  // TODO: Test using SQLParser::as_exprs()

  String statement = "CREATE TABLE foobar (id INT, name VARCHAR(10))";

}
