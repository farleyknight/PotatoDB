#pragma once

#include "recovery/log_mgr.hpp"
#include "recovery/log_record.hpp"
#include "txns/lock_mgr.hpp"
#include "txns/txn_mgr.hpp"
#include "recovery/log_recovery.hpp"

class LogMgrSerialization : public ::testing::Test {
public:
  LogMgrSerialization()
    : log_mgr     (disk_mgr),
      txn_mgr     (lock_mgr, log_mgr, schema_mgr),
      buff_mgr    (10, disk_mgr, log_mgr),
      schema_mgr  (disk_mgr, lock_mgr, log_mgr, buff_mgr)
  {}

  void SetUp() override {
    ::testing::Test::SetUp();
    disk_mgr.truncate_log_file();
  }

  void TearDown() override {
    ::testing::Test::TearDown();
    disk_mgr.delete_log_file();
  }

  DiskMgr disk_mgr;
  LockMgr lock_mgr;
  LogMgr log_mgr;
  TxnMgr txn_mgr;
  BuffMgr buff_mgr;
  SchemaMgr schema_mgr;
};

// NOTE: We should NOT need a schema anywhere in these tests!
// We can easily use a Tuple with a fixed Buffer

TEST_F(LogMgrSerialization, InsertTupleTest) {

  // 1) Create new LogRecord
  auto buffer   = Buffer();
  auto txn_id   = 1;
  auto prev_lsn = 2;

  auto rid   = RID(0);
  auto tuple = Tuple(buffer);

  auto original = LogRecord(txn_id,
                            prev_lsn,
                            LogRecordType::INSERT,
                            rid,
                            tuple);

  // 2) Write it to disk

  log_mgr.append(original);
  log_mgr.flush_log_buffer();

  // 3) Read it back

  LogRecord copy;

  auto &txn = txn_mgr.begin();
  LogRecovery recovery(disk_mgr, buff_mgr, log_mgr, lock_mgr, txn);
  auto log_cursor = recovery.log_cursor();
  log_cursor.deserialize_log_record(copy);

  // 4) Make sure it is identical

  assert(original.txn_id() == copy.txn_id());
  EXPECT_EQ(original.txn_id(),       copy.txn_id());
  EXPECT_EQ(original.prev_lsn(),     copy.prev_lsn());
  EXPECT_EQ(original.record_type(),  copy.record_type());
  EXPECT_EQ(original.insert_rid(),   copy.insert_rid());

  EXPECT_TRUE(original.insert_tuple().eq(copy.insert_tuple()));
}

TEST_F(LogMgrSerialization, ApplyDeleteTupleTest) {
  // TODO!
}

TEST_F(LogMgrSerialization, MarkDeleteTupleTest) {
  // TODO!
}

TEST_F(LogMgrSerialization, RollbackDeleteTupleTest) {
  // TODO!
}

