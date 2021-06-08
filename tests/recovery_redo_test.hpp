#pragma once

#include <string>
#include <vector>

// Inserts two tuples:
// ("x", 2)
// ("y", 3)
std::tuple<RID, RID> redo_test_part1() {
  PotatoDB db;
  db.reset_installation();

  ASSERT_FALSE(db.is_logging_enabled());
  std::cout << "Skip system recovering..." << std::endl;

  db.run_flush_thread();
  ASSERT_TRUE(db.is_logging_enabled());
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

  auto tuple1 = Tuple({value_A_1, value_B_1}, schema);
  auto tuple2 = Tuple({value_A_2, value_B_2}, schema);

  ASSERT_TRUE(test_table_heap->insert_tuple(tuple1, txn));
  ASSERT_TRUE(test_table_heap->insert_tuple(tuple2, txn));

  db.txn_mgr().commit(txn);

  std::cout << "Txn committed" << std::endl;

  db.shutdown();
  std::cout << "System shutdown" << std::endl;

  return std::make_tuple(tuple1.rid1(), tuple2.rid2());
}

void redo_test_part2(const RID& rid1, const RID& rid2) {
  PotatoDB db;

  std::cout << "Restarting system" << std::endl;
  db.startup();
  ASSERT_FALSE(db.is_logging_enabled());

  auto txn = db.txn_mgr().begin();

  // NOTE: The lines below might fail because we are not loading the
  // system catalog on each database start up.
  auto test_schema     = db.catalog().query_schema_for("test_table");
  auto test_table_oid  = db.catalog().table_oid_for("test_table");
  auto test_table_heap = db.table_mgr().table_heap_for("test_table");

  auto null_tuple1 = test_table_heap->find_tuple(rid1, txn);
  auto null_tuple2 = test_table_heap->find_tuple(rid2, txn);

  ASSERT_TRUE(null_tuple1 == nullptr);
  ASSERT_TRUE(null_tuple2 == nullptr);

  db.txn_mgr().commit(txn);

  std::cout << "Begin recovery" << std::endl;

  auto log_recovery = db.log_recovery();
  ASSERT_FALSE(db.logging_enabled());

  std::cout << "Redo underway" << std::endl;
  log_recovery->redo();
  std::cout << "Undo underway" << std::endl;
  log_recovery->undo();

  std::cout << "Check if recovery success" << std::endl;

  auto recovery_txn  = db.txn_mgr().begin();
  auto recovery_heap = db.table_mgr().table_heap_for("test_table");
  auto tuple1        = recovery_heap.find_tuple(rid1, recovery_txn);
  auto tuple2        = recovery_heap.find_tuple(rid2, recovery_txn);
  ASSERT_TRUE(tuple1 != nullptr);
  ASSERT_TRUE(tuple2 != nullptr);
  db.txn_mgr().commit(recovery_txn);

  ASSERT_EQ(tuple1.value(test_schema, 0).as<string>(), "x");
  ASSERT_EQ(tuple2.value(test_schema, 0).as<string>(), "y");
  ASSERT_EQ(tuple1.value(test_schema, 1).as<int>(), 2);
  ASSERT_EQ(tuple2.value(test_schema, 1).as<int>(), 3);
}

TEST(RecoveryRedoTest, RedoTest) {
  auto [rid1, rid2] = redo_test_part1();
  redo_test_part2(rid1, rid2);
}
