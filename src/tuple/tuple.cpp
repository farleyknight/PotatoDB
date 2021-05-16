#include "tuple/tuple.hpp"
#include "catalog/table_schema.hpp"

// Constructor for creating a new tuple based on input value
// TODO: It does not look like nulls are supported. Add a null bitmap?
Tuple::Tuple(vector<Value> values, const QuerySchema& schema)
{
  if (values.size() != schema.column_count()) {
    std::cout << "values.size() == " << values.size() << std::endl;
    std::cout << "schema.column_count() == " << schema.column_count() << std::endl;
  }

  assert(values.size() == schema.column_count());

  // 1. Calculate the size of the tuple.
  uint32_t tuple_length = schema.tuple_length();
  for (auto &i : schema.unlined_columns()) {
    tuple_length += (values[i].length() + sizeof(string_size_t));
  }

  // std::cout << "Resizing tuple " << tuple_length << std::endl;

  buffer_.resize(tuple_length);
  assert(buffer_.size() == tuple_length);

  // 3. Serialize each attribute based on the input value.
  column_index_t column_count = schema.column_count();
  buffer_offset_t offset = schema.tuple_length();

  for (column_index_t i = 0; i < column_count; i++) {
    const auto &col = schema.by_column_oid(i);
    auto col_offset = schema.buffer_offset_for(i);

    if (col.is_inlined()) {
      values[i].cast_as(col.type_id()).serialize_to(col_offset, buffer_);
    } else {
      buffer_.write_uint32(col_offset, offset);
      auto value = values[i].cast_as(col.type_id());
      value.serialize_to(offset, buffer_);
      offset += (values[i].length() + sizeof(buffer_offset_t));
    }
  }
}

buffer_offset_t Tuple::buffer_offset_for(const QuerySchema& schema,
                                         column_oid_t column_oid) const
{
  auto is_inlined = schema.by_column_oid(column_oid).is_inlined();
  auto offset     = schema.buffer_offset_for(column_oid);

  // For inlined data types, data is stored where it is.
  if (is_inlined) {
    return offset;
  }
  // We read the relative offset from the tuple data.
  auto new_offset = buffer_.read_int32(offset);
  // And return the beginning address of the real data for the
  // VARCHAR type.
  return new_offset;
}

vector<Value> Tuple::to_values(const QuerySchema& schema) const
{
  vector<Value> values;
  for (column_index_t i = 0; i < schema.column_count(); ++i) {
    values.push_back(value(schema, i));
  }
  return values;
}

Tuple Tuple::add_defaults(deque<Value>& defaults,
                          const TableSchema& table_schema,
                          const QuerySchema& query_schema) const
{
  auto values = to_values(query_schema);
  vector<Value> new_values;

  for (const auto &col : table_schema.all()) {
    if (query_schema.has_column(col.name())) {
      // std::cout << "Found col w/ name " << col.name() << std::endl;
      auto index = query_schema.index_for(col.name());
      // std::cout << "Adding new value " << values[index].to_string() << std::endl;
      new_values.push_back(values[index]);
    } else {
      // std::cout << "Could not find col w/ name " << col.name() << std::endl;
      auto value = defaults.front();
      defaults.pop_front();
      // std::cout << "Adding new value " << value.to_string() << std::endl;
      new_values.push_back(value);
    }
  }

  auto schema = table_schema.to_query_schema();
  assert(table_schema.column_count() == schema.column_count());
  return Tuple(new_values, schema);
}

const string Tuple::to_string(const QuerySchema& schema) const {
  stringstream os;

  os << "(";
  for (column_index_t i = 0; i < schema.column_count(); ++i) {
    if (i > 0) {
      os << ", ";
    }

    if (is_null(schema, i)) {
      os << "NULL";
    } else {
      os << value(schema, i).to_string();
    }
  }
  os << ")";

  return os.str();
}

// NOTE: This method is different from ordinary `to_string`
// In particular, it's formatted to be sent over the network to the client
// Which means quoting strings, rendering boolean types to 'true'/'false'
//
// Likely more to this, but this explains the difference.
const string Tuple::to_payload(const QuerySchema& schema) const {
  stringstream os;

  os << "(";
  for (column_index_t i = 0; i < schema.column_count(); ++i) {
    if (i > 0) {
      os << ", ";
    }

    if (is_null(schema, i)) {
      os << "NULL";
    } else {
      auto curr_value = value(schema, i);
      if (curr_value.is_varchar()) {
        os << "'" << value(schema, i).to_string() << "'";
      } else {
        os << value(schema, i).to_string();
      }
    }
  }
  os << ")";

  return os.str();
}

Value Tuple::value(const QuerySchema& schema,
                   column_index_t column_index) const
{
  assert(column_index < schema.column_count());

  const TypeId type_id = schema.by_column_oid(column_index).type_id();
  const auto offset = buffer_offset_for(schema, column_index);

  return Value::deserialize_from(offset, buffer_, type_id);
}

Value Tuple::value_by_name(const QuerySchema& schema,
                           const column_name_t& name) const
{
  auto index = schema.index_for(name);
  return value(schema, index);
}

bool Tuple::is_null(const QuerySchema& schema,
                    column_index_t column_index) const
{
  return value(schema, column_index).is_null();
}

Tuple Tuple::key_from_tuple(const QuerySchema& schema,
                            const QuerySchema& key_schema,
                            const vector<uint32_t>& key_attrs) const
{
  vector<Value> values;
  values.reserve(key_attrs.size());
  for (auto i : key_attrs) {
    values.emplace_back(value(schema, i));
  }
  return Tuple(values, key_schema);
}

Tuple Tuple::random_from(const QuerySchema& schema) {
  vector<Value> values;
  for (const auto &col : schema.all()) {
    switch (col.type_id()) {
    case TypeId::BOOLEAN:
      values.push_back(ValueFactory::random_boolean());
      break;
    case TypeId::SMALLINT:
      values.push_back(ValueFactory::random_smallint());
      break;
    case TypeId::BIGINT:
      values.push_back(ValueFactory::random_bigint());
      break;
    case TypeId::INTEGER:
      values.push_back(ValueFactory::random_integer());
      break;
    case TypeId::VARCHAR:
      values.push_back(ValueFactory::random_varchar(col.variable_length()));
      break;
    default:
      throw NotImplementedException("This column type not implemented!");
    }
  }

  return Tuple(values, schema);
}
