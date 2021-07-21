#pragma once

#include <string>
#include <vector>

// External includes
#include "gtest/gtest.h"

// Inserts two tuples:
// ("x", 2)
// ("y", 3)
std::tuple<RID, RID> redo_test_part1() {
  std::cout << "Turning debug logging OFF" << std::endl;
  logger->set_level(spdlog::level::off);

  PotatoDB db;
  db.rebuild_system_catalog();

  EXPECT_FALSE(db.is_logging_enabled());
  std::cout << "Skip system recovering..." << std::endl;

  db.run_flush_thread();
  EXPECT_TRUE(db.is_logging_enabled());
  std::cout << "System logging thread running..." << std::endl;

  std::cout << "Turning debug logging ON" << std::endl;
  logger->set_level(spdlog::level::debug);

  auto &txn = db.txn_mgr().begin();

  std::cout << "Create a test table" << std::endl;
  db.run("CREATE TABLE test_table ( a VARCHAR(20), b SMALLINT ) ");

  auto test_schema      = db.catalog().query_schema_for("test_table");
  auto test_table_oid   = db.catalog().table_oid_for("test_table");
  auto &test_table_heap = db.table_mgr().table_heap_for(test_table_oid);

  auto value_A_1 = Value::make("x");
  auto value_B_1 = Value::make(2);

  auto value_A_2 = Value::make("y");
  auto value_B_2 = Value::make(3);

  auto tuple1 = Tuple({value_A_1, value_B_1}, test_schema);
  auto tuple2 = Tuple({value_A_2, value_B_2}, test_schema);

  logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  logger->debug("INSERT INTO test_table VALUES ('x', 1)");
  logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

  EXPECT_TRUE(test_table_heap.insert_tuple(tuple1, txn));

  logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  logger->debug("INSERT INTO test_table VALUES ('y', 2)");
  logger->debug("[PotatoDB] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

  EXPECT_TRUE(test_table_heap.insert_tuple(tuple2, txn));

  db.txn_mgr().commit(txn);

  std::cout << "Txn committed" << std::endl;
  std::cout << "But we DO NOT SHUTDOWN because that writes all the pages to disk" << std::endl;

  std::cout << "Tuple1 RID: " << tuple1.rid().to_string() << std::endl;
  std::cout << "Tuple2 RID: " << tuple2.rid().to_string() << std::endl;

  return std::make_tuple(tuple1.rid(), tuple2.rid());
}

void redo_test_part2(const RID& rid1, const RID& rid2) {
  PotatoDB db;

  std::cout << "Restarting system" << std::endl;
  db.startup();
  EXPECT_FALSE(db.is_logging_enabled());

  auto &txn = db.txn_mgr().begin();

  // NOTE: The lines below might fail because we are not loading the
  // system catalog on each database start up.
  auto test_schema      = db.catalog().query_schema_for("test_table");
  auto test_table_oid   = db.catalog().table_oid_for("test_table");
  auto &test_table_heap = db.table_mgr().table_heap_for(test_table_oid);

  auto null_tuple1 = test_table_heap.find_tuple(rid1, txn);
  auto null_tuple2 = test_table_heap.find_tuple(rid2, txn);

  ASSERT_TRUE(null_tuple1 == nullptr);
  ASSERT_TRUE(null_tuple2 == nullptr);

  db.txn_mgr().commit(txn);

  std::cout << "Begin recovery" << std::endl;

  auto log_recovery = db.log_recovery();
  EXPECT_FALSE(db.is_logging_enabled());

  std::cout << "Redo underway" << std::endl;
  log_recovery.redo();
  std::cout << "Undo underway" << std::endl;
  log_recovery.undo();

  std::cout << "Check if recovery success" << std::endl;

  auto &recovery_txn  = db.txn_mgr().begin();
  auto &recovery_heap = db.table_mgr().table_heap_for(test_table_oid);

  std::cout << "recovery_heap: file_id: " << recovery_heap.file_id() << std::endl;
  std::cout << "recovery_heap: first_page tuple_count: " <<
    recovery_heap.first_page(recovery_txn).tuple_count() << std::endl;

  auto tuple1         = recovery_heap.find_tuple(rid1, recovery_txn);
  auto tuple2         = recovery_heap.find_tuple(rid2, recovery_txn);
  ASSERT_TRUE(tuple1 != nullptr);
  ASSERT_TRUE(tuple2 != nullptr);
  db.txn_mgr().commit(recovery_txn);

  EXPECT_EQ(tuple1->value(test_schema, 0).as<string>(), "x");
  EXPECT_EQ(tuple2->value(test_schema, 0).as<string>(), "y");
  EXPECT_EQ(tuple1->value(test_schema, 1).as<int>(), 2);
  EXPECT_EQ(tuple2->value(test_schema, 1).as<int>(), 3);
}

TEST(RecoveryRedoTest, RedoTest) {
  auto [rid1, rid2] = redo_test_part1();
  redo_test_part2(rid1, rid2);
}
