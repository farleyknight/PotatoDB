#pragma once

enum class CompoundType {
  NONE        = 0,
  UNION       = 1,
  UNION_ALL   = 2,
  INTERSCTION = 3,
  EXCEPT      = 4
};

class CompoundSelectExpr : public BaseExpr {
public:
  CompoundSelectExpr()
    : BaseExpr (ExprType::COMPOUND_SELECT)
  {}

  void set_left(SelectExpr left) {
    left_ = left;
  }

  void set_right(SelectExpr right) {
    right_ = right;
  }

private:
  // TODO
  // left & right select
  // comp_type
  SelectExpr left_, right_;
  CompoundType comp_type_ = CompoundType::NONE;
};
