#pragma once

#include <iostream>
#include <algorithm>
#include <utility>

// Internal includes
#include "buffer/buff_mgr.hpp"

#include "txns/lock_mgr.hpp"
#include "txns/txn_mgr.hpp"

#include "catalog/catalog.hpp"
#include "catalog/query_builder.hpp"
#include "catalog/table_builder.hpp"

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

  void SetUp() override {
    ::testing::Test::SetUp();
  }

  void TearDown() override {
    ::testing::Test::TearDown();
  };

  ExecEngine& exec_eng() {
    return db_.exec_eng();
  }

  TxnMgr& txn_mgr() {
    return db_.txn_mgr();
  }

  Catalog& catalog() {
    return db_.catalog();
  }

  ptr<ResultSet> query(ptr<BasePlan>&& plan) {
    auto &txn = txn_mgr().begin();
    auto exec_ctx = db_.make_exec_ctx(txn);

    auto result_set = exec_eng().query(move(plan),
                                       txn,
                                       *exec_ctx);
    txn_mgr().commit(txn);
    return result_set;
  }

  bool execute(ptr<BasePlan>&& plan) {
    auto &txn = txn_mgr().begin();
    auto exec_ctx = db_.make_exec_ctx(txn);

    auto status = exec_eng().execute(move(plan),
                                     txn,
                                     *exec_ctx);

    // TODO: If status == false, likely we should abort the txn.
    txn_mgr().commit(txn);
    return status;
  }

private:
  static constexpr uint32_t MAX_VARCHAR_SIZE = 128;
  PotatoDB db_;
};

// NOLINTNEXTLINE
TEST_F(ExecTest, SimpleSeqScanTest) {
  // SELECT colA, colB FROM test_1 WHERE colA < 500

  // CREATE TABLE test_1 (
  //   colA int,
  //   colB int
  // );
  auto create_table_plan = TableBuilder(catalog()).
    table_name("test_1").
    column("colA", TypeId::INTEGER).
    column("colB", TypeId::INTEGER).
    to_plan();

  execute(move(create_table_plan));

  auto test_1 = QueryBuilder(catalog()).table("test_1");

  vector<vector<Value>> data;
  for (int32_t i = 0; i < 10; ++i) {
    data.push_back({ Value::make(i), Value::make(3) });
  }

  auto insert_values_plan = PlanBuilder(catalog()).
    insert_into(test_1).
    tuples(RawTuples(data)).
    to_plan();

  execute(move(insert_values_plan));

  auto scan_plan = PlanBuilder(catalog()).
    select({
        test_1["colA"],
        test_1["colB"]
      }).
    from(test_1).
    where(test_1["colA"].lt(Value::make(5))).
    to_plan();

  auto result_set = query(move(scan_plan));

  // Verify
  for (const auto &tuple : result_set->results()) {
    ASSERT_TRUE(result_set->value<int>("colA", tuple) < 5);
    ASSERT_TRUE(result_set->value<int>("colB", tuple) < 10);
  }

  ASSERT_EQ(result_set->size(), 5);
}

TEST_F(ExecTest, DISABLED_InconsistentTupleLengthTest) {
  string failure_message = "Expected to raise exception about inconsistent tuple lengths";

  // INSERT INTO table_with_two_columns VALUES (1, 2), (3, 4, 5)
  vector<vector<Value>> data = {
    {Value::make(1), Value::make(2)},
    {Value::make(3), Value::make(4), Value::make(5)}
  };

  try {
    auto raw_tuples = RawTuples(data);
    auto table_with_two_cols = QueryBuilder(catalog()).table("table_with_two_cols");

    auto insert_plan = PlanBuilder(catalog()).
      insert_into(table_with_two_cols).
      tuples(move(raw_tuples)).
      to_plan();
    FAIL() << failure_message;
  } catch(Exception &ex) {
    string expected_message =
      "Your SQL statement provided tuples with inconsistent sizes.\n"               \
      "More specifically, the tuple sizes were {2, 3}.\n"                           \
      "Please check your query and try again.\n"                                    \
      "Note that 2 elements are required for the table `table_with_two_columns`.";
    ASSERT_EQ(ex.what(), expected_message);
  }
  FAIL() << failure_message;
}

