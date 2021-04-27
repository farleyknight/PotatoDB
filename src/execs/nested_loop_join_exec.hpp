#pragma once

#include "exprs/base_expr.hpp"
#include "exprs/column_expr.hpp"
#include "plans/nested_loop_join_plan.hpp"

class NestedLoopJoinExec : public BaseExec {
 public:

  NestedLoopJoinExec(MRef<ExecCtx> exec_ctx,
                     MovePtr<NestedLoopJoinPlan> plan,
                     MovePtr<BaseExec> left,
                     MovePtr<BaseExec> right)
    : BaseExec (exec_ctx),
      plan_    (move(plan)),
      left_    (move(left)),
      right_   (move(right)) {}

  static Ptr<BaseExec> make(MRef<ExecCtx> exec_ctx,
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

  bool join_matches(Ref<Tuple> left, Ref<Tuple> right) {
    if (!plan_->has_pred()) {
      return true;
    }

    auto &pred = plan_->pred();

    Value match
      = pred.eval_join(left,  plan_->left_schema(),
                       right, plan_->right_schema());
    return match.get_as<bool>();
  }

  Tuple combine_tuples(Ref<Tuple> left, Ref<Tuple> right) {
    MutVec<Value> values;
    for (Ref<Column> col : plan_->schema().columns()) {
      Ref<ColumnExpr> expr =
        dynamic_cast<Ref<ColumnExpr>>(col.expr());

      JoinSide side = expr.join_side();

      if (side == JoinSide::LEFT) {
        values.push_back(left.value_by_name(plan_->left_schema(),
                                            col.name()));
      } else if (side == JoinSide::RIGHT) {
        values.push_back(right.value_by_name(plan_->right_schema(),
                                             col.name()));
      } else if (side == JoinSide::INVALID) {
        throw Exception("Cannot combine tuples with INVALID_SIDE!");
      }
    }

    return Tuple(move(values), plan_->schema());
  }

private:
  /** The NestedLoop plan node to be executed. */
  Ptr<NestedLoopJoinPlan> plan_;
  Ptr<BaseExec> left_;
  Ptr<BaseExec> right_;
};
