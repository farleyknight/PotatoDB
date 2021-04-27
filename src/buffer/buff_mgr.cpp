
#include "common/config.hpp"
#include "buffer/buff_mgr.hpp"
#include "page/hash_table_header_page.hpp"
#include "page/hash_table_block_page.hpp"

/**********************************************
 * Constructor
 **********************************************/

BuffMgr::BuffMgr(size_t pool_size,
                 MRef<DiskMgr> disk_mgr,
                 MRef<LogMgr> log_mgr)
  : pool_size_ (pool_size),
    disk_mgr_  (disk_mgr),
    log_mgr_   (log_mgr),
    pages_     (MutVec<Page>(pool_size))
{
  // TODO: Use a configuration file to allow `LRUReplacer`
  // to be used instead.
  replacer_ = ClockReplacer::make(pool_size);

  for (size_t i = 0; i < pool_size; ++i) {
    // TODO: Figure out if we need `static_cast` here?
    free_list_.emplace_back(static_cast<int>(i));
  }
}

/**********************************************
 *
 **********************************************/

Ptr<BuffMgr>
BuffMgr::make(size_t pool_size,
              MRef<DiskMgr> disk_mgr,
              MRef<LogMgr> log_mgr)
{
  return make_unique<BuffMgr>(pool_size, disk_mgr, log_mgr);
}

/**********************************************
 *
 **********************************************/

bool BuffMgr::flush(page_id_t page_id) {
  if (!contains_page(page_id)) {
    return false;
  }

  MRef<Page> page = page_by_id(page_id);
  if (!page.is_dirty()) {
    return true;
  }

  disk_mgr_.write_page(page_id, page);
  page.set_dirty(false);
  return true;
}

/**********************************************
 * TODO document me
 **********************************************/

OptRef<HTHeaderPage>
BuffMgr::fetch_ht_header_page(page_id_t page_id) {
  OptRef<Page> maybe_page = create_page();
  if (!maybe_page) {
    return std::nullopt;
  }

  auto &ht_header_page = static_cast<MRef<HTHeaderPage>>(maybe_page.value().get());
  return make_optional<RefWrap<HTHeaderPage>>(ht_header_page);
}


/**********************************************
 * TODO: Document me!
 **********************************************/

OptRef<TablePage>
BuffMgr::fetch_table_page(page_id_t page_id) {
  OptRef<Page> maybe_page = fetch_page(page_id);
  if (!maybe_page) {
    return std::nullopt;
  }

  auto &table_page = static_cast<MRef<TablePage>>(maybe_page.value().get());
  return make_optional<RefWrap<TablePage>>(table_page);
}

/**********************************************
 * TODO: Document me!
 **********************************************/

OptRef<Page>
BuffMgr::fetch_page(page_id_t page_id) {
  frame_id_t frame_id;

  if (contains_page(page_id)) {
    frame_id = page_table_[page_id];
    MRef<Page> page = pages_[frame_id];
    pin_page(page, frame_id);
    return Page::make_opt(page);
  }

  OptRef<Page> maybe_page = find_or_make_page(&frame_id);
  if (!maybe_page.has_value()) {
    return std::nullopt;
  }
  MRef<Page> page = maybe_page.value();

  disk_mgr_.read_page(page_id, page);
  page_table_[page_id] = frame_id;
  page.set_id(page_id);
  pin_page(page, frame_id);

  return page;
}

/**********************************************
 * TODO document me
 **********************************************/

OptRef<HTHeaderPage>
BuffMgr::create_ht_header_page() {
  OptRef<Page> maybe_page = create_page();
  if (!maybe_page) {
    return std::nullopt;
  }

  auto &page = maybe_page.value();
  auto &ht_header_page = static_cast<MRef<HTHeaderPage>>(page.get());
  return make_optional<RefWrap<HTHeaderPage>>(ht_header_page);
}

/**********************************************
 * TODO document me
 **********************************************/

OptRef<TablePage> BuffMgr::create_table_page() {
  OptRef<Page> maybe_page = create_page();
  if (!maybe_page) {
    return std::nullopt;
  }

  auto &page = maybe_page.value();
  auto &table_page = static_cast<MRef<TablePage>>(page.get());
  return make_optional<RefWrap<TablePage>>(table_page);
}

/**********************************************
 * TODO document me
 **********************************************/

OptRef<Page> BuffMgr::create_page() {
  frame_id_t frame_id = 0;
  OptRef<Page> maybe_page = find_or_make_page(&frame_id);
  if (!maybe_page.has_value()) {
    return std::nullopt;
  }
  MRef<Page> page = maybe_page.value();

  page_id_t page_id = disk_mgr_.allocate_page();
  page_table_[page_id] = frame_id;
  page.reset_memory();
  page.set_id(page_id);
  page.set_dirty(true);
  pin_page(page, frame_id);

  return page;
}

/**********************************************
 * TODO: document me
 **********************************************/

bool BuffMgr::unpin(page_id_t page_id, bool is_dirty) {
  if (!contains_page(page_id)) {
    return false;
  }

  frame_id_t frame_id = page_table_[page_id];
  MRef<Page> page = pages_[frame_id];

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

/**********************************************
 * TODO: document me
 **********************************************/

bool BuffMgr::delete_page(page_id_t page_id) {
  if (!contains_page(page_id)) {
    return true;
  }

  frame_id_t frame_id = page_table_[page_id];
  MRef<Page> page = pages_[frame_id];
  if (page.pin_count() > 0) {
    return false;
  }

  disk_mgr_.deallocate_page(page_id);
  page.set_id(INVALID_PAGE_ID);
  page.reset_memory();
  free_list_.push_back(page_id);
  page_table_.erase(page_id);

  return true;
}

/**********************************************
 * TODO document me
 **********************************************/

void BuffMgr::flush_all() {
  for (auto it : page_table_) {
    flush(it.first);
  }
  free_list_.clear();
  page_table_.clear();
  replacer_->reset();
}

/**********************************************
 * TODO document me
 **********************************************/

// TODO: Let's get rid of this raw pointer!
// It's also an out-parameter!
// Let's find a better way to do this..
// I think this method is used elsewhere in this class..
OptRef<Page> BuffMgr::find_or_make_page(MutRawPtr<frame_id_t> frame_id) {
  if (!free_list_.empty()) {
    *frame_id = free_list_.front();
    free_list_.pop_front();
    return Page::make_opt(pages_[*frame_id]);
  } else {
    if (!replacer_->evict(frame_id)) {
      return std::nullopt;
    }
    MRef<Page> page = pages_[*frame_id];
    flush_page(page);
    page_table_.erase(page.id());
    return Page::make_opt(page);
  }
}

/**********************************************
 * TODO document me
 **********************************************/

bool BuffMgr::contains_page(page_id_t page_id) {
  return page_table_.count(page_id) > 0;
}

/**********************************************
 * TODO document me
 **********************************************/

MRef<Page> BuffMgr::page_by_id(page_id_t page_id) {
  return pages_[page_table_[page_id]];
}

/**********************************************
 * TODO document me
 **********************************************/

void BuffMgr::pin_page(MRef<Page> page, frame_id_t frame_id) {
  page.pin();
  replacer_->pin(frame_id);
}

/**********************************************
 * TODO document me
 **********************************************/

void BuffMgr::flush_page(MRef<Page> page) {
  if (page.is_dirty()) {
    disk_mgr_.write_page(page.id(), page);
    page.set_dirty(false);
  }
}
