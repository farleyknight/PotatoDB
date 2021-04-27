#pragma once

#include "buffer/buff_mgr.hpp"

#include "tuple/tuple.hpp"

class LockMgr;
class TableIterator; // TODO: Rename TableIterator to TableIter
class Txn;

class TableHeap {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  TableHeap(MRef<BuffMgr> buff_mgr,
            MRef<LockMgr> lock_mgr,
            MRef<LogMgr> log_mgr,
            page_id_t first_page_id);

  TableHeap(MRef<BuffMgr> buff_mgr,
            MRef<LockMgr> lock_mgr,
            MRef<LogMgr> log_mgr,
            MRef<Txn> txn);

  ~TableHeap() = default;

  const page_id_t first_page_id() const {
    return first_page_id_;
  }

  bool insert_tuple(Ref<Tuple> tuple,
                    MRef<RID> rid,
                    MRef<Txn> txn);
  bool mark_delete(Ref<RID> rid,
                   MRef<Txn> txn);
  bool update_tuple(Ref<Tuple> tuple,
                    Ref<RID> rid,
                    MRef<Txn> txn);
  bool apply_delete(MRef<RID> rid,
                    MRef<Txn> txn);
  void rollback_delete(Ref<RID> rid,
                       MRef<Txn> txn);

  Option<Tuple> find_tuple(Ref<RID> rid,
                           MRef<Txn> txn) const;

  TableIterator begin(MRef<Txn> txn);
  TableIterator end(MRef<Txn> txn);

  MRef<BuffMgr> buff_mgr() { return buff_mgr_; }

private:
  page_id_t first_page_id_;
  MRef<LockMgr> lock_mgr_;
  MRef<LogMgr> log_mgr_;
  MRef<BuffMgr> buff_mgr_;
};
