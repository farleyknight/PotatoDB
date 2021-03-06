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
    : BaseQuery   (QueryNodeType::JOIN, TypeId::INVALID),
      join_side_  (JoinSide::INVALID),
      column_oid_ (INVALID_COLUMN_OID)
  {}

  QueryJoin(TypeId type_id,
            JoinSide side,
            column_oid_t oid)
    : BaseQuery   (QueryNodeType::JOIN, type_id),
      join_side_  (side),
      column_oid_ (oid) {}

  // Allow copy
  QueryJoin(const QueryJoin&) = default;
  // Allow copy assign
  QueryJoin& operator=(const QueryJoin&) = default;
  ~QueryJoin() = default; // Default delete

  static ptr<QueryJoin>
  make_left(QueryColumn left) {
    return make_unique<QueryJoin>(left.type_id(), JoinSide::LEFT, left.oid());
  }

  static ptr<QueryJoin>
  make_left(TypeId type_id, const column_oid_t oid) {
    return make_unique<QueryJoin>(type_id, JoinSide::LEFT, oid);
  }

  static ptr<QueryJoin>
  make_right(QueryColumn right) {
    return make_unique<QueryJoin>(right.type_id(), JoinSide::RIGHT, right.oid());
  }

  static ptr<QueryJoin>
  make_right(TypeId type_id, const column_oid_t oid) {
    return make_unique<QueryJoin>(type_id, JoinSide::RIGHT, oid);
  }

  Value
  eval(const Tuple& tuple,
       const QuerySchema& schema) const override;

  Value
  eval_join(const Tuple& lt,
            const QuerySchema& ls,
            const Tuple& rt,
            const QuerySchema& rs) const override;

  Value
  eval_agg(UNUSED const QuerySchema& schema,
           UNUSED const vector<Value>& group_bys,
           UNUSED const vector<Value>& aggs) const override
  {
    throw NotImplementedException("eval_aggregate not implemented");
  }

  column_index_t
  column_index(const QuerySchema& schema) const;

  column_oid_t
  column_oid() const {
    return column_oid_;
  }

  const string to_string() const;

  JoinSide side() const  {
    return join_side_;
  }

private:
  JoinSide join_side_ = JoinSide::INVALID;
  column_oid_t column_oid_;
};

