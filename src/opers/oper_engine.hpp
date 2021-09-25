#pragma once


class ProgramBuilder {
public:
  OperProgram() {}


private:
  vector<ptr<BaseOper>> opers_;
};

class OperEngine {
public:
  using OperProgram = vector<ptr<BaseOper>>;

  OperEngine(const BuffMgr& buff_mgr,
             const TxnMgr& txn_mgr,
             const Catalog& catalog)
    : buff_mgr_ (buff_mgr),
      txn_mgr_  (txn_mgr),
      catalog_  (catalog)
  {}

  /*
   *


[SCAN TABLE A] => [PRED] => [PROJ] => Result (final,pay,load)

[RAW TUPLES (tuple,data)] => [INSERT] => Result Ok

[RAW TUPLES (tuple,data)] => [DELETE] => Result Ok

[UPDATE] => Result Ok

[SCAN TABLE A] => [COLLECT] => [AGG] => Result (sum,min,max)

[SCAN TABLE A] => [COLLECT] => [SORT] => Result (sorted,a,b,c)

[COMBINE] {[SCAN TABLE A], [SCAN TABLE B]} => [JOIN] => Result ..

  */

  vector<Tuple> eval(OperProgram& program)
  {
    // Things to keep track of:

    // 1) Result Set
    ResultSet results;
    // 2) Object Pool? tuples used during computation
    //    Maybe it could somehow include pages?
    vector<Tuple> tuples;
    // 3) Page IDs
    vector<PageId> page_ids;
    // 3) Cursors that cursor over tables or indexes
    vector<Cursor> cursors;
    // 4) Value Stack
    //    Necessary for basic logic, like AND/OR/NOT
    //    Can also support +,-,*,/,% operations
    vector<Value> stack;

    // TODO: In this method we call source->init() for all
    // sources in the program.
    program.init_all_sources();

    // NOTE: Assuming the first operator will always be a source
    oper_index_t index = 0;

    while (index >= 0) {
      auto &curr = program[index];

      switch(curr->oper_type()) {
        // NOTE: This is too high level!

      case OperType::TABLE_SCAN: {
        if (curr->has_next()) {
          stack.push_back(curr->next());
          index = curr->dest_index();
        } else {
          program.set_source_done(index);
          index = program.next_source_after(index);
        }
      }
      case OperType::PREDICATE1: {
        assert(stack.size() >= 1);
        // NOTE: We could optimize this to only look at the
        // back instead of popping and pushing.
        auto tuple = stack.back();
        stack.pop_back();
        if (curr->matches(tuple)) {
          stack.push_back(tuple);
        }
      }
      case OperType::PREDICATE2: {
        if (curr->join_match(left_tuple, right_tuple)) {
          stack.push_back(curr->join_merge(left_tuple,
                                           right_tuple));
        }
      }
      case OperType::PROJECT: {
        auto tuple = stack.back();
        stack.push_back(curr->pipe(tuple));
      }
      case OperType::RESULTS: {
        results.push_back(stack.back());
        stack.pop_back();
      }
      case OperType::INSERT: {
        curr->sink(stack.back());
        stack.pop_back();
      }
      default: {
        break;
      }
      }
    }


    return results;
  }

  ptr<ResultSet> query(OperProgram& program,
                       UNUSED const Txn& txn,
                       ExecCtx& exec_ctx) const
  {
    vector<Tuple> tuples;

    assert(program.size() > 0);

    auto &curr = program[0];

    curr->init();

    while (curr->has_next()) {
      auto tuple = curr->next();
      tuples.push_back(apply(program, curr->child_index(), tuple))
    }

    auto schema = dynamic_cast<QuerySchemaPlan*>(plan.get())->schema();
    auto exec = ExecFactory::create(exec_ctx, move(plan));

    exec->init();

    while (exec->has_next()) {
      tuples.push_back(exec->next());
    }

    return make_unique<ResultSet>(move(tuples), schema);
  }

private:
  UNUSED const BuffMgr& buff_mgr_;
  UNUSED const TxnMgr& txn_mgr_;
  UNUSED const Catalog& catalog_;
};
