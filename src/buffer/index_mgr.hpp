#pragma once

#include "disk/file_mgr.hpp"

#include "buffer/buff_mgr.hpp"

#include "page/index_header_page.hpp"
#include "catalog/index_schema.hpp"

class IndexMgr {
public:
  // TODO: Rename GenericKey to IndexKey
  // TODO: Rename GenericComp to IndexComp
  using BPlusTree = BTree<GenericKey, RID, GenericComp>;

  IndexMgr(FileMgr& file_mgr,
           LockMgr& lock_mgr,
           LogMgr& log_mgr,
           BuffMgr& buff_mgr)
    : file_mgr_ (file_mgr),
      lock_mgr_ (lock_mgr),
      log_mgr_  (log_mgr),
      buff_mgr_ (buff_mgr)
  {}

  void create_index(const index_name_t& index_name,
                    index_oid_t index_oid,
                    Txn& txn)
  {
    file_id_t file_id = file_mgr_.create_index_file(index_name);
    allocate_header_and_first_page(file_id, txn);

    // TODO: index_schema should be passed as a parameter
    auto comp = GenericComp(index_schema);

    auto tree = make_unique<BPlusTree>(index_name,
                                       file_id,
                                       buff_mgr_,
                                       comp);

    btree_indexes_.insert(make_pair(index_oid, move(btree)));
  }

  BPlusTree& btree_index_for(index_oid_t index_oid) {
    assert(btree_indexes_.count(index_oid) == 1);
    return *btree_indexes_.at(index_oid);
  }

private:
  FileMgr& file_mgr_;
  LockMgr& lock_mgr_;
  LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;

  map<index_oid_t, const index_name_t> index_names_;
  map<index_oid_t, ptr<BTree>> btree_indexes_;
};
