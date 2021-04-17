#pragma once

#include "common/types.hpp"
// #include "buffer/buffer_rw.hpp"

class CastEncoder {
public:
  friend class BufferRW<CastEncoder>;

private:
  CastEncoder() = default;

  template<typename IntT>
  void write_int(MutRef<Buffer> buff, IntT n) const {
    *reinterpret_cast<IntT*>(buff.data()) = n;
  }

  template<typename IntT>
  IntT read_int(Ref<Buffer> buff) const {
    return *reinterpret_cast<const IntT*>(buff.data());
  }

  void write_float(MutRef<Buffer> buff, float f) const {
    *reinterpret_cast<float*>(buff.data()) = f;
  }

  float read_float(Ref<Buffer> buff) const {
    return *reinterpret_cast<const float*>(buff.data());
  }

  void write_double(MutRef<Buffer> buff, double d) const {
    *reinterpret_cast<double*>(buff.data()) = d;
  }

  double read_double(Ref<Buffer> buff) const {
    return *reinterpret_cast<const double*>(buff.data());
  }

  using string_size_t = Buffer::string_size_t;

  void write_string(MutRef<Buffer> buff, String s) const {
    string_size_t size = s.size();

    auto c_string = reinterpret_cast<const unsigned char*>(s.c_str());

    std::memcpy(buff.data(), &size, sizeof(string_size_t));
    std::memcpy(buff.data() + sizeof(string_size_t),
                c_string, size);
  }

  MutString read_string(Ref<Buffer> buff) const {
    string_size_t size = buff.data_[0];
    MutString new_string(size, 0);

    std::memcpy(new_string.data(),
                buff.data() + sizeof(string_size_t),
                size);

    return new_string;
  }
};
