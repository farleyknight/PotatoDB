#pragma once

enum class ExprType {
  // DQL Statement fragments/exprs
  // Data Query Language
  COLUMN,
  COLUMN_LIST,
  COLUMN_DEF,
  COLUMN_DEF_LIST,
  TABLE,
  TABLE_LIST,
  VALUE,
  TUPLE,
  TUPLE_LIST,

  // DDL statement types
  // Data Definition Language
  CREATE_TABLE,
  ALTER_TABLE,
  DROP_TABLE,
  CREATE_INDEX,

  // Catalog statements
  SHOW_TABLES,
  DESCRIBE_TABLE,

  // DML statement types
  // Data Manipulation Language
  SELECT,
  COMPOUND_SELECT,
  WHERE, COMPARE,
  AGG, AGG_LIST,
  LIMIT,
  ORDER_BY,
  GROUP_BY,
  HAVING,
  INSERT,
  UPDATE,
  DELETE_FROM
};
