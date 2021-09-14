// TODO: Rename this file to btree.hpp
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

template<class KeyT, class ValueT, class KeyComp>
class BTree {
public:
  using MappingT       = pair<KeyT, ValueT>;
  using InternalPageT  = BTreeInternalPage<KeyT, PageId, KeyComp>;
  using LeafPageT      = BTreeLeafPage<KeyT, ValueT, KeyComp>;
  using IndexIteratorT = IndexIterator<KeyT, ValueT, KeyComp>;

  BTree(const index_name_t name,
        file_id_t file_id,
        PageId root_page_id,
        const KeyComp comp,
        BuffMgr& buff_mgr)
    : index_name_    (name),
      root_page_id_  (root_page_id),
      buff_mgr_      (buff_mgr),
      comp_          (comp),
      file_id_       (file_id),
      leaf_size_     (LeafPageT::LEAF_PAGE_SIZE),
      internal_size_ (InternalPageT::INTERNAL_PAGE_SIZE)
  {}

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
  IndexIteratorT begin();
  IndexIteratorT begin(const KeyT& key);
  IndexIteratorT end();

  void print(UNUSED BuffMgr& bpm) {
    // TODO: Fix this
    // to_string(reinterpret_cast<BTreePage *>(bpm.fetch_page(root_page_id_)->data()), bpm);
  }

  void draw(const string& outf) {
    std::ofstream out(outf);
    out << "digraph G {" << std::endl;
    // TODO: Fix this
    // to_graph(reinterpret_cast<BTreePage *>(bpm.fetch_page(root_page_id_)->data()), bpm, out);
    out << "}" << std::endl;
    out.close();
  }

  // read data from file and insert one by one
  void insert_from_file(const string& file_name, Txn* txn = nullptr);

  // read data from file and remove one by one
  void remove_from_file(const string& file_name, Txn* txn = nullptr);
  // expose for test purpose
  LeafPageT find_leaf_page(const KeyT& key, bool left_most = false);

  template<class NodeT>
  NodeT new_node();

  template<class NodeT>
  NodeT new_node(PageId parent_id);

  static ptr<BTree<KeyT, ValueT, KeyComp>>
  make_unique(const index_name_t index_name,
              file_id_t file_id,
              PageId root_page_id,
              const KeyComp comp,
              BuffMgr& buff_mgr)
  {
    return make_unique<BTree<KeyT, ValueT, KeyComp>>(index_name,
                                                     file_id,
                                                     root_page_id,
                                                     comp,
                                                     buff_mgr);
  }

private:
  void start_new_tree(const KeyT& key,
                      const ValueT& value);

  bool insert_into_leaf(const KeyT& key,
                        const ValueT& value,
                        Txn *txn = nullptr);

  void insert_into_parent(BTreePage& old_node,
                          const KeyT& key,
                          // NOTE: This is an out-parameter
                          BTreePage& new_node,
                          Txn *txn = nullptr);

  template <class NodeT>
  NodeT split(NodeT &node);

  template <class NodeT>
  bool coalesce_or_redistribute(NodeT &node, Txn *txn = nullptr);

  template <class NodeT>
  bool coalesce(NodeT &neighbor,
                NodeT &node,
                InternalPageT& parent,
                int index,
                Txn *txn = nullptr);

  template <class NodeT>
  void redistribute(NodeT& neighbor,
                    NodeT& node,
                    int32_t index,
                    Txn* txn = nullptr);

  bool adjust_root(BTreePage& node);

  void update_root_page_id(int32_t insert_record = 0);

  void to_graph(BTreePage& page, const BuffMgr& bpm, std::ofstream &out) const;
  const string to_string(bool verbose) const;

  // member variable
  string index_name_;
  PageId root_page_id_;
  BuffMgr& buff_mgr_;
  const KeyComp comp_;
  file_id_t file_id_;
  int32_t leaf_size_;
  int32_t internal_size_;
  int32_t max_block_num_ = 0;
};

template class BTree<IndexKey, RID, IndexComp>;
