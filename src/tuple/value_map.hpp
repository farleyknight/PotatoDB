#pragma once

class ValueMap {
public:
  using Mapping = map<column_oid_t, Value>;

  explicit
  ValueMap(int32_t size)
    : mapping_ (size)
  {}

  explicit
  ValueMap(Mapping mapping)
    : mapping_ (mapping)
  {}

  explicit
  ValueMap(RID rid,
           Mapping mapping)
    : mapping_ (mapping),
      rid_     (rid)
  {}

  static ValueMap
  invalid() {
    return ValueMap(0);
  }

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
  at(column_oid_t oid) const {
    return mapping_.at(oid);
  }

  vector<column_oid_t>
  oids() const {
    vector<column_oid_t> oids;
    for (const auto &[oid, value] : mapping_) {
      oids.push_back(oid);
    }
    return oids;
  }

  void
  erase(column_oid_t oid) {
    mapping_.erase(oid);
  }

private:
  map<column_oid_t, Value> mapping_;
  RID rid_ = RID::invalid();
};
