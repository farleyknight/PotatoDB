#include "btree/b_tree.hpp"

// TODO
// 1) Need to properly sketch out the algo on the type level
//    Which types go where?
// 2) Figure out which types need to be pointers (because of copying or scoping)
//    and which can stay references
// https://github.com/Mike-Dai/cmudb/blob/df07d868f2cf52b051392505aa28cff05e11f0c4/src/index/b_plus_tree.cpp
// https://github.com/astronaut0131/cmu15-445-2017/blob/d393b2b76c38ef02ad8432f3eb66452219fe6508/src/index/b_plus_tree.cpp

// NOTE: Don't worry too much about this interface. I think a much better
// interface is available here:
// https://github.com/yixuaz/CMU-15445/blob/master/project2B/b_plus_tree.cpp


// NOTE:
// One possible optimization: Path Hints:
// https://news.ycombinator.com/item?id=28008541
// https://github.com/tidwall/btree/blob/master/PATH_HINT.md
// https://www.reddit.com/r/programming/comments/oum0wa/path_hints_for_btrees_can_bring_a_performance/


template<class KeyT, class ValueT, class KeyComp>
BTree<KeyT, ValueT, KeyComp>::BTree(const index_name_t name,
                                    file_id_t file_id,
                                    BuffMgr& buff_mgr,
                                    const KeyComp& comp)
  : index_name_    (name),
    buff_mgr_      (buff_mgr),
    file_id_       (file_id),
    comp_          (comp),
    leaf_size_     (LeafPageT::LEAF_PAGE_SIZE),
    internal_size_ (InternalPageT::INTERNAL_PAGE_SIZE)
{}

template<class KeyT, class ValueT, class KeyComp>
bool BTree<KeyT, ValueT, KeyComp>::is_empty() const {
  return root_page_id_ == PageId::INVALID();
}

template<class KeyT, class ValueT, class KeyComp>
vector<ValueT> BTree<KeyT, ValueT, KeyComp>::find_values(const KeyT &key,
                                                         UNUSED Txn* txn)
{
  if (is_empty()) {
    return vector<ValueT>();
  }

  auto leaf_node = find_leaf_page(key);
  ValueT value;
  bool exist = leaf_node.lookup(key, value, comp_);
  vector<ValueT> result;
  if (exist) {
    result.push_back(value);
  }
  buff_mgr_.unpin(leaf_node.page_id(), false);
  return result;
}

template<class KeyT, class ValueT, class KeyComp>
bool BTree<KeyT, ValueT, KeyComp>::insert(const KeyT &key,
                                          const ValueT &value,
                                          UNUSED Txn* txn)
{
  if (is_empty()) {
    start_new_tree(key, value);
    return true;
  }
  return insert_into_leaf(key, value);
}

template<class KeyT, class ValueT, class KeyComp>
void BTree<KeyT, ValueT, KeyComp>::start_new_tree(const KeyT &key,
                                                  const ValueT &value)
{
  // create new node
  auto node = new_node<LeafPageT>();
  // update root_page_id_
  root_page_id_ = node.page_id();
  update_root_page_id(true);
  // insert kv to the root node
  node.insert(key, value, comp_);
  // unpin the root node
  buff_mgr_.unpin(root_page_id_, false);
}

template<class KeyT, class ValueT, class KeyComp>
bool BTree<KeyT, ValueT, KeyComp>::insert_into_leaf(const KeyT &key,
                                                    const ValueT &value,
                                                    Txn* txn)
{
  auto leaf_node = find_leaf_page(key);
  ValueT new_value;

  // duplicate key found
  if (leaf_node.lookup(key, new_value, comp_)) {
    return false;
  }

  // leaf node is not full
  if (leaf_node.size() < leaf_node.max_size()) {
    leaf_node.insert(key, value, comp_);
    buff_mgr_.unpin(leaf_node.page_id(), true);
    return true;
  }

  auto new_leaf_node = split<LeafPageT>(leaf_node);
  if (comp_(key, new_leaf_node.key_at(0)) < 0) {
    leaf_node.insert(key, value, comp_);
  } else {
    new_leaf_node.insert(key, value, comp_);
  }

  leaf_node.set_next_page_id(new_leaf_node.page_id());
  insert_into_parent(leaf_node, new_leaf_node.key_at(0), new_leaf_node, txn);

  return true;
}

