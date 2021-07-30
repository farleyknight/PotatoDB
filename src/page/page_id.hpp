#pragma once

class PageId {
public:
  static const file_id_t  INVALID_FILE_ID = 65535;
  static const block_id_t BLOCK_SENTINEL  = 65535;

  PageId(file_id_t file_id, block_id_t block_id)
    : file_id_  (file_id),
      block_id_ (block_id)
  {}

  static PageId INVALID() {
    return PageId(INVALID_FILE_ID, BLOCK_SENTINEL);
  }

  static PageId STOP_ITERATING(file_id_t file_id) {
    return PageId(file_id, BLOCK_SENTINEL);
  }

  bool stop_iterating() const {
    return block_id_ == BLOCK_SENTINEL;
  }

  static PageId from(uint32_t page_id) {
    auto file_id  = static_cast<file_id_t>(page_id >> 16);
    auto block_id = static_cast<slot_id_t>(page_id);

    return PageId(file_id, block_id);
  }

  int32_t as_int32() const {
    return (static_cast<int16_t>(file_id()) << 16) | block_id();
  }

  bool is_valid() const {
    return (file_id_ != INVALID_FILE_ID && block_id_ != BLOCK_SENTINEL);
  }

  file_id_t file_id() const {
    return file_id_;
  }

  block_id_t block_id() const {
    return block_id_;
  }

  bool operator==(const PageId& other) const {
    return file_id_ == other.file_id_ && block_id_ == other.block_id_;
  }

  bool operator!=(const PageId& other) const {
    return file_id_ != other.file_id_ || block_id_ != other.block_id_;
  }

  friend std::ostream &operator<<(std::ostream &os, const PageId& page_id) {
    os << page_id.to_string();
    return os;
  }

  const string to_string() const {
    return "file_id: " + std::to_string(file_id_) + " block_id: " + std::to_string(block_id_);
  }

private:
  file_id_t file_id_;
  block_id_t block_id_;
};


namespace std {
  template <>
  struct hash<PageId> {
    size_t operator()(const PageId& page_id) const {
      return hash<int64_t>()(page_id.as_int32());
    }
  };
}
