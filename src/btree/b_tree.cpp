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



BTree::BTree(const string index_name,
             BuffMgr& buff_mgr,
             const KeyComp& comp,
             int32_t leaf_size,
             int32_t internal_size)
  : index_name_    (index_name),
    buff_mgr_      (buff_mgr),
    comp_          (comp),
    leaf_size_     (leaf_size),
    internal_size_ (internal_size)
{}


bool BTree::is_empty() const {
  return root_page_id_ == PageId::INVALID();
}

vector<BTree::ValueT>
BTree::find_values(const BTree::KeyT &key, UNUSED Txn* txn) {
  if (is_empty()) {
    return vector<BTree::ValueT>();
  }

  auto leaf_node = find_leaf_page(key);
  BTree::ValueT value;
  bool exist = leaf_node.lookup(key, value, comp_);
  vector<BTree::ValueT> result;
  if (exist) {
    result.push_back(value);
  }
  buff_mgr_.unpin(leaf_node.page_id(), false);
  return result;
}

bool BTree::insert(const BTree::KeyT &key,
                   const BTree::ValueT &value,
                   UNUSED Txn* txn)
{
  if (is_empty()) {
    start_new_tree(key, value);
    return true;
  }
  return insert_into_leaf(key, value);
}

void BTree::start_new_tree(const BTree::KeyT &key,
                           const BTree::ValueT &value)
{
  // create new node
  auto node = new_node<BTreeLeafPage>();
  // update root_page_id_
  root_page_id_ = node.page_id();
  update_root_page_id(true);
  // insert kv to the root node
  node.insert(key, value, comp_);
  // unpin the root node
  buff_mgr_.unpin(root_page_id_, false);
}

bool BTree::insert_into_leaf(const BTree::KeyT &key,
                             const BTree::ValueT &value,
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

  auto new_leaf_node = split<BTreeLeafPage>(leaf_node);
  if (comp_(key, new_leaf_node.key_at(0)) < 0) {
    leaf_node.insert(key, value, comp_);
  } else {
    new_leaf_node.insert(key, value, comp_);
  }

  leaf_node.set_next_page_id(new_leaf_node.page_id());
  insert_into_parent(leaf_node, new_leaf_node.key_at(0), new_leaf_node, txn);

  return true;
}

template <typename NodeT>
NodeT& BTree::split(NodeT &node) {
  auto recipient = new_node<N>(node.parent_page_id());
  node.move_half_to(recipient, buff_mgr_);
  return recipient;
}