TEST_F(ExecTest, DISABLED_WrongLengthOfTuplesTest) {
  string failure_message = "Expected to raise exception about wrong lengths of tuples.";

  // CREATE TABLE table_with_two_columns (
  //   colA int,
  //   colB int
  // );
  auto create_table_plan = TableBuilder(catalog()).
    table_name("table_with_two_columns").
    column("colA", TypeId::INTEGER).
    column("colB", TypeId::INTEGER).
    to_plan();

  execute(move(create_table_plan));

  // INSERT INTO table_with_two_columns VALUES (1, 2, 3, 4, 5, 6)
  vector<vector<Value>> data = {
    {
      Value::make(1), Value::make(2), Value::make(3),
      Value::make(4), Value::make(5), Value::make(6)
    }
  };

  auto raw_tuples = RawTuples(data);

  bool success = false;
  try {
    auto table_with_two_cols = QueryBuilder(catalog()).table("table_with_two_cols");

    auto insert_plan = PlanBuilder(catalog()).
      insert_into(table_with_two_cols).
      tuples(move(raw_tuples)).
      to_plan();
    FAIL() << failure_message;
  } catch(Exception &ex) {
    string expected_message =
      "Your SQL statement provided 6 element(s) per tuple.\n"
      "However, 2 elements are required for the table `table_with_two_columns`.";
    ASSERT_EQ(ex.what(), expected_message);
  }
  FAIL() << failure_message;
}

TEST_F(ExecTest, DISABLED_SimpleRawInsertTest) {
  // INSERT INTO empty_table2 VALUES (100, 10), (101, 11), (102, 12)
  vector<vector<Value>> data {
    {Value::make(100), Value::make(10)},
    {Value::make(101), Value::make(11)},
    {Value::make(102), Value::make(12)}
  };

  auto raw_tuples = RawTuples(data);

  auto empty_table2 = QueryBuilder(catalog()).table("empty_table2");

  auto insert_plan = PlanBuilder(catalog()).
    insert_into(empty_table2).
    tuples(move(raw_tuples)).
    to_plan();

  auto result = execute(move(insert_plan));
  ASSERT_TRUE(result);

  // Iterate through table make sure that values were inserted.
  // SELECT colA, colB FROM empty_table2;
  auto scan_plan = PlanBuilder(catalog()).
    select({
        empty_table2["colA"],
        empty_table2["colB"]
      }).
    from(empty_table2).
    to_plan();

  auto result_set = query(move(scan_plan));

  ASSERT_EQ(result_set->size(), 3);

  // First value
  ASSERT_EQ(result_set->value_at<int32_t>("colA", 0), 100);
  ASSERT_EQ(result_set->value_at<int32_t>("colB", 0), 10);

  // Second value
  ASSERT_EQ(result_set->value_at<int32_t>("colA", 1), 101);
  ASSERT_EQ(result_set->value_at<int32_t>("colB", 1), 11);

  // Third value
  ASSERT_EQ(result_set->value_at<int32_t>("colA", 2), 102);
  ASSERT_EQ(result_set->value_at<int32_t>("colB", 2), 12);
}

TEST_F(ExecTest, DISABLED_SimpleRawInsertAndUpdateTest) {
  // INSERT INTO empty_table2 VALUES (100, 10)

  vector<vector<Value>> data {
    {Value::make(100), Value::make(10)}
  };

  auto raw_tuples = RawTuples(data);

  auto empty_table2 = QueryBuilder(catalog()).table("empty_table2");

  auto insert_plan = PlanBuilder(catalog()).
    insert_into(empty_table2).
    tuples(move(raw_tuples)).
    to_plan();

  execute(move(insert_plan));

  // NOTE: This should update every raw in the table to be 50
  // UPDATE empty_table2 SET colA = 50
  // Scan child plan

  auto update_plan = PlanBuilder(catalog()).
    update(empty_table2).
    set(empty_table2["colA"], Value::make(50)).
    to_plan();

  execute(move(update_plan));

  auto select_plan = PlanBuilder(catalog()).
    select({
        empty_table2["colA"],
        empty_table2["colB"]
      }).
    from(empty_table2).
    to_plan();

  auto result_set = query(move(select_plan));

  ASSERT_EQ(result_set->value_at<int>("colA", 0), 50);
  ASSERT_EQ(result_set->value_at<int>("colB", 0), 10);

  ASSERT_EQ(result_set->size(), 1);
}

