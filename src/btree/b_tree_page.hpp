#pragma once

#include <cassert>
#include <climits>
#include <cstdlib>
#include <string>

#include "buffer/buff_mgr.hpp"
#include "index/generic_key.hpp"

// define page type enum
enum class IndexPageType { INVALID_INDEX_PAGE = 0, LEAF_PAGE, INTERNAL_PAGE };

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
class BTreePage {
public:
  BTreePage(IndexPageType page_type,
            lsn_t lsn,
            int32_t size,
            int32_t max_size,
            PageId parent_page_id,
            PageId page_id)
    : page_type_      (page_type),
      lsn_            (lsn),
      size_           (size),
      max_size_       (max_size),
      parent_page_id_ (parent_page_id),
      page_id_        (page_id)
  {}

  bool is_leaf_page() const;
  bool is_root_page() const;
  void set_page_type(IndexPageType page_type);

  int size() const;
  void set_size(int size);
  void increase_size(int amount);

  int max_size() const;
  void set_max_size(int max_size);
  int min_size() const;

  PageId parent_page_id() const;
  void set_parent_page_id(PageId parent_page_id);

  PageId page_id() const;
  void set_page_id(PageId page_id);

  void set_lsn(lsn_t lsn = INVALID_LSN);

 private:
  // member variable, attributes that both internal and leaf page share
  IndexPageType page_type_;
  lsn_t lsn_;
  int32_t size_;
  int32_t max_size_;
  PageId parent_page_id_;
  PageId page_id_;
};
