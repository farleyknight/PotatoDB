
#include "page/slotted_table_page.hpp"

void SlottedTablePage::allocate(const PageId page_id, const PageId prev_page_id) {
  assert(page_id.is_valid());
  //assert(prev_page_id.is_valid());
  set_page_id(page_id);

  if (log_mgr_.is_logging_enabled()) {
    std::cout << std::endl;
    std::cout << "NEW_PAGE TXN id = " << txn_.id() << std::endl;
    std::cout << "NEW_PAGE prev LSN = " << txn_.prev_lsn() << std::endl;
    std::cout << "NEW_PAGE prev page ID = " << prev_page_id << std::endl;
    std::cout << "NEW_PAGE page ID = " << page_id << std::endl;

    LogRecord log_record(txn_.id(),
                         txn_.prev_lsn(),
                         LogRecordType::NEW_PAGE,
                         prev_page_id,
                         page_id);

    std::cout << "NEW_PAGE SIZE = " << log_record.size() << std::endl;

    lsn_t lsn = log_mgr_.append(log_record);
    set_lsn(lsn);
    txn_.set_prev_lsn(lsn);
  }

  // Set the previous and next page IDs.
  set_table_page_id(page_id);
  set_prev_page_id(prev_page_id);
  set_next_page_id(PageId::STOP_ITERATING(page_id.file_id()));

  set_free_space_pointer(page_->size());
  set_tuple_count(0);
}

bool SlottedTablePage::insert_tuple(Tuple& tuple) {
  // If there is not enough space, then return false.
  if (free_space_remaining() < tuple.size() + TUPLE_SLOT_SIZE) {
    return false;
  }

  logger->debug("[SlottedTablePage] Before inserting tuple, the tuple count is now "
                + std::to_string(tuple_count()));

  // Try to find a free slot to reuse.
  slot_id_t i;
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

  // TODO: Change this to 'copy_tuple' or something?
  // TODO: Better: `write_tuple`
  // NOTE: We actually have two places where `write_tuple` would be useful
  // but they conflict slightly.
  // For SlottedTablePage, we DO NOT want to prefix the size of the tuple
  // However, for LogRecord, we DO want to prefix the size
  // So likely we need `write_tuple` and `write_tuple_with_size_prefix`
  // And therefore also `read_tuple` (size passed in) and `read_tuple_with_size_prefix`
  page_->copy_n_bytes(0, // Source offset
                      // Destination offset
                      free_space_pointer(),
                      tuple.buffer(), // Source buffer
                      tuple.size()); // N bytes

  // Set the tuple.
  set_tuple_offset_at_slot(i, free_space_pointer());
  set_tuple_size_at(i, tuple.size());

  auto rid = RID(table_page_id(), i);
  tuple.set_rid(rid);

  if (i == tuple_count()) {
    set_tuple_count(tuple_count() + 1);
  }

  logger->debug("[SlottedTablePage] After inserting tuple, the tuple count is now "
                + std::to_string(tuple_count()));

  if (log_mgr_.is_logging_enabled()) {
    assert(!txn_.is_shared_locked(rid) && !txn_.is_exclusive_locked(rid));

    bool locked = lock_mgr_.lock_exclusive(txn_, rid);
    assert(locked);

    std::cout << std::endl;
    std::cout << "INSERT RID = " << rid << std::endl;
    std::cout << "INSERT TXN id = " << txn_.id() << std::endl;
    std::cout << "INSERT prev LSN = " << txn_.prev_lsn() << std::endl;

    auto log_record = LogRecord(txn_.id(),
                                txn_.prev_lsn(),
                                LogRecordType::INSERT,
                                rid,
                                tuple);

    std::cout << "INSERT SIZE = " << log_record.size() << std::endl;

    lsn_t lsn = log_mgr_.append(log_record);
    set_lsn(lsn);
    txn_.set_prev_lsn(lsn);
  }

  return true;
}