TEST_F(ExecTest, DISABLED_SimpleSelectInsertTest) {
  auto test_1 = QueryBuilder(catalog()).table("test_1");
  auto empty_table2 = QueryBuilder(catalog()).table("empty_table2");
  auto colA = empty_table2["colA"];
  auto colB = empty_table2["colB"];

  // SQL: INSERT INTO empty_table2 SELECT colA, colB FROM test_1 WHERE colA < 500
  auto insert_plan = PlanBuilder(catalog()).
    insert_into(empty_table2).
    select({colA, colB}).
    from(test_1).
    where(colA.lt(Value::make(500))).
    to_plan();

  // Execute INSERT
  execute(move(insert_plan));

  // SQL: SELECT colA, colB from empty_table2;
  auto full_scan_plan = PlanBuilder(catalog()).
    select({colA, colB}).
    from(empty_table2).
    to_plan();

  // SQL: SELECT colA, colB from empty_table2 WHERE colA < 500;
  auto where_scan_plan = PlanBuilder(catalog()).
    select({colA, colB}).
    from(empty_table2).
    where(colA.lt(Value::make(500))).
    to_plan();

  auto where_set = query(move(where_scan_plan));
  auto full_set  = query(move(full_scan_plan));

  ASSERT_EQ(where_set->size(),
            full_set->size());

  for (size_t i = 0; i < full_set->size(); ++i) {
    ASSERT_EQ(full_set->value_at<int>("colA", i),
              where_set->value_at<int>("colA", i));

    ASSERT_EQ(full_set->value_at<int>("colB", i),
              where_set->value_at<int>("colB", i));
  }

  ASSERT_EQ(full_set->size(), 500);
}

// TODO: For now let's skip anything related to indexes
TEST_F(ExecTest, DISABLED_SimpleRawInsertWithIndexTest) {
  // Create Values to insert
  vector<vector<Value>> data {
    {Value::make(100), Value::make(10)},
    {Value::make(101), Value::make(11)},
    {Value::make(102), Value::make(12)}
  };

  auto empty_table2 = QueryBuilder(catalog()).table("empty_table2");

  // INSERT INTO empty_table2 VALUES (100, 10), (101, 11), (102, 12)
  auto insert_values_plan = PlanBuilder(catalog()).
    insert_into(empty_table2).
    tuples(RawTuples(data)).
    to_plan();

  auto colA = empty_table2["colA"];
  auto colB = empty_table2["colB"];
  auto key_schema = QuerySchema({colA});

  auto &txn = txn_mgr().begin();

  /*
   *
   GenericComp comparator(*key_schema);
   auto &index_meta =
   catalog().create_index(txn,
   "index1",
   "empty_table2");

   */

  /*
    NOTE: For now let's skip anything related to indexes

   catalog().table_schem_for("empty_table2"),
   move(key_schema),
   {0}, 8);

   */

  /*
   *

  execute(move(insert_values_plan));

  // Iterate through table make sure that values were inserted.
  // SELECT * FROM empty_table2;
  auto scan_plan = PlanBuilder(catalog()).
    select({colA, colB}).
    from(empty_table2).
    to_plan();

  auto result_set = query(move(scan_plan));

  // First value
  ASSERT_EQ(result_set->value_at<int32_t>("colA", 0), 100);
  ASSERT_EQ(result_set->value_at<int32_t>("colB", 0), 10);

  // Second value
  ASSERT_EQ(result_set->value_at<int32_t>("colA", 1), 101);
  ASSERT_EQ(result_set->value_at<int32_t>("colB", 1), 11);

  // Third value
  ASSERT_EQ(result_set->value_at<int32_t>("colA", 2), 102);
  ASSERT_EQ(result_set->value_at<int32_t>("colB", 2), 12);

  // Size
  ASSERT_EQ(result_set->size(), 3);

  // Get RID from index, fetch tuple and then compare
  for (auto &table_tuple : result_set->results()) {
    auto index_key =
      table_tuple.key_from_tuple(empty_table2.schema(),
                                 index_meta.key_schema(),
                                 index_meta.key_attrs());

    auto rids = index_meta.scan_key(index_key, txn);
    ASSERT_EQ(rids.size(), 1);

    auto maybe_tuple = empty_table2.table_heap().
      find_tuple(rids[0], txn);

    ASSERT_TRUE(maybe_tuple.has_value());
    auto index_tuple = maybe_tuple.value();

    // Verify colA
    auto index_colA = result_set->value<int>("colA", index_tuple);
    auto table_colA = result_set->value<int>("colA", table_tuple);
    ASSERT_EQ(index_colA, table_colA);

    auto index_colB = result_set->value<int>("colB", index_tuple);
    auto table_colB = result_set->value<int>("colB", table_tuple);
    ASSERT_EQ(index_colB, table_colB);
  }

  */
}

