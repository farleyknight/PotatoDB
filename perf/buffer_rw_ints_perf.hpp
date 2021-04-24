#include <string>
#include <fstream>

template<typename IntT>
void BM_DirectCastEncoding(benchmark::State& state) {
  std::random_device rd;
  std::mt19937 gen(rd());
  const IntT max_range = std::numeric_limits<IntT>::max();
  std::uniform_real_distribution<IntT> dis(1, max_range);

  Buffer buff(sizeof(IntT));
  auto n = dis(gen);
  IntT val;

  while (state.KeepRunning()) {
    *reinterpret_cast<IntT*>(buff.data()) = n;
    benchmark::DoNotOptimize(val = *reinterpret_cast<IntT*>(buff.data()));
    assert(n == val);
  }

  std::ostream cnull(0);
  cnull << val;
}

template<typename EncT, typename IntT>
void BM_BufferRWInt(benchmark::State& state) {
  std::random_device rd;
  std::mt19937 gen(rd());
  const IntT max_range = std::numeric_limits<IntT>::max();
  std::uniform_real_distribution<IntT> dis(1, max_range);

  Buffer buff(sizeof(IntT));
  BufferRW<EncT> buff_rw;
  auto n = dis(gen);
  IntT val;

  while (state.KeepRunning()) {
    buff_rw.template write_int<IntT>(buff, n);
    benchmark::DoNotOptimize(val = buff_rw.template read_int<IntT>(buff));
    assert(n == val);
  }

  std::ostream cnull(0);
  cnull << val;
}

template<typename EncT>
static void BM_BufferRW8(benchmark::State& state) {
  BM_BufferRWInt<EncT, int8_t>(state);
}

BENCHMARK_TEMPLATE(BM_BufferRW8, ByteEncoder);
BENCHMARK_TEMPLATE(BM_BufferRW8, CastEncoder);
BENCHMARK_TEMPLATE(BM_DirectCastEncoding, int8_t);

template<typename EncT>
static void BM_BufferRW16(benchmark::State& state) {
  BM_BufferRWInt<EncT, int16_t>(state);
}

BENCHMARK_TEMPLATE(BM_BufferRW16, ByteEncoder);
BENCHMARK_TEMPLATE(BM_BufferRW16, CastEncoder);
BENCHMARK_TEMPLATE(BM_DirectCastEncoding, int16_t);

template<typename EncT>
static void BM_BufferRW32(benchmark::State& state) {
  BM_BufferRWInt<EncT, int32_t>(state);
}

BENCHMARK_TEMPLATE(BM_BufferRW32, ByteEncoder);
BENCHMARK_TEMPLATE(BM_BufferRW32, CastEncoder);
BENCHMARK_TEMPLATE(BM_DirectCastEncoding, int32_t);

template<typename EncT>
static void BM_BufferRW64(benchmark::State& state) {
  BM_BufferRWInt<EncT, int64_t>(state);
}

BENCHMARK_TEMPLATE(BM_BufferRW64, ByteEncoder);
BENCHMARK_TEMPLATE(BM_BufferRW64, CastEncoder);
BENCHMARK_TEMPLATE(BM_DirectCastEncoding, int64_t);
