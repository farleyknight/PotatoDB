#include "query/query_join.hpp"
#include "tuple/tuple.hpp"

Value QueryJoin::eval(CRef<Tuple> tuple, CRef<QuerySchema> schema) const {
  return tuple.value(schema, column_index(schema));
}

Value QueryJoin::eval_join(CRef<Tuple>  lt,
                           CRef<QuerySchema> ls,
                           CRef<Tuple>  rt,
                           CRef<QuerySchema> rs) const
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

size_t QueryJoin::column_index(CRef<QuerySchema> schema) const {
  return schema.offset_for(column_name_);
}

