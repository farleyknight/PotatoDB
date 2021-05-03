
#include <tuple>

#include "common/config.hpp"
#include "buffer/buff_mgr.hpp"
#include "page/hash_table_header_page.hpp"
#include "page/hash_table_block_page.hpp"

BuffMgr::BuffMgr(size_t pool_size,
                 DiskMgr& disk_mgr,
                 LogMgr& log_mgr)
  : pool_size_ (pool_size),
    pages_     (MutVec<Page>(pool_size)),
    disk_mgr_  (disk_mgr),
    log_mgr_   (log_mgr)
{
  // TODO: Use a configuration file to allow `LRUReplacer`
  // to be used instead.
  replacer_ = make_unique<ClockReplacer>(pool_size);

  for (size_t i = 0; i < pool_size; ++i) {
    // TODO: Figure out if we need `static_cast` here?
    free_list_.emplace_back(static_cast<int>(i));
  }
}

std::tuple<Page*, frame_id_t> BuffMgr::pick_or_evict_page() {
  if (!free_list_.empty()) {
    frame_id_t frame_id = free_list_.front();
    free_list_.pop_front();
    return std::make_tuple(&pages_[frame_id], frame_id);
  } else {
    bool evicted;
    frame_id_t frame_id = -1;
    std::tie(evicted, frame_id) = replacer_->evict();
    if (!evicted) {
      return std::make_tuple(nullptr, frame_id);
    }
    Page& page = pages_[frame_id];
    flush_page(page);
    page_table_.erase(page.page_id());

    return std::make_tuple(&pages_[frame_id], frame_id);
  }
}

bool BuffMgr::flush_page(PageId page_id) {
  if (!contains_page(page_id)) {
    return false;
  }

  Page& page = page_by_id(page_id);
  if (!page.is_dirty()) {
    return true;
  }

  disk_mgr_.write_page(page_id, page);
  page.set_dirty(false);
  return true;
}

Page* BuffMgr::fetch_page(PageId page_id) {
  frame_id_t frame_id;

  if (contains_page(page_id)) {
    frame_id = page_table_[page_id];
    Page& page = pages_[frame_id];
    pin_page(page, frame_id);

    return &pages_[frame_id];
  }

  Page *maybe_page;
  std::tie(maybe_page, frame_id) = pick_or_evict_page();
  if (maybe_page == nullptr) {
    return nullptr;
  }
  Page& page = *maybe_page;

  disk_mgr_.read_page(page_id, page);
  page_table_[page_id] = frame_id;
  page.set_id(page_id);
  pin_page(page, frame_id);

  return maybe_page;
}

// NOTE: At some point this method should take a `file_id_t`
// and allocate an extra block on the page via the `disk_mgr`.
Page* BuffMgr::create_page() {
  frame_id_t frame_id;
  Page *maybe_page = nullptr;
  std::tie(maybe_page, frame_id) = pick_or_evict_page();
  if (maybe_page == nullptr) {
    return nullptr;
  }
  Page& page = *maybe_page;

  PageId page_id = disk_mgr_.allocate_page();
  page_table_[page_id] = frame_id;
  page.reset_memory();
  page.set_id(page_id);
  page.set_dirty(true);
  pin_page(page, frame_id);

  return maybe_page;
}

bool BuffMgr::unpin(PageId page_id, bool is_dirty) {
  if (!contains_page(page_id)) {
    return false;
  }

  frame_id_t frame_id = page_table_[page_id];
  Page& page = pages_[frame_id];

  if (page.pin_count() <= 0) {
    return false;
  }

  page.unpin();
  if (page.pin_count() == 0) {
    replacer_->unpin(frame_id);
  }
  page.set_dirty(page.is_dirty() || is_dirty);

  return true;
}

bool BuffMgr::delete_page(PageId page_id) {
  if (!contains_page(page_id)) {
    return true;
  }

  frame_id_t frame_id = page_table_[page_id];
  Page& page = pages_[frame_id];
  if (page.pin_count() > 0) {
    return false;
  }

  disk_mgr_.deallocate_page(page_id);
  page.set_id(PageId::INVALID());
  page.reset_memory();
  free_list_.push_back(frame_id);
  page_table_.erase(page_id);

  return true;
}

void BuffMgr::flush_all() {
  for (auto it : page_table_) {
    flush_page(it.first);
  }
  free_list_.clear();
  page_table_.clear();
  replacer_->reset();
}

bool BuffMgr::contains_page(PageId page_id) {
  return page_table_.count(page_id) > 0;
}

Page& BuffMgr::page_by_id(PageId page_id) {
  return pages_[page_table_[page_id]];
}

void BuffMgr::pin_page(Page& page, frame_id_t frame_id) {
  page.pin();
  replacer_->pin(frame_id);
}

bool BuffMgr::flush_page(Page& page) {
  if (page.is_dirty()) {
    disk_mgr_.write_page(page.page_id(), page);
    page.set_dirty(false);
    return true;
  }
  return false;
}
