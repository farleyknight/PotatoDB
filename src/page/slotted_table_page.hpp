#pragma once

#include "common/config.hpp"
#include "page/table_page.hpp"

class SlottedTablePage : public TablePage {
public:
  SlottedTablePage(Page* page)
    : TablePage (page)
  {}

  // TODO: Rename to `allocate`
  void init(PageId page_id,
            PageId prev_page_id,
            Txn& txn,
            LogMgr& log_mgr)
  {
    set_page_id(page_id);

    if (log_mgr.logging_enabled()) {
      LogRecord log_record(txn.id(),
                           txn.prev_lsn(),
                           LogRecordType::NEW_PAGE,
                           prev_page_id,
                           page_id);
      // TODO: LogMgr append should take exact same args as
      // LogRecord's constructor
      lsn_t lsn = log_mgr.emplace(move(log_record));
      set_lsn(lsn);
      txn.set_prev_lsn(lsn);
    }

    // Set the previous and next page IDs.
    set_table_page_id(page_id);
    set_prev_page_id(prev_page_id);
    set_next_page_id(PageId::STOP_ITERATING(page_id.file_id()));

    set_free_space_pointer(page_->size());
    set_tuple_count(0);
  }

  bool insert_tuple(Tuple& tuple) {
    // If there is not enough space, then return false.
    if (free_space_remaining() < tuple.size() + TUPLE_SLOT_SIZE) {
      return false;
    }

    // Try to find a free slot to reuse.
    uint32_t i;
    for (i = 0; i < tuple_count(); i++) {
      // If the slot is empty, i.e. its tuple has size 0,
      if (tuple_size_at(i) == 0) {
        // Then we break out of the loop at index i.
        break;
      }
    }

    // If there was no free slot left, and we cannot claim it from
    // the free space, then we give up.
    if (i == tuple_count() &&
        free_space_remaining() < tuple.size() + TUPLE_SLOT_SIZE) {
      return false;
    }

    // Otherwise we claim available free space..
    set_free_space_pointer(free_space_pointer() - tuple.size());

    page_->copy_n_bytes(0, // Source offset
                        // Destination offset
                        free_space_pointer(),
                        tuple.buffer(), // Source buffer
                        tuple.size()); // N bytes

    // Set the tuple.
    set_tuple_offset_at_slot(i, free_space_pointer());
    set_tuple_size_at(i, tuple.size());

    if (i == tuple_count()) {
      set_tuple_count(tuple_count() + 1);
    }

    tuple.set_rid(RID(table_page_id(), i));

    return true;
  }

  bool mark_delete(const RID& rid,
                   Txn& txn,
                   LockMgr& lock_mgr,
                   LogMgr& log_mgr)
  {
    uint32_t slot_id = rid.slot_id();
    // If the slot number is invalid, abort the txn.
    if (slot_id >= tuple_count()) {
      return false;
    }

    uint32_t tuple_size = tuple_size_at(slot_id);
    // If the tuple is already deleted, abort the txn.
    if (is_deleted(tuple_size)) {
      return false;
    }

    if (log_mgr.logging_enabled()) {
       // Acquire an exclusive lock,
       // upgrading from a shared lock if necessary.
       if (txn.is_shared_locked(rid)) {
         if (!lock_mgr.lock_upgrade(txn, rid)) {
           return false;
         }
       } else if (!txn.is_exclusive_locked(rid) &&
                  !lock_mgr.lock_exclusive(txn, rid)) {
         return false;
       }
       Tuple dummy_tuple;
       LogRecord log_record(txn.id(),
                            txn.prev_lsn(),
                            LogRecordType::MARK_DELETE,
                            rid,
                            dummy_tuple);
       lsn_t lsn = log_mgr.emplace(std::move(log_record));
       set_lsn(lsn);
       txn.set_prev_lsn(lsn);
     }

    // Mark the tuple as deleted.
    if (tuple_size > 0) {
      set_tuple_size_at(slot_id,
                        set_deleted_flag(tuple_size));
    }
    return true;
  }

  void rollback_delete(const RID& rid,
                       Txn& txn,
                       LogMgr& log_mgr)
  {
    // Log the rollback.
    if (log_mgr.logging_enabled()) {
      // We must own an exclusive lock on the RID.
      assert(txn.is_exclusive_locked(rid));
      Tuple dummy_tuple;
      LogRecord log_record(txn.id(),
                           txn.prev_lsn(),
                           LogRecordType::ROLLBACK_DELETE,
                           rid,
                           dummy_tuple);
      lsn_t lsn = log_mgr.emplace(move(log_record));
      set_lsn(lsn);
      txn.set_prev_lsn(lsn);
    }

    slot_id_t slot_id = rid.slot_id();
    assert(slot_id < tuple_count());
    int32_t tuple_size = tuple_size_at(slot_id);

    // set tuple size to positive value
    if (is_deleted(tuple_size)) {
      set_tuple_size_at(slot_id,
                        unset_deleted_flag(tuple_size));
    }
  }

