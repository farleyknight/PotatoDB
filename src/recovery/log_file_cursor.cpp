#include "recovery/log_file_cursor.hpp"

void LogFileCursor::append(LogRecord& log_record) {
  append_header(log_record);

  switch (log_record.record_type()) {
  case LogRecordType::INSERT:
    append_insert_record(log_record);
    break;
  case LogRecordType::MARK_DELETE:
  case LogRecordType::APPLY_DELETE:
  case LogRecordType::ROLLBACK_DELETE:
    append_delete_record(log_record);
    break;
  case LogRecordType::UPDATE:
    append_update_record(log_record);
    break;
  case LogRecordType::NEW_PAGE:
    append_new_page_record(log_record);
    break;
  default:
    // NO-OP
    break;
  }
}

void LogFileCursor::append_header(const LogRecord& log_record) {
  append_int32(log_record.size());
  append_lsn(log_record.lsn());
  append_txn_id(log_record.txn_id());
  append_lsn(log_record.prev_lsn());
  auto log_record_type = static_cast<int32_t>(log_record.record_type());
  append_int32(log_record_type);
}

void LogFileCursor::append_insert_record(const LogRecord& log_record) {
  append_rid(log_record.insert_rid());
  append_tuple(log_record.insert_tuple());
}

int32_t LogFileCursor::next_int32() {
  auto val = buffer_.read_int32(buffer_offset_);
  increment_offset(sizeof(val));
  return val;
}

void LogFileCursor::append_int32(int32_t val) {
  buffer_.write_int32(buffer_offset_, val);
  increment_offset(sizeof(val));
}

const PageId LogFileCursor::next_page_id() {
  auto page_id = buffer_.read_page_id(buffer_offset_);
  increment_offset(sizeof(page_id));
  return page_id;
}

void LogFileCursor::append_page_id(PageId val) {
  buffer_.write_page_id(buffer_offset_, val);
  increment_offset(sizeof(val));
}

const RID LogFileCursor::next_rid() {
  auto rid = buffer_.read_rid(buffer_offset_);
  increment_offset(sizeof(uint64_t));
  return rid;
}

void LogFileCursor::append_rid(RID val) {
  buffer_.write_rid(buffer_offset_, val);
  increment_offset(sizeof(uint64_t));
}

const Tuple LogFileCursor::next_tuple() {
  auto tuple = buffer_.read_tuple(buffer_offset_);
  increment_offset(tuple.size() + sizeof(int32_t));
  return tuple;
}

void LogFileCursor::append_tuple(const Tuple& tuple) {
  buffer_.write_tuple(buffer_offset_, tuple);
  increment_offset(tuple.size() + sizeof(int32_t));
}

txn_id_t LogFileCursor::next_txn_id() {
  auto val = buffer_.read_txn_id(buffer_offset_);
  increment_offset(sizeof(val));
  return val;
}

void LogFileCursor::append_txn_id(txn_id_t val) {
  buffer_.write_txn_id(buffer_offset_, val);
  increment_offset(sizeof(val));
}

lsn_t LogFileCursor::next_lsn() {
  auto val = buffer_.read_lsn(buffer_offset_);
  increment_offset(sizeof(val));
  return val;
}

void LogFileCursor::append_lsn(lsn_t val) {
  buffer_.write_lsn(buffer_offset_, val);
  increment_offset(sizeof(val));
}

bool LogFileCursor::deserialize_log_record(LogRecord& log) {
  logger->debug("[LogFileCursor] Deserializing Log Record");
  if (buffer_offset() + LogRecord::HEADER_SIZE > buffer().size()) {
    logger->debug("[LogFileCursor] Could not deserialize! Not enough space..");
    return false;
  }

  last_file_offset_ = file_offset_;

  auto size = buffer_.read_int32(buffer_offset_);
  if (size < 4) {
    logger->debug("[LogFileCursor] Size is too small! Cannot deserialize!");
    return false;
  }

  log.set_size(next_int32());
  log.set_lsn(next_lsn());
  log.set_txn_id(next_txn_id());
  log.set_prev_lsn(next_lsn());

  int32_t record_type_as_int = next_int32();
  LogRecordType record_type  = static_cast<LogRecordType>(record_type_as_int);
  log.set_record_type(record_type);

  switch (record_type) {
  case LogRecordType::INSERT: {
    auto rid = next_rid();
    log.set_insert_rid(rid);
    log.set_insert_tuple(next_tuple());
    return true;
  }
  case LogRecordType::MARK_DELETE:
  case LogRecordType::APPLY_DELETE:
  case LogRecordType::ROLLBACK_DELETE: {
    log.set_delete_rid(next_rid());
    log.set_delete_tuple(next_tuple());
    return true;
  }
  case LogRecordType::UPDATE: {
    log.set_update_rid(next_rid());
    log.set_old_tuple(next_tuple());
    log.set_new_tuple(next_tuple());
    return true;
  }
  case LogRecordType::BEGIN:
  case LogRecordType::COMMIT:
  case LogRecordType::ABORT: {
    return true;
  }
  case LogRecordType::NEW_PAGE: {
    // TODO: This wording is confusing!
    // Instead of `next_page_id` we should call it `parse_page_id`
    // I think `parse` implies we are reading the value and moving forwards
    log.set_prev_page_id(next_page_id()); 
    log.set_page_id(next_page_id());
    return true;
  }
  default:
    // TODO: Debug here!
    assert(false);
  }

  logger->debug("[LogRecovery] Finished deserialization!");
  return true;
}