bool SlottedTablePage::mark_delete(const RID& rid) {
  int32_t slot_id = rid.slot_id();
  // If the slot number is invalid, abort the txn.
  if (slot_id >= tuple_count()) {
    return false;
  }

  int32_t tuple_size = tuple_size_at(slot_id);
  // If the tuple is already deleted, abort the txn.
  if (is_deleted(tuple_size)) {
    return false;
  }

  if (log_mgr_.is_logging_enabled()) {
    // Acquire an exclusive lock,
    // upgrading from a shared lock if necessary.
    if (txn_.is_shared_locked(rid)) {
      if (!lock_mgr_.lock_upgrade(txn_, rid)) {
        return false;
      }
    } else if (!txn_.is_exclusive_locked(rid) &&
               !lock_mgr_.lock_exclusive(txn_, rid)) {
      return false;
    }
    Tuple dummy_tuple;
    LogRecord log_record(txn_.id(),
                         txn_.prev_lsn(),
                         LogRecordType::MARK_DELETE,
                         rid,
                         dummy_tuple);
    lsn_t lsn = log_mgr_.append(log_record);
    set_lsn(lsn);
    txn_.set_prev_lsn(lsn);
  }

  // Mark the tuple as deleted.
  if (tuple_size > 0) {
    set_tuple_size_at(slot_id,
                      set_deleted_flag(tuple_size));
  }

  return true;
}

