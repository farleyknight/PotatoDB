// Taken from:
// https://github.com/NAThompson/using_googlebenchmark

#include <cmath>
#include <ostream>
#include <random>
#include <benchmark/benchmark.h>

template<typename Real>
static void BM_PowTemplate(benchmark::State& state) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<Real> dis(1, 10);
  auto s = dis(gen);
  auto t = dis(gen);
  Real y;
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(y = std::pow(s, t));
  }
  std::ostream cnull(nullptr);
  cnull << y;
}
BENCHMARK_TEMPLATE(BM_PowTemplate, float);
BENCHMARK_TEMPLATE(BM_PowTemplate, double);
BENCHMARK_TEMPLATE(BM_PowTemplate, long double);

BENCHMARK_MAIN();
