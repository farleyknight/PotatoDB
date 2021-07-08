#pragma once

#include "execs/base_exec.hpp"

class HasChildExec {
public:
  HasChildExec(ptr<BaseExec>&& child)
    : child_ (move(child))
  {}

  const ptr<BaseExec>& child() {
    return child_;
  }

protected:
  ptr<BaseExec> child_;
};