void SlottedTablePage::rollback_delete(const RID& rid) {
  // Log the rollback.
  if (log_mgr_.is_logging_enabled()) {
    assert(txn_.is_exclusive_locked(rid));
    Tuple dummy_tuple;
    auto log_record = LogRecord(txn_.id(),
                                txn_.prev_lsn(),
                                LogRecordType::ROLLBACK_DELETE,
                                rid,
                                dummy_tuple);
    lsn_t lsn = log_mgr_.append(log_record);
    set_lsn(lsn);
    txn_.set_prev_lsn(lsn);
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

bool SlottedTablePage::update_tuple(const Tuple& new_tuple,
                                    Tuple& old_tuple,
                                    const RID& rid)
{
  slot_id_t slot_id = rid.slot_id();

  if (slot_id >= tuple_count()) {
    return false;
  }

  int32_t tuple_size = tuple_size_at(slot_id);
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

bool SlottedTablePage::apply_delete(const RID& rid) {
  int32_t slot_id = rid.slot_id();

  int32_t tuple_offset = tuple_offset_at_slot(slot_id);
  int32_t tuple_size = tuple_size_at(slot_id);
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

  if (log_mgr_.is_logging_enabled()) {
    //, "We must own the exclusive lock!";
    assert(txn_.is_exclusive_locked(rid));

    LogRecord log_record(txn_.id(),
                         txn_.prev_lsn(),
                         LogRecordType::APPLY_DELETE,
                         rid,
                         delete_tuple);

    lsn_t lsn = log_mgr_.append(log_record);
    set_lsn(lsn);
    txn_.set_prev_lsn(lsn);
  }

  int32_t pointer = free_space_pointer();

  page_->copy_n_bytes(pointer, // Source offset
                      pointer + tuple_size, // Destination offset
                      page_->buffer(),
                      tuple_offset - pointer); // N bytes

  set_free_space_pointer(pointer + tuple_size);
  set_tuple_size_at(slot_id, 0);
  set_tuple_offset_at_slot(slot_id, 0);

  // Update all tuple offsets.
  for (int32_t i = 0; i < tuple_count(); ++i) {
    int32_t tuple_offset_i = tuple_offset_at_slot(i);
    if (tuple_size_at(i) != 0 && tuple_offset_i < tuple_offset) {
      set_tuple_offset_at_slot(i, tuple_offset_i + tuple_size);
    }
  }

  return true;
}

ptr<Tuple> SlottedTablePage::find_tuple(const RID& rid) {
  // Get the current slot number.
  int32_t slot_id = rid.slot_id();
  // If somehow we have more slots than tuples, abort the txn.
  if (slot_id >= tuple_count()) {
    logger->debug("[SlottedTablePage] Slot ID is greater or equal to tuple count! " + std::to_string(slot_id));
    logger->debug("[SlottedTablePage] Tuple count " + std::to_string(tuple_count()));
    return unique_ptr<Tuple>(nullptr);
  }
  // Otherwise get the current tuple size too.
  int32_t tuple_size = tuple_size_at(slot_id);
  // If the tuple is deleted, abort the txn.
  if (is_deleted(tuple_size)) {
    logger->debug("[SlottedTablePage] This tuple is deleted! " + std::to_string(slot_id));
    return unique_ptr<Tuple>(nullptr);
  }

  // At this point, we have at least a shared lock on the RID.
  // Copy the tuple data into our result.
  int32_t tuple_offset = tuple_offset_at_slot(slot_id);
  auto tuple = make_unique<Tuple>(tuple_size);
  tuple->copy_n_bytes(tuple_offset, // Source offset
                      0, // Destination offset
                      page_->buffer(), // Source buffer
                      tuple_size); // N bytes
  tuple->set_rid(rid);

  return tuple;
}

optional<RID> SlottedTablePage::first_tuple_rid() {
  logger->debug("[SlottedTablePage] Looking for first tuple RID");
  logger->debug("[SlottedTablePage] Page has tuple_count: "
                + std::to_string(tuple_count()));
  // Find and return the first valid tuple.
  for (int32_t i = 0; i < tuple_count(); ++i) {
    if (tuple_size_at(i) > 0) {
      return RID::make_opt(table_page_id(), i);
    }
  }
  return std::nullopt;
}

optional<RID> SlottedTablePage::next_tuple_rid(const RID& curr_rid) {
  // Find and return the first valid tuple after our current slot number.
  for (int32_t i = curr_rid.slot_id() + 1; i < tuple_count(); ++i) {
    // Q: Is this suppose to check that it's not invalid?
    // A: NO! It checks if it's been deleted. We use negative sizes
    // to mark a tuple as deleted in a Slotted Table Page design.
    if (tuple_size_at(i) > 0) {
      return RID::make_opt(table_page_id(), i);
    }
  }

  // Otherwise return false as there are no more tuples.
  return std::nullopt;
}

bool SlottedTablePage::apply_update(const Tuple& new_tuple,
                                    Tuple& old_tuple,
                                    const RID& rid,
                                    int32_t slot_id,
                                    int32_t tuple_size)
{
  int32_t tuple_offset = tuple_offset_at_slot(slot_id);
  old_tuple.copy_n_bytes(tuple_offset,
                         0,
                         page_->buffer(),
                         tuple_size);

  old_tuple.set_rid(rid);

  if (log_mgr_.is_logging_enabled()) {
    // Acquire an exclusive lock, upgrading from shared if necessary.
    if (txn_.is_shared_locked(rid)) {
      if (!lock_mgr_.lock_upgrade(txn_, rid)) {
        return false;
      }
    } else if (!txn_.is_exclusive_locked(rid) &&
               !lock_mgr_.lock_exclusive(txn_, rid)) {
      return false;
    }
    auto log_record = LogRecord(txn_.id(),
                                txn_.prev_lsn(),
                                LogRecordType::UPDATE,
                                rid,
                                old_tuple,
                                new_tuple);

    lsn_t lsn = log_mgr_.append(log_record);
    set_lsn(lsn);
    txn_.set_prev_lsn(lsn);
  }

  // Perform the update.
  int32_t pointer = free_space_pointer();

  page_->copy_n_bytes(pointer, // Source offset
                      // Destination offset
                      pointer + tuple_size - new_tuple.size(),
                      page_->buffer(), // Source buffer
                      tuple_offset - pointer); // N bytes

  set_free_space_pointer(pointer + tuple_size - new_tuple.size());

  page_->copy_n_bytes(0, // Source offset
                      // Dest offset
                      tuple_offset + tuple_size - new_tuple.size(),
                      new_tuple.buffer(), // Source buffer
                      new_tuple.size()); // N Bytes

  set_tuple_size_at(slot_id, new_tuple.size());

  // Update all tuple offsets.
  for (int32_t i = 0; i < tuple_count(); ++i) {
    int32_t tuple_offset_i = tuple_offset_at_slot(i);
    if (tuple_size_at(i) > 0 &&
        tuple_offset_i < tuple_offset + tuple_size) {
      auto offset = tuple_offset_i + tuple_size - new_tuple.size();
      set_tuple_offset_at_slot(i, offset);
    }
  }

  return true;
}
