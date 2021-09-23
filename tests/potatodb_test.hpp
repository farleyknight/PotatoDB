#pragma once

#include "server/potatodb.hpp"
#include "server/system_catalog.hpp"
#include "gtest/gtest.h"

class PotatoDBTest : public ::testing::Test {
public:
  PotatoDB db;

  void SetUp() override {
    ::testing::Test::SetUp();
    db.reset_installation();
  }

  void TearDown() override {
    ::testing::Test::TearDown();
  }
};

TEST_F(PotatoDBTest, ShowZeroTablesTest) {
  auto result = db.run("SHOW TABLES");
  auto &result_set = result.set();

  ASSERT_EQ(result_set->size(), 0);
}

TEST_F(PotatoDBTest, CreateInsertSelectStringTest) {
  db.run("CREATE TABLE test_table ( colA INTEGER, colB VARCHAR(32) )");
  db.run("INSERT INTO test_table VALUES (1, 'hello, world')");
  auto result = db.run("SELECT * FROM test_table");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);

  EXPECT_EQ(result.set()->value_at<int32_t>("colA", 0), 1);
  EXPECT_EQ(result.set()->value_at<string>("colB", 0), "hello, world");
}

TEST_F(PotatoDBTest, CreateInsertSelectAutoIncrementTest) {
  db.run("CREATE TABLE test_table (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(32))");
  db.run("INSERT INTO test_table (name) VALUES ('hello, world')");
  db.run("INSERT INTO test_table (name) VALUES ('another string')");

  auto result = db.run("SELECT * FROM foo_bar");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 2);

  EXPECT_EQ(result.set()->value_at<int32_t>("id", 0), 1);
  EXPECT_EQ(result.set()->value_at<string>("name", 0), "hello, world");

  EXPECT_EQ(result.set()->value_at<int32_t>("id", 1), 2);
  EXPECT_EQ(result.set()->value_at<string>("name", 1), "another string");
}

TEST_F(PotatoDBTest, AggegrationTest) {
  db.run("CREATE TABLE agg_test ( colA INTEGER )");

  const int size = 10;

  for (index_t i = 0; i < size; ++i) {
    db.run("INSERT INTO agg_test VALUES (" + std::to_string(i) + ")");
  }

  auto result
    = db.run("SELECT COUNT(colA), SUM(colA), MIN(colA), MAX(colA) FROM agg_test");

  EXPECT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);

  EXPECT_EQ(result.set()->schema().all().size(), 4u);

  auto countA = result.set()->value_at<int32_t>("COUNT(colA)", 0);
  auto sumA   = result.set()->value_at<int32_t>("SUM(colA)", 0);
  auto minA   = result.set()->value_at<int32_t>("MIN(colA)", 0);
  auto maxA   = result.set()->value_at<int32_t>("MAX(colA)", 0);

  EXPECT_EQ(countA, size);
  EXPECT_EQ(sumA,   (size*(size-1)) / 2);
  EXPECT_EQ(minA,   0);
  EXPECT_EQ(maxA,   size-1);
}

TEST(PotatoDBTest, DISABLED_AlterTableDropColumnTest) {
  // TODO!
  // Now that we have the TableFileMgr, we can actually tackle this!
}

TEST(PotatoDBTest, DISABLED_AlterTableAddColumnTest) {
  // TODO!
  // Now that we have the TableFileMgr, we can actually tackle this!
}

TEST(PotatoDBTest, DISABLED_AlterTableRenameColumnTest) {
  // TODO!
  // Now that we have the TableFileMgr, we can actually tackle this!
}


TEST(PotatoDBTest, ConversionBetweenIncompatibleTypesMismatchTest) {
  PotatoDB db;

  // TODO
  // Write a test that specifies to the user that there was a schema
  // mismatch during an INSERT or UPDATE command.

  // Example:

  // UPDATE foo_bar SET date_column = true WHERE id = 3
  //
  // Should throw an error that shows the `foo_bar` schema
  // and in that schema, it should highlight the column that
  // is trying to be updated, namely `date_column`.
  //
  // As you would expect, `date_column` should have type DATE
  //
  // The incompatible column in the foo_bar schema is highlighted below:
  //
  // At this point, we should run the command DESCRIBE TABLE foo_bar,
  // with the necessary highlighting.
}


