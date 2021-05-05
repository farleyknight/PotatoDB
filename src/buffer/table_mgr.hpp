#pragma once

#include "disk/disk_mgr.hpp"
#include "buffer/buff_mgr.hpp"
#include "page/table_heap.hpp"

class TableMgr {
public:
  TableMgr(const DiskMgr& disk_mgr,
           const BuffMgr& buff_mgr)
    : disk_mgr_ (disk_mgr),
      buff_mgr_ (buff_mgr)
  {}

  TableHeap& table_heap_for(table_oid_t table_oid);

private:
  UNUSED const DiskMgr& disk_mgr_;
  UNUSED const BuffMgr& buff_mgr_;

  MutMap<table_oid_t, page_id_t> page_ids_;
  MutMap<table_oid_t, ptr<TableHeap>> table_heaps_;
};
