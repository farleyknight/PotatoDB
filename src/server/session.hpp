#pragma once

#include "execs/exec_ctx.hpp"
#include "execs/exec_engine.hpp"

#include "tuple/result_set.hpp"

class PotatoDB;

class Session {
public:
  Session(PotatoDB* db) : db_ (db) {}
  ~Session() = default;

  ptr<ResultSet> query(string statement);
  void execute(string statement);

private:
  PotatoDB* db_; // Use as a reference
};