template<class KeyT, class ValueT, class KeyComp>
template<class NodeT>
NodeT BTree<KeyT, ValueT, KeyComp>::split(NodeT &node) {
  auto recipient = new_node<NodeT>(node.parent_page_id());
  node.move_half_to(recipient, buff_mgr_);
  return recipient;
}

template<class KeyT, class ValueT, class KeyComp>
void BTree<KeyT, ValueT, KeyComp>::insert_into_parent(BTreePage& old_node,
                                                      const KeyT &key,
                                                      BTreePage& new_node,
                                                      UNUSED Txn* txn)
{
  if (old_node.is_root_page()) {
    // old_node is the root node
    // create a new node containing old_node,key,new_node
    auto parent_node =
      BTree::new_node<InternalPageT>();
    parent_node.populate_new_root(old_node.page_id(), key,
                                  new_node.page_id());

    auto parent_page_id = parent_node.page_id();
    old_node.set_parent_page_id(parent_page_id);
    new_node.set_parent_page_id(parent_page_id);

    // update root_page_id_
    root_page_id_ = parent_page_id;
    update_root_page_id(false);
    // unpin
    buff_mgr_.unpin(old_node.page_id(), true);
    buff_mgr_.unpin(new_node.page_id(), true);
    buff_mgr_.unpin(parent_page_id, true);
    return;
  }

  auto parent_page_ptr = buff_mgr_.fetch_page(old_node.parent_page_id());
  auto parent_node = BTreeInternalPage<KeyT, PageId, KeyComp>(parent_page_ptr);

  if (parent_node.size() < parent_node.max_size()) {
    // parent node is not full
    parent_node.insert_node_after(old_node.page_id(), key,
                                  new_node.page_id());
    buff_mgr_.unpin(old_node.page_id(), true);
    buff_mgr_.unpin(new_node.page_id(), true);
    buff_mgr_.unpin(parent_node.page_id(), true);
    return;
  }
  // parent node is full
  // split parent node
  auto new_parent_node = split<InternalPageT>(parent_node);
  // insert kv
  if (comp_(key, new_parent_node.key_at(1)) == -1) {
    parent_node.insert_node_after(old_node.page_id(), key,
                                  new_node.page_id());
  } else {
    new_parent_node.insert_node_after(old_node.page_id(), key,
                                      new_node.page_id());
    // remember to change new_node's parent into new_parent_node's page id
    // its parent id is set to the same with old_node in the previous Split
    new_node.set_parent_page_id(new_parent_node.page_id());
  }
  buff_mgr_.unpin(old_node.page_id(), true);
  buff_mgr_.unpin(new_node.page_id(), true);

  // recursive call
  insert_into_parent(parent_node,
                     new_parent_node.key_at(0),
                     new_parent_node);
}

template<class KeyT, class ValueT, class KeyComp>
void BTree<KeyT, ValueT, KeyComp>::remove(const KeyT &key,
                                          Txn* txn)
{
  if (is_empty()) {
    return;
  }

  auto leaf_node = find_leaf_page(key);
  ValueT v;
  if (leaf_node.lookup(key, v, comp_)) {
    leaf_node.remove_and_delete_record(key, comp_);
    coalesce_or_redistribute(leaf_node, txn);
  }
}

