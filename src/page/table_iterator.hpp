#pragma once

#include "tuple/rid.hpp"
#include "tuple/tuple.hpp"
#include "storage/table_page.hpp"
#include "storage/table_heap.hpp"

// TODO: Replace this with an STL-style iterator:
// https://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls

class TableIterator {
public:

  /**********************************************
   * Constructors & destructor
   **********************************************/
  TableIterator(MRef<TableHeap> table_heap,
                Ref<RID> rid,
                MRef<Txn> txn);
  // Copy constructor
  TableIterator(Ref<TableIterator> other);

  /**********************************************
   * Instance methods
   **********************************************/

  // pre-increment
  MRef<TableIterator> operator++();
  // post-increment
  TableIterator operator++(int);
  bool operator==(Ref<TableIterator> it) const;
  bool operator!=(Ref<TableIterator> it) const;
  bool has_tuple() const;
  Ref<Tuple> tuple() const;
  Ref<RID> rid() const {
    return rid_;
  }

private:
  MRef<TableHeap> table_heap_;
  RID rid_;
  MutOption<Tuple> tuple_;
  MRef<Txn> txn_;
};
