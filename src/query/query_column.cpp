#include "query/query_column.hpp"
#include "tuple/tuple.hpp"

Value
QueryColumn::eval(UNUSED const Tuple& tuple,
                  UNUSED const QuerySchema& schema) const
{
  if (is_count_splat()) {
    return Value::count_splat();
  } else if (is_splat()) {
    return Value::splat();
  }
  return tuple.value_by_name(schema, name_);
}

Value
QueryColumn::eval_join(UNUSED const Tuple& lt,
                       UNUSED const QuerySchema& ls,
                       UNUSED const Tuple& rt,
                       UNUSED const QuerySchema& rs) const
{
  throw NotImplementedException("eval_join not implemented!");
}

QueryColumn
QueryColumn::from(TableColumn col) {
  return QueryColumn(col.type_id(),
                     col.table_oid(),
                     col.oid(),
                     col.name());
}

value_length_t
QueryColumn::fixed_length() const {
  return Type::size_of(type_id_);
}

const string
QueryColumn::to_string() const {
  stringstream os;
  os << "Name : " << name_ << std::endl;
  os << "Type : " << Type::as_string(type_id_) << std::endl;
  return os.str();
}


Value
QueryColumn::eval_agg(const QuerySchema& schema,
                      UNUSED const vector<Value>& group_bys,
                      const vector<Value>& aggregates) const
{
  if (is_splat()) {
    throw Exception("Cannot handle splat here!");
  }
  if (is_count_splat()) {
    return aggregates[0];
  }

  auto index = schema.column_index_for(name_);
  return aggregates[index];
}

ptr<QueryComp>
QueryColumn::lt(Value constant) {
  auto self = make_unique<QueryColumn>(*this);
  auto value = make_unique<QueryConst>(constant);
  return make_unique<QueryComp>(move(self), CompareType::LT, move(value));
}

ptr<QueryComp>
QueryColumn::gt(Value constant) {
  auto self = make_unique<QueryColumn>(*this);
  auto value = make_unique<QueryConst>(constant);
  return make_unique<QueryComp>(move(self), CompareType::GT, move(value));
}

