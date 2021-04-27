#pragma once

#include "common/config.hpp"

#include "page/page.hpp"
#include "page/page_layout.hpp"

#include "recovery/log_mgr.hpp"

#include "tuple/tuple.hpp"

#include "txns/txn.hpp"
#include "txns/lock_mgr.hpp"

class LockMgr;

/**
* Slotted page format:
*  ---------------------------------------------------------
*  | HEADER | ... FREE SPACE ... | ... INSERTED TUPLES ... |
*  ---------------------------------------------------------
*                                ^
*                                free space pointer
*
*  Header format (size in bytes):
*  ----------------------------------------------------------------------------
*  | page_id_t (4)| lsn_t (4)| Prevpage_id_t (4)| Nextpage_id_t (4)| FreeSpacePointer(4) |
*  ----------------------------------------------------------------------------
*  ----------------------------------------------------------------
*  | TupleCount (4) | Tuple_1 offset (4) | Tuple_1 size (4) | ... |
*  ----------------------------------------------------------------
*
*/

class TablePageLayout : public PageLayout {
public:
  // In bustub, this is called `Init`
  // I prefer to call this `allocate`, since the main logic behind this
  // method is writing to the page's internal page.
  void init(MRef<Page> page,
            PageId page_id,
            PageId prev_page_id,
            MRef<Txn> txn,
            MRef<LogMgr> log_mgr)
  {
    set_page_id(page, page_id);

    if (log_mgr.logging_enabled()) {
      LogRecord log_record(txn.id(),
                           txn.prev_lsn(),
                           LogRecordType::NEW_PAGE,
                           prev_page_id,
                           page_id);
      // TODO: LogMgr append should take exact same args as
      // LogRecord's constructor
      lsn_t lsn = log_mgr.emplace(move(log_record));
      set_lsn(page, lsn);
      txn.set_prev_lsn(lsn);
    }

    // Set the previous and next page IDs.
    set_table_page_id(page, page_id);
    set_prev_page_id(page, prev_page_id);
    set_next_page_id(page, PageId::INVALID());
    set_free_space_pointer(page, page.size());
    set_tuple_count(page, 0);
  }

  void set_page_id(MRef<Page> page, PageId page_id) {
    write_page_id(page, 0, page_id);
    // Set the page ID.
    // Remember that the arguments of memcpy are:
    // memcpy(destination, source, size);
    // memcpy(data(), &page_id, sizeof(page_id));
  }

  /** @return the page ID of this table page */
  PageId table_page_id(CRef<Page> page) {
    return read_page_id(page, 0);
    // return *reinterpret_cast<page_id_t *>(data());
  }

  /** @return the page ID of the previous table page */
  PageId prev_page_id(CRef<Page> page) {
    return read_page_id(page, OFFSET_PREV_PAGE_ID);
    // return *reinterpret_cast<page_id_t *>(data() + OFFSET_PREV_PAGE_ID);
  }

  /** @return the page ID of the next table page */
  PageId next_page_id(CRef<Page> page) {
    return read_page_id(page, OFFSET_NEXT_PAGE_ID);
    // return *reinterpret_cast<page_id_t *>(data() + OFFSET_NEXT_PAGE_ID);
  }

  /** @return the page ID of this table page */
  void set_table_page_id(MRef<Page> page, PageId table_page_id) {
    write_page_id(page, 0, table_page_id);
    // memcpy(data(), &table_page_id, sizeof(page_id_t));
  }

  /** Set the page id of the previous page in the table. */
  void set_prev_page_id(MRef<Page> page, PageId prev_page_id) {
    write_page_id(page, OFFSET_PREV_PAGE_ID, prev_page_id);
    // memcpy(data() + OFFSET_PREV_PAGE_ID, &prev_page_id, sizeof(page_id_t));
  }

  /** Set the page id of the next page in the table. */
  void set_next_page_id(MRef<Page> page, PageId next_page_id) {
    write_page_id(page, OFFSET_NEXT_PAGE_ID, next_page_id);
    // memcpy(data() + OFFSET_NEXT_PAGE_ID, &next_page_id, sizeof(page_id_t));
  }

