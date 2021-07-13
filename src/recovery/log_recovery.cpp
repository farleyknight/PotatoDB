#include "recovery/log_recovery.hpp"

// TODO:
//
// Something tells me that we can do better
// and that we can convert this hand-written serialization & deserialization
// logic in Google's Protobuf.
//
// Not sure if it's worth the extra code bloat? But it does look convenient.

void LogRecovery::apply_next_log_record(buffer_offset_t buffer_start,
                                        buffer_offset_t buffer_offset,
                                        LogRecord& log)
{
  // TODO: Do we really need `log` to be passed in?
  // Maybe we can just declare it here?
  while (deserialize_log_record(buffer_offset, log)) {
    lsn_mapping_[log.lsn()] = buffer_start + buffer_offset;
    active_txn_[log.txn_id()] = log.lsn();

    // TODO: Add some logging here via spdlog
    // I have a feeling this part of the algo will be complicated and
    // may occasionally benefit from debugging.

    buffer_offset += log.size();

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
      auto page_ptr = buff_mgr_->fetch_page(log.page_id());
      assert(page_ptr != nullptr);

      auto table_page = SlottedTablePage(page_ptr);

      bool need_redo = log.lsn() > table_page->lsn();

      if (need_redo) {
        // TODO: Create a `txn` at the beginning of the recovery proecess.
        // It should get passed down through LogRecovery as necessary.
        // Actually, there probably should be just one `txn` for the
        // entire recovery process.
        //
        // So we can actually make it `txn_`
        //
        page->allocate(log.page_id(), log.prev_page_id(), txn_, log_mgr_);
        page->set_lsn(log.lsn());
        if (log.prev_page_id() != INVALID_PAGE_ID) {
          auto prev_page_ptr = buff_mgr_->fetch_page(log.prev_page_id());
          assert(prev_page_ptr != nullptr);
          auto prev_page = SlottedTablePage(prev_page_ptr);

          bool need_change = prev_page->next_page_id() == log.page_id();
          prevPage->next_page_id(log.page_id());
          buff_mgr_->unpin_page(prev_page->page_id(), need_change);
        }
      }
      buff_mgr_->unpin_page(page->page_id(), need_redo);

      continue;
    }

    RID rid = log.main_rid();
    auto page_ptr = buff_mgr_->fetch_page(rid.page_id());
    assert(page_ptr != nullptr);
    auto table_page = SlottedTablePage(page_ptr);

    bool need_redo = log.lsn() > page->lsn();

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
      page->set_lsn(log.lsn());
    }
    buffer_pool_manager_->unpin_page(page->GetPageId(), need_redo);
  }
}

/*
 *redo phase on TABLE PAGE level(table/table_page.h)
 *read log file from the beginning to end (you must prefetch log records into
 *log buffer to reduce unnecessary I/O operations), remember to compare page's
 *lsn_t with log_record's sequence number, and also build active_txn_ table &
 *lsn_mapping_ table
 */
void LogRecovery::redo() {
  //lock_guard<mutex> lock(mu_); no thread safe

  assert(log_mgr_.is_logging_enabled() == false);

  offset_ = 0;
  buffer_offset_t buffer_offset = 0;
  buffer_offset_t buffer_size   = log_buffer_.size() - buffer_offset;

  auto read_status = disk_mgr_->read_log(buffer_offset, log_buffer_);

  while (read_status) {
    buffer_offset_t buffer_start = offset_;
    offset_ += log_buffer_.size() - buffer_offset;
    buffer_offset = 0;
    LogRecord log;

    buffer_offset = apply_next_log_record(buffer_start, buffer_offset, log);

    log_buffer_.unshift(offset);
    buffer_offset = log_buffer_.size() - buffer_offset;

    read_status = disk_mgr_->read_log(buffer_offset, log_buffer_);
  }
}




/*
 * deserialize a log record from log buffer
 * @return: true means deserialize succeed, otherwise can't deserialize cause
 * incomplete log record
 */
