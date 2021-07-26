#include "btree/b_tree.hpp"


// https://github.com/Mike-Dai/cmudb/blob/df07d868f2cf52b051392505aa28cff05e11f0c4/src/index/b_plus_tree.cpp
// https://github.com/astronaut0131/cmu15-445-2017/blob/d393b2b76c38ef02ad8432f3eb66452219fe6508/src/index/b_plus_tree.cpp

// NOTE: Don't worry too much about this interface. I think a much better
// interface is available here:
// https://github.com/yixuaz/CMU-15445/blob/master/project2B/b_plus_tree.cpp

BTree::BTree(string index_name,
             const BuffMgr& buff_mgr,
             const KeyComp& comp,
             int leaf_size,
             int internal_size)
  : index_name_    (index_name),
    buff_mgr_      (buff_mgr),
    comp_          (comp),
    leaf_size_     (leaf_size),
    internal_size_ (internal_size)
{}


bool BTree::IsEmpty() const {
  return root_page_id_ == INVALID_PAGE_ID;
}

bool BTree::value(const KeyT &key,
                  vector<ValueT> &result,
                  Txn& txn)
{
  if (is_empty()) {
    return false;
  }

  auto leaf_node = find_leaf_page(key);
  ValueT value;
  bool exist = leaf_node.lookup(key, value, comparator_);
  if (exist) {
    result.push_back(value);
  }
  buff_mgr_.unpin(leaf_node.page_id(), false);
  return exist;
}

bool BTree::insert(const KeyT &key,
                   const ValueT &value,
                   Txn& txn)
{
  if (is_empty()) {
    start_new_tree(key, value);
    return true;
  }
  return insert_into_leaf(key, value);
}

void BTree::start_new_tree(const KeyT &key,
                           const ValueT &value)
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

