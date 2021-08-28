#pragma once

#include <algorithm>
#include <cstdio>

#include "index/index_comp.hpp"
#include "server/potatodb.hpp"

// External includes
#include "gtest/gtest.h"

class BTreeInsert : public ::testing::Test {
public:
  BTreeInsert() {}

  void SetUp() override {
    ::testing::Test::SetUp();
    db.rebuild_system_catalog();
  }

  void TearDown() override {
    ::testing::Test::TearDown();
  }

  PotatoDB db;
};

// TODO: If we're going to do this the *right way*...
// Then we should start from the parser and support all the ways to create
// an index that the syntax allows.

TEST_F(BTreeInsert, InsertTestAscending) {
  db.run("CREATE TABLE test_table ( a BIGINT ) ");
  db.run("CREATE INDEX test_index ON test_table (a)")

  db.run("INSERT INTO test_table (a) VALUES (0), (1), (2), (3), (4), (5)");
  auto result_set = db.query("SELECT * FROM test_table");

  for (int32_t i = 0; i < result_set.size(); ++i) {
    auto int_value = result_set.value_at<int32_t>('a', i);
    EXPECT_EQ(int_value, i);
  }
}

TEST_F(BTreeInsert, InsertTestDescending) {
  db.run("CREATE TABLE test_table ( a BIGINT ) ");
  db.run("CREATE INDEX test_index ON test_table (a)");

  db.run("INSERT INTO test_table (a) VALUES (0), (1), (2), (3), (4), (5)");
  auto result_set = db.query("SELECT * FROM test_table");

  for (int32_t i = 0; i < result_set.size(); ++i) {
    auto int_value = result_set.value_at<int32_t>('a', i);
    EXPECT_EQ(int_value, i);
  }
}
