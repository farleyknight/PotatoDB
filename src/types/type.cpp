#include "types/type.hpp"
#include "types/boolean_type.hpp"
#include "types/tinyint_type.hpp"
#include "types/smallint_type.hpp"
#include "types/integer_type.hpp"
#include "types/bigint_type.hpp"
#include "types/decimal_type.hpp"
#include "types/timestamp_type.hpp"
#include "types/varchar_type.hpp"
#include "types/invalid_type.hpp"

#include "value/value.hpp"

const ptr<Type>& Type::instance(TypeId type_id) {
  static map<TypeId, ptr<Type>> types_;
  if (types_.empty()) {
    types_.emplace(TypeId::BOOLEAN,    make_unique<BooleanType>());
    types_.emplace(TypeId::TINYINT,    make_unique<TinyIntType>());
    types_.emplace(TypeId::SMALLINT,   make_unique<SmallIntType>());
    types_.emplace(TypeId::INTEGER,    make_unique<IntegerType>());
    types_.emplace(TypeId::BIGINT,     make_unique<BigIntType>());
    types_.emplace(TypeId::DECIMAL,    make_unique<DecimalType>());
    types_.emplace(TypeId::VARCHAR,    make_unique<VarCharType>());
    types_.emplace(TypeId::TIMESTAMP,  make_unique<TimestampType>());
    types_.emplace(TypeId::INVALID,    make_unique<InvalidType>());
  }

  return types_.at(type_id);
}

