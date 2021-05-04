#pragma once

#include "catalog/schema_ref.hpp"
#include "query/base_query.hpp"
#include "query/query_column.hpp"

enum class JoinSide {
  INVALID = 0,
  LEFT    = 1,
  RIGHT   = 2
};

class QueryJoin : public BaseQuery {
public:
  QueryJoin()
    : BaseQuery    (TypeId::INVALID),
      join_side_   (JoinSide::INVALID),
      column_name_ ("")
  {}

  QueryJoin(TypeId type_id,
            JoinSide side,
            String name)
    : BaseQuery     (type_id),
      join_side_    (side),
      column_name_  (move(name)) {}

  QueryJoin(CRef<QueryJoin>) = default; // Allow copy
  QueryJoin& operator=(CRef<QueryJoin>) = default; // Allow copy assign
  ~QueryJoin() = default; // Default delete

  static QueryJoin make_left(QueryColumn left) {
    return QueryJoin(left.type_id(), JoinSide::LEFT, left.name());
  }

  static QueryJoin make_left(TypeId type_id, String name) {
    return QueryJoin(type_id, JoinSide::LEFT, name);
  }

  static QueryJoin make_right(QueryColumn right) {
    return QueryJoin(right.type_id(), JoinSide::RIGHT, right.name());
  }

  static QueryJoin make_right(TypeId type_id, String name) {
    return QueryJoin(type_id, JoinSide::RIGHT, name);
  }

  Value eval(CRef<Tuple> tuple, CRef<QuerySchema> schema) const;
  Value eval_join(CRef<Tuple>  lt,
                  CRef<QuerySchema> ls,
                  CRef<Tuple>  rt,
                  CRef<QuerySchema> rs) const;

  Value eval_agg(UNUSED CRef<Vec<Value>> group_bys,
                 UNUSED CRef<Vec<Value>> aggs) const
  {
    throw NotImplementedException("eval_aggregate not implemented");
  }

  string to_string() const {
    std::ostringstream os;

    os << "Type id is :: " << Type::as_string(type_id()) << std::endl;
    os << "Join side is :: " << (int)join_side_ << std::endl;
    os << "Column name is :: " << column_name_ << std::endl;
    os << "\n";

    return os.str();
  }
  size_t column_index(CRef<QuerySchema> schema) const;

  JoinSide side() const  {
    return join_side_;
  }

private:
  JoinSide join_side_ = JoinSide::INVALID;
  string column_name_;
};

