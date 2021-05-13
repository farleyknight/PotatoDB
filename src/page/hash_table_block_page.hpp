#pragma once

#include <utility>
#include "common/config.hpp"
#include "page/page.hpp"
#include "index/generic_key.hpp"
#include "index/generic_comp.hpp"
#include "index/int_comp.hpp"

/**
 * Store indexed key and and value together within block page. Supports
 * non-unique keys.
 *
 * Block page format (keys are stored in order):
 *  ----------------------------------------------------------------
 * | KEY(1) + VALUE(1) | KEY(2) + VALUE(2) | ... | KEY(n) + VALUE(n)
 *  ----------------------------------------------------------------
 *
 *  Here '+' means concatenation.
 *
 */

template<class KeyT, class ValueT>
class HTBlockPage {
public:
  using CompT    = Comp<KeyT>;
  using MappingT = pair<KeyT, ValueT>;

  static const int BLOCK_ARRAY_SIZE =
    (4 * PAGE_SIZE / (4 * sizeof(MappingT) + 1));

  HTBlockPage(Page* page)
    : page_ (page)
  {}

  KeyT key_at(slot_offset_t bucket_ind) const;
  ValueT value_at(slot_offset_t bucket_ind) const;
  bool insert(slot_offset_t bucket_ind,
              const KeyT& key,
              const ValueT& value);

  void remove(slot_offset_t bucket_ind);
  bool is_occupied(slot_offset_t bucket_ind) const;
  bool is_readable(slot_offset_t bucket_ind) const;


  void wlatch() {
    page_->wlatch();
  }

  void wunlatch() {
    page_->wunlatch();
  }

  void rlatch() {
    page_->rlatch();
  }

  void runlatch() {
    page_->runlatch();
  }

  size_t size() {
    return page_->size();
  }

  PageId page_id() {
    return page_->page_id();
  }

private:
  Page* page_;
};
