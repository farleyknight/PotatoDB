#include <tuple>

#include "common/config.hpp"
#include "buffer/buff_mgr.hpp"
#include "buffer/lru_replacer.hpp"
#include "page/hash_table_header_page.hpp"
#include "page/hash_table_block_page.hpp"

BuffMgr::BuffMgr(int32_t pool_size,
                 DiskMgr& disk_mgr,
                 LogMgr& log_mgr)
  : pool_size_ (pool_size),
    pages_     (vector<Page>(pool_size)),
    disk_mgr_  (disk_mgr),
    log_mgr_   (log_mgr)
{
  // TODO: Use a configuration file to allow `LRUReplacer`
  // to be used instead.
  replacer_ = make_unique<ClockReplacer>(pool_size);
  // replacer_ = make_unique<LRUReplacer>(pool_size);

  for (int32_t i = 0; i < pool_size; ++i) {
    free_list_.emplace_back(i);
  }
}

tuple<Page*, frame_id_t>
BuffMgr::pick_or_evict_page() {
  if (!free_list_.empty()) {
    frame_id_t frame_id = free_list_.front();
    free_list_.pop_front();
    return make_tuple(&pages_[frame_id], frame_id);
  } else {
    auto [evicted, frame_id] = replacer_->evict();
    if (!evicted) {
      return make_tuple(nullptr, frame_id);
    }
    Page& page = pages_[frame_id];
    flush_page(page);
    page_table_.erase(page.page_id().as_uint32());

    return make_tuple(&pages_[frame_id], frame_id);
  }
}

bool
BuffMgr::flush_page(PageId page_id) {
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

Page*
BuffMgr::fetch_page(PageId page_id) {
  try {
    assert(page_id.is_valid());
    if (contains_page(page_id)) {
      auto frame_id = page_table_[page_id.as_uint32()];
      Page& page = pages_[frame_id];
      pin_page(page, frame_id);
      return &pages_[frame_id];
    }

    auto [maybe_page, frame_id] = pick_or_evict_page();
    if (maybe_page == nullptr) {
      return nullptr;
    }
    Page& page = *maybe_page;

    logger->debug("[BuffMgr] Page Read - " + page_id.to_string());
    disk_mgr_.read_page(page_id, page);
    page_table_[page_id.as_uint32()] = frame_id;
    page.set_id(page_id);

    assert(page.page_id().is_valid());

    logger->debug("[BuffMgr] Page ID is valid");
    logger->flush();

    pin_page(page, frame_id);

    logger->debug("[BuffMgr] Ready to pin frame_id: " + std::to_string(frame_id));
    logger->flush();

    return maybe_page;
  } catch (std::exception& e) {
    logger->debug("[BuffMgr] Caught error in BuffMgr::fetch_page");
    logger->debug(e.what());
  }

  return nullptr;
}

bool
BuffMgr::unpin(PageId page_id, bool is_dirty) {
  if (!contains_page(page_id)) {
    return false;
  }

  auto frame_id = page_table_[page_id.as_uint32()];
  auto &page    = pages_[frame_id];

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

bool
BuffMgr::delete_page(PageId page_id) {
  if (!contains_page(page_id)) {
    return true;
  }

  auto frame_id = page_table_[page_id.as_uint32()];
  auto& page = pages_[frame_id];
  if (page.pin_count() > 0) {
    return false;
  }

  disk_mgr_.deallocate_page(page_id);
  page.set_id(PageId::INVALID());
  page.reset_memory();
  free_list_.push_back(frame_id);
  page_table_.erase(page_id.as_uint32());

  return true;
}

void
BuffMgr::flush_all() {
  for (auto& page : pages_) {
    flush_page(page);
  }
  free_list_.clear();
  page_table_.clear();
  replacer_->reset();
}

bool
BuffMgr::contains_page(PageId page_id) {
  assert(page_id.is_valid());
  return page_table_.count(page_id.as_uint32()) > 0;
}

Page&
BuffMgr::page_by_id(PageId page_id) {
  return pages_[page_table_[page_id.as_uint32()]];
}

void
BuffMgr::pin_page(Page& page, frame_id_t frame_id) {
  page.pin();
  replacer_->pin(frame_id);
}

bool
BuffMgr::flush_page(Page& page) {
  // TODO: Need to add hook into LogMgr to actually flush the page
  // https://github.com/xiaohuanlin/private-bustub/blob/189c621343e30fc51011edfc29809ed91c5fbd55/src/buffer/buffer_pool_manager.cpp#L108
  if (page.is_dirty()) {
    disk_mgr_.write_page(page.page_id(), page);
    page.set_dirty(false);
    return true;
  }
  return false;
}
