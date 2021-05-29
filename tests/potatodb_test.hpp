#pragma once

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

TEST(PotatoDBTest, CreateInsertSelectAutoIncrementTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(32))");
  db.run_statement("INSERT INTO foo_bar (name) VALUES ('hello, world')");
  db.run_statement("INSERT INTO foo_bar (name) VALUES ('another string')");

  auto result = db.run_statement("SELECT * FROM foo_bar");

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

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER )");

  const index_t size = 10;

  for (index_t i = 0; i < size; ++i) {
    db.run_statement("INSERT INTO foo_bar VALUES (" + std::to_string(i) + ")");
  }

  auto result = db.run_statement("SELECT COUNT(colA), SUM(colA), MIN(colA), MAX(colA) FROM foo_bar");

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

const string join_with_commas(const vector<string> values) {
  stringstream ss;
  for (index_t i = 0; i < values.size(); ++i) {
    if (i > 0) {
      ss << ",";
    }
    ss << values[i];
  }
  return ss.str();
}

void create_todo_table(PotatoDB& db, const index_t size) {
  const vector<string> columns = {
    "id INTEGER PRIMARY KEY AUTOINCREMENT",
    "name VARCHAR(32)",
    "done BOOLEAN",
    "created_at TIMESTAMP",
    "updated_at TIMESTAMP"
  };

  db.run_statement("CREATE TABLE todos (" +
                   join_with_commas(columns) + ")");


  for (index_t i = 0; i < size; ++i) {
    const vector<string> values = {
      "'Task #" + std::to_string(i) + "'",
      "false",
      "NOW()",
      "NOW()"
    };

    db.run_statement("INSERT INTO todos ( name, done, created_at, updated_at ) VALUES (" +
                     join_with_commas(values) + ")");
  }
}

TEST(PotatoDBTest, CountStarTest) {
  PotatoDB db;
  db.reset_installation();
  const int size = 10;
  create_todo_table(db, size);

  auto result = db.run_statement("SELECT COUNT(*) FROM todos");
  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);
  EXPECT_EQ(result.set()->value_at<int32_t>("COUNT(*)", 0), size);
}

TEST(PotatoDBTest, SortingTest) {
  PotatoDB db;
  db.reset_installation();
  const int size = 10;
  create_todo_table(db, size);

  auto asc_result = db.run_statement("SELECT * FROM todos ORDER BY id ASC");
  EXPECT_TRUE(asc_result.set() != nullptr);
  EXPECT_EQ(asc_result.set()->size(), 10);
  for (index_t i = 0; i < size; ++i) {
    auto name = asc_result.set()->value_at<string>("name", i);
    EXPECT_EQ(name, "Task #" + std::to_string(i));
  }

  auto desc_result = db.run_statement("SELECT * FROM todos ORDER BY id DESC");
  EXPECT_TRUE(desc_result.set() != nullptr);
  EXPECT_EQ(desc_result.set()->size(), 10);
  for (index_t i = 0; i < size; ++i) {
    auto name = desc_result.set()->value_at<string>("name", i);
    EXPECT_EQ(name, "Task #" + std::to_string(size - 1 - i));
  }
}

TEST(PotatoDBTest, UpdateWhereTest) {
  PotatoDB db;
  db.reset_installation();
  const int size = 10;
  create_todo_table(db, size);

  db.run_statement("UPDATE todos SET done = true WHERE id = 3");

  auto result = db.run_statement("SELECT * FROM todos");
  EXPECT_TRUE(result.set() != nullptr);

  EXPECT_EQ(result.set()->size(), size);
  for (index_t i = 0; i < size; ++i) {
    auto id   = result.set()->value_at<int32_t>("id", i);
    auto done = result.set()->value_at<bool>("done", i);
    if (id == 3) {
      EXPECT_EQ(done, true);
    } else {
      EXPECT_EQ(done, false);
    }
  }
}

TEST(PotatoDBTest, DeleteWhereTest) {
  PotatoDB db;
  db.reset_installation();
  const int size = 10;
  create_todo_table(db, size);

  db.run_statement("DELETE FROM todos WHERE id = 3");

  auto result = db.run_statement("SELECT * FROM todos");
  EXPECT_TRUE(result.set() != nullptr);

  EXPECT_EQ(result.set()->size(), size-1);
  int expected_id = 1;
  for (index_t i = 0; i < size-1; ++i) {
    if (expected_id == 3) {
      ++expected_id;
    }

    auto id = result.set()->value_at<int32_t>("id", i);
    EXPECT_EQ(id, expected_id);
    ++expected_id;
  }
}

TEST(PotatoDBTest, SystemCatalogTest) {
  PotatoDB db;
  db.reset_installation();

  auto result = db.run_statement("SELECT * FROM system_catalog");
  EXPECT_TRUE(result.set()->size() > 0);
}

TEST(PotatoDBTest, CreateTableTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto foo_bar_file_path = db.table_file_for("foo_bar");

  EXPECT_TRUE(db.file_exists(foo_bar_file_path));

  auto result = db.run_statement("SELECT * FROM system_catalog WHERE name == 'foo_bar'");
  auto &result_set = *result.set().get();

  EXPECT_EQ(result_set.size(), 1);
  EXPECT_EQ(result_set.value_at<string>("table_name", 0), "foo_bar");
}

TEST(PotatoDBTest, CreateTableTwiceTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto result = db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  EXPECT_TRUE(result.set() == nullptr);
  EXPECT_EQ(result.to_payload(), "Full-blown ERROR!"); // NOTE SHOULD FAIL
}

TEST(PotatoDBTest, CreateTableIfNotExistsTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto result = db.run_statement("CREATE TABLE IF NOT EXISTS foo_bar ( colA INTEGER, colB INTEGER )");

  EXPECT_TRUE(result.set() == nullptr);
  // NOTE SHOULD NOT FAIL,
  // WARNING INSTEAD
  EXPECT_EQ(result.to_payload(), "Just a WARNING");
}

TEST(PotatoDBTest, ShowTablesTest) {
  PotatoDB db;
  db.reset_installation();

  auto result = db.run_statement("SHOW TABLES");
  auto &result_set = *result.set().get();

  EXPECT_EQ(result_set.size(), 1);
  EXPECT_EQ(result_set.value_at<string>("table_name", 0), "system_catalog");
}

TEST(PotatoDBTest, ShowTablesFooBarTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto result = db.run_statement("SHOW TABLES");
  auto &result_set = *result.set().get();

  EXPECT_EQ(result_set.size(), 2);
  EXPECT_EQ(result_set.value_at<string>("table_name", 0), "system_catalog");
  EXPECT_EQ(result_set.value_at<string>("table_name", 1), "foo_bar");
}

TEST(PotatoDBTest, DescribeTableTest) {
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");
  auto result = db.run_statement("DESCRIBE TABLE foo_bar");

  auto &result_set = *result.set().get();

  EXPECT_EQ(result_set.size(), 2);
  EXPECT_EQ(result_set.value_at<string>("name", 0), "colA");
  EXPECT_EQ(result_set.value_at<string>("name", 1), "colB");
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
  PotatoDB db;
  db.reset_installation();

  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");
  db.run_statement("INSERT INTO foo_bar VALUES (1, 2)");
  db.run_statement("TRUNCATE TABLE foo_bar");

  auto result = db.run_statement("SELECT * FROM foo_bar");
  auto &result_set = result.set();

  EXPECT_EQ(result_set->size(), 0);
}

TEST(PotatoDBTest, AlterTableDropColumnTest) {
  // TODO!
}

TEST(PotatoDBTest, AlterTableAddColumnTest) {
  // TODO!
}
