#include "tuple/tuple_layout.hpp"

tuple_length_t
TupleLayout::tuple_length(const vector<Value>& values) const
{
  // Calculate the size of the tuple.
  auto length = inlined_tuple_length_;
  for (auto i : unlined_columns_) {
    auto var_length = values[i].length() + sizeof(string_size_t);
    length += var_length;
  }
  return length;
}

void
TupleLayout::write_values(const vector<Value>& values,
                          Buffer& buffer) const
{
  auto var_len_offset  = inlined_tuple_length_;
  int32_t column_count = value_layouts_.size();

  for (column_index_t i = 0; i < column_count; i++) {
    const auto &col = value_layouts_[i];

    if (col.is_inlined()) {
      auto casted_value = values[i].cast_as(col.type_id());
      std::cout << "Inlined offset: " << col.offset() << std::endl;
      std::cout << "Inlined casted value: " << casted_value.to_string() << std::endl;
      casted_value.serialize_to(col.offset(), buffer);
    } else {
      std::cout << "Unlined offset: " << col.offset() << std::endl;
      buffer.write_offset(col.offset(), var_len_offset);
      auto casted_value = values[i].cast_as(col.type_id());
      std::cout << "var_len_offset " << var_len_offset << std::endl;
      std::cout << "Unlined casted value: " << casted_value.to_string() << std::endl;
      casted_value.serialize_to(var_len_offset, buffer);
      var_len_offset += (casted_value.length() + sizeof(buffer_offset_t));
    }
  }
}

// Constructor for creating a new tuple based on input value
// TODO: It does not look like nulls are supported. Add a null bitmap?
static Tuple
TupleLayout::make(const map<column_oid_t, Value>& values,
                  Txn& txn) const
{
  // Validate the values against the schema
  auto is_valid = validate(values);
  if (!is_valid) {
    txn.abort_with_reason(AbortReason::TUPLE_SCHEMA_MISMATCH);
    return;
  }

  auto buffer = Buffer(tuple_length(values));
  layout.write_values(values, buffer);
  return Tuple(buffer);
}

bool
TupleLayout::is_inlined(column_index_t index) const
{
  return by_column_index(index).is_inlined();
}

buffer_offset_t
TupleLayout::buffer_offset_for(const Tuple& tuple,
                               column_index_t index) const
{
  if (find(index).is_inlined()) {
    return find(index).offset();
  }

  auto offset = find(index).offset();
  // We read the relative offset from the tuple data.
  auto new_offset = tuple.read_offset(offset);
  buffer_offset_t buffer_size = buffer_.size();
  assert(new_offset < buffer_size);
  // And return the beginning address of the real data for the
  // VARCHAR type.
  return new_offset;
}

const vector<Value>
TupleLayout::to_values(const Tuple& tuple) const
{
  vector<Value> values;
  for (column_index_t index = 0; i < column_count(); ++index) {
    values.push_back(value_by_index(tuple, index));
  }
  return values;
}

void
TupleLayout::add_defaults(map<column_oid_t, Value>& value_map,
                          const map<column_oid_t, Value>& defaults,
                          Txn& txn) const
{
  for (const auto &value_layout : value_layouts_) {
    auto oid   = value_layout.oid();

    if (defaults.contains(oid) && !value_map.contains(oid)) {
      logger->debug("[TupleLayout] Could not find col w/ name: " + col.name());
      auto value = defaults.at(oid);
      logger->debug("[TupleLayout] Adding new value: " + value.to_string());
      value_map.emplace(oid, value);
    } else if (value_map.contains(oid)) {
      // NO-OP
      auto value = value_map.at(oid);
      logger->debug("[TupleLayout] Not touching existing value: " + value.to_string());
    } else {
      logger->debug("[TupleLayout] ABORT!: " + value_map.to_string());
      assert(false);
      // TODO: Time to ABORT!
    }
  }
}

const string
TupleLayout::to_string(const TableSchema& schema) const
{
  // assert(source_ == TupleSources::TABLE_HEAP);

  stringstream os;

  os << "(";
  for (int32_t i = 0; i < schema.column_count(); ++i) {
    if (i > 0) {
      os << ", ";
    }

    auto val = value_by_index(tuple, i);

    // TODO: We need to properly implement NULL!
    if (val.is_null()) {
      os << "NULL";
    } else {
      os << val.to_string();
    }
  }
  os << ")";

  return os.str();
}

