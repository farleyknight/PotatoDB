#pragma once

using oper_index_t = int32_t;
const oper_index_t INVALID_OPER_INDEX = -1;

class HasChildOper {
public:
  HasChildOper(oper_index_t index)
    : child_index_ (index)
  {}

  HasChildOper()
    : child_index_ (INVALID_OPER_INDEX)
  {}

  void set_child_index(oper_index_t index) {
    child_index_ = index;
  }

protected:
  oper_index_t child_index_;
};
