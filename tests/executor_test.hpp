#pragma once

#include <iostream>
#include <algorithm>
#include <utility>

// Internal includes
#include "buffer/buff_mgr.hpp"

#include "txns/lock_mgr.hpp"
#include "txns/txn_mgr.hpp"

#include "catalog/schema_mgr.hpp"
#include "catalog/query_builder.hpp"

#include "plans/raw_tuples_plan.hpp"
#include "plans/plan_builder.hpp"

#include "execs/exec_ctx.hpp"
#include "execs/exec_engine.hpp"

#include "query/query_agg.hpp"
#include "query/query_column.hpp"
#include "query/query_comp.hpp"
#include "query/query_const.hpp"

#include "disk/disk_mgr.hpp"

#include "value/value_factory.hpp"
#include "tuple/result_set.hpp"

#include "server/potatodb.hpp"

// External includes
#include "gtest/gtest.h"

class ExecTest : public ::testing::Test {
public:
  ExecTest()
    : db_ (PotatoDB()) {}

  void
  SetUp() override {
    ::testing::Test::SetUp();
    db_.reset_installation();
  }

  void
  TearDown() override {
    ::testing::Test::TearDown();
  };

  ExecEngine&
  exec_eng() {
    return db_.exec_eng();
  }

  TxnMgr&
  txn_mgr() {
    return db_.txn_mgr();
  }

  SchemaMgr&
  schema_mgr() {
    return db_.schema_mgr();
  }

  ptr<ResultSet>
  query(ptr<BasePlan>&& plan) {
    auto &txn = txn_mgr().begin();
    auto exec_ctx = db_.make_exec_ctx(txn);

    auto result_set = exec_eng().query(move(plan), exec_ctx);
    txn_mgr().commit(txn);
    return result_set;
  }

  const string
  execute(ptr<BasePlan>&& plan) {
    auto &txn = txn_mgr().begin();
    auto exec_ctx = db_.make_exec_ctx(txn);

    auto message = exec_eng().execute(move(plan), exec_ctx);

    // TODO: If status == false, likely we should abort the txn.
    txn_mgr().commit(txn);
    return message;
  }

  static constexpr uint32_t MAX_VARCHAR_SIZE = 128;
  PotatoDB db_;
};


