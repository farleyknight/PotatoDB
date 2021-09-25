#include "tuple/tuple_layout.hpp"

tuple_length_t
TupleLayout::tuple_length(const vector<Value>& values) const
{
  // Calculate the size of the tuple.
  auto length = inlined_tuple_length_;
  // std::cout << "Tuple Length starts at " << length << std::endl;
  for (auto i : unlined_columns_) {
    auto var_length = values[i].length() + sizeof(string_size_t);
    length += var_length;
    /*
      std::cout << "First unlined " << i
      << " w/ length " << var_length
      << " giving current length as " << length
      << std::endl;
     */
  }
  return length;
}
