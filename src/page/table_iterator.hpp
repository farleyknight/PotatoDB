#pragma once

#include "tuple/rid.hpp"
#include "tuple/tuple.hpp"
#include "page/table_page.hpp"
#include "page/table_heap.hpp"

// TODO: Replace this with an STL-style iterator:
// https://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls

class TableIterator {
public:

  TableIterator(TableHeap& table_heap,
                const RID& rid,
                Txn& txn);
  // Copy constructor
  TableIterator(const TableIterator& other);

  // pre-increment
  TableIterator& operator++();
  // post-increment
  TableIterator operator++(int);
  bool operator==(const TableIterator& it) const;
  bool operator!=(const TableIterator& it) const;
  bool has_tuple() const;
  const Tuple& tuple() const;

  bool stop_iterating() const;

  const RID& rid() const {
    return rid_;
  }

private:
  TableHeap& table_heap_;
  RID rid_;
  ptr<Tuple> tuple_;
  Txn& txn_;
};
