
// TODO: Get tests from MiniSQL

TEST(TupleTest, DISABLED_SerializeAndDeserializeTest) {
  // // Make values
  // auto &schema = Parser::statement();

  // // Make schema
  // Tuple tuple = Tuple::make(values, schema);

  // auto &buff = tuple.buff();

  // BufferRW rw;

  // auto &first_column = schema["first_column"];
  // rw.seek(0);
  // EXPECT_EQ(rw.read_column(buff, first_column), first_value);
  // rw.forward(first_column.size());

  // auto &second_column = schema["second_column"];
  // EXPECT_EQ(rw.read_column(buff, second_column), second_value);
  // rw.forward(first_column.size());

  //
}

TEST(TupleTest, MemoryAllocationTest) {
  // uint32_t varchar_length = 10;

  // MutVec<Column> columns {
  //   Column("column_name", TypeId::VARCHAR, varchar_length)
  // };
  // const Schema schema(move(columns));

  // MutVec<Value> values;
  // values.reserve(schema.column_count());

  // uint32_t len = 5;
  // String new_string = random_string();
  // Value value {TypeId::VARCHAR, my_string, len+1, true};

  // values.push_back(value);

  // uint32_t tuple_size = schema.length();
  // for (auto &column_index : schema.unlined_columns()) {
  //   tuple_size += (values[column_index].length() + sizeof(uint32_t));
  // }

  // EXPECT_EQ(tuple_size, 22);
}

TEST(TupleTest, ToStringTest) {
  // uint32_t varchar_length = 10;

  // MutVec<Column> columns {
  //   Column("column_name", TypeId::VARCHAR, varchar_length)
  // };
  // const Schema schema(move(columns));

  // MutVec<Value> values;
  // values.reserve(schema.column_count());

  // uint32_t len = 5;
  // char *my_string = strdup("abcde");

  // values.emplace_back(TypeId::VARCHAR, my_string, len+1, true);
  // Tuple tuple(values, schema);

  // EXPECT_EQ(tuple.size(), varchar_length + Type::size(TypeId::VARCHAR));
  // EXPECT_EQ(tuple.to_string(schema), "(abcde) Tuple size is 22");
}

TEST(TupleTest, RidTest) {
  // Tuple tuple;

  // EXPECT_EQ(tuple.rid(), RID());
}
