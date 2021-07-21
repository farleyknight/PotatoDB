#include "recovery/log_recovery.hpp"
#include "page/slotted_table_page.hpp"

// TODO:
//
// Something tells me that we can do better
// and that we can convert this hand-written serialization & deserialization
// logic in Google's Protobuf.
//
// Not sure if it's worth the extra code bloat? But it does look convenient.

void LogRecovery::apply_next_log_record() {
  LogRecord log;
  while (deserialize_log_record(log)) {
    logger->debug("[LogRecovery] Updating LSN mapping & active TXNs");
    // NOTE: This should be the offset for the entire file, not just the current buffer!
    lsn_mapping_[log.lsn()] = log_cursor_.file_offset();
    active_txn_[log.txn_id()] = log.lsn();

    // TODO: Add some logging here via spdlog
    // I have a feeling this part of the algo will be complicated and
    // may occasionally benefit from debugging.

    // TODO: Can all of these `if`s be converted into a `switch/case`?
    if (log.record_type() == LogRecordType::BEGIN) {
      continue;
    }

    if (log.record_type() == LogRecordType::COMMIT ||
        log.record_type() == LogRecordType::ABORT) {
      assert(active_txn_.erase(log.txn_id()) > 0);
      continue;
    }

    if (log.record_type() == LogRecordType::NEW_PAGE) {
      auto page_ptr = buff_mgr_.fetch_page(log.page_id());
      assert(page_ptr != nullptr);

      auto table_page = SlottedTablePage(page_ptr, txn_, log_mgr_, lock_mgr_);

      bool need_redo = log.lsn() > table_page.lsn();

      if (need_redo) {
        // TODO: Create a `txn` at the beginning of the recovery proecess.
        // It should get passed down through LogRecovery as necessary.
        // Actually, there probably should be just one `txn` for the
        // entire recovery process.
        //
        // So we can actually make it `txn_`
        //
        table_page.allocate(log.page_id(), log.prev_page_id());
        table_page.set_lsn(log.lsn());
        if (log.prev_page_id() != PageId::INVALID()) {
          auto prev_page_ptr = buff_mgr_.fetch_page(log.prev_page_id());
          assert(prev_page_ptr != nullptr);
          auto prev_page = SlottedTablePage(prev_page_ptr, txn_, log_mgr_, lock_mgr_);

          bool need_change = prev_page.next_page_id() == log.page_id();
          prev_page.set_next_page_id(log.page_id());
          buff_mgr_.unpin(prev_page.page_id(), need_change);
        }
      }
      buff_mgr_.unpin(table_page.page_id(), need_redo);
      continue;
    }

    RID rid = log.main_rid();
    auto page_ptr = buff_mgr_.fetch_page(rid.page_id());
    assert(page_ptr != nullptr);
    auto table_page = SlottedTablePage(page_ptr, txn_, log_mgr_, lock_mgr_);

    bool need_redo = log.lsn() > table_page.lsn();

    if (need_redo) {
      switch (log.record_type()) {
      case LogRecordType::INSERT: {
        table_page.insert_tuple(log.insert_tuple());
      }
      case LogRecordType::UPDATE: {
        table_page.update_tuple(log.new_tuple(), log.old_tuple(), rid);
      }
      case LogRecordType::MARK_DELETE: {
        table_page.mark_delete(rid);
      }
      case LogRecordType::APPLY_DELETE: {
        table_page.apply_delete(rid);
      }
      case LogRecordType::ROLLBACK_DELETE: {
        table_page.rollback_delete(rid);
      }
      default:
        assert(false); // NOTE SHOULD NOT GET HERE
      }
      table_page.set_lsn(log.lsn());
    }
    buff_mgr_.unpin(table_page.page_id(), need_redo);
  }
}

void LogRecovery::redo() {
  assert(log_mgr_.is_logging_enabled() == false);

  log_cursor_.buffer_reset();

  auto read_status = init_log_buffer();
  while (read_status) {
    logger->debug("[LogRecovery] Applying next log record");
    apply_next_log_record();
    read_status = disk_mgr_.read_log(log_cursor_);
  }
}

bool LogRecovery::init_log_buffer() {
  auto read_status = disk_mgr_.read_log(log_cursor_);
  logger->debug("[LogRecovery] Was read_status successful? " + std::to_string(read_status));
  std::cout << "[LogRecovery] Was read_status successful? " << std::to_string(read_status) << std::endl;
  return read_status;
}

