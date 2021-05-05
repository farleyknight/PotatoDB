#pragma once

#include <list>
#include <unordered_map>

#include "buffer/clock_replacer.hpp"

#include "page/page.hpp"
#include "page/table_page.hpp"
#include "disk/disk_mgr.hpp"

#include "recovery/log_mgr.hpp"

class BPlusTreePage;
class HTHeaderPage;

/*
 * A better Buffer Pool Manager implementation:
 *
 * A buffer pool manager should not couple buffer data to the read/write
 * methods.
 *
 * It should also not couple buffer data to buffer metadata either.
 *
 * To resolve these two ideas, every time we pass around a page of data,
 * what we really should be passing around are a triple:
 *
 * => Page read-write methods. [CONST, pointer to object on HEAP]
 * => Page metadata            [MUT, small copyable object, can be stored on STACK]
 * => Page data                [MUT, pass by reference, pointer to large memory chunk on the HEAP]
 *
 * 1) By decoupling the read-write methods, this makes conversion from one type of page to another
 *    relatively easy.
 * 2) By decoupling page data from page metadata, we can make lots of existing "mutable" methods
 *    const, since we are only mutating the metadata, not the actual data.
 */

class BuffMgr {
public:
  /**********************************************
   * BuffMgr - A Buffer Manager for our DBMS
   * - Manages chunks of memory called 'pages'
   * - Used for keeping an internal cache of
   *   tuple data in main memory.
   **********************************************/

  BuffMgr(size_t pool_size,
          DiskMgr& disk_mgr,
          LogMgr& log_mgr);

  BuffMgr(const BuffMgr&) = delete; // No copy
  BuffMgr& operator=(const BuffMgr&) = delete; // No copy assign
  ~BuffMgr() = default; // Default delete

  /**********************************************
   * Instance methods
   **********************************************/

  bool flush(PageId page_id);

  Page* fetch_page(PageId page_id);
  Page* create_page();

  bool unpin(PageId page_id, bool is_dirty);

  bool delete_page(PageId page_id);
  void flush_all();

  const vector<Page>& pages()    { return pages_; }
  Page& page_at(size_t i)        { return pages_[i]; }
  size_t pool_size()             { return pool_size_; }

  bool flush_page(PageId page_id);
  bool flush_page(Page& page);

private:
  std::tuple<Page*, frame_id_t> pick_or_evict_page();

  bool contains_page(PageId page_id);
  Page& page_by_id(PageId page_id);
  void pin_page(Page& page, frame_id_t frame_id);

  size_t pool_size_;
  vector<Page> pages_;
  MutMap<PageId, frame_id_t> page_table_;
  MutList<frame_id_t> free_list_;
  ptr<Replacer> replacer_;

  DiskMgr& disk_mgr_;
  const LogMgr& log_mgr_;
};