const string
TupleLayout::to_string(const Tuple& tuple) const
{
  stringstream os;

  os << "(";
  for (column_index_t index = 0; index < column_count(); ++index) {
    if (index > 0) {
      os << ", ";
    }

    auto val = value_by_index(schema, index);

    // TODO: We need to properly implement NULL!
    if (val.is_null()) {
      os << "NULL";
    } else {
      os << val.to_string();
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
const string
TupleLayout::to_payload(const Tuple& tuple) const
{
  stringstream os;

  os << "(";
  for (column_index_t index = 0; index < column_count(); ++index) {
    if (index > 0) {
      os << ", ";
    }

    if (is_null(tuple, index)) {
      os << "NULL";
    } else {
      auto curr_value = value_by_index(tuple, index);
      if (curr_value.is_varchar()) {
        os << "'" << curr_value.to_string() << "'";
      } else {
        os << curr_value.to_string();
      }
    }
  }
  os << ")";

  return os.str();
}

Value
TupleLayout::value_by_column_index(const Tuple& tuple,
                                   column_index_t index) const
{
  assert(index < column_count());

  TypeId type_id = by_column_index(index).type_id();
  auto offset = buffer_offset_for(index);

  assert(offset < buffer_.size());
  // TODO: I think we should move Value::deserialize_from into the
  // ValueLayout class
  // I think Layouts are responsible for serialize & deserializing objects.
  //
  // Instead actually I would prefer the method be called `read_value/write_value`
  return Value::deserialize_from(offset, tuple.buffer(), type_id);
}

Value
TupleLayout::value_by_oid(const Tuple& tuple,
                          column_oid_t oid) const
{
  auto index = column_index_for(oid);
  return value_by_index(tuple, index);
}

bool
TupleLayout::is_null(const Tuple& tuple,
                     column_index_t index) const
{
  return value_by_index(tuple, index).is_null();
}

Tuple
Tuple::key_from_tuple(const Tuple& tuple,
                      const QuerySchema& key_schema,
                      // TODO: key_attrs should NOT be a vector of column indices
                      // It *should* be a vector of column OIDs
                      const vector<column_oid_t>& key_attributes,
                      Txn& txn) const
{
  map<column_oid_t, Value> values;
  values.reserve(key_attributes.size());
  for (auto oid : key_attributes) {
    values.emplace(oid, value_by_oid(tuple, oid));
  }
  return make(values, txn);
}

Tuple
TupleLayout::random_from()
{
  map<column_oid_t, Value> values;
  for (const auto &layout : value_layouts_) {
    switch (col.type_id()) {
    case TypeId::BOOLEAN:
      values.emplace(col.oid(),
                     ValueFactory::random_boolean());
      break;
    case TypeId::SMALLINT:
      values.emplace(col.oid(),
                     ValueFactory::random_smallint());
      break;
    case TypeId::BIGINT:
      values.emplace(col.oid(),
                     ValueFactory::random_bigint());
      break;
    case TypeId::INTEGER:
      values.emplace(col.oid(),
                     ValueFactory::random_integer());
      break;
    case TypeId::VARCHAR:
      values.emplace(col.oid(),
                     ValueFactory::random_varchar(col.variable_length()));
      break;
    default:
      // TODO: Probably should abort the transaction?
      // That seems the like the right way to handle this.
      // System errors can sometimes be contained to a specific transaction
      // and therefore not effect other transactions.
      throw NotImplementedException("This column type not implemented!");
    }
  }

  return make(values, txn);
}

void
TupleLayout::push_back(TypeId type_id,
                       buffer_offset_t buffer_offset,
                       bool is_inlined)
{
  if (!is_inlined) {
    column_index_t index = value_layouts_.size();
    unlined_columns_.push_back(index);
    all_tuples_inlined_ = false;
  }
  auto new_layout = ValueLayout(type_id, buffer_offset, is_inlined);
  value_layouts_.push_back(new_layout);
}

// TODO: Pass in ref to Txn and abort the txn if the validation fails.
bool
TupleLayout::validate(const vector<Value>& values) const
{
  // Check size
  int32_t values_size = values.size();

  if (values_size != column_count()) {
    std::cout << "values.size() == "
              << values.size() << std::endl;
    std::cout << "schema.column_count() == "
              << column_count() << std::endl;
    assert(values_size == column_count());
  }

  // Check value types versus schema types
  //
  // TODO: Write proper error handling should be a good next step
  // towards being a robust database.
  for (int32_t i = 0; i < values_size; ++i) {
    assert(values[i].type_id() == find(i).type_id());
  }

  return true;
}

const string
TupleLayout::to_string() const {
  stringstream os;

  os << "NumColumns:"         << value_layouts_.size()  << ", "
     << "IsInlined:"          << all_tuples_inlined_    << ", "
     << "InlinedTupleLength:" << inlined_tuple_length_;

  return os.str();
}
