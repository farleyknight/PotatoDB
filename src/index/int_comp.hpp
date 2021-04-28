#pragma once

#include "index/comp.hpp"

class IntComp : public Comp<int> {
public:
  int operator()(int lhs, int rhs) const override { return lhs - rhs; }
};