  bool insert_tuple(MRef<Page> page, CRef<Tuple> tuple, MRef<RID> rid) {
    // If there is not enough space, then return false.
    if (free_space_remaining(page) < tuple.size() + SIZE_TUPLE) {
      return false;
    }

    // Try to find a free slot to reuse.
    uint32_t i;
    for (i = 0; i < tuple_count(page); i++) {
      // If the slot is empty, i.e. its tuple has size 0,
      if (tuple_size_at(page, i) == 0) {
        // Then we break out of the loop at index i.
        break;
      }
    }

    // If there was no free slot left, and we cannot claim it from
    // the free space, then we give up.
    if (i == tuple_count(page) &&
        free_space_remaining(page) < tuple.size() + SIZE_TUPLE) {
      return false;
    }

    // Otherwise we claim available free space..
    set_free_space_pointer(page,
                           free_space_pointer(page) - tuple.size());

    page.copy_n_bytes(0,
                      free_space_pointer(page),
                      tuple.data()
                      tuple.size());

    // Set the tuple.
    set_tuple_offset_at_slot(page, i, free_space_pointer(page));
    set_tuple_size_at(page, i, tuple.size());

    rid.set(table_page_id(), i);
    if (i == tuple_count()) {
      set_tuple_count(tuple_count() + 1);
    }

    return true;
  }

  bool mark_delete(MRef<Page> page,
                   CRef<RID> rid,
                   MRef<Txn> txn,
                   MRef<LockMgr> lock_mgr,
                   MRef<LogMgr> log_mgr)
  {
    uint32_t slot_num = rid.slot_num();
    // If the slot number is invalid, abort the txn.
    if (slot_num >= tuple_count(page)) {
      return false;
    }

    uint32_t tuple_size = tuple_size_at(slot_num);
    // If the tuple is already deleted, abort the txn.
    if (is_deleted(page, tuple_size)) {
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
       set_lsn(page, lsn);
       txn.set_prev_lsn(lsn);
     }

    // Mark the tuple as deleted.
    if (tuple_size > 0) {
      set_tuple_size_at(page,
                        slot_num,
                        set_deleted_flag(page,
                                         tuple_size));
    }
    return true;
  }

