#pragma once

#include <cassert>
#include <string>

#include "common/config.hpp"
#include "tuple/tuple.hpp"

/** The type of the log record. */
enum class LogRecordType {
  INVALID         = 0,
  INSERT          = 1,
  MARK_DELETE     = 2,
  APPLY_DELETE    = 3,
  ROLLBACK_DELETE = 4,
  UPDATE          = 5,
  BEGIN           = 6,
  COMMIT          = 7,
  ABORT           = 8,
  NEW_PAGE        = 9,
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
  // TODO: We can replace this hard-coded `20` with a sum of sizeof(..)
  // NOTE: I _think_ it should be:
  //
  // 20 == sizeof(int32_t) + sizeof(lsn_t) + sizeof(txn_id_t) + sizeof(lsn_t) +
  //       sizeof(LogRecordType)
  //
  // Just double check that I suppose
  static const int HEADER_SIZE = 20;

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
            const RID& rid,
            Tuple tuple)
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
            const RID& update_rid,
            const Tuple& old_tuple,
            const Tuple& new_tuple)
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

  const Tuple& delete_tuple()   const { return delete_tuple_; }
  const RID&   delete_rid()     const { return delete_rid_.value(); }

  const Tuple& insert_tuple()   const { return insert_tuple_; }
  const RID&   insert_rid()     const { return insert_rid_.value(); }

  const Tuple& old_tuple()      const { return old_tuple_; }
  const Tuple& new_tuple()      const { return new_tuple_; }
  const RID&   update_rid()     const { return update_rid_.value(); }

  const PageId& page_id()       const { return page_id_; }
  const PageId& prev_page_id()  const { return prev_page_id_; }


  void set_insert_tuple(const Tuple& tuple) {
    insert_tuple_ = tuple;
  }

  // NOTE!
  // size should *not* include the header!
  size_t size()     const { return size_; }
  lsn_t lsn()       const { return lsn_; }
  txn_id_t txn_id() const { return txn_id_; }
  lsn_t prev_lsn()  const { return prev_lsn_; }
  void set_lsn(lsn_t lsn) { lsn_ = lsn; }

  const LogRecordType& record_type() const { return log_record_type_; }

  const string to_string() const {
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

  const RID main_rid() const {
    switch (log_record_type) {
    case LogRecordType::INSERT:
      return insert_rid_;
    case LogRecordType::UPDATE:
      return update_rid_;
    case LogRecordType::DELETE:
      return delete_rid_;
    default:
      assert(false); // NOTE: SHOULD NOT REACH HERE!
    }
    return RID::invalid();
  }

private:
  // NOTE: The size of log record(for serialization, in bytes)
  int32_t size_{0};
  // NOTE: Included in log record "HEADER"
  lsn_t lsn_                     = INVALID_LSN;
  txn_id_t txn_id_               = INVALID_TXN_ID;
  lsn_t prev_lsn_                = INVALID_LSN;
  LogRecordType log_record_type_ = LogRecordType::INVALID;

  // NOTE: Case 1: Delete operation
  optional<RID> delete_rid_;
  Tuple delete_tuple_;

  // NOTE: Case 2: Insert operation
  optional<RID> insert_rid_;
  Tuple insert_tuple_;

  // NOTE: Case 3: Update operation
  optional<RID> update_rid_;
  Tuple old_tuple_, new_tuple_;

  // NOTE Case 4: for new page operation
  PageId page_id_ = PageId::INVALID(),
    prev_page_id_ = PageId::INVALID();
};