// NOLINTNEXTLINE
TEST_F(ExecTest, DISABLED_SimpleIndexDeleteTest) {
  // CREATE INDEX ( a ) ON TABLE test_1;
  // SELECT colA FROM test_1 WHERE colA == 50
  // DELETE FROM test_1 WHERE colA == 50
  // SELECT colA FROM test_1 WHERE colA == 50

  /*
   *

  MutVec<QueryColumn> cols {
    Column("a", TypeId::BIGINT)
  };
  auto key_schema = Schema::make(move(cols));

  GenericComp comparator(*key_schema);
  auto &index_schema = catalog().table("test_1").schema();

  auto &txn = txn_mgr().begin();

  auto &index_meta =
    catalog().create_index(txn,
                           "index1",
                           "test_1",
                           index_schema,
                           move(key_schema), {0}, 8);

  // Construct query plan
  auto scan_plan1 = PlanBuilder(catalog()).
    select({"colA"}).
    from("test_1").
    where("colA", "==", 50).
    to_plan();

  // Execute
  auto result_set1 = query(move(scan_plan1));

  // Verify
  ASSERT_EQ(result_set1->value_at<int>("colA", 0), 50);
  ASSERT_EQ(result_set1->size(), 1);

  Tuple index_key(result_set1->results()[0]);

  auto delete_plan = PlanBuilder(catalog()).
    delete_from("test_1").
    where("colA", "==", 50).
    to_plan();

  execute(move(delete_plan));

  // Construct query plan
  auto scan_plan2 = PlanBuilder(catalog()).
    select({"colA"}).
    from("test_1").
    where("colA", "==", 50).
    to_plan();

  auto result_set2 = query(move(scan_plan2));

  ASSERT_EQ(result_set2->results().size(), 0);

  auto rids = index_meta.scan_key(index_key, txn);
  ASSERT_TRUE(rids.empty());
  */
}

TEST_F(ExecTest, LoopJoinTest) {
  // SELECT test_1.colA, test_1.colB, test_2.col1, test_2.col3
  // FROM test_1
  // JOIN test_2
  // ON test_1.colA = test_2.col1

  /* 
  auto loop_join_plan = PlanBuilder(catalog()).
    select({
        "test_1.colA", "test_1.colB",
        "test_2.col1", "test_2.col3"
      }).
    from("test_1").
    loop_join("test_2").
    on("test_1.colA", "==", "test_2.col1").
    to_plan();

  auto result_set = query(move(loop_join_plan));
  EXPECT_EQ(result_set->size(), 100);

  for (const auto &tuple : result_set->results()) {
    auto colA = result_set->value<int32_t>("colA", tuple);
    auto col1 = result_set->value<int32_t>("col1", tuple);
    EXPECT_EQ(colA, col1);
  }
  */
}

