#pragma once

#include "common/config.hpp"
#include "plans/sort_plan.hpp"

class SortHT {
public:
  SortHT() {}

  using InternalTable = ordered_map<SortKey, vector<Tuple>>;

  void insert_into_bucket(SortKey key, Tuple tuple) {
    table_[key].push_back(tuple);
  }

  // TODO: Should iterate over InternalTable and iterate over each
  // `vector<Tuple>`. Likely this 2nd part is just going to be an
  // ordinary `index_t`
  class Iterator {
  public:
    explicit Iterator(InternalTable::iterator iter, index_t index)
      : iter_ (iter),
        index_ (index)
    {}

    bool operator==(Iterator& other) const {
      return iter_ == other.iter_ && index_ == other.index_;
    }

    bool operator!=(Iterator& other) const {
      return iter_ != other.iter_ || index_ != other.index_;
    }

    Iterator& operator++() {
      // TODO: We only increment `iter_` after index has reached the end
      // of vector.
      ++iter_;
      return *this;
    }

    Iterator operator++(int) {
      auto tmp = *this;
      ++(*this);
      return tmp;
    }

  private:
    InternalTable::iterator iter_;
    index_t index_;
  };

  Iterator begin() {
    return Iterator {table_.begin(), 0};
  }

  Iterator end()   {
    return Iterator {table_.end(), -1};
  }

private:
  InternalTable table_ {};
};
