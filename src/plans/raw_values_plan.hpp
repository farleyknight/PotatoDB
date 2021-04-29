#pragma once

#include "plans/base_plan.hpp"

// TODO: RawValueSet is a big chunk of memory that will NEED to be `move`-ed around.
// And I don't want to do that.
//
// I want to write all of these values to a buffer in the buffer pool.
// I want a page_id to get that buffer back.
//
// All of this requires having a better understanding on how to do this on a
// byte-array.
//
// I'm noticing also that I'm getting frustrated with the way I'm writing code
// because I'm not sure if something is fast or slow, involves lots of memory/
// or only a little..
//
// I'm starting to think about going back to the Jupyter notebooks to do
// some byte-level operations with C++. Learning the DB by looking at the
// tuples as bytes in memory!
//
// That might be a helpful way to learn this stuff.. By looking at the bytes.
// That also might be a starting point for doing performance testing.
// There might be subtle performance differences between different types of
// page layouts.
class RawTuples {
public:
  using Data = MutVec<MutVec<Value>>;

  // Default constructor
  RawTuples() = default;
  // Constructor to accept 2D vector of tuples
  RawTuples(PageId page_id)
    : page_id_ (page_id)
  {}

  // Allow copy constructor
  RawTuples(CRef<RawTuples>) = default;
  // Allow copy assign constructor
  RawTuples& operator=(CRef<RawTuples>) = default;
  // Default destructor
  ~RawTuples() = default;

  PageId page_id() {
    return page_id_;
  }

  Data data() {
    // TODO: This should be removed?
    // It's only in place to allow things to compile
    // Moving towards just holding a page_id
    // However, that could be more coordination and could
    // slow things down?
    //
    // TODO: Get to making performance benchmarks! Stop
    // worrying about the performance of code before you've
    // measured it!
    return data_;
  }

  class Iterator {
  public:
    Iterator(Data::const_iterator iter)
      : iter_(iter) {}

    CRef<Vec<Value>> values() {
      return *iter_;
    }

    Iterator& operator++() {
      ++iter_;
      return *this;
    }

    bool operator==(CRef<Iterator> other) { return iter_ == other.iter_; }
    bool operator!=(CRef<Iterator> other) { return iter_ != other.iter_; }

  private:
    Data::const_iterator iter_;
  };

  Iterator begin() const { return Iterator(data_.begin()); }
  Iterator end()   const { return Iterator(data_.end());   }

private:
  PageId page_id_;
  Data data_;
};

class RawTuplesPlan : public BasePlan {
public:
  RawTuplesPlan(SchemaRef schema_ref,
                RawTuples raw_tuples)
    : BasePlan    (schema_ref),
      raw_tuples_ (raw_tuples) {}

  CRef<RawTuples> raw_tuples() const {
    return raw_tuples_;
  }

  PlanType type() const {
    return PlanType::RAW_TUPLES;
  }

private:
  RawTuples raw_tuples_;
};
