#pragma once

#include "execs/exec_ctx.hpp"
#include "execs/exec_engine.hpp"

#include "parser/sql_parser.hpp"

#include "tuple/result_set.hpp"

class PotatoDB;

class Session {
public:
  Session(PotatoDB* db) : db_ (db) {}
  ~Session() = default;

  MutPtr<ResultSet> execute(string query);

private:
  PotatoDB* db_; // Use as a reference
};
