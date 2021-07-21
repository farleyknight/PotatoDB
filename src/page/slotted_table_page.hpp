#pragma once

#include "common/config.hpp"
#include "page/table_page.hpp"

class SlottedTablePage : public TablePage {
protected:
  Txn& txn_;
  LogMgr& log_mgr_;
  LockMgr& lock_mgr_;

public:
  SlottedTablePage(Page* page,
                   Txn& txn,
                   LogMgr& log_mgr,
                   LockMgr& lock_mgr)
    : TablePage (page),
      txn_      (txn),
      log_mgr_  (log_mgr),
      lock_mgr_ (lock_mgr)
  {}

  void allocate(const PageId page_id, const PageId prev_page_id);
  bool insert_tuple(Tuple& tuple);
  bool mark_delete(const RID& rid);
  void rollback_delete(const RID& rid);
  bool apply_delete(const RID& rid);

  bool update_tuple(const Tuple& new_tuple, Tuple& old_tuple, const RID& rid);
  ptr<Tuple> find_tuple(const RID& rid);

  optional<RID> first_tuple_rid();

  optional<RID> next_tuple_rid(const RID& curr_rid);

  int32_t tuple_count() {
    return page_->read_int32(OFFSET_TUPLE_COUNT);
  }

  /** Set the number of tuples in this page. */
  void set_tuple_count(int32_t tuple_count) {
    page_->write_int32(OFFSET_TUPLE_COUNT, tuple_count);
  }

protected:
  bool apply_update(const Tuple& new_tuple,
                    Tuple& old_tuple,
                    const RID& rid,
                    int32_t slot_id,
                    int32_t tuple_size);

  int32_t free_space_pointer() {
    return page_->read_int32(OFFSET_FREE_SPACE);
  }

  void set_free_space_pointer(int32_t free_space_pointer) {
    page_->write_int32(OFFSET_FREE_SPACE, free_space_pointer);
  }

  int32_t free_space_remaining() {
    return free_space_pointer() -
      SIZE_TABLE_PAGE_HEADER - TUPLE_SLOT_SIZE * tuple_count();
  }

  int32_t tuple_offset_at_slot(int32_t slot_id) {
    auto offset = OFFSET_TUPLE_OFFSET + TUPLE_SLOT_SIZE * slot_id;
    return page_->read_int32(offset);
  }

  void set_tuple_offset_at_slot(int32_t slot_id,
                                int32_t tuple_offset) {
    auto buffer_offset = OFFSET_TUPLE_OFFSET + TUPLE_SLOT_SIZE * slot_id;
    page_->write_int32(buffer_offset, tuple_offset);
  }

  int32_t tuple_size_at(int32_t slot_id) {
    auto buffer_offset = OFFSET_TUPLE_SIZE + TUPLE_SLOT_SIZE * slot_id;
    return page_->read_int32(buffer_offset);
  }

  void set_tuple_size_at(int32_t slot_id, int32_t size) {
    auto buffer_offset = OFFSET_TUPLE_SIZE + TUPLE_SLOT_SIZE * slot_id;
    page_->write_int32(buffer_offset, size);
  }

  static bool is_deleted(int32_t tuple_size) {
    return static_cast<bool>(tuple_size & DELETE_MASK) || tuple_size == 0;
  }

  static int32_t set_deleted_flag(int32_t tuple_size) {
    return static_cast<int32_t>(tuple_size | DELETE_MASK);
  }

  static int32_t unset_deleted_flag(int32_t tuple_size) {
    return static_cast<int32_t>(tuple_size & (~DELETE_MASK));
  }
};
