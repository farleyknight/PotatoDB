#pragma once

#include "buffer/buffer.hpp"

#include "catalog/query_schema.hpp"

#include "tuple/rid.hpp"
#include "tuple/tuple_layout.hpp"
#include "value/value.hpp"
#include "value/value_factory.hpp"

class Txn;

enum class TupleSources {
  TABLE_HEAP   = 0,
  QUERY_SCHEMA = 1,
  LOG_RECOVERY = 2
};

// TODO:
// There is an anti-pattern hidden in this class
// We construct Tuples via vector<Value> but that
// does not always work out.
//
// The problem is that that there are many parts of the code
// that construct & manipulate tuples.
//
// But in actuality, we should really delegate Tuple reading/writing
// into the ResultSet class.
// Imagine if we set it up such that `ResultSet` automatically
// maintains a vector<Tuple> and a QuerySchema for those tuples.
//
//
// auto results = ResultSet(..)
// while (exec_eng.has_next()) {
//   /* Version 1 */
//   exec_eng.fetch_next();
//
//   /* Version 2, if we need to do any processing on the value map */
//   auto value_map = exec_eng.next_value_map();
//   results.new_tuple(value_map);
// }
//
// EXPECT_EQ(exec_eng.results(), results);

class Tuple {
public:
  Tuple(TupleSources source)
    : source_ (source)
  {}

  explicit Tuple(tuple_length_t length)
    : source_ (TupleSources::TABLE_HEAP),
      buffer_ (length)
  {}

  explicit Tuple(RID rid)
    : rid_    (rid),
      source_ (TupleSources::TABLE_HEAP)
  {}

  explicit Tuple(Buffer buffer)
    : source_ (TupleSources::LOG_RECOVERY),
      buffer_ (buffer)
  {}

  // Destructor
  ~Tuple() = default;

  void
  resize_buffer(tuple_length_t tuple_length);

  bool is_valid() const {
    return rid_.has_value();
  }

  void copy_from(const Tuple& tuple) {
    buffer_.copy_from(tuple.buffer_);
  }

  bool eq(const Tuple& tuple) {
    if (size() != tuple.size()) {
      return false;
    }

    return std::memcmp(buffer_.char_ptr(),
                       tuple.buffer_.char_ptr(), buffer_.size()) == 0;
  }

  ///////////////////////////////////////////////////
  // TODO: Move the methods BELOW into TupleLayout //
  ///////////////////////////////////////////////////

  ///////////////////////////////////////////////////
  // TODO: Move the methods ABOVE into TupleLayout //
  ///////////////////////////////////////////////////


  const RID rid()               const { return rid_.value(); }
  void set_rid(RID rid)               { rid_.emplace(rid); }
  int32_t size()                const { return buffer_.size(); }

  void reset(size_t new_size) {
    buffer_.resize(new_size);
    fill(buffer_.begin(), buffer_.end(), 0);
  }

  const PageId page_id() const { return rid_->page_id(); }


  // TODO: Rename this method to `copy_tuple` or something
  // That is effectively what it's doing.
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
  // TODO: Change this to an integer that can be casted to a RID
  optional<RID> rid_ = nullopt;
  TupleSources source_ = TupleSources::TABLE_HEAP;
  Buffer buffer_;
};