  void rollback_delete(MRef<Page> page,
                       CRef<RID> rid,
                       MRef<Txn> txn,
                       MRef<LogMgr> log_mgr)
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
      set_lsn(page, lsn);
      txn.set_prev_lsn(lsn);
    }

    int slot_id = rid.slot_id();
    assert(slot_num < tuple_count(page));
    int32_t tuple_size = tuple_size_at(page, slot_id);

    // set tuple size to positive value
    if (is_deleted(page, tuple_size)) {
      set_tuple_size_at(page,
                        slot_id,
                        unset_deleted_flag(page, tuple_size));
    }
  }

  // TODO: Consider making the return value a std::optional
  bool update_tuple(MRef<Page> page,
                    CRef<Tuple> new_tuple,
                    MRef<Tuple> old_tuple,
                    CRef<RID> rid)
  {
    uint32_t slot_id = rid.slot_id();

    if (slot_id >= tuple_count(page)) {
      return false;
    }

    uint32_t tuple_size = tuple_size_at(page, slot_id);
    if (is_deleted(page, tuple_size)) {
      return false;
    }

    // If there is not enuogh space to update, we need to update via delete followed by an insert (not enough space).
    if (free_space_remaining(page) + tuple_size < new_tuple.size()) {
      return false;
    }

    apply_update(page, new_tuple, old_tuple, rid, slot_num, tuple_size);
    return true;
  }

  void apply_delete(MRef<Page> page,
                    MRef<RID> rid,
                    MRef<Txn> txn,
                    MRef<LogMgr> log_mgr)
  {
    uint32_t slot_num = rid.slot_num();

    uint32_t tuple_offset = tuple_offset_at_slot(page, slot_num);
    uint32_t tuple_size = tuple_size_at(page, slot_num);
    // Check if this is a delete operation, i.e. commit a delete.
    if (is_deleted(page, tuple_size)) {
      tuple_size = unset_deleted_flag(page, tuple_size);
    }
    // Otherwise we are rolling back an insert.

    // We need to copy out the deleted tuple for undo purposes.
    Tuple delete_tuple;
    delete_tuple.copy_n_bytes(tuple_offset, // Source offset
                              0, // Destination
                              page.buffer(), // Source buffer
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
      set_lsn(page, lsn);
      txn.set_prev_lsn(lsn);
    }

    uint32_t pointer = free_space_pointer(page);

    page.copy_n_bytes(pointer, // Source
                      pointer + tuple_size, // Destination
                      tuple_offset - pointer) // N bytes

    // memmove(
    //   data() + pointer + tuple_size,
    //   data() + pointer,
    //   tuple_offset - pointer
    // );

    set_free_space_pointer(page, pointer + tuple_size);
    set_tuple_size_at(page, slot_num, 0);
    set_tuple_offset_at_slot(page, slot_num, 0);

    // Update all tuple offsets.
    for (uint32_t i = 0; i < tuple_count(page); ++i) {
      uint32_t tuple_offset_i = tuple_offset_at_slot(page, i);
      if (tuple_size_at(i) != 0 && tuple_offset_i < tuple_offset) {
        set_tuple_offset_at_slot(page, i, tuple_offset_i + tuple_size);
      }
    }
  }

  bool find_tuple(CRef<Page> page, CRef<RID> rid, MRef<Tuple> tuple) {
    // Get the current slot number.
    uint32_t slot_num = rid.slot_num();
    // If somehow we have more slots than tuples, abort the txn.
    if (slot_num >= tuple_count(page)) {
      return false;
    }
    // Otherwise get the current tuple size too.
    uint32_t tuple_size = tuple_size_at(page, slot_num);
    // If the tuple is deleted, abort the txn.
    if (is_deleted(tuple_size)) {
      return false;
    }

    // At this point, we have at least a shared lock on the RID.
    // Copy the tuple data into our result.
    uint32_t tuple_offset = tuple_offset_at_slot(page, slot_num);
    tuple.reset(tuple_size);
    tuple.copy_n_bytes(tuple_offset, // Source offset
                       page.buffer(), // Destination buffer
                       tuple_size); // N bytes

    tuple.set_rid(rid);
    return true;
  }

  Option<RID> first_tuple_rid(CRef<Page> page) {
    // Find and return the first valid tuple.
    for (uint32_t i = 0; i < tuple_count(page); ++i) {
      if (tuple_size_at(i) > 0) {
        return RID::make_opt(table_page_id(page), i);
      }
    }
    return std::nullopt;
  }

  Option<RID> next_tuple_rid(CRef<RID> curr_rid) {
    // Find and return the first valid tuple after our current slot number.
    for (auto i = curr_rid.slot_num() + 1; i < tuple_count(); ++i) {
      // Q: Is this suppose to check that it's not invalid?
      if (tuple_size_at(i) > 0) {
        return RID::make_opt(table_page_id(page), i);
      }
    }

    // Otherwise return false as there are no more tuples.
    return std::nullopt;
  }

  uint32_t tuple_count(CRef<Page> page) {
    return read_uint32(page, OFFSET_TUPLE_COUNT);
    // return *reinterpret_cast<uint32_t *>(data() + OFFSET_TUPLE_COUNT);
  }

  /** Set the number of tuples in this page. */
  void set_tuple_count(MRef<Page> page, uint32_t tuple_count) {
    write_uint32(page, OFFSET_TUPLE_COUNT, tuple_count);
    // memcpy(data() + OFFSET_TUPLE_COUNT, &tuple_count, sizeof(uint32_t));
  }

