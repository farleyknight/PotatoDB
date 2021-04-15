
#include <random>
#include <benchmark/benchmark.h>

#include "buffer/buffer.hpp"
#include "buffer/buffer_rw.hpp"

template<BufferEnc enc>
static void BM_BufferRW(benchmark::State& state) {
  std::random_device rd;
  std::mt19937 gen(rd());
  const int32_t max_range = 1000;
  std::uniform_real_distribution<int32_t> dis(1, max_range);

  Buffer buff(4);
  auto n = dis(gen);
  int32_t val;

  while (state.KeepRunning()) {
    BufferRW::write_int32<enc>(buff, n);
    benchmark::DoNotOptimize(val = BufferRW::read_int32<enc>(buff));
    assert(n == val);
  }

  std::ostream cnull(0);
  cnull << val;
}

BENCHMARK_TEMPLATE(BM_BufferRW, BufferEnc::BYTE);
BENCHMARK_TEMPLATE(BM_BufferRW, BufferEnc::CAST);

BENCHMARK_MAIN();
