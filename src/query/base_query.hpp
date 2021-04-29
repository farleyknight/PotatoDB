#pragma once

#include <vector>
#include <functional>

#include "value/value.hpp"

class Tuple;
class QuerySchema;

class BaseQuery {
public:
  BaseQuery() : type_id_{TypeId::INVALID} {}
  BaseQuery(TypeId type_id) : type_id_{type_id} {}

  // Allow copy
  BaseQuery(CRef<BaseQuery>) = default;
  // Allow copy assign
  BaseQuery& operator=(CRef<BaseQuery>) = default;
  // Default destructor
  ~BaseQuery() = default;

  Value eval_join(UNUSED CRef<Tuple> lt, UNUSED CRef<QuerySchema> ls,
                  UNUSED CRef<Tuple> rt, UNUSED CRef<QuerySchema> rs)
    const
  {
    throw NotImplementedException("eval_join not implemented");
  }

  Value eval_agg(UNUSED CRef<QuerySchema> schema,
                 UNUSED CRef<Vec<Value>> group_bys,
                 UNUSED CRef<Vec<Value>> aggregates) const {
    throw NotImplementedException("eval_agg not implemented");
  }

  Value eval(UNUSED CRef<Tuple> tuple,
             UNUSED CRef<QuerySchema> schema) const {
    throw NotImplementedException("eval not implemented");
  }

  TypeId type_id() const {
    return type_id_;
  }

  string to_string() const {
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

protected:
  TypeId type_id_;
};
