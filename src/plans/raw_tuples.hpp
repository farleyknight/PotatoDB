#pragma once

#include "value/value.hpp"

class RawTuples {
public:
  using Data = MutVec<MutVec<Value>>;

  // Default constructor
  RawTuples() = default;
  // Constructor to accept 2D vector of tuples
  RawTuples(PageId page_id)
    : page_id_ (page_id)
  {}

  // Allow copy constructor
  RawTuples(CRef<RawTuples>) = default;
  // Allow copy assign constructor
  RawTuples& operator=(CRef<RawTuples>) = default;
  // Default destructor
  ~RawTuples() = default;

  PageId page_id() {
    return page_id_;
  }

  Data data() {
    return data_;
  }

  class Iterator {
  public:
    Iterator(Data::const_iterator iter)
      : iter_(iter) {}

    CRef<Vec<Value>> values() {
      return *iter_;
    }

    Iterator& operator++() {
      ++iter_;
      return *this;
    }

    bool operator==(CRef<Iterator> other) { return iter_ == other.iter_; }
    bool operator!=(CRef<Iterator> other) { return iter_ != other.iter_; }

  private:
    Data::const_iterator iter_;
  };

  Iterator begin() const { return Iterator(data_.begin()); }
  Iterator end()   const { return Iterator(data_.end());   }

private:
  PageId page_id_;
  Data data_;
};
