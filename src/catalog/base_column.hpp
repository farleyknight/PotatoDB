#pragma once

#include "types/type.hpp"

class BaseColumn {
public:
  virtual int32_t
  offset() const = 0;

  virtual bool
  is_inlined() const = 0;

  virtual TypeId
  type_id() const = 0;

  virtual int32_t
  fixed_length() const = 0;

  virtual int32_t
  variable_length() const = 0;

  virtual Value
  default_value() const = 0;

  virtual bool
  has_default() const = 0;
};
