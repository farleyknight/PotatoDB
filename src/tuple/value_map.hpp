#pragma once

class ValueMap {
public:
  using Mapping = map<column_oid_t, Value>;

  ValueMap(int32_t size)
    : mapping_ (size)
  {}

  ValueMap(Mapping mapping)
    : mapping_ (mapping)
  {}

  ValueMap(RID rid,
           Mapping mapping)
    : mapping_ (mapping),
      rid_     (rid)
  {}

  Mapping::iterator
  begin() {
    return mapping_.begin();
  }

  Mapping::iterator
  end() {
    return mapping_.end();
  }

  Mapping::const_iterator
  begin() const {
    return mapping_.cbegin();
  }

  Mapping::const_iterator
  end() const {
    return mapping_.cend();
  }

  bool
  contains(column_oid_t oid) {
    return mapping_.contains(oid);
  }

  void
  reserve(int32_t size) {
    mapping_.reserve(size);
  }

  void
  set_rid(RID rid) {
    rid_ = rid;
  }

  RID
  rid() const {
    return rid_;
  }

  void
  emplace(column_oid_t oid,
          const Value&& value)
  {
    mapping_.emplace(oid, move(value));
  }

  const Value
  at(column_oid_t oid) {
    return mapping_.at(oid);
  }

private:
  map<column_oid_t, Value> mapping_;
  RID rid_ = RID::invalid();
};
