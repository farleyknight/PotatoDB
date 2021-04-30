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
                CRef<RID> rid,
                Txn txn);
  // Copy constructor
  TableIterator(CRef<TableIterator> other);

  // pre-increment
  TableIterator& operator++();
  // post-increment
  TableIterator operator++(int);
  bool operator==(CRef<TableIterator> it) const;
  bool operator!=(CRef<TableIterator> it) const;
  bool has_tuple() const;
  CRef<Tuple> tuple() const;
  CRef<RID> rid() const {
    return rid_;
  }

private:
  TableHeap& table_heap_;
  RID rid_;
  MutOption<Tuple> tuple_;
  Txn& txn_;
};
