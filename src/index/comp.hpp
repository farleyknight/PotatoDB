#pragma once

#include "common/exceptions.hpp"

template <class K>
class Comp {
public:
  virtual int operator()(UNUSED K lhs, UNUSED K rhs) const {
    throw NotImplementedException("not implemented");
  }
};