  // TODO: Consider making the return value a std::optional
  bool update_tuple(const Tuple& new_tuple,
                    Tuple& old_tuple,
                    const RID& rid)
  {
    slot_id_t slot_id = rid.slot_id();

    if (slot_id >= tuple_count()) {
      return false;
    }

    uint32_t tuple_size = tuple_size_at(slot_id);
    if (is_deleted(tuple_size)) {
      return false;
    }

    // If there is not enough space to update, we need to update via delete followed by an insert (not enough space).
    if (free_space_remaining() + tuple_size < new_tuple.size()) {
      return false;
    }

    apply_update(new_tuple, old_tuple, rid, slot_id, tuple_size);
    return true;
  }

  void apply_delete(RID& rid,
                    Txn& txn,
                    LogMgr& log_mgr)
  {
    uint32_t slot_id = rid.slot_id();

    uint32_t tuple_offset = tuple_offset_at_slot(slot_id);
    uint32_t tuple_size = tuple_size_at(slot_id);
    // Check if this is a delete operation, i.e. commit a delete.
    if (is_deleted(tuple_size)) {
      tuple_size = unset_deleted_flag(tuple_size);
    }
    // Otherwise we are rolling back an insert.

    // We need to copy out the deleted tuple for undo purposes.
    Tuple delete_tuple;
    delete_tuple.copy_n_bytes(tuple_offset, // Source offset
                              0, // Destination
                              page_->buffer(), // Source buffer
                              tuple_size); // N bytes

    delete_tuple.set_rid(rid);

    if (log_mgr.logging_enabled()) {
      //, "We must own the exclusive lock!";
      assert(txn.is_exclusive_locked(rid));

      LogRecord log_record(txn.id(),
                           txn.prev_lsn(),
                           LogRecordType::APPLY_DELETE,
                           rid,
                           delete_tuple);

      lsn_t lsn = log_mgr.emplace(move(log_record));
      set_lsn(lsn);
      txn.set_prev_lsn(lsn);
    }

    uint32_t pointer = free_space_pointer();

    page_->copy_n_bytes(pointer, // Source offset
                        pointer + tuple_size, // Destination offset
                        page_->buffer(),
                        tuple_offset - pointer); // N bytes

    // memmove(
    //   data() + pointer + tuple_size,
    //   data() + pointer,
    //   tuple_offset - pointer
    // );

    set_free_space_pointer(pointer + tuple_size);
    set_tuple_size_at(slot_id, 0);
    set_tuple_offset_at_slot(slot_id, 0);

    // Update all tuple offsets.
    for (uint32_t i = 0; i < tuple_count(); ++i) {
      uint32_t tuple_offset_i = tuple_offset_at_slot(i);
      if (tuple_size_at(i) != 0 && tuple_offset_i < tuple_offset) {
        set_tuple_offset_at_slot(i, tuple_offset_i + tuple_size);
      }
    }
  }

  // TODO: This should return a ptr<Tuple>
  // There are two cases below that should return a ptr<Tuple> with nullptr
  ptr<Tuple> find_tuple(const RID& rid) {
    // Get the current slot number.
    uint32_t slot_id = rid.slot_id();
    // If somehow we have more slots than tuples, abort the txn.
    if (slot_id >= tuple_count()) {
      std::cout << "Slot ID is greater or equal to tuple count! " << slot_id << std::endl;
      std::cout << "Tuple count " << tuple_count() << std::endl;
      return unique_ptr<Tuple>(nullptr);
    }
    // Otherwise get the current tuple size too.
    uint32_t tuple_size = tuple_size_at(slot_id);
    // If the tuple is deleted, abort the txn.
    if (is_deleted(tuple_size)) {
      std::cout << "This tuple is deleted! " << slot_id << std::endl;
      return unique_ptr<Tuple>(nullptr);
    }

    // At this point, we have at least a shared lock on the RID.
    // Copy the tuple data into our result.
    uint32_t tuple_offset = tuple_offset_at_slot(slot_id);
    auto tuple = make_unique<Tuple>(tuple_size);
    // tuple->reset(tuple_size);
    tuple->copy_n_bytes(tuple_offset, // Source offset
                        0, // Destination offset
                        page_->buffer(), // Source buffer
                        tuple_size); // N bytes

    tuple->set_rid(rid);
    return tuple;
  }

  Option<RID> first_tuple_rid() {
    // Find and return the first valid tuple.
    for (uint32_t i = 0; i < tuple_count(); ++i) {
      if (tuple_size_at(i) > 0) {
        return RID::make_opt(table_page_id(), i);
      }
    }
    return std::nullopt;
  }

