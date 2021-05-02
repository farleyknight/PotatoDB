#pragma once

#include "disk/disk_mgr.hpp"
#include "buffer/buff_mgr.hpp"
#include "page/table_heap.hpp"

class TableMgr {
public:
  TableMgr(CRef<DiskMgr> disk_mgr,
           CRef<BuffMgr> buff_mgr)
    : disk_mgr_ (disk_mgr),
      buff_mgr_ (buff_mgr)
  {}

  TableHeap& table_heap_for(table_oid_t table_oid);

private:
  CRef<DiskMgr> disk_mgr_;
  CRef<BuffMgr> buff_mgr_;

  MutMap<table_oid_t, page_id_t> page_ids_;
  MutMap<table_oid_t, MutPtr<TableHeap>> table_heaps_;
};
