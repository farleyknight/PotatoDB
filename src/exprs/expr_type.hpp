#pragma once

enum class ExprType {
  // Statement fragments/exprs
  COLUMN,
  COLUMN_LIST,
  COLUMN_DEF,
  COLUMN_DEF_LIST,
  TABLE,
  TABLE_LIST,
  VALUE,
  TUPLE,
  TUPLE_LIST,

  // Statement types
  SELECT,
  WHERE,
  LIMIT,
  ORDER_BY,
  GROUP_BY,
  HAVING,

  INSERT,

  CREATE_TABLE,
};


