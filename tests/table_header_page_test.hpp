#pragma once

TEST(TableHeaderPageTest, WriteThenReadOneColumn) {
  auto page_ptr = new Page();
  auto table_header_page = TableHeaderPage(page_ptr);

  auto table_name    = "foobar";
  auto column_name   = "string_column";
  auto table_oid     = 7;
  auto column_oid    = 15;
  auto string_length = 20;

  vector<TableColumn> cols;
  auto col = TableColumn(table_oid,
                         column_oid,
                         column_name,
                         string_length,
                         TypeId::VARCHAR,
                         false,
                         true,
                         true);
  cols.push_back(col);

  auto original = TableSchema(cols, table_name, table_oid);


  table_header_page.write_schema(original);
  auto copy = table_header_page.read_schema();

  EXPECT_EQ(copy.table_name(), original.table_name());
  EXPECT_EQ(copy.table_oid(),  original.table_oid());
  EXPECT_EQ(copy.all().size(), original.all().size());

  int32_t column_count = original.all().size();

  for (int32_t i = 0; i < column_count; ++i) {
    auto &col_copy = copy.all()[i];
    auto &col_orig = original.all()[i];

    EXPECT_EQ(col_copy.name(),             col_orig.name());

    EXPECT_EQ(col_copy.type_id(),          col_orig.type_id());
    EXPECT_EQ(col_copy.table_oid(),        col_orig.table_oid());
    EXPECT_EQ(col_copy.oid(),              col_orig.oid());
    EXPECT_EQ(col_copy.fixed_length(),     col_orig.fixed_length());
    EXPECT_EQ(col_copy.variable_length(),  col_orig.variable_length());

    EXPECT_EQ(col_copy.is_inlined(),       col_orig.is_inlined());
    EXPECT_EQ(col_copy.is_primary_key(),   col_orig.is_primary_key());
    EXPECT_EQ(col_copy.is_autoincrement(), col_orig.is_autoincrement());
    EXPECT_EQ(col_copy.is_nullable(),      col_orig.is_nullable());
  }

  delete page_ptr;
}

TEST(TableHeaderPageTest, DISABLED_WriteThenReadTwoColumns) {
  // BOOLEAN
  // TINYINT
  // SMALLINT
  // INTEGER
  // BIGINT
  // DECIMAL
  // VARCHAR(2)
  // VARCHAR(200)
  // TIMESTAMP
  // cols.push_back(make_string_column("stringB"));
}
