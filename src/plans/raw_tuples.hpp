#pragma once

#include "value/value.hpp"
#include "tuple/value_map.hpp"
#include "exprs/value_map_list_expr.hpp"

class RawTuples {
public:
  using Data = vector<ValueMap>;

  RawTuples() = default;
  RawTuples(Data data)
    : data_ (data)
  {}

  RawTuples(ValueMapListExpr expr) {
    for (const auto &value_map_expr : expr.list()) {
      data_.push_back(value_map_expr.to_value_map());
    }
  }

  // Allow copy constructor
  RawTuples(const RawTuples&) = default;
  // Allow copy assign constructor
  RawTuples& operator=(const RawTuples&) = default;
  // Default destructor
  ~RawTuples() = default;

  Data
  data() {
    return data_;
  }

  const string
  to_string() const {
    stringstream os;
    for (const auto &value_map : data_) {
      for (const auto &[column_oid, value] : value_map) {
        os << column_oid << " => " << value.to_string() << "; ";
      }
      os << std::endl;
    }
    return os.str();
  }

  class Iterator {
  public:
    Iterator(Data::const_iterator iter)
      : iter_(iter) {}

    const ValueMap&
    value_map() {
      return *iter_;
    }

    Iterator& operator++() {
      ++iter_;
      return *this;
    }

    bool
    operator==(const Iterator& other) const { return iter_ == other.iter_; }
    bool
    operator!=(const Iterator& other) const { return iter_ != other.iter_; }

  private:
    Data::const_iterator iter_;
  };

  Iterator
  begin() const { return Iterator(data_.begin()); }
  Iterator
  end()   const { return Iterator(data_.end());   }

  int32_t
  size() const {
    return data_.size();
  }

  bool
  empty() const {
    return data_.size() == 0;
  }

private:
  Data data_;
};