bool LogRecovery::deserialize_log_record(LogRecord& log) {
  logger->debug("[LogRecovery] Deserializing Log Record");
  if (log_cursor_.buffer_offset() + LogRecord::HEADER_SIZE > log_cursor_.buffer().size()) {
    std::cout << "Could not deserialize! Not enough space.." << std::endl;
    logger->debug("[LogRecovery] Could not deseriali ze! Not enough space..");
    return false;
  }

  std::cout << std::endl;
  std::cout << "READING LogRecord Header" << std::endl;
  auto size = log_cursor_.next_int32();
  std::cout << "Size is " << size << std::endl;
  log.set_size(size);

  auto lsn = log_cursor_.next_lsn();
  std::cout << "LSN is " << lsn << std::endl;
  log.set_lsn(lsn);

  auto txn_id = log_cursor_.next_txn_id();
  std::cout << "TXN id is " << txn_id << std::endl;
  log.set_txn_id(txn_id);

  auto prev_lsn = log_cursor_.next_lsn();
  std::cout << "Prev LSN is " << prev_lsn << std::endl;
  log.set_prev_lsn(prev_lsn);

  int32_t record_type_as_int = log_cursor_.next_int32();
  std::cout << "record_type_as_int is " << record_type_as_int << std::endl;
  LogRecordType record_type  = static_cast<LogRecordType>(record_type_as_int);
  log.set_record_type(record_type);

  switch (record_type) {
  case LogRecordType::INSERT: {
    std::cout << "RecordType == INSERT" << std::endl;
    auto rid = log_cursor_.next_rid();
    std::cout << "RID is " << rid << std::endl;
    log.set_insert_rid(rid);
    log.set_insert_tuple(log_cursor_.next_tuple());
    return true;
  }
  case LogRecordType::MARK_DELETE:
  case LogRecordType::APPLY_DELETE:
  case LogRecordType::ROLLBACK_DELETE: {
    std::cout << "RecordType == DELETE" << std::endl;
    log.set_delete_rid(log_cursor_.next_rid());
    log.set_delete_tuple(log_cursor_.next_tuple());
    return true;
  }
  case LogRecordType::UPDATE: {
    std::cout << "RecordType == UPDATE" << std::endl;
    log.set_update_rid(log_cursor_.next_rid());
    log.set_old_tuple(log_cursor_.next_tuple());
    log.set_new_tuple(log_cursor_.next_tuple());
    return true;
  }
  case LogRecordType::BEGIN:
  case LogRecordType::COMMIT:
  case LogRecordType::ABORT: {
    std::cout << "RecordType == BEGIN|COMMIT|ABORT" << std::endl;
    return true;
  }
  case LogRecordType::NEW_PAGE: {
    std::cout << "RecordType == NEW_PAGE" << std::endl;

    auto prev_page_id = log_cursor_.next_page_id();
    std::cout << "Prev Page ID : " << prev_page_id << std::endl;
    log.set_prev_page_id(prev_page_id);

    auto page_id = log_cursor_.next_page_id();
    std::cout << "Page ID : " << page_id << std::endl;
    log.set_page_id(page_id);

    return true;
  }
  default:
    // TODO: Debug here!
    assert(false);
  }

  logger->debug("[LogRecovery] Finished deserialization!");
  return true;
}

/*
 *undo phase on TABLE PAGE level(table/table_page.h)
 *iterate through active txn map and undo each operation
 */
void LogRecovery::undo() {
  assert(log_mgr_.is_logging_enabled() == false);

  for (auto& [txn_id, lsn] : active_txn_) {
    while (lsn != INVALID_LSN) {
      log_cursor_.set_file_offset(lsn_mapping_[lsn]);
      disk_mgr_.read_log(log_cursor_);

      LogRecord log;
      assert(deserialize_log_record(log));
      assert(log.lsn() == lsn);

      lsn = log.prev_lsn();
      if (log.record_type() == LogRecordType::BEGIN) {
        assert(log.prev_lsn() == INVALID_LSN);
        continue;
      }

      if (log.record_type() == LogRecordType::COMMIT ||
          log.record_type() == LogRecordType::ABORT) {
        assert(false); // NOTE: SHOULD NOT GET HERE!
      }

      if (log.record_type() == LogRecordType::NEW_PAGE) {
        if (!buff_mgr_.delete_page(log.page_id())) {
          disk_mgr_.deallocate_page(log.page_id());
        }

        if (log.prev_page_id() != PageId::INVALID()) {
          auto prev_page_ptr = buff_mgr_.fetch_page(log.prev_page_id());
          assert(prev_page_ptr != nullptr);

          auto prev_page = SlottedTablePage(prev_page_ptr, txn_, log_mgr_, lock_mgr_);
          assert(prev_page.next_page_id() == log.page_id());

          prev_page.set_next_page_id(PageId::INVALID());
          buff_mgr_.unpin(prev_page.page_id(), true);
        }
        continue;
      }

      auto rid = log.main_rid();
      auto page_ptr = buff_mgr_.fetch_page(rid.page_id());
      assert(page_ptr != nullptr);

      auto page = SlottedTablePage(page_ptr, txn_, log_mgr_, lock_mgr_);
      assert(page.lsn() >= log.lsn());

      switch (log.record_type()) {
      case LogRecordType::INSERT: {
        page.apply_delete(log.insert_rid());
      }
      case LogRecordType::UPDATE: {
        Tuple tuple;
        page.update_tuple(log.old_tuple(), tuple, log.update_rid());
        assert(tuple.eq(log.new_tuple()));
      }
      case LogRecordType::MARK_DELETE: {
        page.rollback_delete(log.delete_rid());
      }
      case LogRecordType::APPLY_DELETE: {
        page.insert_tuple(log.delete_tuple());
      }
      case LogRecordType::ROLLBACK_DELETE: {
        page.mark_delete(log.delete_rid());
      }
      default:
        assert(false); // NOTE SHOULD NOT GET HERE
      }

      buff_mgr_.unpin(page.page_id(), true);
    }
  }

  active_txn_.clear();
  lsn_mapping_.clear();
}

