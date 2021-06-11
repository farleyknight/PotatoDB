#pragma once

#include "server/potatodb.hpp"

#include "gtest/gtest.h"

TEST(PotatoDBTest, CreateInsertSelectTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");
  db.run("INSERT INTO foo_bar VALUES (1, 2)");
  auto result = db.run("SELECT * FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);

  EXPECT_EQ(result.set()->value_at<int32_t>("colA", 0), 1);
  EXPECT_EQ(result.set()->value_at<int32_t>("colB", 0), 2);
}

TEST(PotatoDBTest, SelectEmptyTableTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto result = db.run("SELECT * FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 0);

  EXPECT_EQ(result.to_payload(), "");
}

TEST(PotatoDBTest, CreateInsertSelectStringTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB VARCHAR(32) )");
  db.run("INSERT INTO foo_bar VALUES (1, 'hello, world')");
  auto result = db.run("SELECT * FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);

  EXPECT_EQ(result.set()->value_at<int32_t>("colA", 0), 1);
  EXPECT_EQ(result.set()->value_at<string>("colB", 0), "hello, world");
}

TEST(PotatoDBTest, CreateInsertSelectAutoIncrementTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(32))");
  db.run("INSERT INTO foo_bar (name) VALUES ('hello, world')");
  db.run("INSERT INTO foo_bar (name) VALUES ('another string')");

  auto result = db.run("SELECT * FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 2);

  EXPECT_EQ(result.set()->value_at<int32_t>("id", 0), 1);
  EXPECT_EQ(result.set()->value_at<string>("name", 0), "hello, world");

  EXPECT_EQ(result.set()->value_at<int32_t>("id", 1), 2);
  EXPECT_EQ(result.set()->value_at<string>("name", 1), "another string");
}

TEST(PotatoDBTest, AggegrationTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER )");

  const index_t size = 10;

  for (index_t i = 0; i < size; ++i) {
    db.run("INSERT INTO foo_bar VALUES (" + std::to_string(i) + ")");
  }

  auto result
    = db.run("SELECT COUNT(colA), SUM(colA), MIN(colA), MAX(colA) FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);

  EXPECT_EQ(result.set()->schema().all().size(), 4);

  auto countA = result.set()->value_at<int32_t>("COUNT(colA)", 0);
  auto sumA   = result.set()->value_at<int32_t>("SUM(colA)", 0);
  auto minA   = result.set()->value_at<int32_t>("MIN(colA)", 0);
  auto maxA   = result.set()->value_at<int32_t>("MAX(colA)", 0);

  EXPECT_EQ(countA, size);
  EXPECT_EQ(sumA,   (size*(size-1)) / 2);
  EXPECT_EQ(minA,   0);
  EXPECT_EQ(maxA,   size-1);
}

TEST(PotatoDBTest, SystemCatalogTest) {
  PotatoDB db;
  db.reset_installation();

  auto result = db.run("SELECT * FROM system_catalog");
  EXPECT_TRUE(result.set()->size() > 0);
}

TEST(PotatoDBTest, CreateTableTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  EXPECT_TRUE(db.disk_mgr().table_file_exists("foo_bar"));

  auto result = db.run("SELECT * FROM system_catalog WHERE table_name == 'foo_bar'");
  auto &result_set = result.set();

  EXPECT_EQ(result_set->size(), 1);
  EXPECT_EQ(result_set->value_at<string>("table_name", 0), "foo_bar");
}

TEST(PotatoDBTest, CreateTableTwiceTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto result = db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  EXPECT_TRUE(result.set() == nullptr);
  EXPECT_EQ(result.to_payload(), "Full-blown ERROR!");
}

TEST(PotatoDBTest, CreateTableIfNotExistsTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto result =
    db.run("CREATE TABLE IF NOT EXISTS foo_bar ( colA INTEGER, colB INTEGER )");

  EXPECT_TRUE(result.set() == nullptr);
  // NOTE SHOULD NOT FAIL,
  // WARNING INSTEAD
  EXPECT_EQ(result.to_payload(), "Just a WARNING");
}

TEST(PotatoDBTest, DISABLED_MissingColumnTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto result = db.run("SELECT colC FROM foo_bar");

  EXPECT_TRUE(result.set() == nullptr);
  EXPECT_EQ(result.to_payload(), "Could not find column 'colC' on table 'foo_bar");
}

TEST(PotatoDBTest, ShowTablesTest) {
  PotatoDB db;
  db.reset_installation();

  auto result = db.run("SHOW TABLES");
  auto &result_set = result.set();

  ASSERT_EQ(result_set->size(), 1);
  EXPECT_EQ(result_set->value_at<string>("table_name", 0), "system_catalog");
}

TEST(PotatoDBTest, ShowTablesFooBarTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto result = db.run("SHOW TABLES");
  auto &result_set = result.set();

  ASSERT_EQ(result_set->size(), 2);
  EXPECT_EQ(result_set->value_at<string>("table_name", 0), "system_catalog");
  EXPECT_EQ(result_set->value_at<string>("table_name", 1), "foo_bar");
}

TEST(PotatoDBTest, DescribeTableTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");
  auto result = db.run("DESCRIBE TABLE foo_bar");
  auto &result_set = result.set();

  ASSERT_EQ(result_set->size(), 2);
  EXPECT_EQ(result_set->value_at<string>("object_name", 0), "colA");
  EXPECT_EQ(result_set->value_at<string>("object_name", 1), "colB");
}

TEST(PotatoDBTest, LoadSystemCatalogAfterRestartTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  // NOTE: Use 2nd instance to simulate starting a new DB
  PotatoDB db2;
  // NOTE: startup() should NOT start the server!
  // Otherwise it will block all other tests!
  db2.startup();

  auto result = db2.run("DESCRIBE TABLE foo_bar");
  auto &result_set = result.set();

  ASSERT_EQ(result_set->size(), 2);
  EXPECT_EQ(result_set->value_at<string>("object_name", 0), "colA");
  EXPECT_EQ(result_set->value_at<string>("object_name", 1), "colB");
}

TEST(PotatoDBTest, LoadSchemaAfterRestartTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  PotatoDB db2;
  // NOTE: startup() should NOT start the server!
  // Otherwise it will block all other tests!
  db2.startup();

  EXPECT_TRUE(db2.catalog().has_table_named("foo_bar"));
  EXPECT_TRUE(db2.catalog().table_has_column_named("foo_bar", "colA"));
  EXPECT_TRUE(db2.catalog().table_has_column_named("foo_bar", "colB"));
}

TEST(PotatoDBTest, DISABLED_DropTableTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");
  db.run("DROP TABLE foo_bar");

  auto result = db.run("SHOW TABLES");
  auto &result_set = result.set();

  EXPECT_EQ(result_set->size(), 1);
  EXPECT_EQ(result_set->value_at<string>("table_name", 0), "system_catalog");
}

TEST(PotatoDBTest, DISABLED_TruncateTableTest) {
  PotatoDB db;
  db.reset_installation();

  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");
  db.run("INSERT INTO foo_bar VALUES (1, 2)");
  db.run("TRUNCATE TABLE foo_bar");

  auto result = db.run("SELECT * FROM foo_bar");
  auto &result_set = result.set();

  EXPECT_EQ(result_set->size(), 0);
}

TEST(PotatoDBTest, DISABLED_AlterTableDropColumnTest) {
  // TODO!
}

TEST(PotatoDBTest, DISABLED_AlterTableAddColumnTest) {
  // TODO!
}
