#pragma once

#include "execs/exec_ctx.hpp"

#include "parser/sql_parser.hpp"
#include "server/resources.hpp"

#include "tuples/result_set.hpp"

class Session {
public:
  Session(CRef<Resources> resources,
          const int bp_size = 1000)
    : buffer_pool_size_ (bp_size)
  {}

  ~Session();

  ResultSet execute(String query) {
    try {
      // TODO: Rename as_exprs to as_stmts
      auto exprs = SQLParser::as_exprs(query);
      // TODO: Allow for multiple statements
      auto plan = build_plan(exprs[0]);
      auto &txn = txn_mgr().begin();
      auto exec_ctx = ExecCtx::make(txn, resources_);

      auto result_set = exec_eng().execute(move(plan),
                                           txn,
                                           *exec_ctx);
      txn_mgr().commit(txn);
      return result_set;
    } catch (std::runtime_exception& e) {
      return ResultSet();
    }
  }

private:
  CRef<Resources> resources_;
};
