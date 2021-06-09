#pragma once

TEST(RecoveryCheckpointTest, DISABLED_CheckpointTest) {
  PotatoDB db;
  db.reset_installation();

  ASSERT_FALSE(db.is_logging_enabled());
  std::cout << "Skip system recovering..." << std::endl;

  db.run_flush_thread();
  ASSERT_TRUE(db.is_logging_enabled());
  std::cout << "System logging thread running..." << std::endl;

  std::cout << "Create a test table" << std::endl;
  db.run_statement("CREATE TABLE test_table ( a VARCHAR(20), b SMALLINT ) ");

  auto test_schema      = db.catalog().query_schema_for("test_table");
  auto test_table_oid   = db.catalog().table_oid_for("test_table");
  auto &test_table_heap = db.table_mgr().table_heap_for(test_table_oid);

  auto value_A = Value::make("x");
  auto value_B = Value::make(2);

  auto tuple = Tuple({value_A, value_B}, test_schema);

  // set log time out very high so that flush doesn't happen before checkpoint is performed
  db.log_mgr().set_log_timeout(std::chrono::seconds(15));

  // insert a ton of tuples
  auto &txn = db.txn_mgr().begin();
  for (int i = 0; i < 1000; ++i) {
    EXPECT_TRUE(test_table_heap.insert_tuple(tuple, txn));
  }
  db.txn_mgr().commit(txn);

  // Do checkpoint
  db.checkpoint_mgr().begin();
  db.checkpoint_mgr().end();

  auto &pages = db.buff_mgr().pages();
  auto pool_size = db.buff_mgr().pool_size();

  // Check that all pages in the buffer pool are marked as non-dirty
  bool all_pages_clean = true;
  for (size_t i = 0; i < pool_size; ++i) {
    auto &page = pages[i];
    auto page_id = page.page_id();

    if (page_id.is_valid() && page.is_dirty()) {
      all_pages_clean = false;
      break;
    }
  }
  EXPECT_TRUE(all_pages_clean);

  // compare each page in the buffer pool to that page's
  // data on disk. ensure they match after the checkpoint
  bool all_pages_match = true;
  auto buffer = Buffer();
  for (size_t i = 0; i < pool_size; i++) {
    auto &page = pages[i];
    auto page_id = page.page_id();

    if (page_id.is_valid()) {
      db.file_mgr().read_buffer(page_id, buffer);

      if (std::memcmp(buffer.ptr(), page.buffer().cptr(), buffer.size()) != 0) {
        all_pages_match = false;
        break;
      }
    }
  }

  EXPECT_TRUE(all_pages_match);

  // Verify all committed transactions flushed to disk
  auto persisted_lsn = db.log_mgr().persisted_lsn();
  auto next_lsn = db.log_mgr().next_lsn();
  EXPECT_EQ(persisted_lsn, (next_lsn - 1));

  // verify log was flushed and each page's LSN <= persistent lsn
  bool all_pages_lte = true;
  for (size_t i = 0; i < pool_size; ++i) {
    auto &page = pages[i];
    auto page_id = page.page_id();

    if (page_id.is_valid() && page.read_lsn() > persisted_lsn) {
      all_pages_lte = false;
      break;
    }
  }

  EXPECT_TRUE(all_pages_lte);

  std::cout << "Shutdown system" << std::endl;
}
