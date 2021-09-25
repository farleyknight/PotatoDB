#include "recovery/log_recovery.hpp"
#include "page/slotted_table_page.hpp"

void LogRecovery::apply_log_record(LogRecord& log) {
  logger->debug("[LogRecovery] Updating LSN mapping & active TXNs");

  // TODO: This should be found BEFORE reading the record.
  lsn_mapping_[log.lsn()] = log_cursor_.last_file_offset(); 
  active_txn_[log.txn_id()] = log.lsn();

  // TODO: Add some logging here via spdlog
  // I have a feeling this part of the algo will be complicated and
  // may occasionally benefit from debugging.

  // TODO: Can all of these `if`s be converted into a `switch/case`?
  if (log.record_type() == LogRecordType::BEGIN) {
    return;
  }

  if (log.record_type() == LogRecordType::COMMIT ||
      log.record_type() == LogRecordType::ABORT) {
    assert(active_txn_.erase(log.txn_id()) > 0);
    return;
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
    return;
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
      break;
    }
    case LogRecordType::UPDATE: {
      table_page.update_tuple(log.new_tuple(), log.old_tuple(), rid);
      break;
    }
    case LogRecordType::MARK_DELETE: {
      table_page.mark_delete(rid);
      break;
    }
    case LogRecordType::APPLY_DELETE: {
      table_page.apply_delete(rid);
      break;
    }
    case LogRecordType::ROLLBACK_DELETE: {
      table_page.rollback_delete(rid);
      break;
    }
    default:
      assert(false); // NOTE SHOULD NOT GET HERE
    }
    table_page.set_lsn(log.lsn());
  }
  buff_mgr_.unpin(table_page.page_id(), need_redo);
}

void LogRecovery::redo() {
  assert(log_mgr_.is_logging_enabled() == false);

  int32_t deserialize_failures = 0;

  auto read_status = disk_mgr_.read_log(log_cursor_);
  while (read_status) {
    LogRecord log;
    auto deserialize_status = log_cursor_.deserialize_log_record(log);
    while (deserialize_status) {
      logger->debug("[LogRecovery] Applying next log record");
      apply_log_record(log);
      deserialize_status = log_cursor_.deserialize_log_record(log);
    }
    if (!deserialize_status) {
      deserialize_failures++;
    }
    if (deserialize_failures > 3) {
      logger->debug("[LogRecovery] Too many deserialize failures! Returning early..");
      return;
    }
    read_status = disk_mgr_.read_log(log_cursor_);
  }
}

LogFileCursor& LogRecovery::log_cursor() {
  disk_mgr_.read_log(log_cursor_);
  return log_cursor_;
}

/*
 *undo phase on TABLE PAGE level(table/table_page.h)
 *iterate through active txn map and undo each operation
 */
void LogRecovery::undo() {
  assert(log_mgr_.is_logging_enabled() == false);

  for (auto& [txn_id, lsn] : active_txn_) {
    while (lsn != INVALID_LSN) {
      auto file_offset = lsn_mapping_[lsn];
      log_cursor_.set_file_offset(file_offset);
      disk_mgr_.read_log(log_cursor_);

      LogRecord log;
      assert(log_cursor_.deserialize_log_record(log));
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
        break;
      }
      case LogRecordType::UPDATE: {
        auto tuple = Tuple(TupleSources::LOG_RECOVERY);
        page.update_tuple(log.old_tuple(), tuple, log.update_rid());
        assert(tuple.eq(log.new_tuple()));
        break;
      }
      case LogRecordType::MARK_DELETE: {
        page.rollback_delete(log.delete_rid());
        break;
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
