#include "tuple/tuple.hpp"
#include "catalog/table_schema.hpp"
#include "txns/txn.hpp"

void
Tuple::resize_buffer(tuple_length_t tuple_length)
{
  logger->debug("[Tuple] Resizing tuple " + std::to_string(tuple_length));
  // Then resize the underlying buffer.
  buffer_.resize(tuple_length);
  assert(buffer_.size() == tuple_length);
}
