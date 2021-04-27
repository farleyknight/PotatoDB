#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "common/config.hpp"
#include "buffer/replacer.hpp"

class ClockReplacer : public Replacer {
public:
  /**********************************************
   * Constructors & destructor
   **********************************************/

  ClockReplacer(size_t max_frames)
    : max_frame_id_     (max_frames),
      available_frames_ (0),
      curr_frame_id_    (0)
  {
    // Resize our vectors.
    pinned_.resize(max_frames);
    recently_used_.resize(max_frames);
    second_chance_.resize(max_frames);

    // Since we can unpin pages before they have been pinned, we set all of
    // these values to true.
    std::fill(pinned_.begin(), pinned_.end(), true);
  }

  ClockReplacer(const ClockReplacer &) = delete; // No copy
  ClockReplacer& operator=(const ClockReplacer &) = delete; // No copy assign
  ~ClockReplacer() = default; // Default delete

  static MutPtr<Replacer> make(size_t max_frames) {
    return make_unique<ClockReplacer>(max_frames);
  }

  /**********************************************
  * Instance methods
  **********************************************/

  /**
   * Set the passed-in pointer to the frame ID of the next frame that we should evict.
   * Note that we cannot evict a page that has pins. We can only consider unpinned pages.
   *
   * Return true if we can evict a frame, and false otherwise.
   */
  bool evict(frame_id_t *frame_id) {
    // We can only do an eviction if we have frames to evict!
    while (available_frames_ > 0) {
      // If a frame was recently used and is not pinned, we check if it can be evicted.
      if (recently_used_[curr_frame_id_] && !pinned_[curr_frame_id_]) {
        // Check if we should give this frame a second chance.
        if (second_chance_[curr_frame_id_]) {
          // If we have already seen this frame, it loses it's second chance.
          // In the next go-around, we'll be considering this frame for eviction.
          second_chance_[curr_frame_id_] = false;
        } else {
          // Do the eviction! Set the integer pointer of the frame we're evicting.
          *frame_id = curr_frame_id_;
          // Once a frame has been evicted, that implies it was not recently used.
          recently_used_[curr_frame_id_] = false;
          // Decrement our frames and return true.
          available_frames_--;
          return true;
        }
      }
      // Increment our clock hand, going back to the beginning if needed.
      curr_frame_id_ = (curr_frame_id_ + 1) % max_frame_id_;
    }

    // Could not do eviction!
    // Set frame ID pointer to nullptr and return false.
    frame_id = nullptr;

    // TODO: Think about returning a std::optional<frame_id_t> instead of passing in a pointer
    return false;
  }

  // When we get to stuff about sequential scanning and page prefetching, you will
  // see that there are cases where we load data into the buffer pool but we
  // are not reading or writing to it. This method handles that case.
  void allocate(frame_id_t frame_id) {
    // `frame_id` should never exceed `max_frame_id_`
    assert(frame_id <= max_frame_id_);
    // Allocating a frame is, for our purposes, an event that means the
    // frame was "recently used".
    recently_used_[frame_id] = true;
    // Since it was recently used, we also allow the frame to have a second
    // chance during the eviction phase.
    second_chance_[frame_id] = true;
    // We have allocated a new frame, hence we can increment our total frames.
    available_frames_++;
  }

  // Pin the frame, preventing it from being thrown out by `evict`
  void pin(frame_id_t frame_id) {
    // `frame_id` should never exceed `max_frame_id_`
    assert(frame_id <= max_frame_id_);
    // Update our pinning flag
    pinned_[frame_id] = true;
    // NOTE: No need to set the `recently_used_` flag since pinned frames are
    // never considered for eviction anyways.

    // Only decrement if the frame was recently used.
    if (recently_used_[frame_id]) {
      // Decrement total number of frames we have available
      available_frames_--;
    }
  }

  // unpin the frame, allowing it to be thrown out by `evict`
  void unpin(frame_id_t frame_id) {
    // `frame_id` should never exceed `max_frame_id_`
    assert(frame_id <= max_frame_id_);

    // unpinning means setting this flag to false.
    if (!pinned_[frame_id]) {
      return;
    }
    pinned_[frame_id] = false;
    // If a frame is unpinned, then the frame was recently used!
    recently_used_[frame_id] = true;
    // Since it was recently used, we also allow the frame to have a second
    // chance during the eviction phase.
    second_chance_[frame_id] = true;
    // Increment total number of frames in use
    available_frames_++;
  }

  size_t size() {
    return available_frames_;
  }

private:
  // Maximum number of frames the clock replacer can keep track of.
  // This is specified in the constructor.
  size_t max_frame_id_;

  // Total number of frames currently in the clock replacer.
  // This will go up or down, based on how many we've pinned.
  //
  // `available_frames_` should always been smaller than `max_frame_id_`
  size_t available_frames_;

  // The clock replacement algorithm requires keeping track of the current frame ID.
  //
  // `curr_frame_id_` should always been smaller than `max_frame_id_`
  frame_id_t curr_frame_id_;

  // `pinned_` keeps track of which frames are pinned by the DBMS.
  // If a frame has been pinned, it cannot be considered for eviction.
  //
  // This vector should be of size `max_frame_id_`
  MutVec<bool> pinned_;

  // `recently_used_` keeps track of which frames have been recently used. I
  // If a frame has been recently used, then we DO NOT want to evict it in the
  // next call to `evict`.
  //
  // This vector should be of size `max_frame_id_`
  MutVec<bool> recently_used_;

  // `second_chance_` is similar to `recently_used_`, but is used by our clock algo.
  // Any time a frame is allocated, we set both `recently_used_` and `second_chance_`.
  // However, during our eviction phase, we reset `second_chance_` from 1 to 0
  // in the event that we have already gone around the "clock" once before.
  //
  // This vector should be of size `max_frame_id_`
  MutVec<bool> second_chance_;
};
