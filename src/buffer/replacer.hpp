#pragma once

#include <tuple>

class Replacer {
public:
  /**********************************************
   * Constructor & destructor
   **********************************************/

  Replacer() = default;
  virtual ~Replacer() = default;

  /**********************************************
   * Instance methods
   **********************************************/

  virtual std::tuple<bool, frame_id_t> evict() = 0;
  virtual void pin(frame_id_t frame_id) = 0;
  virtual void unpin(frame_id_t frame_id) = 0;
  virtual size_t size() = 0;
  virtual void reset() = 0;
};
