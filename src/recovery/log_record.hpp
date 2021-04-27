#pragma once

#include <cassert>
#include <string>

#include "common/config.hpp"
#include "tuple/tuple.hpp"

/** The type of the log record. */
enum class LogRecordType {
  INVALID = 0,
  INSERT,
  MARK_DELETE,
  APPLY_DELETE,
  ROLLBACK_DELETE,
  UPDATE,
  BEGIN,
  COMMIT,
  ABORT,
  /** Creating a new page in the table heap. */
  NEW_PAGE,
};

/**
 * For every write operation on the table page, you should write ahead a corresponding log record.
 *
 * For EACH log record, HEADER is like (5 fields in common, 20 bytes in total).
 *---------------------------------------------
 * | size | lsn_t | transID | prevLSN | LogType |
 *---------------------------------------------
 * For insert type log record
 *---------------------------------------------------------------
 * | HEADER | tuple_rid | tuple_size | tuple_data(char[] array) |
 *---------------------------------------------------------------
 * For delete type (including markdelete, rollbackdelete, applydelete)
 *----------------------------------------------------------------
 * | HEADER | tuple_rid | tuple_size | tuple_data(char[] array) |
 *---------------------------------------------------------------
 * For update type log record
 *-----------------------------------------------------------------------------------
 * | HEADER | tuple_rid | tuple_size | old_tuple_data | tuple_size | new_tuple_data |
 *-----------------------------------------------------------------------------------
 * For new page type log record
 *--------------------------
 * | HEADER | prev_page_id |
 *--------------------------
 */
class LogRecord {
public:
  // constructor for Txn type(BEGIN/COMMIT/ABORT)
  LogRecord(txn_id_t txn_id,
            lsn_t prev_lsn,
            LogRecordType log_record_type)
    : size_            (HEADER_SIZE),
      txn_id_          (txn_id),
      prev_lsn_        (prev_lsn),
      log_record_type_ (log_record_type)
  {}

  // constructor for INSERT/DELETE type
  LogRecord(txn_id_t txn_id,
            lsn_t prev_lsn,
            LogRecordType log_record_type,
            CRef<RID> rid,
            Move<Tuple> tuple)
    : txn_id_          (txn_id),
      prev_lsn_        (prev_lsn),
      log_record_type_ (log_record_type)
  {
    if (log_record_type == LogRecordType::INSERT) {
      insert_rid_   = rid;
      insert_tuple_.copy_from(tuple);
    } else {
      assert(log_record_type == LogRecordType::APPLY_DELETE ||
             log_record_type == LogRecordType::MARK_DELETE ||
             log_record_type == LogRecordType::ROLLBACK_DELETE);
      delete_rid_   = rid;
      delete_tuple_.copy_from(tuple);
    }
    // calculate log record size
    size_ = HEADER_SIZE + sizeof(RID) + sizeof(int32_t) + tuple.size();
  }

  // constructor for UPDATE type
  LogRecord(txn_id_t txn_id,
            lsn_t prev_lsn,
            LogRecordType log_record_type,
            CRef<RID> update_rid,
            CRef<Tuple> old_tuple,
            CRef<Tuple> new_tuple)
    : txn_id_          (txn_id),
      prev_lsn_        (prev_lsn),
      log_record_type_ (log_record_type),
      update_rid_      (update_rid),
      old_tuple_       (old_tuple),
      new_tuple_       (new_tuple)
  {
    // calculate log record size
    size_ = HEADER_SIZE + sizeof(RID) + old_tuple.size() +
      new_tuple.size() + 2 * sizeof(int32_t);
  }

  // constructor for NEW_PAGE type
  LogRecord(txn_id_t txn_id,
            lsn_t prev_lsn,
            LogRecordType log_record_type,
            PageId prev_page_id,
            PageId page_id)
    : size_            (HEADER_SIZE),
      txn_id_          (txn_id),
      prev_lsn_        (prev_lsn),
      log_record_type_ (log_record_type),
      page_id_         (page_id),
      prev_page_id_    (prev_page_id)
  {
    // calculate log record size,
    // header size + sizeof(prev_page_id) + sizeof(page_id)
    size_ = HEADER_SIZE + sizeof(page_id_t) * 2;
  }

  ~LogRecord() = default;

  CRef<Tuple> delete_tuple()        { return delete_tuple_; }
  CRef<RID>   delete_rid()          { return delete_rid_.value(); }

  CRef<Tuple> insert_tuple()        { return insert_tuple_; }
  CRef<RID>   insert_rid()          { return insert_rid_.value(); }

  CRef<Tuple> original_tuple()      { return old_tuple_; }
  CRef<Tuple> update_tuple()        { return new_tuple_; }
  CRef<RID>   update_rid()          { return update_rid_.value(); }

  PageId     prev_page_id()         { return prev_page_id_; }

  size_t size()     { return size_; }
  lsn_t lsn()       { return lsn_; }
  txn_id_t txn_id() { return txn_id_; }
  lsn_t prev_lsn()  { return prev_lsn_; }

  CRef<LogRecordType> log_record_type() { return log_record_type_; }

  // For debug purpose
  String to_string() const {
    std::ostringstream os;
    os << "Log["
       << "size:" << size_ << ", "
       << "LSN:" << lsn_ << ", "
       << "transID:" << txn_id_ << ", "
       << "prevLSN:" << prev_lsn_ << ", "
       << "file_id: " << page_id_.file_id() << ", "
       << "block_id: " << page_id_.block_id() << ", "
       << "LogType:" << static_cast<int>(log_record_type_) << "]";

    return os.str();
  }

 private:
  // the size of log record(for serialization, in bytes)
  int32_t size_{0};
  // must have fields
  lsn_t lsn_       = INVALID_LSN;
  txn_id_t txn_id_ = INVALID_TXN_ID;
  lsn_t prev_lsn_  = INVALID_LSN;
  LogRecordType log_record_type_ = LogRecordType::INVALID;

  // case1: for delete operation, delete_tuple_ for UNDO operation
  MutOption<RID> delete_rid_;
  Tuple delete_tuple_;

  // case2: for insert operation
  MutOption<RID> insert_rid_;
  Tuple insert_tuple_;

  // case3: for update operation
  MutOption<RID> update_rid_;
  Tuple old_tuple_, new_tuple_;

  // case4: for new page operation
  PageId page_id_, prev_page_id_;
  static const int HEADER_SIZE = 20;
};
