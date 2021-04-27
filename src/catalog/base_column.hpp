#pragma once

#include "types/type.hpp"

class BaseColumn {
public:
  virtual size_t offset() const = 0;
  virtual bool is_inlined() const = 0;
  virtual TypeId type_id() const = 0;
  virtual size_t fixed_length() const = 0;
  virtual size_t variable_length() const = 0;
};
