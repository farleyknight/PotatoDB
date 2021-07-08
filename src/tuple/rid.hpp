#pragma once

#include <sstream>
#include <string>
#include <unordered_set>
#include <optional>

#include "common/config.hpp"

#include "page/page_id.hpp"

class RID {
public:
  RID() = default;

  explicit RID(PageId page_id, slot_id_t slot_id) {
    // TODO: Make slot number it's own type: slot_id_t
    page_id_ = page_id;
    slot_id_ = slot_id;
  }

  explicit RID(uint64_t rid)  {
    // TODO: Maybe find a way to get a PageId (now two numbers)
    // From a 64 bit number?
    page_id_ = PageId::from(static_cast<page_id_t>(rid >> 32));

    // NOTE: Each page has around 4KB, right?
    // The maximum for a 16 bit number is 65536
    // or about 65K, so we don't have to worry about
    // slot_id being enough.
    slot_id_ = static_cast<slot_id_t>(rid);
  }

  // Default copy
  RID(const RID&) = default;
  // Default copy assign
  RID& operator=(const RID&) = default;
  // Default delete
  ~RID() = default;

  // TODO: Delete this
  static optional<RID> make_opt(PageId page_id, slot_id_t slot_id) {
    return make_optional<RID>(page_id, slot_id);
  }

  bool operator==(const RID& other) {
    return as_uint64() == other.as_uint64();
  }

  uint64_t as_uint64() const {
    uint64_t result = static_cast<uint64_t>(page_id_.as_uint32());
    result = result << 32;
    result = result | slot_id_;
    return result;
  }

  PageId page_id() const {
    return page_id_;
  }

  slot_id_t slot_id() const {
    return slot_id_;
  }

  void set(PageId page_id, slot_id_t slot_id) {
    page_id_ = page_id;
    slot_id_ = slot_id;
  }

  bool operator==(const RID& other) const {
    return page_id_ == other.page_id_ && slot_id_ == other.slot_id_;
  }

  const string to_string() const {
    std::stringstream os;
    os << "file_id: " << page_id_.file_id();
    os << "block_id: " << page_id_.block_id();
    os << " slot_num: " << slot_id_ << "\n";

    return os.str();
  }

  friend std::ostream &operator<<(std::ostream &os, const RID& rid) {
    os << rid.to_string();
    return os;
  }

  bool is_valid() const {
    return page_id_.is_valid();
  }

  bool stop_iterating() const {
    return page_id_.stop_iterating();
  }

private:
  PageId page_id_    = PageId::INVALID();
  slot_id_t slot_id_ = 0;
};

namespace std {
  template <>
  struct hash<RID> {
    size_t operator()(const RID& obj) const {
      return hash<int64_t>()(obj.as_uint64());
    }
  };
}
