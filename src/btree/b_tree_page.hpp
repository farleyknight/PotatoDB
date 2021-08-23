#pragma once

#include <cassert>
#include <climits>
#include <cstdlib>
#include <string>

#include "buffer/buff_mgr.hpp"
#include "page/page_layout.hpp"
#include "index/generic_key.hpp"

// define page type enum
enum class IndexPageType {
  INVALID       = 0,
  LEAF_PAGE     = 1,
  INTERNAL_PAGE = 2
};

/**
 * Both internal and leaf page are inherited from this page.
 *
 * It actually serves as a header part for each B+ tree page and
 * contains information shared by both leaf page and internal page.
 *
 * Header format (size in byte, 24 bytes in total):
 * ----------------------------------------------------------------------------
 * | PageType (4) | lsn (4) | CurrentSize (4) | MaxSize (4) |
 * ----------------------------------------------------------------------------
 * | parent_page_id (4) | page_id(4) |
 * ----------------------------------------------------------------------------
 */
class BTreePage : public PageLayout {
public:
  BTreePage(Page* page)
    : PageLayout (page)
  {}

  static constexpr int32_t PAGE_TYPE_OFFSET      = 0;
  static constexpr int32_t LSN_OFFSET            = 4;
  static constexpr int32_t CURRENT_SIZE_OFFSET   = 8;
  static constexpr int32_t MAX_SIZE_OFFSET       = 12;
  static constexpr int32_t PARENT_PAGE_ID_OFFSET = 16;
  static constexpr int32_t PAGE_ID_OFFSET        = 20;

  bool is_leaf_page() const;
  bool is_root_page() const;

  void set_page_type(IndexPageType page_type);
  IndexPageType page_type() const;
  void increase_size(int amount);

  int size() const;
  void set_size(int32_t size);

  int max_size() const;
  void set_max_size(int32_t max_size);

  PageId parent_page_id() const;
  void set_parent_page_id(PageId parent_page_id);

  PageId page_id() const;
  void set_page_id(PageId page_id);

  lsn_t lsn() const;
  void set_lsn(lsn_t lsn);
};
