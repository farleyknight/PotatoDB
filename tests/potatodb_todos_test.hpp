#pragma once

const string join_with_commas(const vector<string> values) {
  stringstream ss;
  for (index_t i = 0; i < values.size(); ++i) {
    if (i > 0) {
      ss << ",";
    }
    ss << values[i];
  }
  return ss.str();
}

void create_todo_table(PotatoDB& db, const index_t size) {
  const vector<string> columns = {
    "id INTEGER PRIMARY KEY AUTOINCREMENT",
    "name VARCHAR(32)",
    "done BOOLEAN",
    "created_at TIMESTAMP",
    "updated_at TIMESTAMP"
  };

  db.run("CREATE TABLE todos (" +
         join_with_commas(columns) + ")");


  for (index_t i = 0; i < size; ++i) {
    const vector<string> values = {
      "'Task #" + std::to_string(i) + "'",
      "false",
      "NOW()",
      "NOW()"
    };

    db.run("INSERT INTO todos ( name, done, created_at, updated_at ) VALUES (" +
                     join_with_commas(values) + ")");
  }
}

TEST(TodoAppTest, CountStarTest) {
  PotatoDB db;
  db.reset_installation();
  const int size = 10;
  create_todo_table(db, size);

  auto result = db.run("SELECT COUNT(*) FROM todos");
  ASSERT_TRUE(result.set() != nullptr);
  EXPECT_EQ(result.set()->size(), 1);
  EXPECT_EQ(result.set()->value_at<int32_t>("COUNT(*)", 0), size);
}

TEST(TodoAppTest, InsertTest) {
  // TODO:
  // Use create_todo_table
  // Create 10 TODOs
  // Verify each of the `id`s are auto-incrementing.
}

TEST(TodoAppTest, SortingTest) {
  PotatoDB db;
  db.reset_installation();
  const int size = 10;
  create_todo_table(db, size);

  auto asc_result = db.run("SELECT * FROM todos ORDER BY id ASC");
  ASSERT_TRUE(asc_result.set() != nullptr);
  ASSERT_EQ(asc_result.set()->size(), 10);
  for (index_t i = 0; i < size; ++i) {
    auto name = asc_result.set()->value_at<string>("name", i);
    EXPECT_EQ(name, "Task #" + std::to_string(i));
  }

  auto desc_result = db.run("SELECT * FROM todos ORDER BY id DESC");
  EXPECT_TRUE(desc_result.set() != nullptr);
  ASSERT_EQ(desc_result.set()->size(), 10);
  for (index_t i = 0; i < size; ++i) {
    auto name = desc_result.set()->value_at<string>("name", i);
    EXPECT_EQ(name, "Task #" + std::to_string(size - 1 - i));
  }
}

TEST(TodoAppTest, UpdateWhereTest) {
  PotatoDB db;
  db.reset_installation();
  const int size = 10;
  create_todo_table(db, size);

  db.run("UPDATE todos SET done = true WHERE id = 3");

  auto result = db.run("SELECT * FROM todos");
  EXPECT_TRUE(result.set() != nullptr);

  EXPECT_EQ(result.set()->size(), size);
  for (index_t i = 0; i < size; ++i) {
    auto id   = result.set()->value_at<int32_t>("id", i);
    auto done = result.set()->value_at<bool>("done", i);
    if (id == 3) {
      EXPECT_EQ(done, true);
    } else {
      EXPECT_EQ(done, false);
    }
  }
}

TEST(TodoAppTest, DeleteWhereTest) {
  PotatoDB db;
  db.reset_installation();
  const int size = 10;
  create_todo_table(db, size);

  db.run("DELETE FROM todos WHERE id = 3");

  auto result = db.run("SELECT * FROM todos");
  EXPECT_TRUE(result.set() != nullptr);

  EXPECT_EQ(result.set()->size(), size-1);
  int expected_id = 1;
  for (index_t i = 0; i < size-1; ++i) {
    if (expected_id == 3) {
      ++expected_id;
    }

    auto id = result.set()->value_at<int32_t>("id", i);
    EXPECT_EQ(id, expected_id);
    ++expected_id;
  }
}
