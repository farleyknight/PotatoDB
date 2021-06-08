#pragma once

#include <string>
#include <vector>

std::tuple<RID, RID> undo_test_part1() {
  PotatoDB db;
  db.reset_installation();

  ASSERT_FALSE(db.logging_enabled());
  std::cout << "Skip system recovering..." << std::endl;

  db.run_flush_thread();
  ASSERT_TRUE(db.logging_enabled());
  std::cout << "System logging thread running..." << std::endl;

  auto txn = db.txn_mgr().begin();

  std::cout << "Create a test table" << std::endl;
  db.run_command("CREATE TABLE test_table ( a VARCHAR(20), b SMALLINT ) ");

  auto test_schema     = db.catalog().query_schema_for("test_table");
  auto test_table_oid  = db.catalog().table_oid_for("test_table");
  auto test_table_heap = db.table_mgr().table_heap_for("test_table");

  auto value_A_1 = Value::make("x");
  auto value_B_1 = Value::make(2);

  auto value_A_2 = Value::make("y");
  auto value_B_2 = Value::make(3);

  auto tuple1 = Tuple({value_A_1, value_B_1}, test_schema);
  auto tuple2 = Tuple({value_A_2, value_B_2}, test_schema);

  ASSERT_TRUE(test_table_heap->insert_tuple(tuple1, txn));
  ASSERT_TRUE(test_table_heap->insert_tuple(tuple2, txn));

  std::cout << "System crash before commit" << std::endl;

  return std::make_tuple(tuple1.rid(), tuple2.rid());
}

void undo_test_part2(const RID& rid1, const RID& rid2) {
  PotatoDB db;

  std::cout << "Restarting system" << std::endl;
  db.startup();
  ASSERT_FALSE(db.logging_enabled());

  std::cout << "Recovery started" << std::endl;
  auto log_recovery = db.log_recovery();
  ASSERT_FALSE(db.logging_enabled());

  std::cout << "Redo underway" << std::endl;
  log_recovery->redo();
  std::cout << "Undo underway" << std::endl;
  log_recovery->undo();

  std::cout << "Check if failed txn is undone successfully" << std::endl;

  auto txn             = db.txn_mgr().begin();
  auto test_table_heap = db.table_mgr().table_heap_for("test_table");
  auto tuple1          = test_table_heap.find_tuple(rid1, txn);
  auto tuple2          = test_table_heap.find_tuple(rid2, txn);
  ASSERT_TRUE(tuple1 == nullptr);
  ASSERT_TRUE(tuple2 == nullptr);

  db.txn_mgr().commit(txn);
}

TEST(RecoveryUndoTest, UndoTest) {
  auto [rid1, rid2] = undo_test_part1();
  undo_test_part2(rid1, rid2);
}
