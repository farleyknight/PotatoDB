#pragma once

#include "buffer/buffer.hpp"

#include "catalog/query_schema.hpp"

#include "tuple/rid.hpp"
#include "value/value.hpp"
#include "value/value_factory.hpp"

class Tuple {
public:
  Tuple() = default;

  Tuple(uint32_t size)
    : buffer_ (size)
  {}

  // Constructor for table heap tuple
  // NOTE: Has no data
  Tuple(RID rid) : rid_(rid) {}
  // Provide values w/ schema

  Tuple(vector<Value> values, const QuerySchema& schema);

  // Destructor
  ~Tuple() = default;

  bool is_valid() const {
    return rid_.has_value();
  }

  buffer_offset_t buffer_offset_for(const QuerySchema& schema,
                                    column_oid_t column_index) const;

  void copy_from(const Tuple& tuple) {
    buffer_.copy_from(tuple.buffer_);
  }

  Value value(const QuerySchema& schema,
              column_index_t column_index) const;

  Value value_by_name(const QuerySchema& schema,
                      const column_name_t& name) const;

  bool is_null(const QuerySchema& schema,
               uint32_t column_index) const;

  Tuple key_from_tuple(const QuerySchema& schema,
                       const QuerySchema& key_schema,
                       const vector<uint32_t>& key_attrs) const;

  const RID rid()               const { return rid_.value(); }
  void set_rid(RID rid)               { rid_.emplace(rid); }

  size_t size()                 const { return buffer_.size(); }

  void reset(size_t new_size) {
    buffer_.resize(new_size);
    fill(buffer_.begin(), buffer_.end(), 0);
  }

  const PageId page_id() const { return rid_->page_id(); }

  vector<Value> to_values(const QuerySchema& schema) const;
  Tuple add_defaults(deque<Value>& defaults,
                     const TableSchema& table_schema,
                     const QuerySchema& query_schema) const;

  void copy_n_bytes(size_t source_offset,
                    size_t dest_offset,
                    const Buffer& source_buffer,
                    size_t n_bytes)
  {
    //assert(buffer_.size() >= n);
    // TODO: Handle this inside the Buffer
    memcpy(buffer_.ptr() + dest_offset,
           source_buffer.cptr() + source_offset,
           n_bytes);
  }

  const string to_string(const QuerySchema& schema) const;
  const string to_payload(const QuerySchema& schema) const;

  static Tuple random_from(const QuerySchema& schema);

  Buffer& buffer() {
    return buffer_;
  }

  const Buffer& buffer() const {
    return buffer_;
  }

private:
  optional<RID> rid_ = nullopt;
  Buffer buffer_;
};
