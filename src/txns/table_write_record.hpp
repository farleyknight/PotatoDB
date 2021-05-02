#pragma once

#include <deque>

#include "tuple/tuple.hpp"
#include "tuple/rid.hpp"

#include "table/table_heap_ref.hpp"

enum class WType {
  INSERT = 0,
  DELETE = 1,
  UPDATE = 2
};

class TableWriteRecord {
public:
  // NOTE: We are intentionally copying the RID, WType, and Tuple here,
  TableWriteRecord(RID rid,
                   WType wtype,
                   Tuple tuple,
                   table_oid_t table_oid)
    : rid_       (rid),
      wtype_     (wtype),
      tuple_     (tuple),
      table_oid_ (table_oid) {}

  static MutList<TableWriteRecord> make_list() {
    return MutList<TableWriteRecord>();
  }

  bool is_delete() {
    return wtype_ == WType::DELETE;
  }

  bool is_insert() {
    return wtype_ == WType::INSERT;
  }

  bool is_update() {
    return wtype_ == WType::UPDATE;
  }

  WType wtype() {
    return wtype_;
  }

  RID& rid() {
    return rid_;
  }

  Tuple& tuple() {
    return tuple_;
  }

  CRef<Tuple> tuple() const {
    return tuple_;
  }

  table_oid_t table_oid() {
    return table_oid_;
  }

private:
  RID rid_;
  WType wtype_;
  Tuple tuple_;
  table_oid_t table_oid_;
};
