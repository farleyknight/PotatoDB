#pragma once

class PageId {
public:
  PageId() = default;
  PageId(file_id_t file_id, block_id_t block_id)
    : file_id_  (file_id),
      block_id_ (block_id)
  {}

  static PageId INVALID() {
    return PageId();
  }

  static PageId from(uint32_t page_id) {
    auto file_id  = static_cast<file_id_t>(page_id >> 16);
    auto block_id = static_cast<slot_id_t>(page_id);

    return PageId(file_id, block_id);
  }

  uint32_t as_uint32() const {
    return (static_cast<uint16_t>(file_id_) << 16) | block_id_;
  }

  file_id_t file_id() const {
    return file_id_;
  }

  block_id_t block_id() const {
    return block_id_;
  }

  bool operator==(CRef<PageId> other) const {
    return file_id_ == other.file_id_ && block_id_ == other.block_id_;
  }

private:
  file_id_t file_id_   = -1;
  block_id_t block_id_ = -1;
};
