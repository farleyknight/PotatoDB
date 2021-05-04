#pragma once

#include "buffer/replacer.hpp"

class LRUReplacer : public Replacer {
public:
  LRUReplacer(size_t num_pages)
    : num_pages_ (num_pages)
  {}

  // No copy
  LRUReplacer(const LRUReplacer&) = delete;
  // No copy assign
  LRUReplacer& operator=(const LRUReplacer&) = delete;
  ~LRUReplacer() = default; // Default delete

  std::tuple<bool, frame_id_t> evict() {
    return std::make_tuple(false, -1);
  }

  void pin(UNUSED frame_id_t frame_id) {
    // TODO:
    return;
  }

  void unpin(UNUSED frame_id_t frame_id) {
    // TODO:
    return;
  }

  size_t size() {
    return 0; // TODO!
  }

  void reset() {
    return; // TODO!
  }

private:
  UNUSED int num_pages_ = 0;
};
