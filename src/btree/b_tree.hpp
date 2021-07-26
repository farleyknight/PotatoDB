#pragma once

#include <queue>
#include <string>
#include <vector>

#include "common/config.hpp"

#include "index/index_iterator.hpp"
#include "btree/b_tree_internal_page.hpp"
#include "btree/b_tree_leaf_page.hpp"

#include "txns/txn.hpp"

/*
 * Main class providing the API for the Interactive B+ Tree.
 *
 * Implementation of simple b+ tree data structure where internal pages direct * the search and leaf pages contain actual data.
 * (1) We only support unique key
 * (2) support insert & remove
 * (3) The structure should shrink and grow dynamically
 * (4) Implement index iterator for range scan
 */

class BTree {
public:
  using KeyT    = GenericKey;
  using ValueT  = RID;
  using KeyComp = GenericComp;

  using InternalPage = BTreeInternalPage<KeyT,
                                         ValueT, KeyComp>;
  using LeafPage     = BTreeLeafPage<KeyT, ValueT, KeyComp>;
  using MappingT     = pair<KeyT, ValueT>;

  static constexpr int LEAF_PAGE_SIZE =
    (PAGE_SIZE - LEAF_PAGE_HEADER_SIZE) / sizeof(MappingT);

  BTree(const string name,
        const BuffMgr& buff_mgr,
        const KeyComp& comparator,
        int leaf_size     = LeafPage::LEAF_PAGE_SIZE,
        int internal_size = InternalPage::INTERNAL_PAGE_SIZE);

  // Returns true if this B+ tree has no keys and values.
  bool is_empty() const;

  // Insert a key-value pair into this B+ tree.
  bool insert(const KeyT& key,
              const ValueT& value,
              Txn* txn = nullptr);

  // Remove a key and its value from this B+ tree.
  void remove(const KeyT& key,
              Txn* txn = nullptr);

  // return the value associated with a given key
  vector<ValueT> find_values(const KeyT& key,
                             Txn* txn = nullptr);

  // index iterator
  IndexIterator begin();
  IndexIterator begin(const KeyT& key);
  IndexIterator end();

  void print(UNUSED BuffMgr& bpm) {
    // TODO: Fix this
    // to_string(reinterpret_cast<BTreePage *>(bpm.fetch_page(root_page_id_)->data()), bpm);
  }

  void draw(UNUSED const BuffMgr& bpm,
            const string& outf) {
    std::ofstream out(outf);
    out << "digraph G {" << std::endl;
    // TODO: Fix this
    // to_graph(reinterpret_cast<BTreePage *>(bpm.fetch_page(root_page_id_)->data()), bpm, out);
    out << "}" << std::endl;
    out.close();
  }

  // read data from file and insert one by one
  void insert_from_file(const string& file_name, OptRef<Txn> txn);

  // read data from file and remove one by one
  void remove_from_file(const string& file_name, OptRef<Txn> txn);
  // expose for test purpose
  const Page& find_leaf_page(const KeyT& key, bool leftMost = false);

 private:
  void start_new_tree(const KeyT& key,
                      const ValueT& value);

  bool insert_into_leaf(const KeyT& key,
                        const ValueT& value,
                        Txn *txn = nullptr);

  void insert_into_parent(BTreePage& old_node,
                          const KeyT& key,
                          // NOTE: This might actually be an out-parameter?
                          BTreePage& new_node,
                          Txn *txn = nullptr);

  // TODO: Figure out the appropriate return signature for this. I am almost certain this
  // does some memory allocations?
  template <typename N>
  N *split(N *node);

  template <typename N>
  bool CoalesceOrRedistribute(N *node, Txn *txn = nullptr);

  template <typename N>
  bool Coalesce(N **neighbor_node,
                N **node,
                BTreeInternalPage<KeyT, page_id_t, KeyComp> **parent,
                int index,
                Txn *txn = nullptr);

  template <typename N>
  void redistribute(N *neighbor_node, N *node, int index);

  bool AdjustRoot(BTreePage *node);

  void UpdateRootpage_id_t(int insert_record = 0);

  /* Debug Routines for FREE!! */
  void to_graph(BTreePage *page, const BuffMgr& bpm, std::ofstream &out) const;
  void to_string(BTreePage *page, const BuffMgr& bpm) const;

  // member variable
  string index_name_;
  PageId root_page_id_ = PageId::INVALID();
  const BuffMgr& buff_mgr_;
  KeyComp comp_;
  int leaf_size_;
  int internal_size_;
};
