#pragma once

#include <sstream>
#include <string>
#include <unordered_set>
#include <optional>

#include "common/config.hpp"

class RID {
public:
  /**********************************************
  * Constructors & destructor
  **********************************************/

  RID() = default;

  explicit RID(page_id_t page_id, uint32_t slot_num) {
    // TODO: Make slot number it's own type: slot_id_t
    page_id_ = page_id;
    slot_num_ = slot_num;
  }

  explicit RID(int64_t rid)  {
    page_id_ = static_cast<page_id_t>(rid >> 32);
    slot_num_ = static_cast<uint32_t>(rid);
  }

  RID(Ref<RID>) = default; // Default copy
  MutRef<RID> operator=(Ref<RID>) = default; // Default copy assign
  ~RID() = default; // Default delete

  static Option<RID> make_opt(page_id_t page_id, uint32_t slot_num) {
    return make_optional<RID>(page_id, slot_num);
  }

  /**********************************************
   * Instance methods
   **********************************************/

  int64_t get() const {
    return (static_cast<int64_t>(page_id_)) << 32 | slot_num_;
  }

  page_id_t page_id() const {
    return page_id_;
  }

  uint32_t slot_num() const {
    return slot_num_;
  }

  void set(page_id_t page_id, uint32_t slot_num) {
    page_id_ = page_id;
    slot_num_ = slot_num;
  }

  bool operator==(const RID &other) const {
    return page_id_ == other.page_id_ && slot_num_ == other.slot_num_;
  }

  /**********************************************
  * Debug methods
  **********************************************/

  // TODO: No move b/c RVO?
  String to_string() const {
    std::stringstream os;
    os << "page_id: " << page_id_;
    os << " slot_num: " << slot_num_ << "\n";

    return os.str();
  }

  friend std::ostream &operator<<(std::ostream &os, const RID &rid) {
    os << rid.to_string();
    return os;
  }

private:
  page_id_t page_id_    = INVALID_PAGE_ID;
  uint32_t slot_num_ = 0;  // logical offset from 0, 1...
};

namespace std {
  template <>
  struct hash<RID> {
    size_t operator()(const RID &obj) const {
      return hash<int64_t>()(obj.get());
    }
  };
}
