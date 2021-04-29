#pragma once

#include "exprs/base_expr.hpp"

enum class JoinSide {
  INVALID = 0,
  LEFT    = 1,
  RIGHT   = 2
};

class QueryJoin : public BaseJoin {
public:
  QueryJoin(JoinSide     side,
            CRef<Schema> schema,
            Move<String> name)
    : BaseQuery      (schema.column_by_name(name).type_id()),
      join_side_     (side),
      source_schema_ (schema),
      column_name_   (move(name)) {}

  QueryJoin(CRef<QueryJoin> ) = delete; // No copy
  QueryJoin& operator=(CRef<QueryJoin>) = delete; // No copy assign
  ~QueryJoin() = default; // Default delete

  static Ptr<BaseQuery> make_left(CRef<Schema> schema,
                                  Move<String> name) {
    return make(JoinSide::LEFT, schema, move(name));
  }

  static Ptr<BaseQuery> make_right(CRef<Schema> schema,
                                   Move<String> name) {
    return make(JoinSide::RIGHT, schema, move(name));
  }

  Value eval(CRef<Tuple> tuple, CRef<Schema> schema) const override {
    return tuple.value(schema, column_index());
  }

  Value eval_join(CRef<Tuple>  lt,
                  CRef<Schema> ls,
                  CRef<Tuple>  rt,
                  CRef<Schema> rs) const override
  {
    switch (join_side_) {
    case JoinSide::LEFT:
      return lt.value(ls, column_index());
    case JoinSide::RIGHT:
      return rt.value(rs, column_index());
    case JoinSide::INVALID:
      throw Exception("Cannot eval join with INVALID_SIDE!");
    }
  }

  Value eval_agg(UNUSED CRef<Vec<Value>> group_bys,
                 UNUSED CRef<Vec<Value>> aggs) const override
  {
    throw NotImplementedException("eval_aggregate not implemented");
  }

  string to_string() const override {
    std::ostringstream os;

    os << "Type id is :: " << Type::as_string(return_type()) << std::endl;
    os << "Join side is :: " << (int)join_side_ << std::endl;
    os << "Column name is :: " << column_name_ << std::endl;
    os << "Column index is :: " << column_index() << std::endl;
    os << "\n";

    return os.str();
  }

  uint32_t column_index() const {
    return source_schema_.by_name(column_name_);
  }

private:
  JoinSide join_side_ = JoinSide::INVALID;
  CRef<Schema> source_schema_;
  string column_name_;
};