// NOLINTNEXTLINE
TEST_F(ExecTest, HashJoinTest) {
  // SELECT test_1.colA, test_1.colB, test_2.col1, test_2.col3
  // FROM test_1
  // JOIN test_2
  // ON test_1.colA = test_2.col1

  /*

  auto hash_join_plan = PlanBuilder(catalog()).
    select({
        "test_1.colA", "test_1.colB",
        "test_2.col1", "test_2.col3"
      }).
    from("test_1").
    hash_join("test_2").
    on("test_1.colA", "==", "test_2.col1").
    to_plan();

  auto result_set = query(move(hash_join_plan));
  EXPECT_EQ(result_set->size(), 100);

  for (const auto &tuple : result_set->results()) {
    auto colA = result_set->value<int32_t>("colA", tuple);
    auto col1 = result_set->value<int32_t>("col1", tuple);
    EXPECT_EQ(colA, col1);
  }

  */
}

// NOLINTNEXTLINE
TEST_F(ExecTest, SimpleAggTest) {
  // SELECT COUNT(colA), SUM(colA), MIN(colA), MAX(colA) from test_1;

  /**************************************************
   * TODO: This is the new version of PlanBuilder.
   **************************************************/

  /*
  auto test_1 = QueryBuilder(catalog()).table("test_1");

  auto agg_plan = PlanBuilder(catalog()).
    select({
        QueryAgg::count(test_1["colA"]),
        QueryAgg::sum(test_1["colA"]),
        QueryAgg::min(test_1["colA"]),
        QueryAgg::max(test_1["colA"])
      }).
    from(test_1).
    to_plan();
  */

  /**************************************************
   * TODO: The code below should be functionally
   * identical to the code above.
   **************************************************/

  /*
  auto &meta = catalog().table("test_1");
  auto scan_schema = Schema::slice(meta.schema(), {"colA"});

  auto scan_plan = SeqScanPlan::make(move(scan_schema),
                                     meta.oid());

  // COUNT(colA)
  AggExpr countA(meta.schema(), "colA", AggType::COUNT);

  // SUM(colA)
  AggExpr sumA(meta.schema(), "colA", AggType::SUM);

  // MIN(colA)
  AggExpr minA(meta.schema(), "colA", AggType::MIN);

  // MAX(colA)
  AggExpr maxA(meta.schema(), "colA", AggType::MAX);

  auto agg_schema = Schema::make({
      Schema::pair("COUNT(colA)", countA),
      Schema::pair("SUM(colA)",   sumA),
      Schema::pair("MIN(colA)",   minA),
      Schema::pair("MAX(colA)",   maxA)
    });

  MutVec<AggExpr> aggs;
  aggs.reserve(4);
  // COUNT(colA)
  aggs.emplace_back(TypeId::INTEGER, meta.schema(),
                    "colA", AggType::COUNT);
  // SUM(colA)
  aggs.emplace_back(TypeId::INTEGER, meta.schema(),
                    "colA", AggType::SUM);
  // MIN(colA)
  aggs.emplace_back(TypeId::INTEGER, meta.schema(),
                    "colA", AggType::MIN);
  // MAX(colA)
  aggs.emplace_back(TypeId::INTEGER, meta.schema(),
                    "colA", AggType::MAX);

  auto agg_plan = AggPlan::make(move(agg_schema),
                                move(scan_plan),
                                move(aggs));

  auto result_set = query(move(agg_plan));

  ASSERT_EQ(result_set->size(), 1);
  auto first_tuple = result_set->results()[0];

  auto countA_val = result_set->value<int32_t>("COUNT()countA", first_tuple);
  auto sumA_val   = result_set->value<int32_t>("sumA",   first_tuple);
  auto minA_val   = result_set->value<int32_t>("minA",   first_tuple);
  auto maxA_val   = result_set->value<int32_t>("maxA",   first_tuple);

  // Should count all tuples
  ASSERT_EQ(countA_val, TEST1_SIZE);
  // Should sum from 0 to TEST1_SIZE
  ASSERT_EQ(sumA_val, TEST1_SIZE * (TEST1_SIZE - 1) / 2);
  // Minimum should be 0
  ASSERT_EQ(minA_val, 0);
  // Maximum should be TEST1_SIZE - 1
  ASSERT_EQ(maxA_val, TEST1_SIZE - 1);
  */
}

