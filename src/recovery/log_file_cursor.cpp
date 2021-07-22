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
  // Start with size
  append_int32(log_record.size());

  // Add LSN
  append_lsn(log_record.lsn());

  // Add TXN id
  append_txn_id(log_record.txn_id());

  // Add prev LSN
  append_lsn(log_record.prev_lsn());

  // Add record type
  auto log_record_type = static_cast<int32_t>(log_record.record_type());
  append_int32(log_record_type);

  std::cout << "LogRecord header ends at: " << buffer_offset_ << std::endl;
}

void LogFileCursor::append_insert_record(const LogRecord& log_record) {
  // Write the RID
  std::cout << "LogFileBuffer::append_insert_record RID : "
            << log_record.insert_rid() << std::endl;
  std::cout << "LogFileBuffer::append_insert_record RID offset : "
            << buffer_offset_ << std::endl;

  auto before_offset = buffer_offset_;
  append_rid(log_record.insert_rid());
  std::cout << "LogFileBuffer::append_insert_record RID (read back): "
            << buffer_.read_rid(before_offset) << std::endl;


  before_offset = buffer_offset_;
  append_tuple(log_record.insert_tuple());
  std::cout << "LogFileBuffer::append_insert_record Tuple offset : "
            << before_offset << std::endl;

  std::cout << "LogFileBuffer::append_insert_record FINAL offset : "
            << buffer_offset_ << std::endl;
}

int32_t LogFileCursor::next_int32() {
  std::cout << "next_int32 at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  auto val = buffer_.read_int32(buffer_offset_);
  increment_offset(sizeof(val));
  return val;
}

void LogFileCursor::append_int32(int32_t val) {
  std::cout << "append_int32 at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  buffer_.write_int32(buffer_offset_, val);
  increment_offset(sizeof(val));
}

const PageId LogFileCursor::next_page_id() {
  std::cout << "next_page_id at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  auto page_id = buffer_.read_page_id(buffer_offset_);
  increment_offset(sizeof(page_id));
  return page_id;
}

void LogFileCursor::append_page_id(PageId val) {
  std::cout << "append_page_id at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  buffer_.write_page_id(buffer_offset_, val);
  increment_offset(sizeof(val));
}

const RID LogFileCursor::next_rid() {
  std::cout << "next_rid at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  auto rid = buffer_.read_rid(buffer_offset_);
  increment_offset(sizeof(uint64_t));
  return rid;
}

void LogFileCursor::append_rid(RID val) {
  std::cout << "append_rid at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  buffer_.write_rid(buffer_offset_, val);
  increment_offset(sizeof(uint64_t));
}

const Tuple LogFileCursor::next_tuple() {
  std::cout << "next_tuple at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  auto tuple = buffer_.read_tuple(buffer_offset_);
  increment_offset(tuple.size() + sizeof(int32_t));
  return tuple;
}

void LogFileCursor::append_tuple(const Tuple& tuple) {
  std::cout << "append_tuple at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  buffer_.write_tuple(buffer_offset_, tuple);
  increment_offset(tuple.size() + sizeof(int32_t));
}

txn_id_t LogFileCursor::next_txn_id() {
  std::cout << "next_txn_id at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  auto val = buffer_.read_txn_id(buffer_offset_);
  increment_offset(sizeof(val));
  return val;
}

void LogFileCursor::append_txn_id(txn_id_t val) {
  std::cout << "append_txn_id at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  buffer_.write_txn_id(buffer_offset_, val);
  increment_offset(sizeof(val));
}

lsn_t LogFileCursor::next_lsn() {
  std::cout << "next_lsn at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  auto val = buffer_.read_lsn(buffer_offset_);
  increment_offset(sizeof(val));
  return val;
}

void LogFileCursor::append_lsn(lsn_t val) {
  std::cout << "append_lsn at buffer_offset: " << buffer_offset_
            << " and file_offset: " << file_offset_ << std::endl;
  buffer_.write_lsn(buffer_offset_, val);
  increment_offset(sizeof(val));
}

bool LogFileCursor::deserialize_log_record(LogRecord& log) {
  logger->debug("[LogRecovery] Deserializing Log Record");
  if (buffer_offset() + LogRecord::HEADER_SIZE > buffer().size()) {
    std::cout << "Could not deserialize! Not enough space.." << std::endl;
    logger->debug("[LogRecovery] Could not deserialize! Not enough space..");
    return false;
  }

  std::cout << std::endl;
  std::cout << "READING LogRecord Header" << std::endl;
  auto size = buffer_.read_int32(buffer_offset_);
  if (size < 4) {
    std::cout << "Size is too small! Cannot deserialize!" << std::endl;
    return false;
  }

  size = next_int32();
  std::cout << "Size is " << size << std::endl;
  log.set_size(size);

  auto lsn = next_lsn();
  std::cout << "LSN is " << lsn << std::endl;
  log.set_lsn(lsn);

  auto txn_id = next_txn_id();
  std::cout << "TXN id is " << txn_id << std::endl;
  log.set_txn_id(txn_id);

  auto prev_lsn = next_lsn();
  std::cout << "Prev LSN is " << prev_lsn << std::endl;
  log.set_prev_lsn(prev_lsn);

  int32_t record_type_as_int = next_int32();
  std::cout << "record_type_as_int is " << record_type_as_int << std::endl;
  LogRecordType record_type  = static_cast<LogRecordType>(record_type_as_int);
  log.set_record_type(record_type);

  switch (record_type) {
  case LogRecordType::INSERT: {
    std::cout << "RecordType == INSERT" << std::endl;
    auto rid = next_rid();
    std::cout << "RID is " << rid << std::endl;
    log.set_insert_rid(rid);
    log.set_insert_tuple(next_tuple());
    return true;
  }
  case LogRecordType::MARK_DELETE:
  case LogRecordType::APPLY_DELETE:
  case LogRecordType::ROLLBACK_DELETE: {
    std::cout << "RecordType == DELETE" << std::endl;
    log.set_delete_rid(next_rid());
    log.set_delete_tuple(next_tuple());
    return true;
  }
  case LogRecordType::UPDATE: {
    std::cout << "RecordType == UPDATE" << std::endl;
    log.set_update_rid(next_rid());
    log.set_old_tuple(next_tuple());
    log.set_new_tuple(next_tuple());
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

    auto prev_page_id = next_page_id();
    std::cout << "Prev Page ID : " << prev_page_id << std::endl;
    log.set_prev_page_id(prev_page_id);

    auto page_id = next_page_id();
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

