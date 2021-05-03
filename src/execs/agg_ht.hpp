#pragma once

#include "common/config.hpp"
#include "plans/agg_plan.hpp"

/**
 * A simplified hash table that has all the necessary functionality for aggregations.
 */
class AggHT {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  AggHT(CRef<AggPlan> plan) {
    for (const auto &node : plan.aggs()) {
      nodes_.emplace_back(node);
    }

    for (const auto &type : plan.agg_types()) {
      types_.emplace_back(type);
    }

    assert(nodes_.size() == types_.size());
  }

  /**********************************************
   * Instance methods
   **********************************************/

  AggValue generate() {
    MutVec<Value> values;
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
          // Count increases by one.
          result.aggs_[i] = result.aggs_[i].add(Value(TypeId::INTEGER, 1));
          break;
        case AggType::SUM:
          // Sum increases by addition.
          result.aggs_[i] = result.aggs_[i].add(input.aggs_[i]);
          break;
        case AggType::MIN:
          // Min is just the min.
          result.aggs_[i] = result.aggs_[i].min(input.aggs_[i]);
          break;
        case AggType::MAX:
          // Max is just the max.
          result.aggs_[i] = result.aggs_[i].max(input.aggs_[i]);
          break;
      }
    }
  }

  void insert_combine(CRef<AggKey> key, AggValue& val) {
    if (table_.count(key) == 0) {
      table_.insert({key, generate()});
    }
    combine(table_.at(key), val);
  }

  /**********************************************
   * Iterator class
   **********************************************/
  class Iterator {
  public:
    /**********************************************
     * Constructors & destructor
     **********************************************/

    /** Creates an iterator for the aggregate map. */
    explicit Iterator(Map<AggKey, AggValue>::const_iterator iter)
      : iter_(iter) {}

    /**********************************************
     * Instance methods
     **********************************************/

    CRef<AggKey> key() { return iter_->first; }

    CRef<AggValue> val() { return iter_->second; }

    Iterator &operator++() {
      ++iter_;
      return *this;
    }

    bool operator==(CRef<Iterator> other) const {
      return iter_ == other.iter_;
    }
    bool operator!=(CRef<Iterator> other) const {
      return iter_ != other.iter_;
    }

  private:
    Map<AggKey, AggValue>::const_iterator iter_;
  };

  /**********************************************
   * Iterator methods
   **********************************************/

  Iterator begin() const { return Iterator {table_.cbegin()}; }
  Iterator end()   const { return Iterator {table_.cend()}; }

private:
  MutMap<AggKey, AggValue> table_ {};
  MutVec<BaseQuery> nodes_;
  MutVec<AggType> types_;
};