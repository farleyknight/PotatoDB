#pragma once

#include "query/base_query.hpp"
#include "query/query_column.hpp"
#include "query/query_join.hpp"
#include "plans/nested_loop_join_plan.hpp"

class NestedLoopJoinExec : public BaseExec {
 public:

  NestedLoopJoinExec(ExecCtx& exec_ctx,
                     MovePtr<NestedLoopJoinPlan> plan,
                     MovePtr<BaseExec> left,
                     MovePtr<BaseExec> right)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      left_    (move(left)),
      right_   (move(right)) {}

  static Ptr<BaseExec> make(ExecCtx& exec_ctx,
                            MovePtr<NestedLoopJoinPlan> plan,
                            MovePtr<BaseExec> left,
                            MovePtr<BaseExec> right)
  {
    return make_unique<NestedLoopJoinExec>(exec_ctx,
                                           move(plan),
                                           move(left),
                                           move(right));
  }

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

  Tuple next() override {
    while (left_->has_next()) {
      auto left_tuple = left_->next();
      while (right_->has_next()) {
        auto right_tuple = right_->next();
        if (join_matches(left_tuple, right_tuple)) {
          return combine_tuples(left_tuple, right_tuple);
        }
      }
      // NOTE: After we have iterated though all of the tuples in `right_` then we need
      // to "reset" `right_`
      right_->init();
    }

    // TODO: Should never reach here!
    return Tuple();
  }

  bool join_matches(CRef<Tuple> left, CRef<Tuple> right) {
    if (!plan_->has_pred()) {
      return true;
    }

    auto pred = plan_->pred();

    auto &left_schema =
      exec_ctx_.catalog().find_query_schema(plan_->left_schema_ref());

    auto &right_schema =
      exec_ctx_.catalog().find_query_schema(plan_->right_schema_ref());

    Value match
      = pred.eval_join(left,  left_schema,
                       right, right_schema);
    return match.as<bool>();
  }

  Tuple combine_tuples(CRef<Tuple> left, CRef<Tuple> right) {
    vector<Value> values;

    auto &schema =
      exec_ctx_.catalog().find_query_schema(plan_->schema_ref());

    for (auto col : schema.all()) {
      CRef<QueryJoin> join = col.join();

      JoinSide side = join.side();

      if (side == JoinSide::LEFT) {
        auto &left_schema =
          exec_ctx_.catalog().find_query_schema(plan_->left_schema_ref());

        values.push_back(left.value_by_name(left_schema,
                                            col.name()));
      } else if (side == JoinSide::RIGHT) {
        auto &right_schema =
          exec_ctx_.catalog().find_query_schema(plan_->right_schema_ref());

        values.push_back(right.value_by_name(right_schema,
                                             col.name()));
      } else if (side == JoinSide::INVALID) {
        throw Exception("Cannot combine tuples with INVALID_SIDE!");
      }
    }

    return Tuple(move(values), schema);
  }

private:
  Ptr<NestedLoopJoinPlan> plan_;
  Ptr<BaseExec> left_;
  Ptr<BaseExec> right_;
};
