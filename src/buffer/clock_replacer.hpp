#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "common/config.hpp"
#include "buffer/replacer.hpp"

class ClockReplacer : public Replacer {
public:
  ClockReplacer(size_t max_frames);

  // No copy
  ClockReplacer(const ClockReplacer& other) = delete;
  // No copy assign
  ClockReplacer& operator=(const ClockReplacer& other) = delete;
  ~ClockReplacer() = default; // Default delete

  std::tuple<bool, frame_id_t> evict() override;

  void allocate(frame_id_t frame_id);
  void pin(frame_id_t frame_id) override;
  // unpin the frame, allowing it to be thrown out by `evict`
  void unpin(frame_id_t frame_id) override;

  size_t size() override {
    return available_frames_;
  }

  void reset() override {
    // TODO
  }

private:
  size_t max_frame_id_;
  size_t available_frames_;
  frame_id_t curr_frame_id_;
  vector<bool> pinned_;
  vector<bool> recently_used_;
  vector<bool> second_chance_;
};
