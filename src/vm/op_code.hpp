#pragma once

enum class OpCode {
  INVALID    = 0,
  LOAD_INT32 = 1,
  ADD_INT32  = 2,
  SUB_INT32  = 3,
  MUL_INT32  = 4,
  DIV_INT32  = 5,
  RETURN     = 99
};
