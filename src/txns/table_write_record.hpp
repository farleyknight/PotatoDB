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
  /**********************************************
  * Constructors & destructor
  **********************************************/

  // NOTE: We are intentionally copying the RID, WType, and Tuple here,
  TableWriteRecord(RID rid,
                   WType wtype,
                   Tuple tuple,
                   CRef<TableHeapRef> table_heap_ref)
    : rid_            (rid),
      wtype_          (wtype),
      tuple_          (tuple),
      table_heap_ref_ (table_heap_ref) {}

  static MutList<TableWriteRecord> make_list() {
    return MutList<TableWriteRecord>();
  }

  /**********************************************
  * Instance methods
  **********************************************/

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

  MRef<RID> rid() {
    return rid_;
  }

  CRef<Tuple> tuple() {
    return tuple_;
  }

  CRef<TableHeapRef> table() {
    return table_heap_ref_;
  }

private:
  RID rid_;
  WType wtype_;
  /** The tuple is only used for the update operation. */
  Tuple tuple_;
  /** The table heap specifies which table this write record is for. */
  CRef<TableHeapRef> table_heap_ref_;
};
