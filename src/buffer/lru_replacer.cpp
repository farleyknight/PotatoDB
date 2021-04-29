#include "common/config.hpp"
#include "buffer/lru_replacer.hpp"

// TODO: LRUReplacer should be a subclass of Replacer

LRUReplacer::LRUReplacer(size_t num_pages)
  : num_pages_ (num_pages) {}

bool LRUReplacer::evict(UNUSED frame_id_t *frame_id) {
  // TODO:
  return false;
}

/*
  void LRUReplacer::allocate(frame_id_t frame_id) {
  // TODO:
  }

 */

void LRUReplacer::pin(UNUSED frame_id_t frame_id) {
  // TODO:
}

void LRUReplacer::unpin(UNUSED frame_id_t frame_id) {
  // TODO:
}

size_t LRUReplacer::size() {
  return 0;
}
