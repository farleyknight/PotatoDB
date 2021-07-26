#pragma once

#include "page/page.hpp"
#include "page/page_layout.hpp"

/**
 *
 * Header Page for linear probing hash table.
 *
 * Header format (size in byte, 16 bytes in total):
 * -------------------------------------------------------------
 * | lsn_t (4) | Size (4) | page_id_t(4) | NextBlockIndex(4)
 * -------------------------------------------------------------
 */

// TODO: Move to `/hash`

class HTHeaderPage : public PageLayout {
public:
  HTHeaderPage(Page* page)
    : PageLayout (page)
  {}

  size_t size() const;
  void set_size(size_t size);
  PageId page_id() const;
  void set_page_id(PageId page_id);
  lsn_t lsn() const;
  void set_lsn(lsn_t lsn);
  void add_block_page_id(PageId page_id);
  PageId block_page_id(size_t index);
  size_t num_blocks() const;
  void reset_block_index();

private:
  lsn_t lsn_;
  size_t size_;
  PageId page_id_ = PageId::INVALID();
  size_t next_index_;
};
