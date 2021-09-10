#pragma once

#include "buffer/buffer.hpp"

#include "catalog/query_schema.hpp"

#include "tuple/rid.hpp"
#include "value/value.hpp"
#include "value/value_factory.hpp"

enum class TupleSources {
  TABLE_HEAP   = 0,
  QUERY_SCHEMA = 1,
  LOG_RECOVERY = 2
};

class Tuple {
public:
  Tuple() = default;

  explicit Tuple(int32_t size)
    : source_ (TupleSources::TABLE_HEAP),
      buffer_ (size)
  {}

  explicit Tuple(RID rid)
    : rid_    (rid),
      source_ (TupleSources::TABLE_HEAP)
  {}

  explicit Tuple(vector<Value> values, const QuerySchema& schema);

  explicit Tuple(Buffer buffer)
    : source_ (TupleSources::LOG_RECOVERY),
      buffer_ (buffer)
  {}

  // Destructor
  ~Tuple() = default;

  bool is_valid() const {
    return rid_.has_value();
  }

  buffer_offset_t
  buffer_offset_for(const auto& schema,
                    column_index_t index) const;

  void copy_from(const Tuple& tuple) {
    buffer_.copy_from(tuple.buffer_);
  }

  bool eq(const Tuple& tuple) {
    if (size() != tuple.size()) {
      return false;
    }

    return std::memcmp(buffer_.char_ptr(), tuple.buffer_.char_ptr(), buffer_.size()) == 0;
  }

  Value value(const auto& schema, column_index_t column_index) const;

  Value value_by_name(const QuerySchema& schema, const column_name_t& name) const;

  Value value_by_oid(const auto& schema, column_oid_t oid) const;

  bool is_null(const auto& schema,
               column_index_t column_index) const;

  Tuple key_from_tuple(const QuerySchema& schema,
                       const QuerySchema& key_schema,
                       const vector<int32_t>& key_attrs) const;

  const RID rid()               const { return rid_.value(); }
  void set_rid(RID rid)               { rid_.emplace(rid); }
  int32_t size()                const { return buffer_.size(); }

  void reset(size_t new_size) {
    buffer_.resize(new_size);
    fill(buffer_.begin(), buffer_.end(), 0);
  }

  const PageId page_id() const { return rid_->page_id(); }

  vector<Value> to_values(const QuerySchema& schema) const;
  Tuple add_defaults(deque<Value>& defaults,
                     const TableSchema& table_schema,
                     const QuerySchema& query_schema) const;

  // TODO: Rename this method
  void copy_n_bytes(buffer_offset_t source_offset,
                    buffer_offset_t dest_offset,
                    const Buffer& source_buffer,
                    buffer_offset_t n_bytes)
  {
    // TODO: Handle this inside the Buffer
    memcpy(buffer_.ptr(dest_offset),
           source_buffer.const_ptr(source_offset),
           n_bytes);
  }

  const string to_string(const TableSchema& schema) const;
  const string to_string(const QuerySchema& schema) const;
  const string to_payload(const QuerySchema& schema) const;

  static Tuple random_from(const QuerySchema& schema);

  Buffer& buffer() {
    return buffer_;
  }

  const Buffer& buffer() const {
    return buffer_;
  }

  void set_source(TupleSources source) {
    source_ = source;
  }

private:
  // TODO: Change this to a pointer.
  optional<RID> rid_ = nullopt;
  TupleSources source_ = TupleSources::TABLE_HEAP;
  Buffer buffer_;
};
