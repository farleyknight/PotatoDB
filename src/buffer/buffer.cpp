
#include "buffer/buffer.hpp"
#include "tuple/tuple.hpp"

void Buffer::write_tuple(buffer_offset_t offset, const Tuple& tuple) {
  copy_n_bytes(0, offset, tuple.buffer(), tuple.buffer().size());
}