// NOLINTNEXTLINE
TEST_F(ExecTest, SimpleGroupByAggTest) {
  // SELECT COUNT(colA), colB, SUM(colC)
  // FROM test_1
  // GROUP BY colB
  // HAVING COUNT(colA) > 100

  // auto test_1 = QueryBuilder(catalog()).table("test_1");

  /**************************************************
   * TODO: This is the new version of PlanBuilder.
   **************************************************/

  /*
  auto agg_plan = PlanBuilder(catalog()).
    select({
        AggExpr::count(test_1["colA"]),
        test_1["colB"],
        AggExpr::sum(test_1["colC"])
      }).
    from(test1).
    group_by(test_1["colB"]).
    having(AggExpr::count(test_1["colA"]),
           ">",
           ConstExpr::make<int>(100)).
    to_plan();
  */
  /**************************************************
   * TODO: The code below should be functionally
   * identical to the code above.
   **************************************************/

  /*
  auto &meta = catalog().table("test_1");
  auto scan_schema = Schema::slice(meta.schema(),
                                   {"colA", "colB", "colC"});

  auto scan_plan = SeqScanPlan::make(move(scan_schema),
                                     meta.oid());

  // COUNT(colA)
  AggExpr countA(meta.schema(), "colA", AggType::COUNT);

  // colB (used in GROUP BY)
  GroupByExpr groupByB(meta.schema(), "colB");

  // SUM(colC)
  AggExpr sumC(meta.schema(), "colC", AggType::SUM);

  auto agg_schema = Schema::make({
      Schema::pair("COUNT(colA)", countA),
      Schema::pair("colB",        groupByB),
      Schema::pair("SUM(colC)",   sumC)
    });

  // HAVING COUNT(colA) > 100
  auto having_countA = AggExpr::make(meta.schema(), "colA", AggType::COUNT);
  auto const100 = ConstExpr::make<int>(100);

  auto having_clause = CompExpr::make(move(having_countA),
                                      CompType::GT,
                                      move(const100));

  auto having = HavingExpr::make(TypeId::BOOLEAN,
                                 meta.schema(),
                                 move(having_clause));

  // Aggregation exprs
  MutVec<AggExpr> aggs;
  aggs.reserve(2);
  // COUNT(colA)
  aggs.emplace_back(TypeId::INTEGER,
                    meta.schema(), "colA", AggType::COUNT);
  // SUM(colC)
  aggs.emplace_back(TypeId::INTEGER,
                    meta.schema(), "colC", AggType::SUM);

  // Group by exprs
  MutVec<GroupByExpr> group_bys;
  group_bys.reserve(1);
  group_bys.emplace_back(TypeId::INTEGER, meta.schema(), "colB");

  auto agg_plan = AggPlan::make(move(agg_schema),
                                move(scan_plan),
                                move(aggs),
                                move(group_bys),
                                move(having));

  auto result_set = query(move(agg_plan));

  ASSERT_EQ(result_set->size() > 0, true);

  MutSet<int32_t> encountered;

  for (const auto &tuple : result_set->results()) {
    // Should have countA > 100
    auto assert_countA = result_set->value<int32_t>("countA", tuple);
    ASSERT_GT(assert_countA, 100);

    // Should have unique colBs.
    auto assert_colB   = result_set->value<int32_t>("colB", tuple);
    ASSERT_EQ(encountered.count(assert_colB), 0);

    encountered.insert(assert_colB);
    // Sanity check: ColB should also be within [0, 10).
    ASSERT_TRUE(0 <= assert_colB && assert_colB < 10);
  }
  */
}
