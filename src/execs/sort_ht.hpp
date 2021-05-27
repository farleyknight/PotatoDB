#pragma once

#include "common/config.hpp"
#include "plans/sort_plan.hpp"
#include "plans/sort_key.hpp"

class SortHT {
public:
  SortHT() {}

  using Bucket = vector<Tuple>;
  using Table  = ordered_map<SortKey, Bucket>;

  void insert_into_bucket(SortKey key, Tuple tuple) {
    table_[key].push_back(tuple);
  }

  void merge_sort(UNUSED const string direction) {
    // TODO!
  }

  class Iterator {
  public:
    explicit Iterator(Table::iterator table_iter,
                      Bucket::iterator bucket_iter)
      : table_iter_  (table_iter),
        bucket_iter_ (bucket_iter)
    {}

    Tuple tuple() const {
      return *bucket_iter_;
    }

    bool operator==(const Iterator& other) const {
      return
        table_iter_ == other.table_iter_ &&
        bucket_iter_ == other.bucket_iter_;
    }

    bool operator!=(const Iterator& other) const {
      return
        table_iter_ != other.table_iter_ ||
        bucket_iter_ != other.bucket_iter_;
    }

    Iterator& operator--() {
      if (bucket_iter_ != table_iter_->second.begin()) {
        --bucket_iter_;
      } else {
        --table_iter_;
        bucket_iter_ = table_iter_->second.end();
      }
      return *this;
    }

    Iterator operator--(int) {
      auto tmp = *this;
      --(*this);
      return tmp;
    }

    Iterator& operator++() {
      if (bucket_iter_ != table_iter_->second.end()) {
        ++bucket_iter_;
      } else {
        ++table_iter_;
        bucket_iter_ = table_iter_->second.begin();
      }
      return *this;
    }

    Iterator operator++(int) {
      auto tmp = *this;
      ++(*this);
      return tmp;
    }

  private:
    Table::iterator table_iter_;
    Bucket::iterator bucket_iter_;
  };

  Iterator begin() {
    return Iterator(
      table_.begin(),
      table_.begin()->second.begin()
    );
  }

  Iterator end() {
    return Iterator(
      table_.end(),
      table_.end()->second.end()
    );
  }

private:
  Table table_ {};
};
