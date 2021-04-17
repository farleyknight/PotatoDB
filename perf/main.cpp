
#include <random>
#include <benchmark/benchmark.h>
#include <limits>

#include "buffer/buffer.hpp"
#include "buffer/buffer_rw.hpp"
#include "buffer/byte_encoder.hpp"
#include "buffer/cast_encoder.hpp"

#include "buffer_rw_ints_perf.hpp"
#include "buffer_rw_decimals_perf.hpp"
#include "buffer_rw_strings_perf.hpp"

BENCHMARK_MAIN();

