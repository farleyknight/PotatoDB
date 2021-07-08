#pragma once

#include "plans/plan_factory.hpp"

// External includes
#include "gtest/gtest.h"

class PlanTest : ::testing::TestCase {
public:
  PlanTest() {}

  const string create_table_foobar_statement =
    "CREATE TABLE foobar "                      \
    "("                                         \
    "id INTEGER PRIMARY KEY,"                   \
    "name VARCHAR(10) NOT NULL"                 \
    ")";

  void SetUp() override {
    ::testing::Test::SetUp();
    create_foobar();
  }

  void create_foobar() {
    db.execute(statement);
  }

  void TearDown() override {
    ::testing::Test::TearDown();
  }

  PotatoDB db;
}

TEST_F(PlanTest, SelectStarGivesAllColumnsTest) {
  auto foobar_query_schema =
    db.catalog().query_schema_for("foobar");

  const string select_statement = "SELECT * FROM foobar";

  auto exprs = SQLParser::as_exprs(select_statement);
  auto plan  = PlanFactory::create(db.catalog(), expr[0]);

  EXPECT_EQ(plan.plan_type(), PlanType::TABLE_SCAN);
  EXPECT_EQ(plan.schema(), foobar_query_schema);
  EXPECT_EQ(plan.pred(), nullptr);
}

TEST_F(PlanTest, SelectTableNameStarGivesTableColumnsTest) {
  auto foobar_query_schema =
    db.catalog().query_schema_for("foobar");

  const string select_statement
    = "SELECT foobar.* FROM foobar";

  auto exprs = SQLParser::as_exprs(select_statement);
  auto plan  = PlanFactory::create(db.catalog(), expr[0]);

  EXPECT_EQ(plan.plan_type(), PlanType::TABLE_SCAN);
  EXPECT_EQ(plan.schema(), foobar_query_schema);
  EXPECT_EQ(plan.pred(), nullptr);
}

TEST_F(PlanTest, SelectColumnNamesQuerySchemaTest) {
  auto column_names = vector<string>({"id"});
  auto foobar_query_schema =
    db.catalog().query_schema_for("foobar", column_names);

  const string select_statement
    = "SELECT foobar.id FROM foobar";

  auto exprs = SQLParser::as_exprs(select_statement);
  auto plan  = PlanFactory::create(db.catalog(), expr[0]);

  EXPECT_EQ(plan.plan_type(), PlanType::TABLE_SCAN);
  EXPECT_EQ(plan.schema(), foobar_query_schema);
  EXPECT_EQ(plan.pred(), nullptr);
}
