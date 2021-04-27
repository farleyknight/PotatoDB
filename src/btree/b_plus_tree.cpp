
#include "btree/b_plus_tree.hpp"

BPlusTree::BPlusTree(String index_name,
                     Ref<BuffMgr> buff_mgr,
                     Ref<KeyComp> comp,
                     int leaf_size,
                     int internal_size)
  : index_name_    (index_name),
    buff_mgr_      (buff_mgr),
    comp_          (comp),
    leaf_size_     (leaf_size),
    internal_size_ (internal_size)
{
  // TODO
}

IndexIterator
BPlusTree::begin() {
  // TODO!
  return IndexIterator();
}

IndexIterator
BPlusTree::begin(Ref<BPlusTree::KeyT> key) {
  // TODO!
  return IndexIterator();
}

IndexIterator
BPlusTree::end() {
  // TODO!
  return IndexIterator();
}

// TODO: Maybe make this const?
Vec<BPlusTree::ValueT> BPlusTree::find_values(Ref<BPlusTree::KeyT> key,
                                              OptRef<Txn> txn)
{
  return Vec<BPlusTree::ValueT>();
}

bool BPlusTree::insert(Ref<BPlusTree::KeyT> key,
                       Ref<BPlusTree::ValueT> value,
                       OptRef<Txn> txn)
{
  // TODO!
  return false;
}

void BPlusTree::remove(Ref<KeyT> key,
                       OptRef<Txn> txn)
{
  // TODO!
}