void BTree::insert_into_parent(BTreePage old_node,
                               const BTree::KeyT &key,
                               BTreePage new_node,
                               Txn* txn)
{
  if (old_node.is_root_page()) {
    // old_node is the root node
    // create a new node containing old_node,key,new_node
    auto parent_node =
      new_node<BTreeInternalPage<KeyT, PageId, KeyComp>>();
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

  auto parent_page = fetch_page(old_node.parent_page_id());
  auto parent_node = BTreeInternalPage<KeyT, PageId, KeyComp>(parent_page.data());

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
  auto new_parent_node =
    split<BTreeInternalPage<BTree::KeyT, PageId, KeyComp>>(parent_node);
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

void BTree::remove(const BTree::KeyT &key,
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

template <typename NodeT>
bool BTree::coalesce_or_redistribute(NodeT& node, Txn* txn)
{
  if (node.is_root_page()) {
    return adjust_root(node);
  }

  if (node.size() >= node.min_size()) {
    buff_mgr_.unpin(node.page_id(), true);
    return false;
  }

  auto parent_page = fetch_page(node.parent_page_id());
  auto parent = BTreeInternalPage<BTree::KeyT, PageId, BTree::KeyComp>(parent_page.data());
  int index = parent.value_index(node.page_id());

  if (index == 0) {
    // right sibling if node is the leftmost child
    sibling_page = fetch_page(parent.value_at(index + 1));
  } else {
    // left sibling if not
    sibling_page = fetch_page(parent.value_at(index - 1));
  }

  sibling = NodeT(sibling_page.get_data());
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
      coalesce(sibling, node, parent, index, transaction);
      buff_mgr_.unpin(sibling.page_id(), true);
    }
    deletion = true;
  }
  coalesce_or_redistribute(parent, txn);
  return deletion;
}

template <typename NodeT>
bool BTree::coalesce(NodeT &neighbor,
                     NodeT &node,
                     BTreeInternalPage<BTree::KeyT, PageId, BTree::KeyComp> &parent,
                     int32_t index)
{
  node.move_all_to(neighbor, index, buff_mgr_);
  parent.remove(index);
  buff_mgr_.delete_page(node.page_id());
  return parent.size() == 0;
}

template <typename NodeT>
void BTree::redistribute(NodeT& neighbor, NodeT& node, int32_t index) {
  if (index == 0) {
    // neighbor_node is the right sibling of node
    neighbor.move_first_to_end_of(node, buff_mgr_);
  } else {
    // else neighbor_node is the left sibling of node
    neighbor.move_last_to_front_of(node, index, buff_mgr_);
  }
}

bool BTree::adjust_root(BTreePage& old_root) {
  if (old_root.is_leaf_page()) {
    if (old_root.size() == 0) {
      // delete root page
      buff_mgr_.delete_page(root_page_id_);
      root_page_id_ = INVALID_PAGE_ID;
      update_root_page_id();
      return true;
    }
    return false;
  }

  // old_root_node is a internal node
  if (old_root.size() == 1) {
    // has one last child
    auto root = BTreeInternalPage<KeyT, PageId, KeyComp>(old_root);
    auto child_page_id = root.valueAt(0);
    // delete root page
    buff_mgr_.delete_page(root.page_id());
    // child node becomes the new root
    root_page_id_ = child_page_id;
    update_root_page_id();
    auto child_page = fetch_page(child_page_id);
    auto child = BTreePage(child_page.data());
    child.set_parent_page_id(INVALID_PAGE_ID);
    buff_mgr_.unpin(child.page_id(), true);
    return true;
  }
  return false;
}

IndexInterator BTree::begin() {
  KeyT k = {};
  return IndexIterator<KeyT,ValueT,KeyComp>(find_leaf_page(k, true),
                                            buff_mgr_, 0);
}

/*
 * Input parameter is low key, find the leaf page that contains the input key
 * first, then construct index iterator
 * @return : index iterator
 */

IndexIterator BTree::begin(const KeyT &key) {
  auto leaf_page = find_leaf_page(key);
  return IndexIterator<KeyT, ValueT, KeyComp>(leaf_page,
                                              buff_mgr_,
                                              leaf_page.key_index(key, comp_));
}

BTree::LeafPageT
BTree::find_leaf_page(const KeyT &key,
                      bool left_most)
{
  PageId page_id = root_page_id_;
  auto page_ptr = fetch_page(page_id);
  auto b_tree_page = BTreePage(page_ptr);

  while (!b_tree_page.is_leaf_page()) {
    auto internal_page = BTree::InternalPageT(page_ptr);
    if (left_most) {
      page_id = internal_page.value_at(0);
    } else {
      page_id = internal_page.lookup(key, comp_);
    }

    buff_mgr_.unpin(internal_page.page_id(), false);
    page_ptr = fetch_page(page_id);
    b_tree_page = BTreePage(page_ptr);
  }

  return BTreeLeafPage(page_ptr);
}

void BTree::update_root_page_id(int32_t insert_record) {
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
}

string BTree::to_string(bool verbose) {
  if (is_empty()) {
    return "Empty Tree";
  }

  queue<BTreePage> queue;
  auto root_page_ptr = fetch_page(root_page_id_);
  queue.push(BTreePage(root_page_ptr));
  string output;
  int32_t total_size = 1;
  while (!queue.empty()) {
    int32_t curr_size = 0;
    for (int i = 0; i < total_size; i++) {
      auto front = queue.front();
      queue.pop();
      if (front.is_leaf_page()) {
        output += "| parent_id(" + std::to_string(front.parent_page_id()) + ") ";
        output += BTree::LeafPageT(front.page_ptr()).to_string(verbose);
        output += "| ";
      } else {
        auto node = BTree::InternalPageT(front.page_ptr());
        output += "| page_id(" + std::to_string(front.page_id()) + ") ";
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

void BTree::insert_from_file(const string &file_name, Txn* txn) {
  int64_t key;
  ifstream input(file_name);
  while (input) {
    input >> key;
    KeyT index_key;
    index_key.set_from_integer(key);
    RID rid(key);
    insert(index_key, rid, txn);
  }
}
/*
 * This method is used for test only
 * Read data from file and remove one by one
 */
void BTree::remove_from_file(const string &file_name,
                             Txn* txn) {
  int64_t key;
  ifstream input(file_name);
  while (input) {
    input >> key;
    KeyT index_key;
    index_key.set_from_integer(key);
    remove(index_key, txn);
  }
}

Page *BTree::fetch_page(PageId page_id) {
  auto ptr = buff_mgr_.fetch_page(page_id);
  if (ptr == nullptr)
    throw std::runtime_error("fail to fetch page");
  return ptr;
}

Page *BTree::new_page(page_id_t &page_id) {
  auto ptr = buff_mgr_.new_page(page_id);
  if (ptr == nullptr)
    throw std::runtime_error("run out of memory");
  return ptr;
}

template<typename NodeT>
NodeT BTree::new_node() {
  return new_node<NodeT>(PageId::INVALID());
}

template<typename NodeT>
NodeT BTree::new_node(PageId parent_id) {
  PageId new_page_id;
  Page *page_ptr = new_page(new_page_id);
  auto node = NodeT(page_ptr);
  node.init(new_page_id, parent_id);
  return node;
}
