
#include "buffer/buffer.hpp"
#include "tuple/tuple.hpp"

void Buffer::write_tuple(buffer_offset_t offset, const Tuple& tuple) {
  write_uint32(offset, tuple.size());
  auto tuple_offset = offset + sizeof(uint32_t);

  std::memcpy(ptr(tuple_offset),
              tuple.buffer().cptr(0),
              tuple.buffer().size());
}

const Tuple Buffer::read_tuple(buffer_offset_t offset) {
  auto tuple_size = read_uint32(offset);
  auto tuple_offset = offset + sizeof(uint32_t);

  Tuple new_tuple(tuple_size);
  std::memcpy(new_tuple.buffer().ptr(), ptr(tuple_offset), tuple_size);

  return new_tuple;
}

void Buffer::write_string(buffer_offset_t offset, const string& value) {
  string_size_t length = value.size();

  auto c_string = reinterpret_cast<const unsigned char*>(value.c_str());

  std::memcpy(ptr(offset),
              &length, sizeof(string_size_t));
  std::memcpy(ptr(offset + sizeof(string_size_t)),
              c_string, length);
}

const string Buffer::read_string(buffer_offset_t offset) const {
  logger->debug("Buffer offset: " + std::to_string(offset));

  string_size_t size;
  std::memcpy(&size, cptr(offset), sizeof(string_size_t));

  logger->debug("String size: " + std::to_string(size));

  assert(size < data_.size());

  string new_string(size, 0);
  assert(offset + sizeof(string_size_t) < data_.size());
  std::memcpy(new_string.data(),
              cptr(offset + sizeof(string_size_t)),
              size);

  return new_string;
}
