#pragma once

#include "value/value.hpp"
#include "exprs/tuple_list_expr.hpp"

class RawTuples {
public:
  using Data = vector<vector<Value>>;

  // Default constructor
  RawTuples() = default;
  // Constructor to accept 2D vector of tuples
  RawTuples(Data data)
    : data_ (data)
  {}

  RawTuples(TupleListExpr expr) {
    for (const auto &tuple_expr : expr.list()) {
      vector<Value> raw_tuple;
      for (const auto &value_expr : tuple_expr.list()) {
        raw_tuple.push_back(value_expr.to_value());
      }
      data_.push_back(raw_tuple);
    }
  }

  // Allow copy constructor
  RawTuples(const RawTuples&) = default;
  // Allow copy assign constructor
  RawTuples& operator=(const RawTuples&) = default;
  // Default destructor
  ~RawTuples() = default;

  Data data() {
    return data_;
  }

  class Iterator {
  public:
    Iterator(Data::const_iterator iter)
      : iter_(iter) {}

    const vector<Value>& values() {
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
  Data data_;
};
