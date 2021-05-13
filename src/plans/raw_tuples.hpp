#pragma once

#include "value/value.hpp"
#include "exprs/tuple_list_expr.hpp"

class RawTuples {
public:
  using Data = vector<vector<Value>>;

  RawTuples() = default;
  RawTuples(Data data)
    : data_ (data)
  {}

  RawTuples(TupleListExpr expr) {
    for (const auto &tuple_expr : expr.list()) {
      vector<Value> raw_tuple;
      for (const auto &value_expr : tuple_expr.list()) {
        auto value = value_expr.to_value();
        std::cout << "Got value " << value.to_string() << std::endl;
        // TODO! What is the type for this value?
        // That needs to be addressed somewhere..
        raw_tuple.push_back(value);
      }
      data_.push_back(raw_tuple);
    }
  }

  const string to_string() const {
    stringstream os;
    for (const auto &row : data_) {
      for (const auto &value : row) {
        os << value.to_string() << ",";
      }
      os << ";" << std::endl;
    }
    return os.str();
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

  size_t size() const {
    return data_.size();
  }

  bool empty() const {
    return data_.size() == 0;
  }

private:
  Data data_;
};
