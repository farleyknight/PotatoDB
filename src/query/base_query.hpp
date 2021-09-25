#pragma once

#include <vector>
#include <functional>

#include "common/exceptions.hpp"
#include "value/value.hpp"

class Tuple;
class QuerySchema;
class TableSchema;

enum class QueryNodeType {
  BASE     = 0,
  COLUMN   = 1,
  CONST    = 2,
  COMP     = 3,
  AGG      = 4,
  JOIN     = 5,
  GROUP_BY = 6,
  HAVING   = 7,
  WHERE    = 8
};

class BaseQuery {
public:
  BaseQuery()
    : node_type_ (QueryNodeType::BASE),
      type_id_   (TypeId::INVALID)
  {}

  BaseQuery(QueryNodeType type, TypeId type_id)
    : node_type_ (type),
      type_id_   (type_id)
  {}

  // Allow copy
  BaseQuery(const BaseQuery&) = default;
  // Allow copy assign
  BaseQuery& operator=(const BaseQuery&) = default;
  // Default destructor
  virtual ~BaseQuery() = default;

  virtual Value
  eval_join(UNUSED const Tuple& lt, UNUSED const QuerySchema& ls,
            UNUSED const Tuple& rt, UNUSED const QuerySchema& rs) const
  {
    throw NotImplementedException("eval_join not implemented");
  }

  virtual Value
  eval_agg(UNUSED const QuerySchema& schema,
           UNUSED const vector<Value>& group_bys,
           UNUSED const vector<Value>& aggregates) const
  {
    throw NotImplementedException("eval_agg not implemented");
  }

  virtual Value
  eval(UNUSED const Tuple& tuple,
       UNUSED const QuerySchema& schema) const
  {
    throw NotImplementedException("eval not implemented");
  }

  virtual Value
  eval(UNUSED const Tuple& tuple,
       UNUSED const TableSchema& schema) const
  {
    throw NotImplementedException("eval not implemented");
  }

  TypeId type_id() const {
    return type_id_;
  }

  const string to_string() const {
    throw NotImplementedException("to_string not implemented");
  }

  // TODO: In the future, we may want to bind the parsed string to the `BaseQuery` as needed.
  // This will allow us to show a table in the console, where an expression is the string
  // representation of the expression, such as "2 + 2":
  //
  // SELECT name, addr, 2 + 2, phone FROM users;
  //
  // Result:
  //
  // name | addr | 2 + 2 | phone
  // ----------------------------
  // Blah | Blah | 4     | 234
  // Foo  | Bar  | 4     | 890
  //
  // Although that might be left to `to_string()`. Another case could be:
  //
  // SELECT name, addr, 2 + 2 AS int_sum, phone FROM users;
  //
  // Now an anonymous expression "2 + 2" has a name, `int_sum`, which means we would get:
  //
  // Result:
  //
  // name | addr | int_sum | phone
  // ----------------------------
  // Blah | Blah | 4       | 234
  // Foo  | Bar  | 4       | 890
  //
  string name() const {
    throw NotImplementedException("name is not implemented for BaseQuery");
  }

  QueryNodeType node_type() {
    return node_type_;
  }

protected:
  QueryNodeType node_type_;
  TypeId type_id_;
};