bool BTree::insert_into_leaf(const KeyT &key,
                             const ValueT &value,
                             Txn& txn)
{
  auto leaf_node = find_leaf_page(key);
  ValueT v;

  // duplicate key found
  if (leaf_node.lookup(key, v, comparator_)) {
    return false;
  }

  // leaf node is not full
  if (leaf_node.size() < leaf_node.max_size()) {
    leaf_node.insert(key, value, comp_);
    buff_mgr_.unpin(leaf_node.page_id(), true);
    return true;
  }

  auto new_leaf_node = split<BTreeLeafPage>(leaf_node);
  if (comp_(key,new_leaf_node.key_at(0)) < 0) {
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

void BTree::insert_into_parent(BTreePage& old_node,
                               const KeyT &key,
                               BTreePage* new_node,
                               Txn& txn)
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
    split<BTreeInternalPage<KeyT, PageId, KeyComp>>(parent_node);
  // insert kv
  if (comp_(key, new_parent_node.key_at(1)) == -1) {
    parent_node.insert_node_after(old_node.page_id(), key,
                                  new_node.page_id());
  } else {
    new_parent_node.insertNodeAfter(old_node->page_id(), key,
                                    new_node->page_id());
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

void BTree::remove(const KeyT &key,
                   Txn& transaction)
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
bool BTree::coalesce_or_redistribute(NodeT& node,
                                     Txn& txn)
{
  if (node->IsRootPage()) {
    return AdjustRoot(node);
  }
  if (node->GetSize() >= node->GetMinSize()) {
    buffer_pool_manager_->UnpinPage(node->GetPageId(),true);
    return false;
  }
  auto parent_page = FetchPage(node->GetParentPageId());
  auto parent = reinterpret_cast<BTreeInternalPage<KeyT,page_id_t,KeyComp>*>
                (parent_page->GetData());
  int index = parent->ValueIndex(node->GetPageId());
  N *sibling;
  decltype(parent_page) sibling_page;
  if (index == 0)
    // right sibling if node is the leftmost child
    sibling_page = FetchPage(parent->ValueAt(index + 1));
  else
    // left sibling if not
    sibling_page = FetchPage(parent->ValueAt(index-1));
  sibling = reinterpret_cast<N*>(sibling_page->GetData());
  bool deletion;
  if (sibling->GetSize() + node->GetSize() > node->GetMaxSize()) {
    // redistribute
    Redistribute(sibling,node,index);
    buffer_pool_manager_->UnpinPage(sibling->GetPageId(),true);
    deletion = false;
  } else {
    if (index == 0) {
      // right sibling
      // move sibling content to node and delete parent entry 1
      Coalesce(node,sibling,parent,1,transaction);
      buffer_pool_manager_->UnpinPage(node->GetPageId(),true);
    }
    else {
      // left sibling
      Coalesce(sibling, node, parent, index, transaction);
      buffer_pool_manager_->UnpinPage(sibling->GetPageId(), true);
    }
    deletion = true;
  }
  CoalesceOrRedistribute(parent,transaction);
  return deletion;
}

template <typename N>
bool BTree::coalesce(NodeT &neighbor,
                     NodeT &node,
                     BTreeInternalPage<KeyT, PageId, KeyComp> &parent,
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
    auto child = reinterpret_cast<BTreePage*>(child_page->GetData());
    child->SetParentPageId(INVALID_PAGE_ID);
    buffer_pool_manager_->UnpinPage(child->GetPageId(),true);
    return true;
  }
  return false;
}

/*****************************************************************************
 * INDEX ITERATOR
 *****************************************************************************/
/*
 * Input parameter is void, find the leaftmost leaf page first, then construct
 * index iterator
 * @return : index iterator
 */
IndexInterator
BTree::begin() {
  KeyT k = {};
  return IndexIterator<KeyT,ValueT,KeyComp>(find_leaf_page(k, true),
                                            buff_mgr_, 0);
}

/*
 * Input parameter is low key, find the leaf page that contains the input key
 * first, then construct index iterator
 * @return : index iterator
 */
INDEX_TEMPLATE_ARGUMENTS
INDEXITERATOR_TYPE BTree::Begin(const KeyT &key) {
  auto leaf_page = FindLeafPage(key);
  return IndexIterator<KeyT,ValueT,KeyComp>(leaf_page,buffer_pool_manager_,leaf_page->KeyIndex(key,comparator_));
}

/*****************************************************************************
 * UTILITIES AND DEBUG
 *****************************************************************************/
/*
 * Find leaf page containing particular key, if leftMost flag == true, find
 * the left most leaf page
 */
INDEX_TEMPLATE_ARGUMENTS
B_PLUS_TREE_LEAF_PAGE_TYPE *BTree::FindLeafPage(const KeyT &key,
                                                         bool leftMost) {
  page_id_t page_id = root_page_id_;
  auto page = FetchPage(page_id);
  auto p = reinterpret_cast<BTreePage *>(page->GetData());
  while (!p->IsLeafPage()) {
    auto internal_p = reinterpret_cast<
        BTreeInternalPage<KeyT, page_id_t, KeyComp> *>(
        page->GetData());
    page_id = leftMost ? internal_p->ValueAt(0)
                       : internal_p->Lookup(key, comparator_);
    buffer_pool_manager_->UnpinPage(internal_p->GetPageId(), false);
    page = FetchPage(page_id);
    p = reinterpret_cast<BTreePage *>(page->GetData());
  }
  return reinterpret_cast<B_PLUS_TREE_LEAF_PAGE_TYPE *>(page->GetData());
}

/*
 * Update/Insert root page id in header page(where page_id = 0, header_page is
 * defined under include/page/header_page.h)
 * Call this method everytime root page id is changed.
 * @parameter: insert_record      defualt value is false. When set to true,
 * insert a record <index_name, root_page_id> into header page instead of
 * updating it.
 */
INDEX_TEMPLATE_ARGUMENTS
void BTree::UpdateRootPageId(int insert_record) {
  HeaderPage *header_page = static_cast<HeaderPage *>(
      buffer_pool_manager_->FetchPage(HEADER_PAGE_ID));
  if (insert_record)
    // create a new record<index_name + root_page_id> in header_page
    header_page->InsertRecord(index_name_, root_page_id_);
  else
    // update root_page_id in header_page
    header_page->UpdateRecord(index_name_, root_page_id_);
  buffer_pool_manager_->UnpinPage(HEADER_PAGE_ID, true);
}

/*
 * This method is used for debug only
 * print out whole b+tree sturcture, rank by rank
 */
INDEX_TEMPLATE_ARGUMENTS
std::string BTree::ToString(bool verbose) {
  if (IsEmpty()) return "Empty Tree";
  std::queue<BTreePage*> queue;
  auto root_page = FetchPage(root_page_id_);
  queue.push(reinterpret_cast<BTreePage*>(root_page->GetData()));
  std::string output;
  int size = 1;
  while (!queue.empty()) {
    int tmp_size = 0;
    for (int i = 0; i < size; i++) {
      auto front = queue.front();
      queue.pop();
      if (front->IsLeafPage()) {
        output += "|parent_id("+std::to_string(front->GetParentPageId())+") ";
        output += reinterpret_cast<B_PLUS_TREE_LEAF_PAGE_TYPE*>(front)->ToString(verbose);
        output += "| ";
      } else {
        auto node = reinterpret_cast<BTreeInternalPage<KeyT,page_id_t,KeyComp>*>(front);
        output += "|page_id("+std::to_string(front->GetPageId())+") ";
        output += node->ToString(verbose);
        output += "| ";
        int origin_size = queue.size();
        node->QueueUpChildren(&queue,buffer_pool_manager_);
        tmp_size += (int)queue.size() - origin_size;
      }
      buffer_pool_manager_->UnpinPage(front->GetPageId(),false);
    }
    size = tmp_size;
    output += '\n';
  }
  return output;
}

/*
 * This method is used for test only
 * Read data from file and insert one by one
 */
INDEX_TEMPLATE_ARGUMENTS
void BTree::InsertFromFile(const std::string &file_name,
                                    Transaction *transaction) {
  int64_t key;
  std::ifstream input(file_name);
  while (input) {
    input >> key;

    KeyT index_key;
    index_key.SetFromInteger(key);
    RID rid(key);
    Insert(index_key, rid, transaction);
  }
}
/*
 * This method is used for test only
 * Read data from file and remove one by one
 */
INDEX_TEMPLATE_ARGUMENTS
void BTree::RemoveFromFile(const std::string &file_name,
                                    Transaction *transaction) {
  int64_t key;
  std::ifstream input(file_name);
  while (input) {
    input >> key;
    KeyT index_key;
    index_key.SetFromInteger(key);
    Remove(index_key, transaction);
  }
}

INDEX_TEMPLATE_ARGUMENTS
Page *BTree::FetchPage(page_id_t page_id) {
  auto ptr = buffer_pool_manager_->FetchPage(page_id);
  if (ptr == nullptr)
    throw std::runtime_error("fail to fetch page");
  return ptr;
}

INDEX_TEMPLATE_ARGUMENTS
Page *BTree::NewPage(page_id_t &page_id) {
  auto ptr = buffer_pool_manager_->NewPage(page_id);
  if (ptr == nullptr)
    throw std::runtime_error("run out of memory");
  return ptr;
}

INDEX_TEMPLATE_ARGUMENTS
template <typename N> N *BTree::NewNode(page_id_t parent_id) {
  page_id_t new_page_id;
  Page *page = NewPage(new_page_id);
  auto node = reinterpret_cast<N *>(page->GetData());
  node->Init(new_page_id, parent_id);
  return node;
}








