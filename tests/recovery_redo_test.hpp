#pragma once

#include <string>
#include <vector>

std::tuple<RID, RID> redo_test_part1() {
  PotatoDB db;
  db.rebuild_system_catalog();

  EXPECT_FALSE(db.is_logging_enabled());
  db.run_flush_thread();
  EXPECT_TRUE(db.is_logging_enabled());

  auto &txn = db.txn_mgr().begin();

  db.run("CREATE TABLE test_table ( a VARCHAR(20), b INTEGER ) ");

  auto test_schema      = db.schema_mgr().query_schema_for("test_table");
  auto test_table_oid   = db.schema_mgr().table_oid_for("test_table");
  auto &test_table_heap = db.schema_mgr().table_heap_for(test_table_oid);

  auto value_A_1 = Value::make("x");
  auto value_B_1 = Value::make(2);

  auto value_A_2 = Value::make("y");
  auto value_B_2 = Value::make(3);

  auto tuple1 = Tuple({value_A_1, value_B_1}, test_schema);
  auto tuple2 = Tuple({value_A_2, value_B_2}, test_schema);

  EXPECT_TRUE(test_table_heap.insert_tuple(tuple1, txn));
  EXPECT_TRUE(test_table_heap.insert_tuple(tuple2, txn));

  db.txn_mgr().commit(txn);

  return std::make_tuple(tuple1.rid(), tuple2.rid());
}

void redo_test_part2(const RID& rid1, const RID& rid2) {
  PotatoDB db;

  db.startup();
  EXPECT_FALSE(db.is_logging_enabled());

  auto &txn = db.txn_mgr().begin();

  // NOTE: The lines below might fail because we are not loading the
  // system catalog on each database start up.
  auto test_schema      = db.catalog().query_schema_for("test_table");
  auto test_table_oid   = db.catalog().table_oid_for("test_table");
  auto &test_table_heap = db.catalog().table_heap_for(test_table_oid);

  auto null_tuple1 = test_table_heap.find_tuple(rid1, txn);
  auto null_tuple2 = test_table_heap.find_tuple(rid2, txn);

  ASSERT_TRUE(null_tuple1 == nullptr);
  ASSERT_TRUE(null_tuple2 == nullptr);

  db.txn_mgr().commit(txn);

  auto log_recovery = db.log_recovery();
  EXPECT_FALSE(db.is_logging_enabled());

  log_recovery.redo();
  log_recovery.undo();

  auto &recovery_txn  = db.txn_mgr().begin();
  auto &recovery_heap = db.catalog().table_heap_for(test_table_oid);

  auto tuple1         = recovery_heap.find_tuple(rid1, recovery_txn);
  auto tuple2         = recovery_heap.find_tuple(rid2, recovery_txn);
  ASSERT_TRUE(tuple1 != nullptr);
  ASSERT_TRUE(tuple2 != nullptr);
  db.txn_mgr().commit(recovery_txn);

  EXPECT_EQ(tuple1->value(test_schema, 0).as<string>(), "x");
  EXPECT_EQ(tuple2->value(test_schema, 0).as<string>(), "y");
  EXPECT_EQ(tuple1->value(test_schema, 1).as<int>(), 2);
  EXPECT_EQ(tuple2->value(test_schema, 1).as<int>(), 3);

  db.shutdown();
}

TEST(RecoveryRedoTest, RedoTest) {
  auto [rid1, rid2] = redo_test_part1();
  redo_test_part2(rid1, rid2);
}
