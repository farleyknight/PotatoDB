#pragma once

// TODO: The executor engine and the parser should be tested together
// We should be able to run the PotatoDB instance, have it parse the
// queries, and then see the results of it.
//
// Basically it's an end-to-end test that is one step away from allowing
// the server to run and perform a query.

#include "server/potatodb.hpp"

#include "gtest/gtest.h"

TEST(PotatoDBTest, CreateInsertSelectTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");
  db.run_statement("INSERT INTO foo_bar VALUES (1, 2)");
  auto result = db.run_statement("SELECT * FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);

  EXPECT_EQ(result.set()->value_at<int32_t>("colA", 0), 1);
  EXPECT_EQ(result.set()->value_at<int32_t>("colB", 0), 2);
}

TEST(PotatoDBTest, CreateInsertSelectStringTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB VARCHAR(32) )");
  db.run_statement("INSERT INTO foo_bar VALUES (1, 'hello, world')");
  auto result = db.run_statement("SELECT * FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);

  EXPECT_EQ(result.set()->value_at<int32_t>("colA", 0), 1);
  EXPECT_EQ(result.set()->value_at<string>("colB", 0), "hello, world");
}


TEST(PotatoDBTest, SystemCatalogTest) {
  PotatoDB db;
  db.reset_installation();

  auto result = db.run_statement("SELECT * FROM system_catalog");
  // TODO: Test that the system catalog exists
  EXPECT_TRUE(result.set()->size() > 0);
}

TEST(PotatoDBTest, CreateTableTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto foo_bar_file_path = db.table_file_for("foo_bar");

  EXPECT_TRUE(db.file_exists(foo_bar_file_path));

  auto result = db.run_statement("SELECT * FROM system_catalog WHERE table_name = 'foo_bar'");

  EXPECT_EQ(result.set()->size(), 1);
}

TEST(PotatoDBTest, ShowTableTest) {
  PotatoDB db;
  db.reset_installation();

  auto result = db.run_statement("SHOW TABLES");
  auto &result_set = *result.set().get();

  std::cout << " SHOW TABLES RESULTS : " << result_set.to_string() << std::endl;
}

TEST(PotatoDBTest, ShowFooBarTableTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto result = db.run_statement("SHOW TABLES");
  auto &result_set = result.set();

  EXPECT_EQ(result_set->size(), 2);
  EXPECT_EQ(result_set->value_at<string>("table_name", 0), "system_catalog");
  EXPECT_EQ(result_set->value_at<string>("table_name", 1), "foo_bar");
}

TEST(PotatoDBTest, DropTableTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");
  db.run_statement("DROP TABLE foo_bar");

  auto result = db.run_statement("SHOW TABLES");
  auto &result_set = result.set();

  EXPECT_EQ(result_set->size(), 1);
  EXPECT_EQ(result_set->value_at<string>("table_name", 0), "system_catalog");
}

TEST(PotatoDBTest, TruncateTableTest) {
  // TODO!
}

TEST(PotatoDBTest, DescribeTableTest) {
  // TODO!
}


TEST(PotatoDBTest, AlterTableDropColumnTest) {
  // TODO!
}

TEST(PotatoDBTest, AlterTableAddColumnTest) {
  // TODO!
}
