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
*  | page_id_t (4)| lsn_t (4)| prev_page_id_t (4)| next_page_id_t (4)| FreeSpacePointer(4) |
*  ----------------------------------------------------------------------------
*  ----------------------------------------------------------------
*  | TupleCount (4) | Tuple_1 offset (4) | Tuple_1 size (4) | ... |
*  ----------------------------------------------------------------
*
*/

class TablePage : public PageLayout {
public:
  TablePage(Page* page)
    : PageLayout (page)
  {}

  // TODO: Finish recovery module
  lsn_t lsn() {
    return page_->read_lsn();
  }

  void set_lsn(lsn_t lsn) {
    page_->write_lsn(lsn);
  }

  void set_page_id(PageId page_id) {
    page_->write_page_id(0, page_id);
  }

  PageId table_page_id() {
    return page_->read_page_id(0);
  }

  PageId prev_page_id() {
    return page_->read_page_id(OFFSET_PREV_PAGE_ID);
  }

  PageId next_page_id() {
    return page_->read_page_id(OFFSET_NEXT_PAGE_ID);
  }

  void set_table_page_id(PageId table_page_id) {
    page_->write_page_id(0, table_page_id);
  }

  void set_prev_page_id(PageId prev_page_id) {
    page_->write_page_id(OFFSET_PREV_PAGE_ID, prev_page_id);
  }

  void set_next_page_id(PageId next_page_id) {
    page_->write_page_id(OFFSET_NEXT_PAGE_ID, next_page_id);
  }

protected:

  static constexpr size_t SIZE_TABLE_PAGE_HEADER = 24;
  static constexpr size_t TUPLE_SLOT_SIZE = 8;
  static constexpr size_t OFFSET_PREV_PAGE_ID = 8;
  static constexpr size_t OFFSET_NEXT_PAGE_ID = 12;
  static constexpr size_t OFFSET_FREE_SPACE = 16;
  static constexpr size_t OFFSET_TUPLE_COUNT = 20;
  static constexpr size_t OFFSET_TUPLE_OFFSET = 24;
  static constexpr size_t OFFSET_TUPLE_SIZE = 28;
};
