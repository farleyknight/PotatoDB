#pragma once

#include "disk/file_mgr.hpp"

#include "btree/b_tree.hpp"

#include "buffer/buff_mgr.hpp"
#include "catalog/index_schema.hpp"

#include "index/index_key.hpp"
#include "index/index_comp.hpp"

#include "page/index_header_page.hpp"

class IndexMgr {
public:
  using BPlusTree = BTree<IndexKey, RID, IndexComp>;

  IndexMgr(FileMgr& file_mgr,
           LockMgr& lock_mgr,
           LogMgr& log_mgr,
           BuffMgr& buff_mgr)
    : file_mgr_ (file_mgr),
      lock_mgr_ (lock_mgr),
      log_mgr_  (log_mgr),
      buff_mgr_ (buff_mgr)
  {}

  IndexSchema read_index_schema(Catalog& catalog, file_id_t file_id) {
    auto page_id           = file_mgr_.index_header_page(file_id);
    auto page_ptr          = buff_mgr_.fetch_page(page_id);
    assert(page_ptr);
    auto index_header_page = IndexHeaderPage(page_ptr);

    return index_header_page.read_schema(catalog);
  }

  void create_index_file(const index_name_t& index_name,
                         const IndexSchema index_schema,
                         index_oid_t index_oid)
  {
    file_id_t file_id = file_mgr_.create_index_file(index_name);
    allocate_header_and_first_page(file_id);

    auto comp = IndexComp(index_schema);

    auto btree = make_unique<BPlusTree>(index_name,
                                        file_id,
                                        FileMgr::index_header_page(file_id),
                                        comp,
                                        buff_mgr_);

    btree_indexes_.emplace(index_oid, move(btree));
  }

  BPlusTree& btree_index_for(index_oid_t index_oid) {
    assert(btree_indexes_.contains(index_oid));
    return *btree_indexes_.at(index_oid);
  }

  index_oid_t index_oid_for(file_id_t file_id) {
    assert(index_oids_.contains(file_id));
    return index_oids_[file_id];
  }

private:
  void allocate_header_and_first_page(file_id_t file_id) {
    auto header_page_id = FileMgr::index_header_page(file_id);
    // NOTE: By default, root page ID is the first page ID
    auto root_page_id   = FileMgr::first_index_page(file_id);

    // TODO: We should allocate the block with the following info:
    // * file_id of this file
    // * file_name to associate with the file_id
    //   - This gives us an opportunity to be sure it didn't get moved or renamed
    //   - The mapping of file_id to file_name is created by iterating over all files and mapping
    //     these two things together.
    // * root_page_id should be stored
    //    - An initially be set to (file_id, 1)
    //    - NOT static, it can change.
    //      - Why? BC deleting enough pages forces us to move the root page ID
    // * index_name should be stored in the header page
    // * index_schema (as IndexSchema) should be stored
    //    - Will probably need it's own custom serialize/deserialize
    auto header_page_ptr = buff_mgr_.fetch_page(root_page_id);
    assert(header_page_ptr != nullptr);
    auto header_page = IndexHeaderPage(header_page_ptr);
    header_page.wlatch();
    header_page.allocate(header_page_id, root_page_id);
    header_page.wunlatch();

    auto root_page_ptr = buff_mgr_.fetch_page(root_page_id);
    assert(root_page_ptr != nullptr);
    auto root_page = BTreeInternalPage<IndexKey, RID, IndexComp>(root_page_ptr);
    // must call initialize method after "create" a new node
    header_page.wlatch();
    root_page.allocate(root_page_id, PageId::STOP_ITERATING(file_id));
    header_page.wunlatch();

    void allocate(PageId page_id,
                  PageId parent_id = PageId::INVALID());

    buff_mgr_.unpin(root_page_id, true);
  }

  FileMgr& file_mgr_;
  UNUSED LockMgr& lock_mgr_;
  UNUSED LogMgr& log_mgr_;
  BuffMgr& buff_mgr_;

  map<file_id_t, index_oid_t> index_oids_;

  map<index_oid_t, const index_name_t> index_names_;
  map<index_oid_t, ptr<BPlusTree>> btree_indexes_;
};
