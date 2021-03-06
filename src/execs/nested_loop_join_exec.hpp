#pragma once

#include "query/base_query.hpp"
#include "query/query_column.hpp"
#include "query/query_join.hpp"
#include "plans/nested_loop_join_plan.hpp"

class NestedLoopJoinExec : public BaseExec {
public:
  NestedLoopJoinExec(ExecCtx& exec_ctx,
                     ptr<NestedLoopJoinPlan>&& plan,
                     ptr<BaseExec>&& left,
                     ptr<BaseExec>&& right)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      left_    (move(left)),
      right_   (move(right)) {}


  void init() override {
    left_->init();
    right_->init();
  }

  bool has_next() override {
    if (left_->has_next()) {
      return right_->has_next();
    }
    return false;
  }

  Tuple
  next_tuple() override {
    while (left_->has_next()) {
      auto left_tuple = left_->next_tuple();
      while (right_->has_next()) {
        auto right_tuple = right_->next_tuple();
        if (join_matches(left_tuple, right_tuple)) {
          return combine_tuples(left_tuple, right_tuple);
        }
      }
      // NOTE: After we have iterated though all of the tuples in `right_` then we need
      // to "reset" `right_`
      right_->init();
    }

    // TODO: Should never reach here!
    return Tuple(TupleSources::TABLE_HEAP);
  }

  ValueMap
  next_value_map() override {
    // TODO: Finish me!
    return ValueMap::invalid();
  }

  bool join_matches(const Tuple& left,
                    const Tuple& right) {
    if (!plan_->has_pred()) {
      return true;
    }

    auto &pred = plan_->pred();

    auto left_schema  = plan_->left_schema();
    auto right_schema = plan_->right_schema();

    Value match
      = pred.eval_join(left,  left_schema,
                       right, right_schema);
    return match.as<bool>();
  }

  Tuple
  combine_tuples(const Tuple& left,
                 const Tuple& right)
  {
    auto &schema = plan_->schema();
    ValueMap value_map(schema.joins().size());

    for (auto join : schema.joins()) {
      JoinSide side = join.side();

      auto name = join.name();
      if (side == JoinSide::LEFT) {
        value_map.emplace(join.column_oid(),
                          plan_->left_schema().layout().value_by_name(left, name));
      } else if (side == JoinSide::RIGHT) {
        value_map.emplace(join.column_oid(),
                          plan_->right_schema().layout().value_by_name(right, name));
      } else if (side == JoinSide::INVALID) {
        throw Exception("Cannot combine tuples with INVALID_SIDE!");
      }
    }

    return schema.layout().make(value_map, exec_ctx().txn());
  }

  const string
  message_on_completion(int32_t result_count) const override {
    return "Found " + std::to_string(result_count) + " record(s)";
  }

private:
  ptr<NestedLoopJoinPlan> plan_;
  ptr<BaseExec> left_;
  ptr<BaseExec> right_;
};
