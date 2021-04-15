#pragma once

#include "common/types.hpp"
#include "buffer/buffer_rw.hpp"

class CastEncoder {
public:
  friend class BufferRW<CastEncoder>;

private:
  CastEncoder() = default;

  template<typename IntT>
  void write_int(MutRef<Buffer> buff, IntT n) {
    *reinterpret_cast<IntT*>(buff.data()) = n;
  }

  template<typename IntT>
  IntT read_int(Ref<Buffer> buff) {
    return *reinterpret_cast<const IntT*>(buff.data());
  }
};
