#pragma once

#include "disk/disk_mgr.hpp"
#include "buffer/buff_mgr.hpp"

class TableMgr {
public:
  TableMgr(CRef<DiskMgr> disk_mgr,
           CRef<BuffMgr> buff_mgr)
    : disk_mgr_ (disk_mgr),
      buff_mgr_ (buff_mgr) {}

  // TODO: Should fetch the page from the buffer pool
  // Should store a reference to the page in a Vec
  // Should return a reference to the TableHeap
  TableHeap& table_heap_for(table_oid_t table_oid);

  bool insert_tuple(CRef<Tuple> tuple,
                    table_oid_t table_oid,
                    Txn& txn)
  {
    return table_heap_for(table_oid).insert_tuple(tuple, txn);
  }

private:
  CRef<DiskMgr> disk_mgr_;
  CRef<BuffMgr> buff_mgr_;
  // TODO: This mapping is populated on initial DB start up
  // It is also populated during `table_heap_for` if necessary.
  MutMap<table_oid_t, page_id_t> table_heaps_;
};
