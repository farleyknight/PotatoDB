#pragma once

#include <random>

static constexpr uint32_t TEST1_SIZE = 1000;
static constexpr uint32_t TEST2_SIZE = 100;
static constexpr uint32_t TEST_VARLEN_SIZE = 10;

enum class Dist : uint8_t {
  Uniform,
  Zipf_50,
  Zipf_75,
  Zipf_95,
  Zipf_99,
  Serial
};

struct ColumnInsertMeta {
  ColumnInsertMeta(String given_name,
                   const TypeId given_type,
                   bool given_nullable,
                   Dist given_dist,
                   uint64_t given_min,
                   uint64_t given_max)
    : name     (given_name),
      type     (given_type),
      nullable (given_nullable),
      dist     (given_dist),
      min      (given_min),
      max      (given_max) {}

  String name;
  const TypeId type;
  bool nullable;
  Dist dist;
  uint64_t min;
  uint64_t max;
  uint64_t serial_counter = 0;
};

struct TableInsertMeta {
public:
  TableInsertMeta(String given_name,
                  uint32_t given_num_rows,
                  MoveVec<ColumnInsertMeta> given_col_meta)
    : name     (given_name),
      num_rows (given_num_rows),
      col_meta (std::move(given_col_meta)) {}

  String name;
  uint32_t num_rows;
  vector<ColumnInsertMeta> col_meta;
};

class TableGenerator {
public:
  explicit TableGenerator(ExecCtx& exec_ctx)
    : exec_ctx_ (exec_ctx) {}

  void generate_test_tables() {
    /*
     * This array configures each of the test tables.
     * Each table is configured with a name, size, and schema.
     * We also configure the columns of the table. If
     * you add a new table, set it up here.
     */

    vector<TableInsertMeta> insert_meta {
      // The empty table
      TableInsertMeta {
        "empty_table",
        0,
        {
          {"colA", TypeId::INTEGER, false, Dist::Serial, 0, 0}
        }
      },

      // Table 1
      TableInsertMeta {
        "test_1",
        TEST1_SIZE,
        {
          {"colA", TypeId::INTEGER, false, Dist::Serial,  0, 0},
          {"colB", TypeId::INTEGER, false, Dist::Uniform, 0, 9},
          {"colC", TypeId::INTEGER, false, Dist::Uniform, 0, 9999},
          {"colD", TypeId::INTEGER, false, Dist::Uniform, 0, 99999}
        }
      },

      // Table 2
      TableInsertMeta {
        "test_2",
        TEST2_SIZE,
        {
          {"col1", TypeId::SMALLINT, false, Dist::Serial,  0, 0},
          {"col2", TypeId::INTEGER,  true,  Dist::Uniform, 0, 9},
          {"col3", TypeId::BIGINT,   false, Dist::Uniform, 0, 1024},
          {"col4", TypeId::INTEGER,  true,  Dist::Uniform, 0, 2048}
        }
      },

      // Table 3
      TableInsertMeta {
        "test_3",
        TEST2_SIZE,
        {
          {"col1", TypeId::INTEGER, false, Dist::Serial, 0, 0},
          {"col2", TypeId::INTEGER, true, Dist::Uniform, 10, 19},
          {"col3", TypeId::BIGINT, false, Dist::Uniform, 0, 1024},
          {"col4", TypeId::INTEGER, true, Dist::Uniform, 0, 2048}
        }
      },

      // Empty table with two columns
      TableInsertMeta {
        "empty_table2",
        0,
        {
          {"colA", TypeId::INTEGER, false, Dist::Serial, 0, 0},
          {"colB", TypeId::INTEGER, false, Dist::Uniform, 0, 9}
        }
      },

      // Empty table with two columns
      TableInsertMeta {
        "empty_table3",
        0,
        {
          {"outA", TypeId::INTEGER, false, Dist::Serial, 0, 0},
          {"outB", TypeId::INTEGER, false, Dist::Uniform, 0, 9}
        }
      }
    };

    for (auto &table_meta : insert_meta) {
      // Create Schema
      vector<Column> cols {};
      cols.reserve(table_meta.col_meta.size());
      for (const auto &col_meta : table_meta.col_meta) {
        if (col_meta.type != TypeId::VARCHAR) {
          cols.emplace_back(col_meta.name,
                            col_meta.type);
        } else {
          cols.emplace_back(col_meta.name,
                            col_meta.type,
                            TEST_VARLEN_SIZE);
        }
      }

      auto schema = Schema::make(move(cols));
      auto name  = String(table_meta.name);
      auto &info = exec_ctx_.create_table(exec_ctx_.txn(),
                                          move(name),
                                          move(schema));
      fill_table(info, table_meta);
    }
  }

  void fill_table(Ref<TableMeta> info, TableInsertMeta& table_meta) {
    uint32_t num_inserted = 0;
    uint32_t batch_size = 128;
    while (num_inserted < table_meta.num_rows) {
      vector<Vec<Value>> values;
      uint32_t num_values = std::min(batch_size,
                                     table_meta.num_rows - num_inserted);

      for (auto col_meta : table_meta.col_meta) {
        values.emplace_back(make_values(col_meta, num_values));
      }

      for (uint32_t i = 0; i < num_values; i++) {
        vector<Value> entry;
        entry.reserve(values.size());
        for (const auto &col : values) {
          entry.emplace_back(col[i]);
        }
        RID rid;
        bool inserted =
          info.table_heap().insert_tuple(Tuple(entry, info.schema()),
                                         rid,
                                         exec_ctx_.txn());

        assert(inserted); // "Sequential insertion cannot fail"
        num_inserted++;
      }
    }
  }

  template <typename CppType>
  Vec<Value> generate_numeric_values(ColumnInsertMeta& col_meta,
                                     uint32_t count)
  {
    vector<Value> values;
    if (col_meta.dist == Dist::Serial) {
      for (uint32_t i = 0; i < count; i++) {
        auto count = static_cast<CppType>(col_meta.serial_counter);
        values.emplace_back(Value(col_meta.type, count));
        col_meta.serial_counter += 1;
      }
      return values;
    }

    std::default_random_engine generator;
    // TODO(Amadou): Break up in two branches if this is too weird.
    std::conditional_t<std::is_integral_v<CppType>,
                       std::uniform_int_distribution<CppType>,
                       std::uniform_real_distribution<CppType>>
        distribution(static_cast<CppType>(col_meta.min),
                     static_cast<CppType>(col_meta.max));

    for (uint32_t i = 0; i < count; i++) {
      values.emplace_back(Value(col_meta.type, distribution(generator)));
    }
    return values;
  }

  Vec<Value> make_values(ColumnInsertMeta& col_meta,
                         uint32_t count)
  {
    switch (col_meta.type) {
    case TypeId::TINYINT:
      return generate_numeric_values<int8_t>(col_meta, count);
    case TypeId::SMALLINT:
      return generate_numeric_values<int16_t>(col_meta, count);
    case TypeId::INTEGER:
      return generate_numeric_values<int32_t>(col_meta, count);
    case TypeId::BIGINT:
      return generate_numeric_values<int64_t>(col_meta, count);
    case TypeId::DECIMAL:
      return generate_numeric_values<double>(col_meta, count);
    default:
      assert("Not yet implemented");
    }

    assert(false); // Should never reach here!

    Vec<Value> values;
    return values;
  }

private:
  ExecCtx& exec_ctx_;
};
