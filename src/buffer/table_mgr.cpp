
#include "buffer/table_mgr.hpp"

TableHeap& TableMgr::table_heap_for(table_oid_t table_oid) {
  return *table_heaps_[table_oid];
}
