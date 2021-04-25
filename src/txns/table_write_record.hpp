#pragma once

#include <deque>

#include "tuple/tuple.hpp"
#include "tuple/rid.hpp"

class TableHeap;

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
                   Ref<TableHeap> table)
    : rid_(rid),
      wtype_(wtype),
      tuple_(tuple),
      table_(table) {}

  static List<TableWriteRecord> make_list() {
    return std::list<TableWriteRecord>();
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

  MutRef<RID> rid() {
    return rid_;
  }

  Ref<Tuple> tuple() {
    return tuple_;
  }

  Ref<TableHeap> table() {
    return table_;
  }

private:
  RID rid_;
  WType wtype_;
  /** The tuple is only used for the update operation. */
  Tuple tuple_;
  /** The table heap specifies which table this write record is for. */
  CRef<TableHeap> table_;
};
