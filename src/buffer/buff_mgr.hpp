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
          MRef<DiskMgr> disk_mgr,
          MRef<LogMgr> log_mgr);

  BuffMgr(Ref<BuffMgr>) = delete; // No copy
  BuffMgr& operator=(Ref<BuffMgr>) = delete; // No copy assign
  ~BuffMgr() = default; // Default delete

  /**********************************************
   * Heap allocation
   **********************************************/

  static Ptr<BuffMgr> make(size_t pool_size,
                           MRef<DiskMgr> disk_mgr,
                           MRef<LogMgr> log_mgr);

  /**********************************************
   * Instance methods
   **********************************************/

  bool flush(page_id_t page_id);

  OptRef<Page> fetch_page(page_id_t page_id);
  OptRef<Page> create_page();

  // NOTE: This is why we should decouple page read-write methods from
  // page data.
  OptRef<TablePage> fetch_table_page(page_id_t page_id);
  OptRef<TablePage> create_table_page();

  OptRef<BPlusTreePage> fetch_btree_page(page_id_t page_id);
  OptRef<BPlusTreePage> create_btree_page();

  OptRef<HTHeaderPage> fetch_ht_header_page(page_id_t page_id);
  OptRef<HTHeaderPage> create_ht_header_page();

  bool unpin(page_id_t page_id, bool is_dirty);

  bool delete_page(page_id_t page_id);
  void flush_all();

  Ref<Vec<Page>> pages()         { return pages_; }
  MRef<Page> page_at(size_t i) { return pages_[i]; }
  size_t pool_size()             { return pool_size_; }

  void flush_page(page_id_t page_id);
  void flush_page(MRef<Page> page);

private:
  // TODO: We can get rid of this out parameter if
  // we return a pair.
  // And there should be a way to do destucturing bind
  // via something called std::tie?
  // https://en.cppreference.com/w/cpp/utility/tuple/make_tuple
  OptRef<Page> find_or_make_page(MutRawPtr<frame_id_t> frame_id);
  bool contains_page(page_id_t page_id);
  MRef<Page> page_by_id(page_id_t page_id);
  void pin_page(MRef<Page> page, frame_id_t frame_id);

  size_t pool_size_;
  MutVec<Page> pages_;
  MutMap<page_id_t, frame_id_t> page_table_;
  MutList<frame_id_t> free_list_;
  MRef<DiskMgr> disk_mgr_;
  Ref<LogMgr> log_mgr_;
  MutPtr<Replacer> replacer_;
};
