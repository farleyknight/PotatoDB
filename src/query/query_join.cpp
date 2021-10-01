#include "query/query_join.hpp"
#include "tuple/tuple.hpp"
#include "catalog/query_schema.hpp"

Value QueryJoin::eval(const Tuple& tuple,
                      const QuerySchema& schema) const
{
  return schema.layout().value_by_index(tuple, column_index(schema));
}

Value QueryJoin::eval_join(const Tuple&  lt,
                           const QuerySchema& ls,
                           const Tuple&  rt,
                           const QuerySchema& rs) const
{
  switch (join_side_) {
  case JoinSide::LEFT:
    return ls.layout().value_by_index(lt, column_index(ls));
  case JoinSide::RIGHT:
    return rs.layout().value_by_index(rt, column_index(rs));
  case JoinSide::INVALID:
    throw Exception("Cannot eval join with INVALID_SIDE!");
  }
}

column_index_t
QueryJoin::column_index(const QuerySchema& schema) const
{
  return schema.column_index_for(column_oid_);
}

const string QueryJoin::to_string() const {
  std::ostringstream os;

  os << "Type id is :: " << Type::as_string(type_id()) << std::endl;
  os << "Join side is :: " << (int)join_side_ << std::endl;
  os << "Column oid is :: " << column_oid_ << std::endl;
  os << "\n";

  return os.str();
}
