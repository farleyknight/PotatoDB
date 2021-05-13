#pragma once

#include "execs/exec_ctx.hpp"
#include "execs/exec_engine.hpp"

#include "tuple/result_set.hpp"
#include "server/statement_result.hpp"

class PotatoDB;

class Session {
public:
  Session(PotatoDB* db) : db_ (db) {}
  ~Session() = default;

  StatementResult run_statement(const string& statement);

private:
  PotatoDB* db_; // Use as a reference
};