  Option<RID> next_tuple_rid(const RID& curr_rid) {
    // Find and return the first valid tuple after our current slot number.
    for (uint32_t i = curr_rid.slot_id() + 1; i < tuple_count(); ++i) {
      // Q: Is this suppose to check that it's not invalid?
      if (tuple_size_at(i) > 0) {
        return RID::make_opt(table_page_id(), i);
      }
    }

    // Otherwise return false as there are no more tuples.
    return std::nullopt;
  }

  uint32_t tuple_count() {
    return page_->read_uint32(OFFSET_TUPLE_COUNT);
    // return *reinterpret_cast<uint32_t *>(data() + OFFSET_TUPLE_COUNT);
  }

  /** Set the number of tuples in this page. */
  void set_tuple_count(uint32_t tuple_count) {
    page_->write_uint32(OFFSET_TUPLE_COUNT, tuple_count);
    // memcpy(data() + OFFSET_TUPLE_COUNT, &tuple_count, sizeof(uint32_t));
  }

private:

  void apply_update(const Tuple& new_tuple,
                    Tuple& old_tuple,
                    const RID& rid,
                    uint32_t slot_id,
                    uint32_t tuple_size)
  {
    uint32_t tuple_offset = tuple_offset_at_slot(slot_id);
    old_tuple.copy_n_bytes(tuple_offset,
                           0,
                           page_->buffer(),
                           tuple_size);

    old_tuple.set_rid(rid);

    uint32_t pointer = free_space_pointer();

    page_->copy_n_bytes(pointer, // Source offset
                        // Destination offset
                        pointer + tuple_size - new_tuple.size(),
                        page_->buffer(), // Source buffer
                        tuple_offset - pointer); // N bytes

    // memmove(
    //   data() + pointer + tuple_size - new_tuple.size(),
    //   data() + pointer,
    //   tuple_offset - pointer
    // );

    set_free_space_pointer(pointer + tuple_size - new_tuple.size());

    page_->copy_n_bytes(0, // Source offset
                        // Dest offset
                        tuple_offset + tuple_size - new_tuple.size(),
                        new_tuple.buffer(), // Source buffer
                        new_tuple.size()); // N Bytes

    set_tuple_size_at(slot_id, new_tuple.size());

    // Update all tuple offsets.
    for (uint32_t i = 0; i < tuple_count(); ++i) {
      uint32_t tuple_offset_i = tuple_offset_at_slot(i);
      if (tuple_size_at(i) > 0 &&
          tuple_offset_i < tuple_offset + tuple_size) {
        auto offset = tuple_offset_i + tuple_size - new_tuple.size();
        set_tuple_offset_at_slot(i, offset);
      }
    }
  }

  uint32_t free_space_pointer() {
    return page_->read_uint32(OFFSET_FREE_SPACE);
  }

  void set_free_space_pointer(uint32_t free_space_pointer) {
    page_->write_uint32(OFFSET_FREE_SPACE, free_space_pointer);
  }

  uint32_t free_space_remaining() {
    return free_space_pointer() -
      SIZE_TABLE_PAGE_HEADER - TUPLE_SLOT_SIZE * tuple_count();
  }

  uint32_t tuple_offset_at_slot(uint32_t slot_id) {
    auto offset = OFFSET_TUPLE_OFFSET + TUPLE_SLOT_SIZE * slot_id;
    return page_->read_uint32(offset);
  }

  void set_tuple_offset_at_slot(uint32_t slot_id,
                                uint32_t tuple_offset) {
    auto buffer_offset = OFFSET_TUPLE_OFFSET + TUPLE_SLOT_SIZE * slot_id;
    page_->write_uint32(buffer_offset, tuple_offset);
  }

  uint32_t tuple_size_at(uint32_t slot_id) {
    auto buffer_offset = OFFSET_TUPLE_SIZE + TUPLE_SLOT_SIZE * slot_id;
    return page_->read_uint32(buffer_offset);
  }

  void set_tuple_size_at(uint32_t slot_id, uint32_t size) {
    auto buffer_offset = OFFSET_TUPLE_SIZE + TUPLE_SLOT_SIZE * slot_id;
    page_->write_uint32(buffer_offset, size);
  }

  static bool is_deleted(uint32_t tuple_size) {
    return static_cast<bool>(tuple_size & DELETE_MASK) || tuple_size == 0;
  }

  static uint32_t set_deleted_flag(uint32_t tuple_size) {
    return static_cast<uint32_t>(tuple_size | DELETE_MASK);
  }

  static uint32_t unset_deleted_flag(uint32_t tuple_size) {
    return static_cast<uint32_t>(tuple_size & (~DELETE_MASK));
  }
};
