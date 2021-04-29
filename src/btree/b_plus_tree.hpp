#pragma once

#include <queue>
#include <string>
#include <vector>

#include "common/config.hpp"

#include "index/index_iterator.hpp"
#include "btree/b_plus_tree_internal_page.hpp"
#include "btree/b_plus_tree_leaf_page.hpp"

#include "txns/txn.hpp"

/*
 * Main class providing the API for the Interactive B+ Tree.
 *
 * Implementation of simple b+ tree data structure where internal pages direct
 * the search and leaf pages contain actual data.
 * (1) We only support unique key
 * (2) support insert & remove
 * (3) The structure should shrink and grow dynamically
 * (4) Implement index iterator for range scan
 */

// https://github.com/Mike-Dai/cmudb/blob/df07d868f2cf52b051392505aa28cff05e11f0c4/src/index/b_plus_tree.cpp

class BPlusTree {
public:
  using KeyT    = GenericKey;
  using ValueT  = RID;
  using KeyComp = GenericComp;

  using InternalPage = BPlusTreeInternalPage<KeyT,
                                             page_id_t, KeyComp>;
  using LeafPage     = BPlusTreeLeafPage<KeyT, ValueT, KeyComp>;
  using MappingT     = std::pair<KeyT, ValueT>;

  static constexpr int LEAF_PAGE_SIZE =
    (PAGE_SIZE - LEAF_PAGE_HEADER_SIZE) / sizeof(MappingT);

  BPlusTree(String name,
            CRef<BuffMgr> buff_mgr,
            CRef<KeyComp> comparator,
            int leaf_size     = LeafPage::LEAF_PAGE_SIZE,
            int internal_size = InternalPage::INTERNAL_PAGE_SIZE);

  // Returns true if this B+ tree has no keys and values.
  bool is_empty() const;

  // Insert a key-value pair into this B+ tree.
  bool insert(CRef<KeyT> key,
              CRef<ValueT> value,
              OptRef<Txn> txn = std::nullopt);

  // Remove a key and its value from this B+ tree.
  void remove(CRef<KeyT> key,
              OptRef<Txn> txn = std::nullopt);

  // return the value associated with a given key
  Vec<ValueT> find_values(CRef<KeyT> key,
                          OptRef<Txn> txn = std::nullopt);

  // index iterator
  IndexIterator begin();
  IndexIterator begin(CRef<KeyT> key);
  IndexIterator end();

  void print(UNUSED BuffMgr& bpm) {
    // TODO: Fix this
    // to_string(reinterpret_cast<BPlusTreePage *>(bpm.fetch_page(root_page_id_)->data()), bpm);
  }

  void draw(UNUSED CRef<BuffMgr> bpm,
            CRef<String> outf) {
    std::ofstream out(outf);
    out << "digraph G {" << std::endl;
    // TODO: Fix this
    // to_graph(reinterpret_cast<BPlusTreePage *>(bpm.fetch_page(root_page_id_)->data()), bpm, out);
    out << "}" << std::endl;
    out.close();
  }

  // read data from file and insert one by one
  void insert_from_file(CRef<String> file_name, OptRef<Txn> txn);

  // read data from file and remove one by one
  void remove_from_file(CRef<String> file_name, OptRef<Txn> txn);
  // expose for test purpose
  CRef<Page> find_leaf_page(CRef<KeyT> key, bool leftMost = false);

 private:
  void start_new_tree(CRef<KeyT> key,
                      CRef<ValueT> value);

  bool insert_into_leaf(CRef<KeyT> key,
                        CRef<ValueT> value,
                        Txn *txn = nullptr);

  void insert_into_parent(BPlusTreePage& old_node,
                          CRef<KeyT> key,
                          // NOTE: This might actually be an out-parameter?
                          BPlusTreePage& new_node,
                          Txn *txn = nullptr);

  // TODO: Figure out the appropriate return signature for this. I am almost certain this
  // does some memory allocations?
  template <typename N>
  N *split(N *node);

  // NOTE: Don't worry too much about this interface. I think a much better
  // interface is available here:
  // https://github.com/yixuaz/CMU-15445/blob/master/project2B/b_plus_tree.cpp
  template <typename N>
  bool CoalesceOrRedistribute(N *node, Txn *txn = nullptr);

  template <typename N>
  bool Coalesce(N **neighbor_node,
                N **node,
                BPlusTreeInternalPage<KeyT, page_id_t, KeyComp> **parent,
                int index,
                Txn *txn = nullptr);

  template <typename N>
  void Redistribute(N *neighbor_node, N *node, int index);

  bool AdjustRoot(BPlusTreePage *node);

  void UpdateRootpage_id_t(int insert_record = 0);

  /* Debug Routines for FREE!! */
  void to_graph(BPlusTreePage *page, CRef<BuffMgr> bpm, std::ofstream &out) const;
  void to_string(BPlusTreePage *page, CRef<BuffMgr> bpm) const;

  // member variable
  String index_name_;
  PageId root_page_id_;
  CRef<BuffMgr> buff_mgr_;
  KeyComp comp_;
  int leaf_size_;
  int internal_size_;
};