template<class KeyT, class ValueT, class KeyComp>
template<class NodeT>
bool BTree<KeyT, ValueT, KeyComp>::coalesce_or_redistribute(NodeT& node, Txn* txn)
{
  if (node.is_root_page()) {
    return adjust_root(node);
  }

  if (node.size() >= node.min_size()) {
    buff_mgr_.unpin(node.page_id(), true);
    return false;
  }

  Page* sibling_page_ptr = nullptr;
  auto parent_page_ptr = buff_mgr_.fetch_page(node.parent_page_id());
  auto parent = InternalPageT(parent_page_ptr);
  int index = parent.value_index(node.page_id());

  if (index == 0) {
    // right sibling if node is the leftmost child
    sibling_page_ptr = buff_mgr_.fetch_page(parent.value_at(index + 1));
  } else {
    // left sibling if not
    sibling_page_ptr = buff_mgr_.fetch_page(parent.value_at(index - 1));
  }

  auto sibling = NodeT(sibling_page_ptr);
  bool deletion;
  if (sibling.size() + node.size() > node.max_size()) {
    // redistribute
    redistribute(sibling, node, index);
    buff_mgr_.unpin(sibling.page_id(), true);
    deletion = false;
  } else {
    if (index == 0) {
      // right sibling
      // move sibling content to node and delete parent entry 1
      coalesce(node, sibling, parent, 1, txn);
      buff_mgr_.unpin(node.page_id(), true);
    }
    else {
      // left sibling
      coalesce(sibling, node, parent, index, txn);
      buff_mgr_.unpin(sibling.page_id(), true);
    }
    deletion = true;
  }
  coalesce_or_redistribute(parent, txn);
  return deletion;
}

template<class KeyT, class ValueT, class KeyComp>
template <class NodeT>
bool BTree<KeyT, ValueT, KeyComp>::coalesce(NodeT& neighbor,
                                            NodeT& node,
                                            InternalPageT &parent,
                                            int32_t index,
                                            UNUSED Txn* txn)
{
  node.move_all_to(neighbor, index, buff_mgr_);
  parent.remove(index);
  buff_mgr_.delete_page(node.page_id());
  return parent.size() == 0;
}

template<class KeyT, class ValueT, class KeyComp>
template<class NodeT>
void BTree<KeyT, ValueT, KeyComp>::redistribute(NodeT& neighbor,
                                                NodeT& node,
                                                int32_t index,
                                                UNUSED Txn *txn)
{
  if (index == 0) {
    // neighbor_node is the right sibling of node
    neighbor.move_first_to_end_of(node, buff_mgr_);
  } else {
    // else neighbor_node is the left sibling of node
    neighbor.move_last_to_front_of(node, index, buff_mgr_);
  }
}

template<class KeyT, class ValueT, class KeyComp>
bool BTree<KeyT, ValueT, KeyComp>::adjust_root(BTreePage& old_root) {
  if (old_root.is_leaf_page()) {
    if (old_root.size() == 0) {
      // delete root page
      buff_mgr_.delete_page(root_page_id_);
      root_page_id_ = PageId::INVALID();
      update_root_page_id();
      return true;
    }
    return false;
  }

  // old_root_node is a internal node
  if (old_root.size() == 1) {
    // has one last child
    auto root = InternalPageT(old_root);
    auto child_page_id = root.value_at(0);
    // delete root page
    buff_mgr_.delete_page(root.page_id());
    // child node becomes the new root
    root_page_id_ = child_page_id;
    update_root_page_id();
    auto child_page = buff_mgr_.fetch_page(child_page_id);
    auto child = BTreePage(child_page.data());
    child.set_parent_page_id(PageId::INVALID());
    buff_mgr_.unpin(child.page_id(), true);
    return true;
  }
  return false;
}

template<class KeyT, class ValueT, class KeyComp>
IndexIterator<KeyT, ValueT, KeyComp> BTree<KeyT, ValueT, KeyComp>::begin() {
  KeyT k = {};
  return IndexIteratorT(find_leaf_page(k, true), buff_mgr_, 0);
}

/*
 * Input parameter is low key, find the leaf page that contains the input key
 * first, then construct index iterator
 * @return : index iterator
 */

template<class KeyT, class ValueT, class KeyComp>
IndexIterator<KeyT, ValueT, KeyComp> BTree<KeyT, ValueT, KeyComp>::begin(const KeyT &key) {
  auto leaf_page = find_leaf_page(key);
  return IndexIterator<KeyT, ValueT, KeyComp>(leaf_page,
                                              buff_mgr_,
                                              leaf_page.key_index(key, comp_));
}

