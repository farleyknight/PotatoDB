#include "query/query_join.hpp"
#include "tuple/tuple.hpp"

Value QueryJoin::eval(const Tuple& tuple,
                      const QuerySchema& schema) const
{
  return tuple.value(schema, column_index(schema));
}

Value QueryJoin::eval_join(const Tuple&  lt,
                           const QuerySchema& ls,
                           const Tuple&  rt,
                           const QuerySchema& rs) const
{
  switch (join_side_) {
  case JoinSide::LEFT:
    return lt.value(ls, column_index(ls));
  case JoinSide::RIGHT:
    return rt.value(rs, column_index(rs));
  case JoinSide::INVALID:
    throw Exception("Cannot eval join with INVALID_SIDE!");
  }
}

column_index_t QueryJoin::column_index(const QuerySchema& schema) const {
  return schema.buffer_offset_for(column_name_);
}
