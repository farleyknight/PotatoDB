#pragma once

class FooBarTableTest : public ::testing::Test {
public:
  PotatoDB db;

  void SetUp() override {
    ::testing::Test::SetUp();
    db.reset_installation();
    db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");
  }

  void TearDown() override {
    ::testing::Test::TearDown();
  }
};

TEST_F(FooBarTableTest, CreateTableTest) {
  EXPECT_TRUE(db.table_oid_for("foo_bar"));

  auto result = db.run("SHOW TABLES");
  auto &result_set = result.set();

  EXPECT_EQ(result_set->size(), 1);
  EXPECT_EQ(result_set->value_at<string>("table_name", 0), "foo_bar");
}

TEST_F(FooBarTableTest, CreateInsertSelectTest) {
  db.run("INSERT INTO foo_bar VALUES (1, 2)");

  auto result = db.run("SELECT * FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);

  EXPECT_EQ(result.set()->value_at<int32_t>("colA", 0), 1);
  EXPECT_EQ(result.set()->value_at<int32_t>("colB", 0), 2);
}

TEST_F(FooBarTableTest, SelectEmptyTableTest) {
  auto result = db.run("SELECT * FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 0);

  EXPECT_EQ(result.to_payload(), "No entries to send");
}


TEST_F(FooBarTableTest, CreateTableTwiceTest) {
  auto result =
    db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  EXPECT_TRUE(result.set() == nullptr);
  EXPECT_EQ(result.to_payload(), "Full-blown ERROR!");
}

TEST_F(FooBarTableTest, CreateTableIfNotExistsTest) {
  auto result =
    db.run("CREATE TABLE IF NOT EXISTS foo_bar ( colA INTEGER, colB INTEGER )");

  EXPECT_TRUE(result.set() == nullptr);
  // NOTE SHOULD NOT FAIL,
  // WARNING INSTEAD
  EXPECT_EQ(result.to_payload(), "Just a WARNING");
  // TODO: Better messaging here? Likely something for a config file!
  // TODO: Add a place for error messaging in the YAML config file.
}

TEST_F(FooBarTableTest, MissingColumnTest) {
  db.run("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");

  auto result = db.run("SELECT colC FROM foo_bar");

  EXPECT_TRUE(result.set() == nullptr);
  auto expected_message =
    "Could not find column 'colC' on table 'foo_bar'";
  EXPECT_EQ(result.to_payload(), expected_message);
}


TEST_F(FooBarTableTest, ShowTablesFooBarTest) {
  auto result = db.run("SHOW TABLES");
  auto &result_set = result.set();

  ASSERT_EQ(result_set->size(), 1);
  EXPECT_EQ(result_set->value_at<string>("table_name", 0), "foo_bar");
}

TEST_F(FooBarTableTest, DescribeTableTest) {
  auto result = db.run("DESCRIBE TABLE foo_bar");
  auto &result_set = result.set();
  assert(result_set != nullptr);

  ASSERT_EQ(result_set->size(), 2);
  EXPECT_EQ(result_set->value_at<string>("field_name", 0), "colA");
  EXPECT_EQ(result_set->value_at<string>("field_name", 1), "colB");

  // TODO: Add expectations for `type`, `nullable`, `key`,
  // `default`, and `extra`
}

TEST_F(FooBarTableTest, LoadSystemCatalogAfterRestartTest) {
  // NOTE: We must shutdown first to flush all the pages to disk.
  db.shutdown();

  // NOTE: Use 2nd instance to simulate starting a new DB
  PotatoDB db2;
  // NOTE: startup() should NOT start the server!
  // Otherwise it will block all other tests!
  std::cout << "Restarting DB" << std::endl;
  db2.startup();

  auto result = db2.run("DESCRIBE TABLE foo_bar");
  auto &result_set = result.set();

  ASSERT_EQ(result_set->size(), 2);

  EXPECT_EQ(result_set->value_at<string>("field_name", 0), "colA");
  EXPECT_EQ(result_set->value_at<string>("field_name", 1), "colB");
}

TEST_F(FooBarTableTest, DISABLED_DropTableTest) {
  db.run("DROP TABLE foo_bar");

  auto result = db.run("SHOW TABLES");
  auto &result_set = result.set();

  EXPECT_EQ(result_set->size(), 0);
}

TEST_F(FooBarTableTest, DISABLED_TruncateTableTest) {
  db.run("INSERT INTO foo_bar VALUES (1, 2)");
  db.run("TRUNCATE TABLE foo_bar");

  auto result = db.run("SELECT * FROM foo_bar");
  auto &result_set = result.set();

  EXPECT_EQ(result_set->size(), 0);
}

// NOLINTNEXTLINE
TEST_F(FooBarTableTest, SimpleSeqScanTest) {
  auto foo_bar_oid = db.table_oid_for("foo_bar");
  assert(foo_bar_oid);
  auto foo_bar_name = db.table_name_for(foo_bar_oid);
  assert(foo_bar_name == "foo_bar");

  vector<vector<Value>> data;
  for (int32_t i = 0; i < 10; ++i) {
    db.run("INSERT INTO foo_bar VALUES (" + std::to_string(i) + ", 3)");
  }

  auto result_set
    = db.run("SELECT colA, colB FROM foo_bar WHERE colA < 500");

  // Verify
  for (const auto &tuple : result_set->results()) {
    ASSERT_TRUE(result_set->value<int>("colA", tuple) < 5);
    ASSERT_TRUE(result_set->value<int>("colB", tuple) < 10);
  }

  ASSERT_EQ(result_set->size(), 5);
}

TEST_F(FooBarTableTest, DISABLED_InconsistentTupleLengthTest) {
  string failure_message
    = "Expected to raise exception about inconsistent tuple lengths";

  try {
    db.run("INSERT INTO foo_bar VALUES (1, 2), (3, 4, 5)");
    FAIL() << failure_message;
  } catch(Exception &ex) {
    string expected_message =
      "Your SQL statement provided tuples with inconsistent sizes.\n" \
      "More specifically, the tuple sizes were {2, 3}.\n"             \
      "Please check your query and try again.\n"                      \
      "Note that 2 elements are required for the table `foo_bar`.";
    ASSERT_EQ(ex.what(), expected_message);
  }
  FAIL() << failure_message;
}

TEST_F(FooBarTableTest, DISABLED_WrongLengthOfTuplesTest) {
  string failure_message = "Expected to raise exception about wrong lengths of tuples.";

  try {
    db.run("INSERT INTO foo_bar VALUES (1, 2, 3, 4, 5, 6)");

    FAIL() << failure_message;
  } catch(Exception &ex) {
    string expected_message =
      "Your SQL statement provided 6 element(s) per tuple.\n"
      "However, 2 elements are required for the table `foo_bar`.";
    ASSERT_EQ(ex.what(), expected_message);
  }
  FAIL() << failure_message;
}

TEST_F(FooBarTableTest, DISABLED_SimpleRawInsertTest) {
  db.run("INSERT INTO foo_bar VALUES (100, 10), (101, 11), (102, 12)");

  auto result = db.run("SELECT * FROM foo_bar");
  auto &result_set = result.set();

  ASSERT_EQ(result_set->size(), 3);

  // First value
  ASSERT_EQ(result_set->value_at<int32_t>("colA", 0), 100);
  ASSERT_EQ(result_set->value_at<int32_t>("colB", 0), 10);

  // Second value
  ASSERT_EQ(result_set->value_at<int32_t>("colA", 1), 101);
  ASSERT_EQ(result_set->value_at<int32_t>("colB", 1), 11);

  // Third value
  ASSERT_EQ(result_set->value_at<int32_t>("colA", 2), 102);
  ASSERT_EQ(result_set->value_at<int32_t>("colB", 2), 12);
}


TEST_F(FooBarTableTest, DISABLED_SimpleRawInsertAndUpdateTest) {
  db.run("INSERT INTO foo_bar VALUES (100, 10)");

  db.run("UPDATE foo_bar SET colA = 50");
  auto result = db.run("SELECT * FROM foo_bar");
  auto &result_set = result.set();

  ASSERT_EQ(result_set->size(), 1);

  EXPECT_EQ(result_set->value_at<int>("colA", 0), 50);
  EXPECT_EQ(result_set->value_at<int>("colB", 0), 10);
}

TEST_F(FooBarTableTest, DISABLED_WrongLengthOfTuplesTest) {
  PotatoDB db;

  string failure_message = "Expected to raise exception about wrong lengths of tuples.";

  db.run("CREATE TABLE table_two_columns ( colA INTEGER, colB INTEGER )");

  try {
    db.run("INSERT INTO table_two_columns VALUES (1, 2, 3, 4, 5, 6)");

    FAIL() << failure_message;
  } catch(Exception &ex) {
    string expected_message =
      "Your SQL statement provided 6 element(s) per tuple.\n"
      "However, 2 elements are required for the table `foo_bar`.";
    ASSERT_EQ(ex.what(), expected_message);
  }
  FAIL() << failure_message;
}

TEST_F(FooBarTableTest, DISABLED_SimpleSelectInsertTest) {
  db.run("CREATE TABLE test_table ( colA INTEGER, colB INTEGER )");

  for (int32_t colA = 0; colA < 1000; ++colA) {
    auto colB = colA % 100;
    db.run("INSERT INTO foo_bar ( " +
           std::to_string(colA) +
           ", " +
           std::to_string(colB) +
           " )");
  }

  db.run("INSERT INTO test_table SELECT colA, colB FROM foo_bar WHERE colA < 500");

  auto full_results
    = db.run("SELECT * FROM test_table");
  auto where_results
    = db.run("SELECT * FROM test_table WHERE colA < 500");

  auto &full_set  = full_results->set();
  auto &where_set = where_results->set();

  ASSERT_EQ(where_set->size(), full_set->size());

  for (int i = 0; i < full_set->size(); ++i) {
    ASSERT_EQ(full_set->value_at<int>("colA", i),
              where_set->value_at<int>("colA", i));

    ASSERT_EQ(full_set->value_at<int>("colB", i),
              where_set->value_at<int>("colB", i));
  }

  ASSERT_EQ(full_set->size(), 500);
}
