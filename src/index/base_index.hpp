#pragma once

#include "tuple/tuple.hpp"
#include "txns/txn.hpp"


class BaseIndex {
public:
  // NOTE: I deleted the instance variable for IndexMeta.
  // However, this class may need it for the virtual methods below.
  // In the future, I may have to revive that instance variable
  // but keep in mind that BaseIndex is often a child of IndexMeta.
  // So let's be sure not to create a circular dependency.
  BaseIndex() = default;
  virtual ~BaseIndex() = default;

  static Ptr<BaseIndex> make() {
    return make_unique<BaseIndex>();
  }

  virtual void insert_entry(UNUSED CRef<Tuple> key,
                            UNUSED CRef<RID> rid) {
    throw Exception("insert_entry is not implemented on BaseIndex");
  }

  virtual void delete_entry(UNUSED CRef<Tuple> key,
                            UNUSED CRef<RID> rid) {
    throw Exception("delete_entry is not implemented on BaseIndex");
  }

  virtual Vec<RID> scan_key(UNUSED CRef<Tuple> key) const {
    throw Exception("scan_key is not implemented on BaseIndex");
  }
};
