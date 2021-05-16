#pragma once

#include "common/types.hpp"
// #include "buffer/buffer_rw.hpp"

// TODO: This whole class is deprecated
// Delete ASAP

class CastEncoder {
public:
  friend class BufferRW<CastEncoder>;

private:
  using string_size_t = Buffer::string_size_t;

  CastEncoder() = default;

  template<typename IntT>
  void write_int(Buffer& buff, IntT n) const {
    *reinterpret_cast<IntT*>(buff.ptr()) = n;
  }

  template<typename IntT>
  IntT read_int(const Buffer& buff) const {
    return *reinterpret_cast<const IntT*>(buff.cptr());
  }

  void write_float(Buffer& buff, float f) const {
    *reinterpret_cast<float*>(buff.ptr()) = f;
  }

  float read_float(const Buffer& buff) const {
    return *reinterpret_cast<const float*>(buff.cptr());
  }

  void write_double(Buffer& buff, double d) const {
    *reinterpret_cast<double*>(buff.ptr()) = d;
  }

  double read_double(const Buffer& buff) const {
    return *reinterpret_cast<const double*>(buff.cptr());
  }

  void write_string(Buffer& buff, const string s) const {
    string_size_t size = s.size();

    auto c_string = reinterpret_cast<const unsigned char*>(s.c_str());

    // std::cout << "Got c_string " << c_string << std::endl;

    std::memcpy(buff.ptr(), &size, sizeof(string_size_t));
    std::memcpy(buff.ptr(sizeof(string_size_t)),
                c_string, size);
  }

  const string read_string(const Buffer& buff) const {
    string_size_t size = buff.as_bytes()[0];
    string new_string(size, 0);

    std::memcpy(new_string.data(),
                buff.cptr() + sizeof(string_size_t),
                size);

    return new_string;
  }
};
