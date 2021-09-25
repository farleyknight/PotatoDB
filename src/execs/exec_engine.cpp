#include "execs/exec_engine.hpp"

// NOTE: This version does not collect results, hence the inner
// loop does not do anything with the Tuple & RID
const string
ExecEngine::execute(ptr<BasePlan>&& plan,
                    ExecCtx& exec_ctx)
{
  assert(plan);
  assert(plan != nullptr);
  auto exec = ExecFactory::create(exec_ctx, move(plan));

  int result_count = 0;
  exec->init();

  try {
    while (exec->has_next()) {
      exec->next();
      ++result_count;
    }
  } catch (Exception &e) {
    return e.what();
  }

  return exec->message_on_completion(result_count);
}

ptr<ResultSet>
ExecEngine::query(ptr<BasePlan>&& plan,
                  ExecCtx& exec_ctx) const
{
  vector<Tuple> tuples;

  // TODO: We should verify that plan has SchemaPlan here
  auto schema = dynamic_cast<QuerySchemaPlan*>(plan.get())->schema();
  auto exec = ExecFactory::create(exec_ctx, move(plan));

  exec->init();

  while (exec->has_next()) {
    tuples.push_back(exec->next());
  }

  return make_unique<ResultSet>(move(tuples), schema);
}
