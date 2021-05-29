
#include "page/table_iterator.hpp"
#include "page/slotted_table_page.hpp"

TableIterator::TableIterator(TableHeap& table_heap,
                             const RID& rid,
                             Txn& txn)
  : table_heap_ (table_heap),
    rid_        (rid),
    txn_        (txn)
{
  if (rid_.is_valid()) {
    tuple_ = table_heap_.find_tuple(rid_, txn);
  }
}

TableIterator::TableIterator(const TableIterator& other)
  : table_heap_ (other.table_heap_),
    rid_        (other.rid()),
    txn_        (other.txn_)
{
  if (rid_.is_valid()) {
    tuple_ = table_heap_.find_tuple(rid_, other.txn_);
  }
}

// TODO: This whole thing is begging for a good refactor.
TableIterator& TableIterator::operator++() {
  assert(tuple_);

  auto &buff_mgr = table_heap_.buff_mgr();
  auto page_id   = tuple_->page_id();
  auto file_id   = page_id.file_id();
  SlottedTablePage curr_page(buff_mgr.fetch_page(page_id));

  auto next_tuple_rid = curr_page.next_tuple_rid(tuple_->rid());

  if (next_tuple_rid.has_value()) {
    auto rid = next_tuple_rid.value();
    tuple_ = table_heap_.find_tuple(rid, txn_);
    while (tuple_ == nullptr) {
      next_tuple_rid = curr_page.next_tuple_rid(next_tuple_rid.value());
      rid = next_tuple_rid.value();
      tuple_ = table_heap_.find_tuple(rid, txn_);
    }
  }

  if (!next_tuple_rid.has_value()) {
    while (curr_page.next_page_id() != PageId::STOP_ITERATING(file_id)) {
      page_id = curr_page.next_page_id();
      auto next_page = SlottedTablePage(buff_mgr.fetch_page(page_id));

      buff_mgr.unpin(curr_page.table_page_id(), false);
      next_tuple_rid = next_page.first_tuple_rid();

      if (next_tuple_rid.has_value()) {
        break;
      }
    }
  }

  if (!next_tuple_rid.has_value()) {
    // NOTE: Setting RID to have an STOP_ITERATING
    // means we have exhausted this table iterator
    rid_.set(PageId::STOP_ITERATING(file_id), 0);
    return *this;
  }

  auto rid = next_tuple_rid.value();

  if (*this != table_heap_.end(txn_)) {
    tuple_ = table_heap_.find_tuple(rid, txn_);
  }

  buff_mgr.unpin(curr_page.table_page_id(), false);
  return *this;
}

TableIterator TableIterator::operator++(int) {
  TableIterator clone(*this);
  ++(*this);
  return clone;
}

bool TableIterator::operator==(const TableIterator& iter) const {
  if (tuple_ == nullptr) {
    return false;
  }

  auto first_rid = rid();
  auto second_rid = iter.rid();

  // std::cout << "Tuple RID: " << tuple_rid.to_string() << std::endl;
  // std::cout << "First RID: " << first_rid.to_string() << std::endl;
  // std::cout << "Second RID: " << second_rid.to_string() << std::endl;

  return first_rid.get() == second_rid.get();
}

bool TableIterator::stop_iterating() const {
  return rid_.stop_iterating();
}

bool TableIterator::operator!=(const TableIterator& it) const {
  return !(*this == it);
}

bool TableIterator::has_tuple() const {
  return tuple_ != nullptr;
}

const Tuple& TableIterator::tuple() const {
  assert(tuple_);
  assert(tuple_->size() > 0);
  return *tuple_;
}
