
#include "buffer/clock_replacer.hpp"

ClockReplacer::ClockReplacer(size_t max_frames)
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

std::tuple<bool, frame_id_t> ClockReplacer::evict() {
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
        // *frame_id = curr_frame_id_;
        // Once a frame has been evicted, that implies it was not recently used.
        recently_used_[curr_frame_id_] = false;
        // Decrement our frames and return true.
        available_frames_--;

        return std::make_tuple(true, curr_frame_id_);
        //return true;
      }
    }
    // Increment our clock hand, going back to the beginning if needed.
    curr_frame_id_ = (curr_frame_id_ + 1) % max_frame_id_;
  }

  // Could not do eviction!
  // Set frame ID pointer to nullptr and return false.
  // frame_id = nullptr;

  // TODO: Think about returning a std::optional<frame_id_t> instead of passing in a pointer
  return std::make_tuple(false, -1);
  // return false;
}


// When we get to stuff about sequential scanning and page prefetching, you will
// see that there are cases where we load data into the buffer pool but we
// are not reading or writing to it. This method handles that case.
void ClockReplacer::allocate(frame_id_t frame_id) {
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
void ClockReplacer::pin(frame_id_t frame_id) {
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

void ClockReplacer::unpin(frame_id_t frame_id) {
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


