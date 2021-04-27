#include "execs/agg_exec.hpp"

/**********************************************
 * TODO: Document me
 **********************************************/

void AggExec::init() {
  child_.init();
  table_.generate();

  Tuple tuple;
  RID rid;
  while (child_.has_next()){
    auto tuple = child_.next();
    auto key = make_key(tuple);
    auto value = make_val(tuple);
    table_.insert_combine(key, value);
  }
  table_iter_ = table_.begin();
}

bool AggExec::has_next() {
  while (!at_the_end()) {
    if (match_found()) {
      return true;
    }
    ++table_iter_;
  }
  return false;
}

bool AggExec::at_the_end() const {
  return table_iter_ == table_.end();
}

bool AggExec::match_found() {
  bool has_pred = plan_.has_having();
  if (!has_pred) {
    return true;
  }

  auto key = table_iter_.key();
  auto value = table_iter_.val();

  auto &schema = find_schema(child_.schema_ref());
  auto &pred = plan_.having();
  auto result =
    pred.eval_agg(schema,
                  key.group_bys_,
                  value.aggs_).get_as<bool>();
  return result;
}

/**********************************************
 * TODO: Document me
 **********************************************/

Tuple AggExec::next() {
  // create tuple according to output schema
  auto key = table_iter_.key();
  auto value = table_iter_.val();

  auto &schema = find_schema(child_.schema_ref());

  MutVec<Value> tuple_values;
  for (auto const &col: schema.all()) {
    auto val = col.eval_agg(schema,
                            key.group_bys_,
                            value.aggs_);
    tuple_values.push_back(val);
  }

  return Tuple(tuple_values, schema);
}

/**********************************************
 * TODO: Document me
 **********************************************/

AggKey AggExec::make_key(Ref<Tuple> tuple) {
  auto &schema = find_schema(child_.schema_ref());

  MutVec<Value> keys(plan_.group_bys().size());
  for (auto const &expr : plan_.group_bys()) {
    keys.emplace_back(expr.eval(tuple, schema));
  }
  return AggKey(keys);
}

/**********************************************
 * TODO: Document me
 **********************************************/

AggValue AggExec::make_val(Ref<Tuple> tuple) {
  auto &schema = find_schema(child_.schema_ref());

  MutVec<Value> values(plan_.aggs().size());
  for (auto const &expr : plan_.aggs()) {
    values.emplace_back(expr.eval(tuple, schema));
  }
  return AggValue(values);
}
