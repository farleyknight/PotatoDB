#pragma once

#include "buffer/replacer.hpp"

/**
 * LRUReplacer implements the lru replacement policy, which approximates the Least Recently Used policy.
 */
class LRUReplacer : public Replacer {
public:

  /**********************************************
  * Constructors & destructor
  **********************************************/

  explicit LRUReplacer(size_t num_pages);
  LRUReplacer(Ref<LRUReplacer>) = delete;
  // No copy
  MRef<LRUReplacer> operator=(Ref<LRUReplacer>) = delete;
  // No copy assign
  ~LRUReplacer() = default; // Default delete

  /**********************************************
  * Instance methods
  **********************************************/

  bool evict(frame_id_t *frame_id) override;
  void pin(frame_id_t frame_id) override;
  void unpin(frame_id_t frame_id) override;
  size_t size() override;

private:
  int num_pages_ = 0;
  // TODO(student): implement me!
};