private:

  void apply_update(MRef<Page> page,
                    CRef<Tuple> new_tuple,
                    MRef<Tuple> old_tuple,
                    CRef<RID> rid,
                    uint32_t slot_num,
                    uint32_t tuple_size)
  {
    uint32_t tuple_offset = tuple_offset_at_slot(slot_num);
    old_tuple.copy_n_bytes(tuple_size, page.buffer(), tuple_offset);
    old_tuple.set_rid(rid);

    uint32_t pointer = free_space_pointer(page);

    page.copy_n_bytes(pointer, // Source offset
                      // Destination offset
                      pointer + tuple_size - new_tuple.size(),
                      tuple_offset - pointer); // N bytes

    // memmove(
    //   data() + pointer + tuple_size - new_tuple.size(),
    //   data() + pointer,
    //   tuple_offset - pointer
    // );

    set_free_space_pointer(page,
                           pointer + tuple_size - new_tuple.size());

    page.copy_n_bytes(0, // Source offset
                      // Dest offset
                      tuple_offset + tuple_size - new_tuple.size(),
                      new_tuple.data(), // Source buffer
                      new_tuple.size()); // N Bytes

    set_tuple_size_at(page, slot_num, new_tuple.size());

    // Update all tuple offsets.
    for (uint32_t i = 0; i < tuple_count(page); ++i) {
      uint32_t tuple_offset_i = tuple_offset_at_slot(page, i);
      if (tuple_size_at(page, i) > 0 &&
          tuple_offset_i < tuple_offset + tuple_size) {
        auto offset = tuple_offset_i + tuple_size - new_tuple.size()
        set_tuple_offset_at_slot(page, i, offset);
      }
    }
  }

  static constexpr size_t SIZE_TABLE_PAGE_HEADER = 24;
  static constexpr size_t SIZE_TUPLE = 8;
  static constexpr size_t OFFSET_PREV_PAGE_ID = 8;
  static constexpr size_t OFFSET_NEXT_PAGE_ID = 12;
  static constexpr size_t OFFSET_FREE_SPACE = 16;
  static constexpr size_t OFFSET_TUPLE_COUNT = 20;
  static constexpr size_t OFFSET_TUPLE_OFFSET = 24;
  static constexpr size_t OFFSET_TUPLE_SIZE = 28;

  uint32_t free_space_pointer(CRef<Page> page) {
    return read_uint32(page, OFFSET_FREE_SPACE);
    // return *reinterpret_cast<uint32_t *>(data() + OFFSET_FREE_SPACE);
  }

  void set_free_space_pointer(MRef<Page> page,
                              uint32_t free_space_pointer)
  {
    write_uint32(page, OFFSET_FREE_SPACE, free_space_pointer);
    // memcpy(data() + OFFSET_FREE_SPACE, &free_space_pointer, sizeof(uint32_t));
  }

  uint32_t free_space_remaining(CRef<Page> page) {
    return free_space_pointer(page) -
      SIZE_TABLE_PAGE_HEADER - SIZE_TUPLE * tuple_count(page);
  }

  uint32_t tuple_offset_at_slot(CRef<Page> Page, uint32_t slot_id) {
    auto offset = OFFSET_TUPLE_OFFSET + SIZE_TUPLE * slot_id;
    return read_uint32(page, offset);
  }

  void set_tuple_offset_at_slot(CRef<Page> page,
                                uint32_t slot_id,
                                uint32_t tuple_offset) {
    auto buffer_offset = OFFSET_TUPLE_OFFSET + SIZE_TUPLE * slot_id;
    write_uint32(page, buffer_offset, tuple_offset);
  }

  uint32_t tuple_size_at(CRef<Page> page, uint32_t slot_id) {
    auto buffer_offset = OFFSET_TUPLE_SIZE + SIZE_TUPLE * slot_id;
    return read_uint32(page, buffer_offset);
    // return *reinterpret_cast<uint32_t *>(data() + );
  }

  /** Set tuple size at slot slot_num. */
  void set_tuple_size_at(uint32_t slot_num, uint32_t size) {
    auto buffer_offset = OFFSET_TUPLE_SIZE + SIZE_TUPLE * slot_id;
    write_uint32(page, buffer_offset, size);
    // memcpy(data() + OFFSET_TUPLE_SIZE + SIZE_TUPLE * slot_num, &size, sizeof(uint32_t));
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
