#pragma once

// TODO: The executor engine and the parser should be tested together
// We should be able to run the PotatoDB instance, have it parse the
// queries, and then see the results of it.
//
// Basically it's an end-to-end test that is one step away from allowing
// the server to run and perform a query.

#include "server/potatodb.hpp"

#include "gtest/gtest.h"

TEST(PotatoDBTest, CreateTableTest) {
  // TODO: Test that the table file was created
}

TEST(PotatoDBTest, CreateInsertSelectTest) {
  PotatoDB db;
  db.run_statement("CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )");
  db.run_statement("INSERT INTO foo_bar VALUES (1, 1)");
  auto result = db.run_statement("SELECT * FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);
}

