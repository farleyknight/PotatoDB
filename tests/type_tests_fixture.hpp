#pragma once

class TypeTests : public ::testing::Test { 
public:
  template<typename value_t>
  void InstanceTest(TypeId type_id, value_t min, value_t max) {
    auto &type_instance = Type::instance(type_id);

    EXPECT_EQ(type_id, type_instance->type_id());
    EXPECT_TRUE(type_instance->is_castable_from(type_id));

    EXPECT_EQ(type_instance->size(), sizeof(value_t));
    EXPECT_EQ(type_instance->min().as<value_t>(), min);
    EXPECT_EQ(type_instance->max().as<value_t>(), max);
  }

  template<typename value_t>
  void InstanceTest(TypeId type_id) {
    InstanceTest<value_t>(type_id,
                          std::numeric_limits<value_t>::min(),
                          std::numeric_limits<value_t>::max());
  }

  template<typename value_t>
  void SerializeAndDeserialize(TypeId type_id, value_t data1, value_t data2) {
    Buffer buff(sizeof(value_t));
    auto &type_instance = Type::instance(type_id);

    type_instance->serialize_to(buff, Value::make(data1));
    auto val = type_instance->deserialize_from(buff);
    EXPECT_EQ(val.as<value_t>(), data1);

    type_instance->serialize_to(buff, Value::make(data2));
    auto val2 = type_instance->deserialize_from(buff);
    EXPECT_EQ(val2.as<value_t>(), data2);
  }

  template<typename value_t>
  void SerializeAndDeserialize(TypeId type_id) {
    SerializeAndDeserialize<value_t>(type_id,
                                     std::numeric_limits<value_t>::min(),
                                     std::numeric_limits<value_t>::max());
  }

};

