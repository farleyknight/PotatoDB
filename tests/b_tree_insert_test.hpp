#pragma once

#include <algorithm>
#include <cstdio>

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

TEST(BTreeInsert, InsertTestAscending) {
  db.run("CREATE TABLE test_table ( a BIGINT ) ");
  auto key_schema = db.catalog().query_schema_for("test_table");

  GenericComp comparator(key_schema);

  // TODO:
  // * Let's store metadata about the tree in the first block (block_id = 0)
  // * The remaining blocks can be used by the B-Tree however it wants to.
  // * The index name is the first arg here. Instead we should be passing it to
  //   the file_mgr_.
  // * Then the file_mgr_ can create the index file. Our file extension should be .idx
  // * Instead of passing the index name, we pass in the first page of the "B-Tree content"
  //   which should be PageId first_page_id = (file_id, 1)

  file_id_t file_id = file_mgr_.create_index_file("test_index");

  BTree<GenericKey, RID, GenericComp> tree(file_id,
                                           bpm,
                                           comparator);

  GenericKey index_key;
  RID rid;

  auto &txn = db.txn_mgr().begin();

  vector<int64_t> keys = {1, 2, 3, 4, 5};
  for (auto key : keys) {
    int64_t value = key & 0xFFFFFFFF;
    rid.set(static_cast<int32_t>(key >> 32), value);
    index_key.set_from_integer(key);
    tree.insert(index_key, rid, txn);
  }

  vector<RID> rids;
  for (auto key : keys) {
    rids.clear();
    index_key.set_from_integer(key);
    tree.value(index_key, &rids);
    EXPECT_EQ(rids.size(), 1);

    int64_t value = key & 0xFFFFFFFF;
    EXPECT_EQ(rids[0].slot_num(), value);
  }

  int64_t start_key = 1;
  int64_t current_key = start_key;
  index_key.set_from_integer(start_key);
  for (auto iter = tree.begin(index_key); iter != tree.end(); ++iter) {
    auto location = iter->second;
    EXPECT_EQ(location.page_id(), 0);
    EXPECT_EQ(location.slot_num(), current_key);
    current_key = current_key + 1;
  }

  EXPECT_EQ(current_key, keys.size() + 1);
}

TEST(BTreeInsertTests, InsertTestDescending) {
  // create KeyComparator and index schema
  Schema *key_schema = ParseCreateStatement("a bigint");
  GenericComparator<8> comparator(key_schema);

  DiskManager *disk_manager = new DiskManager("test.db");
  BufferPoolManager *bpm = new BufferPoolManager(50, disk_manager);
  // create b+ tree
  BPlusTree<GenericKey<8>, RID, GenericComparator<8>> tree("foo_pk", bpm, comparator);
  GenericKey<8> index_key;
  RID rid;
  // create transaction
  Transaction *transaction = new Transaction(0);

  // create and fetch header_page
  page_id_t page_id;
  auto header_page = bpm->NewPage(&page_id);
  (void)header_page;

  std::vector<int64_t> keys = {5, 4, 3, 2, 1};
  for (auto key : keys) {
    int64_t value = key & 0xFFFFFFFF;
    rid.Set(static_cast<int32_t>(key >> 32), value);
    index_key.SetFromInteger(key);
    tree.Insert(index_key, rid, transaction);
  }

  std::vector<RID> rids;
  for (auto key : keys) {
    rids.clear();
    index_key.SetFromInteger(key);
    tree.GetValue(index_key, &rids);
    EXPECT_EQ(rids.size(), 1);

    int64_t value = key & 0xFFFFFFFF;
    EXPECT_EQ(rids[0].GetSlotNum(), value);
  }

  int64_t start_key = 1;
  int64_t current_key = start_key;
  index_key.SetFromInteger(start_key);
  for (auto iterator = tree.Begin(index_key); iterator != tree.end(); ++iterator) {
    auto location = (*iterator).second;
    EXPECT_EQ(location.GetPageId(), 0);
    EXPECT_EQ(location.GetSlotNum(), current_key);
    current_key = current_key + 1;
  }

  EXPECT_EQ(current_key, keys.size() + 1);

  start_key = 3;
  current_key = start_key;
  index_key.SetFromInteger(start_key);
  for (auto iterator = tree.Begin(index_key); iterator != tree.end(); ++iterator) {
    auto location = (*iterator).second;
    EXPECT_EQ(location.GetPageId(), 0);
    EXPECT_EQ(location.GetSlotNum(), current_key);
    current_key = current_key + 1;
  }

  db.buff_mgr().unpin(HEADER_PAGE_ID, true);

}
