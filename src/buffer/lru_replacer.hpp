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
  LRUReplacer(CRef<LRUReplacer>) = delete;
  // No copy
  LRUReplacer& operator=(CRef<LRUReplacer>) = delete;
  // No copy assign
  ~LRUReplacer() = default; // Default delete

  /**********************************************
  * Instance methods
  **********************************************/

  std::tuple<bool, frame_id_t> evict() override;

  void pin(frame_id_t frame_id) override;
  void unpin(frame_id_t frame_id) override;
  size_t size() override;
  void reset() override;

private:
  UNUSED int num_pages_ = 0;
  // TODO(student): implement me!
};