// TODO: For now let's skip anything related to indexes
TEST(ExecTest, DISABLED_SimpleRawInsertWithIndexTest) {
  /*
   *

   // Create Values to insert
   vector<vector<Value>> data {
   {Value::make(100), Value::make(10)},
   {Value::make(101), Value::make(11)},
   {Value::make(102), Value::make(12)}
   };

   auto empty_table2 = QueryBuilder(schema_mgr()).table("empty_table2");

   // INSERT INTO foo_bar VALUES (100, 10), (101, 11), (102, 12)
   auto insert_values_plan = PlanBuilder(schema_mgr()).
   insert_into(empty_table2).
   tuples(RawTuples(data)).
   to_plan();

   auto colA = empty_table2["colA"];
   auto colB = empty_table2["colB"];
   auto key_schema = QuerySchema({colA});

   */

  // auto &txn = txn_mgr().begin();

  /*
   *
   GenericComp comparator(*key_schema);
   auto &index_meta =
   schema_mgr().create_index(txn,
   "index1",
   "empty_table2");

   */

  /*
    NOTE: For now let's skip anything related to indexes

   schema_mgr().table_schem_for("empty_table2"),
   move(key_schema),
   {0}, 8);

   */

  /*
   *

  execute(move(insert_values_plan));

  // Iterate through table make sure that values were inserted.
  // SELECT * FROM empty_table2;
  auto scan_plan = PlanBuilder(schema_mgr()).
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
TEST(ExecTest, DISABLED_SimpleIndexDeleteTest) {
  // CREATE INDEX ( a ) ON TABLE foo_bar;
  // SELECT colA FROM foo_bar WHERE colA == 50
  // DELETE FROM foo_bar WHERE colA == 50
  // SELECT colA FROM foo_bar WHERE colA == 50

  /*
   *

  MutVec<QueryColumn> cols {
    Column("a", TypeId::BIGINT)
  };
  auto key_schema = Schema::make(move(cols));

  GenericComp comparator(*key_schema);
  auto &index_schema = schema_mgr().table("foo_bar").schema();

  auto &txn = txn_mgr().begin();

  auto &index_meta =
    schema_mgr().create_index(txn,
                           "index1",
                           "foo_bar",
                           index_schema,
                           move(key_schema), {0}, 8);

  // Construct query plan
  auto scan_plan1 = PlanBuilder(schema_mgr()).
    select({"colA"}).
    from("foo_bar").
    where("colA", "==", 50).
    to_plan();

  // Execute
  auto result_set1 = query(move(scan_plan1));

  // Verify
  ASSERT_EQ(result_set1->value_at<int>("colA", 0), 50);
  ASSERT_EQ(result_set1->size(), 1);

  Tuple index_key(result_set1->results()[0]);

  auto delete_plan = PlanBuilder(schema_mgr()).
    delete_from("foo_bar").
    where("colA", "==", 50).
    to_plan();

  execute(move(delete_plan));

  // Construct query plan
  auto scan_plan2 = PlanBuilder(schema_mgr()).
    select({"colA"}).
    from("foo_bar").
    where("colA", "==", 50).
    to_plan();

  auto result_set2 = query(move(scan_plan2));

  ASSERT_EQ(result_set2->results().size(), 0);

  auto rids = index_meta.scan_key(index_key, txn);
  ASSERT_TRUE(rids.empty());
  */
}

TEST(ExecTest, LoopJoinTest) {
  // SELECT foo_bar.colA, foo_bar.colB, test_2.col1, test_2.col3
  // FROM foo_bar
  // JOIN test_2
  // ON foo_bar.colA = test_2.col1

  /* 
  auto loop_join_plan = PlanBuilder(schema_mgr()).
    select({
        "foo_bar.colA", "foo_bar.colB",
        "test_2.col1", "test_2.col3"
      }).
    from("foo_bar").
    loop_join("test_2").
    on("foo_bar.colA", "==", "test_2.col1").
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
TEST(ExecTest, HashJoinTest) {
  // SELECT foo_bar.colA, foo_bar.colB, test_2.col1, test_2.col3
  // FROM foo_bar
  // JOIN test_2
  // ON foo_bar.colA = test_2.col1

  /*

  auto hash_join_plan = PlanBuilder(schema_mgr()).
    select({
        "foo_bar.colA", "foo_bar.colB",
        "test_2.col1", "test_2.col3"
      }).
    from("foo_bar").
    hash_join("test_2").
    on("foo_bar.colA", "==", "test_2.col1").
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
TEST(ExecTest, SimpleAggTest) {
  // SELECT COUNT(colA), SUM(colA), MIN(colA), MAX(colA) from foo_bar;

  /**************************************************
   * TODO: This is the new version of PlanBuilder.
   **************************************************/

  /*
  auto foo_bar = QueryBuilder(schema_mgr()).table("foo_bar");

  auto agg_plan = PlanBuilder(schema_mgr()).
    select({
        QueryAgg::count(foo_bar["colA"]),
        QueryAgg::sum(foo_bar["colA"]),
        QueryAgg::min(foo_bar["colA"]),
        QueryAgg::max(foo_bar["colA"])
      }).
    from(foo_bar).
    to_plan();
  */

  /**************************************************
   * TODO: The code below should be functionally
   * identical to the code above.
   **************************************************/

  /*
  auto &meta = schema_mgr().table("foo_bar");
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

  auto countA_val = result_set->value<int32_t>("countA", first_tuple);
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
TEST(ExecTest, SimpleGroupByAggTest) {
  // SELECT COUNT(colA), colB, SUM(colC)
  // FROM foo_bar
  // GROUP BY colB
  // HAVING COUNT(colA) > 100

  // auto foo_bar = QueryBuilder(schema_mgr()).table("foo_bar");

  /**************************************************
   * TODO: This is the new version of PlanBuilder.
   **************************************************/

  /*
  auto agg_plan = PlanBuilder(schema_mgr()).
    select({
        AggExpr::count(foo_bar["colA"]),
        foo_bar["colB"],
        AggExpr::sum(foo_bar["colC"])
      }).
    from(test1).
    group_by(foo_bar["colB"]).
    having(AggExpr::count(foo_bar["colA"]),
           ">",
           ConstExpr::make<int>(100)).
    to_plan();
  */
  /**************************************************
   * TODO: The code below should be functionally
   * identical to the code above.
   **************************************************/

  /*
  auto &meta = schema_mgr().table("foo_bar");
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
                                      ComparisonType::GT,
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

