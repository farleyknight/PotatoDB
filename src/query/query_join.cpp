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

const string QueryJoin::to_string() const {
  std::ostringstream os;

  os << "Type id is :: " << Type::as_string(type_id()) << std::endl;
  os << "Join side is :: " << (int)join_side_ << std::endl;
  os << "Column name is :: " << column_name_ << std::endl;
  os << "\n";

  return os.str();
}
