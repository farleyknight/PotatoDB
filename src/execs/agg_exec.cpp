#include "execs/agg_exec.hpp"

void AggExec::init() {
  child_->init();

  assert(plan_ != nullptr);
  table_.init(plan_);
  table_.generate();

  Tuple tuple;
  while (child_->has_next()){
    auto tuple = child_->next();
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
  bool has_pred = plan_->has_having();
  if (!has_pred) {
    return true;
  }

  auto key = table_iter_.key();
  auto value = table_iter_.val();

  auto pred = plan_->having();
  auto result =
    pred.eval_agg(schema(),
                  key.group_bys_,
                  value.aggs_).as<bool>();
  return result;
}

Tuple AggExec::next() {
  // create tuple according to output schema
  auto key = table_iter_.key();
  auto value = table_iter_.val();

  vector<Value> tuple_values;
  for (QueryColumn const &col : schema().all()) {
    auto val = col.eval_agg(schema(),
                            key.group_bys_,
                            value.aggs_);
    tuple_values.push_back(val);
  }

  return Tuple(tuple_values, schema());
}

AggKey AggExec::make_key(const Tuple& tuple) {
  vector<Value> keys;
  for (auto const &node : plan_->group_bys()) {
    keys.emplace_back(node.eval(tuple, schema()));
  }
  return AggKey(keys);
}

AggValue AggExec::make_val(const Tuple& tuple) {
  vector<Value> values;
  for (auto const &node : plan_->aggs()) {
    values.emplace_back(node.eval(tuple, schema()));
  }
  return AggValue(values);
}
