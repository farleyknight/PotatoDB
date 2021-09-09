#pragma once

#include <list>
#include <unordered_map>

#include "buffer/clock_replacer.hpp"

#include "page/page.hpp"
#include "disk/disk_mgr.hpp"

#include "recovery/log_mgr.hpp"

class BuffMgr {
public:
  BuffMgr(int32_t pool_size,
          DiskMgr& disk_mgr,
          LogMgr& log_mgr);

  // No copy
  BuffMgr(const BuffMgr&) = delete;
  // No copy assign
  BuffMgr& operator=(const BuffMgr&) = delete;
  // Default delete
  ~BuffMgr() = default;

  bool flush(PageId page_id);

  Page* fetch_page(PageId page_id);

  bool unpin(PageId page_id, bool is_dirty);

  bool delete_page(PageId page_id);
  void flush_all();

  const vector<Page>& pages()    { return pages_; }
  Page& page_at(size_t i)        { return pages_[i]; }
  size_t pool_size()             { return pool_size_; }

  bool flush_page(PageId page_id);
  bool flush_page(Page& page);

private:
  tuple<Page*, frame_id_t> pick_or_evict_page();

  bool contains_page(PageId page_id);
  Page& page_by_id(PageId page_id);
  void pin_page(Page& page, frame_id_t frame_id);

  int32_t pool_size_;
  vector<Page> pages_;
  map<int32_t, frame_id_t> page_table_;
  MutList<frame_id_t> free_list_;
  ptr<Replacer> replacer_;

  DiskMgr& disk_mgr_;
  LogMgr& log_mgr_;
};
