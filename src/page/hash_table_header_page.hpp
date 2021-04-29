#pragma once

#include "page/page.hpp"

/**
 *
 * Header Page for linear probing hash table.
 *
 * Header format (size in byte, 16 bytes in total):
 * -------------------------------------------------------------
 * | lsn_t (4) | Size (4) | page_id_t(4) | NextBlockIndex(4)
 * -------------------------------------------------------------
 */

class HTHeaderPage : public Page {
public:
  /**
   * @return the number of buckets in the hash table;
   */
  size_t size() const;

  /**
   * Sets the size field of the hash table to size
   *
   * @param size the size for the size field to be set to
   */
  void set_size(size_t size);

  /**
   * @return the page ID of this page
   */
  page_id_t page_id() const;

  /**
   * Sets the page ID of this page
   *
   * @param page_id the page id for the page id field to be set to
   */
  void set_page_id(page_id_t page_id);

  /**
   * @return the lsn of this page
   */
  lsn_t lsn() const;

  /**
   * Sets the lsn_t of this page
   *
   * @param lsn the log sequence number for the lsn field to be set to
   */
  void set_lsn(lsn_t lsn);

  /**
   * Adds a block page_id to the end of header page
   *
   * @param page_id page_id to be added
   */
  void add_block_page_id(page_id_t page_id);

  /**
   * Returns the page_id of the index-th block
   *
   * @param index the index of the block
   * @return the page_id for the block.
   */
  page_id_t block_page_id(size_t index);

  /**
   * @return the number of blocks currently stored in the header page
   */
  size_t num_blocks() const ;

  void reset_block_index();

private:
  lsn_t lsn_;
  size_t size_;
  PageId page_id_;
  size_t next_index_;
  // page_id_t block_page_ids_[0];
};
