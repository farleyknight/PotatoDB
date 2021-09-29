#include "buffer/buffer.hpp"

void
Buffer::write_buffer(buffer_offset_t offset,
                     const Buffer& buffer)
{
  write_int32(offset, buffer.size());
  auto buffer_offset = offset + sizeof(buffer.size());
  std::memcpy(ptr(buffer_offset),
              buffer.char_ptr(),
              buffer.size());
}

const Buffer
Buffer::read_buffer(buffer_offset_t offset) {
  auto buffer_size = read_int32(offset);
  auto buffer_offset = offset + sizeof(buffer_size);

  auto new_buffer = Buffer(buffer_size);
  std::memcpy(new_buffer.char_ptr(),
              ptr(buffer_offset),
              buffer_size);

  return new_buffer;
}

void
Buffer::write_string(buffer_offset_t offset, const string& value) {
  string_size_t length = value.size();

  auto c_string = reinterpret_cast<const unsigned char*>(value.c_str());

  std::memcpy(ptr(offset),
              &length, sizeof(string_size_t));
  std::memcpy(ptr(offset + sizeof(string_size_t)),
              c_string, length);
}

const string
Buffer::read_string(buffer_offset_t offset) const {
  string_size_t size;
  std::memcpy(&size, const_ptr(offset), sizeof(string_size_t));

  logger->debug("[Buffer] String size: " + std::to_string(size));

  int32_t data_size = data_.size();
  assert(size < data_size);

  string new_string(size, 0);
  assert(offset + sizeof(string_size_t) < data_.size());
  std::memcpy(new_string.data(),
              const_ptr(offset + sizeof(string_size_t)),
              size);

  return new_string;
}