bool LogRecovery::deserialize_log_record(buffer_offset_t buffer_offset,
                                         LogRecord& log)
{
  if (buffer_offset + LogRecord::HEADER_SIZE > log_buffer_.size()) {
    return false;
  }

  size_t size     = log_record_.read_int32(buffer_offset);
  lsn_t lsn       = log_record_.read_lsn(buffer_offset + 4);
  txn_id_t txn_id = log_record_.read_txn_id(buffer_offset + 8);
  lsn_t prev_lsn  = log_record_.read_lsn(buffer_offset + 12);

  int32_t record_type_as_int = log_record_.read_int32(buffer_offset + 16);
  LogRecordType record_type  = static_cast<LogRecordType>(log_record_as_int);

  buffer_offset += LogRecord::HEADER_SIZE;
  switch (log_record.log_record_type_) {
  case LogRecordType::INSERT:
    auto rid = log_buffer_.read_rid()
    log_record.set_insert_rid();
    log_record.insert_rid_ = *reinterpret_cast<const RID *>(data);
    log_record.insert_tuple_.DeserializeFrom(data + sizeof(RID));
    break;
  case LogRecordType::MARK_DELETE:
  case LogRecordType::APPLY_DELETE:
  case LogRecordType::ROLLBACK_DELETE:
    log_record.delete_rid_ = *reinterpret_cast<const RID *>(data);
    log_record.delete_tuple_.DeserializeFrom(data + sizeof(RID));
    break;
  case LogRecordType::UPDATE:
    log_record.update_rid_ = *reinterpret_cast<const RID *>(data);
    log_record.old_tuple_.DeserializeFrom(data + sizeof(RID));
    log_record.new_tuple_.DeserializeFrom(data + sizeof(RID) + 4
                                          + log_record.old_tuple_.GetLength());
    break;
  case LogRecordType::BEGIN:
  case LogRecordType::COMMIT:
  case LogRecordType::ABORT:
    break;
  case LogRecordType::NEWPAGE:
    log_record.prev_page_id_ = *reinterpret_cast<const page_id_t *>(data);
    log_record.page_id_ = *reinterpret_cast<const page_id_t *>(data + sizeof(page_id_t));
    break;
  default:
    // TODO: Debug here!
    assert(false);
  }
  return true;
}

/*
 *undo phase on TABLE PAGE level(table/table_page.h)
 *iterate through active txn map and undo each operation
 */
void LogRecovery::undo() {
  //lock_guard<mutex> lock(mu_); no thread safe
  // ENABLE_LOGGING must be false when recovery

  assert(log_mgr_.is_logging_enabled() == false);

  for (auto &txn : active_txn_) {
    lsn_t lsn = txn.second;
    while (lsn != INVALID_LSN) {
      LogRecord log;
      disk_manager_->ReadLog(log_buffer_, PAGE_SIZE, lsn_mapping_[lsn]);
      assert(DeserializeLogRecord(log_buffer_, log));
      assert(log.lsn_ == lsn);
      lsn = log.prev_lsn_;
      if (log.log_record_type_ == LogRecordType::BEGIN) {
        assert(log.prev_lsn_ == INVALID_LSN);
        continue;
      }
      if (log.log_record_type_ == LogRecordType::COMMIT ||
          log.log_record_type_ == LogRecordType::ABORT)
        assert(false);
      if (log.log_record_type_ == LogRecordType::NEWPAGE) {
        if (!buffer_pool_manager_->DeletePage(log.page_id_))
          disk_manager_->DeallocatePage(log.page_id_);
        if (log.prev_page_id_ != INVALID_PAGE_ID) {
          auto prevPage = static_cast<TablePage *>(
                                                   buffer_pool_manager_->FetchPage(log.prev_page_id_));
          assert(prevPage != nullptr);
          assert(prevPage->GetNextPageId() == log.page_id_);
          prevPage->SetNextPageId(INVALID_PAGE_ID);
          buffer_pool_manager_->UnpinPage(prevPage->GetPageId(), true);
        }
        continue;
      }
      RID rid = log.log_record_type_ == LogRecordType::INSERT ? log.insert_rid_ :
        log.log_record_type_ == LogRecordType::UPDATE ? log.update_rid_ :
        log.delete_rid_;
      auto page = static_cast<TablePage *>(buffer_pool_manager_->FetchPage(rid.GetPageId()));
      assert(page != nullptr);
      assert(page->GetLSN() >= log.lsn_);
      if (log.log_record_type_ == LogRecordType::INSERT) {
        page->ApplyDelete(log.insert_rid_, nullptr, nullptr);
      } else if (log.log_record_type_ == LogRecordType::UPDATE) {
        Tuple tuple;
        page->UpdateTuple(log.old_tuple_, tuple, log.update_rid_,
                          nullptr, nullptr, nullptr);
        assert(tuple.GetLength() == log.new_tuple_.GetLength() &&
               memcmp(tuple.GetData(), log.new_tuple_.GetData(), tuple.GetLength()) == 0);
      } else if (log.log_record_type_ == LogRecordType::MARKDELETE) {
        page->RollbackDelete(log.delete_rid_, nullptr, nullptr);
      } else if (log.log_record_type_ == LogRecordType::APPLYDELETE) {
        page->InsertTuple(log.delete_tuple_, log.delete_rid_,
                          nullptr, nullptr, nullptr);
      } else if (log.log_record_type_ == LogRecordType::ROLLBACKDELETE) {
        page->MarkDelete(log.delete_rid_, nullptr, nullptr, nullptr);
      } else
        assert(false);
      buffer_pool_manager_->UnpinPage(page->GetPageId(), true);
    }
  }
  active_txn_.clear();
  lsn_mapping_.clear();
}

