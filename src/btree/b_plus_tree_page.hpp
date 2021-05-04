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
 * | PageType (4) | lsn_t (4) | CurrentSize (4) | MaxSize (4) |
 * ----------------------------------------------------------------------------
 * | Parentpage_id_t (4) | page_id_t(4) |
 * ----------------------------------------------------------------------------
 */
class BPlusTreePage {
public:
  BPlusTreePage(IndexPageType page_type,
                lsn_t lsn,
                int32_t size,
                int32_t max_size,
                page_id_t parent_page_id,
                page_id_t page_id)
    : page_type_      (page_type),
      lsn_            (lsn),
      size_           (size),
      max_size_       (max_size),
      parent_page_id_ (parent_page_id),
      page_id_        (page_id) {}

  bool is_leaf_page() const;
  bool IsRootPage() const;
  void SetPageType(IndexPageType page_type);

  int GetSize() const;
  void SetSize(int size);
  void IncreaseSize(int amount);

  int GetMaxSize() const;
  void SetMaxSize(int max_size);
  int GetMinSize() const;

  page_id_t GetParentpage_id_t() const;
  void SetParentpage_id_t(page_id_t parent_page_id);

  page_id_t page_id() const;
  void Setpage_id_t(page_id_t page_id);

  void Setlsn_t(lsn_t lsn = INVALID_LSN);

 private:
  // member variable, attributes that both internal and leaf page share
  IndexPageType page_type_;
  lsn_t lsn_;
  int32_t size_;
  int32_t max_size_;
  page_id_t parent_page_id_;
  page_id_t page_id_;
};
