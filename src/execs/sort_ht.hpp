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
    logger->debug("INSERT INTO BUCKET -- SortKey: " + key.to_string());
    table_[key].push_back(tuple);
  }

  size_t size() const {
    return table_.size();
  }

  const Table& table() const {
    return table_;
  }

  void merge_sort(UNUSED const string direction) {
    // TODO!
  }

  class Iterator {
  public:
    explicit Iterator(Table::iterator table_iter,
                      int32_t index,
                      int32_t size)
      : table_iter_  (table_iter),
        index_       (index),
        size_        (size)
    {}

    bool has_next() const {
      return count_ < size_;
    }

    Tuple tuple() const {
      int32_t size = table_iter_->second.size();
      assert(index_ < size);
      assert(index_ >= 0);
      return table_iter_->second[index_];
    }

    bool operator==(const Iterator& other) const {
      return
        table_iter_ == other.table_iter_ &&
        index_      == other.index_;
    }

    Iterator& operator++() {
      ++count_;
      ++index_;
      int32_t size = table_iter_->second.size();
      if (index_ == size) {
        ++table_iter_;
        index_ = 0;
      }
      return *this;
    }

  private:
    Table::iterator table_iter_;
    int32_t index_;
    int32_t count_ = 0;
    int32_t size_ = 0;
  };

  class RIterator {
  public:
    explicit RIterator(Table::reverse_iterator table_iter,
                       int32_t index,
                       int32_t size)
      : table_iter_  (table_iter),
        index_       (index),
        size_        (size)
    {}

    bool has_next() const {
      return count_ < size_;
    }

    Tuple tuple() const {
      int32_t size = table_iter_->second.size();
      assert(index_ < size);
      assert(index_ >= 0);
      return table_iter_->second[index_];
    }

    bool operator==(const RIterator& other) const {
      return
        table_iter_ == other.table_iter_ &&
        index_      == other.index_;
    }

    RIterator& operator++() {
      ++count_;
      --index_;
      if (index_ < 0) {
        ++table_iter_;
        index_ = table_iter_->second.size() - 1;
      }
      return *this;
    }

  private:
    Table::reverse_iterator table_iter_;
    int32_t index_;
    int32_t count_ = 0;
    int32_t size_;
  };


  Iterator begin() {
    return Iterator(table_.begin(), 0, size());
  }

  Iterator end() {
    return Iterator(table_.end(),
                    table_.end()->second.size(),
                    size());
  }

  RIterator rbegin() {
    return RIterator(table_.rbegin(),
                     table_.rbegin()->second.size()-1,
                     size());
  }

  RIterator rend() {
    return RIterator(table_.rend(), -1, size());
  }

private:
  Table table_ {};
};
