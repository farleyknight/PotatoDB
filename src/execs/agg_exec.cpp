#include "execs/agg_exec.hpp"

void AggExec::init() {
  child_->init();

  // TODO: Maybe move this assertion into the constructor
  assert(plan_ != nullptr);

  table_.init(plan_);
  table_.generate();

  while (child_->has_next()){
    auto tuple = child_->next();
    auto agg_key = make_key(tuple);
    auto agg_value = make_val(tuple);
    table_.insert_combine(agg_key, agg_value);
  }
  table_iter_ = table_.begin();
}

bool AggExec::has_next() {
  while (!at_the_end()) {
    if (!plan_->has_having()) {
      return true;
    }
    if (plan_->has_having() && match_found()) {
      return true;
    }
    ++table_iter_;
  }
  return false;
}

bool AggExec::at_the_end() {
  auto end = table_.end();
  return table_iter_ == end;
}

bool AggExec::match_found() {
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
  for (auto const &col : schema().all()) {
    auto val = col.eval_agg(schema(),
                            key.group_bys_,
                            value.aggs_);
    tuple_values.push_back(val);
  }

  ++table_iter_;

  return Tuple(tuple_values, schema());
}

AggKey AggExec::make_key(const Tuple& tuple) {
  vector<Value> keys;
  for (auto const &node : plan_->group_bys()) {
    std::cout << "GROUP BY! " << std::endl;
    keys.emplace_back(node.eval(tuple, schema()));
  }
  return AggKey(keys);
}

AggValue AggExec::make_val(const Tuple& tuple) {
  vector<Value> values;
  for (auto const &node : plan_->aggs()) {
    values.emplace_back(node.eval(tuple, child_schema()));
  }
  return AggValue(values);
}
