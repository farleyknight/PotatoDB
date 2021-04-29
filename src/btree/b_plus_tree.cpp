
#include "btree/b_plus_tree.hpp"

BPlusTree::BPlusTree(String index_name,
                     CRef<BuffMgr> buff_mgr,
                     CRef<KeyComp> comp,
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
BPlusTree::begin(UNUSED CRef<BPlusTree::KeyT> key) {
  // TODO!
  return IndexIterator();
}

IndexIterator
BPlusTree::end() {
  // TODO!
  return IndexIterator();
}

// TODO: Maybe make this const?
Vec<BPlusTree::ValueT>
BPlusTree::find_values(UNUSED CRef<BPlusTree::KeyT> key,
                       UNUSED OptRef<Txn> txn)
{
  return Vec<BPlusTree::ValueT>();
}

bool BPlusTree::insert(UNUSED CRef<BPlusTree::KeyT> key,
                       UNUSED CRef<BPlusTree::ValueT> value,
                       UNUSED OptRef<Txn> txn)
{
  // TODO!
  return false;
}

void BPlusTree::remove(UNUSED CRef<KeyT> key,
                       UNUSED OptRef<Txn> txn)
{
  // TODO!
}
