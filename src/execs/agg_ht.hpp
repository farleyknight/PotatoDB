#pragma once

#include "common/config.hpp"
#include "plans/agg_plan.hpp"

class AggHT {
public:
  AggHT() {}

  using InternalTable = map<AggKey, AggValue>;

  void init(const ptr<AggPlan>& plan) {
    assert(plan != nullptr);
    for (const auto &node : plan->aggs()) {
      nodes_.emplace_back(node);
    }

    for (const auto &type : plan->agg_types()) {
      types_.emplace_back(type);
    }

    assert(nodes_.size() == types_.size());
  }

  AggValue generate() {
    vector<Value> values;
    for (const auto &type : types_) {
      switch (type) {
        case AggType::COUNT:
          // Count starts at zero.
          values.emplace_back(Value(TypeId::INTEGER, 0));
          break;
        case AggType::SUM:
          // Sum starts at zero.
          values.emplace_back(Value(TypeId::INTEGER, 0));
          break;
        case AggType::MIN:
          // Min starts at INT_MAX.
          values.emplace_back(Value(TypeId::INTEGER, Int32::MAX));
          break;
        case AggType::MAX:
          // Max starts at INT_MIN.
          values.emplace_back(Value(TypeId::INTEGER, Int32::MIN));
          break;
      }
    }
    return {values};
  }

  void combine(AggValue& result, AggValue& input) {
    for (size_t i = 0; i < nodes_.size(); ++i) {
      switch (types_[i]) {
        case AggType::COUNT:
          result.aggs_[i] = result.aggs_[i].add(Value(TypeId::INTEGER, 1));
          break;
        case AggType::SUM:
          result.aggs_[i] = result.aggs_[i].add(input.aggs_[i]);
          break;
        case AggType::MIN:
          result.aggs_[i] = result.aggs_[i].min(input.aggs_[i]);
          break;
        case AggType::MAX:
          result.aggs_[i] = result.aggs_[i].max(input.aggs_[i]);
          break;
      }
    }
  }

  void insert_combine(const AggKey& key, AggValue& val) {
    if (table_.count(key) == 0) {
      table_.insert({key, generate()});
    }
    combine(table_.at(key), val);
  }

  class Iterator {
  public:
    explicit Iterator(InternalTable::iterator iter)
      : iter_(iter) {}

    const AggKey& key() {
      return iter_->first;
    }

    const AggValue& val() {
      return iter_->second;
    }

    Iterator& operator++() {
      ++iter_;
      return *this;
    }

    Iterator operator++(int) {
      auto tmp = *this;
      ++(*this);
      return tmp;
    }

    bool operator==(Iterator& other) const {
      return iter_ == other.iter_;
    }

    bool operator!=(Iterator& other) const {
      return iter_ != other.iter_;
    }

  private:
    InternalTable::iterator iter_;
  };

  Iterator begin() { return Iterator {table_.begin()}; }
  Iterator end()   { return Iterator {table_.end()}; }

private:
  InternalTable table_ {};
  vector<BaseQuery> nodes_;
  vector<AggType> types_;
};
