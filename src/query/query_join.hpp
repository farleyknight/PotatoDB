#pragma once

#include "catalog/schema_ref.hpp"
#include "query/base_query.hpp"

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
      schema_ref_  (SchemaRef::INVALID()),
      column_name_ ("")
  {}

  QueryJoin(TypeId type_id,
            JoinSide side,
            CRef<SchemaRef> schema_ref,
            String name)
    : BaseQuery     (type_id),
      join_side_    (side),
      schema_ref_   (schema_ref),
      column_name_  (move(name)) {}

  QueryJoin(CRef<QueryJoin>) = default; // Allow copy
  QueryJoin& operator=(CRef<QueryJoin>) = default; // Allow copy assign
  ~QueryJoin() = default; // Default delete

  static QueryJoin make_left(TypeId type_id,
                             SchemaRef schema,
                             String name)
  {
    return QueryJoin(type_id, JoinSide::LEFT, schema, name);
  }

  static QueryJoin make_right(TypeId type_id,
                              SchemaRef schema,
                              String name)
  {
    return QueryJoin(type_id, JoinSide::RIGHT, schema, name);
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
  SchemaRef schema_ref_;
  string column_name_;
};

