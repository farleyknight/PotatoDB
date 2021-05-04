
#include "value/value_factory.hpp"

Value ValueFactory::from_column(BaseColumn column) {
  switch (column.type_id()) {
  case TypeId::BOOLEAN:
    return random_boolean();

  case TypeId::SMALLINT:
    return random_smallint();

  case TypeId::BIGINT:
    return random_bigint();

  case TypeId::VARCHAR:
    return random_varchar(column.variable_length());

  default:
    throw Exception(ExceptionType::NOT_IMPLEMENTED,
                    "Random type not implemented!");
  }
}

String ValueFactory::random_string(uint32_t length) {
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  // mt19937 is a standard mersenne_twister_engine
  std::mt19937 generator(seed);

  static const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

  auto random_length = static_cast<uint32_t>(1 + generator() % (length - 1));
  std::string random_string;
  random_string.reserve(random_length);
  for (uint32_t i = 0; i < random_length; ++i) {
    random_string += alphanum[generator() % (sizeof(alphanum) - 1)];
  }
  return random_string;
}
