#pragma once

#include "page/page_id.hpp"
#include "value/value.hpp"

class RawTuples {
public:
  using Data = vector<vector<Value>>;

  // Default constructor
  RawTuples() = default;
  // Constructor to accept 2D vector of tuples
  RawTuples(Data data)
    : data_ (data)
  {}

  // Allow copy constructor
  RawTuples(const RawTuples&) = default;
  // Allow copy assign constructor
  RawTuples& operator=(const RawTuples&) = default;
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

    const Vec<Value>& values() {
      return *iter_;
    }

    Iterator& operator++() {
      ++iter_;
      return *this;
    }

    bool operator==(const Iterator& other) { return iter_ == other.iter_; }
    bool operator!=(const Iterator& other) { return iter_ != other.iter_; }

  private:
    Data::const_iterator iter_;
  };

  Iterator begin() const { return Iterator(data_.begin()); }
  Iterator end()   const { return Iterator(data_.end());   }

  bool empty() {
    return data_.size() == 0;
  }

private:
  PageId page_id_;
  Data data_;
};