template<class KeyT, class ValueT, class KeyComp>
BTreeLeafPage<KeyT, ValueT, KeyComp>
BTree<KeyT, ValueT, KeyComp>::find_leaf_page(const KeyT &key,
                                             bool left_most)
{
  PageId page_id = root_page_id_;
  auto page_ptr = buff_mgr_.fetch_page(page_id);
  auto b_tree_page = BTreePage(page_ptr);

  while (!b_tree_page.is_leaf_page()) {
    auto internal_page = InternalPageT(page_ptr);
    if (left_most) {
      page_id = internal_page.value_at(0);
    } else {
      page_id = internal_page.lookup(key, comp_);
    }

    buff_mgr_.unpin(internal_page.page_id(), false);
    page_ptr = buff_mgr_.fetch_page(page_id);
    b_tree_page = BTreePage(page_ptr);
  }

  return BTree::LeafPageT(page_ptr);
}

template<class KeyT, class ValueT, class KeyComp>
void BTree<KeyT, ValueT, KeyComp>::update_root_page_id(UNUSED int32_t insert_record) {
  // TODO: This is something that should be handled by SystemCatalog
  // However, SystemCatalog itself needs a refactor. So holding off on this for now.

  /*
    auto page = buff_mgr_.fetch_page(HEADER_PAGE_ID);
    auto header_page = HeaderPage(page);
    if (insert_record) {
    // create a new record<index_name + root_page_id> in header_page
    header_page.insert_record(index_name_, root_page_id_);
    } else {
    // update root_page_id in header_page
    header_page.update_record(index_name_, root_page_id_);
    }

    buff_mgr_.unpin(HEADER_PAGE_ID, true);
   */
}

template<class KeyT, class ValueT, class KeyComp>
const string BTree<KeyT, ValueT, KeyComp>::to_string(bool verbose) const {
  if (is_empty()) {
    return "Empty Tree";
  }

  std::queue<BTreePage> queue;
  auto root_page_ptr = buff_mgr_.fetch_page(root_page_id_);
  queue.push(BTreePage(root_page_ptr));
  string output;
  int32_t total_size = 1;
  while (!queue.empty()) {
    int32_t curr_size = 0;
    for (int i = 0; i < total_size; i++) {
      auto front = queue.front();
      queue.pop();
      if (front.is_leaf_page()) {
        output += "| parent_id(" + front.parent_page_id().to_string() + ") ";
        output += LeafPageT(front.page_ptr()).to_string(verbose);
        output += "| ";
      } else {
        auto node = InternalPageT(front.page_ptr());
        output += "| page_id(" + front.page_id().to_string() + ") ";
        output += node.to_string(verbose);
        output += "| ";
        int32_t origin_size = queue.size();
        node.queue_up_children(&queue, buff_mgr_);
        curr_size += queue.size() - origin_size;
      }
      buff_mgr_.unpin(front.page_id(), false);
    }
    total_size = curr_size;
    output += '\n';
  }
  return output;
}

// TODO: Convert this to use FileHandle
template<class KeyT, class ValueT, class KeyComp>
void BTree<KeyT, ValueT, KeyComp>::insert_from_file(const string &file_name, Txn* txn) {
  int64_t key;
  fstream input(file_name);
  while (input) {
    input >> key;
    KeyT index_key;
    index_key.set_from_integer(key);
    RID rid(key);
    insert(index_key, rid, txn);
  }
}

// TODO: Convert this to use FileHandle
template<class KeyT, class ValueT, class KeyComp>
void BTree<KeyT, ValueT, KeyComp>::remove_from_file(const string &file_name,
                                                    Txn* txn)
{
  int64_t key;
  fstream input(file_name);
  while (input) {
    input >> key;
    KeyT index_key;
    index_key.set_from_integer(key);
    remove(index_key, txn);
  }
}

template<class KeyT, class ValueT, class KeyComp>
template<class NodeT>
NodeT BTree<KeyT, ValueT, KeyComp>::new_node() {
  return new_node<NodeT>(PageId::INVALID());
}

template<class KeyT, class ValueT, class KeyComp>
template<class NodeT>
NodeT BTree<KeyT, ValueT, KeyComp>::new_node(PageId parent_id) {
  PageId new_page_id(file_id_, max_block_num_);
  max_block_num_++;
  auto page_ptr = buff_mgr_.fetch_page(new_page_id);
  auto node = NodeT(page_ptr);
  node.init(new_page_id, parent_id);
  return node;
}
