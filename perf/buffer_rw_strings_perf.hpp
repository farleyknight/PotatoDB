
std::string random_string(size_t length) {
  auto random_char = []() -> char {
    const char charset[] =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";
    const size_t max_index = (sizeof(charset) - 1);
    return charset[ rand() % max_index ];
  };

  std::string new_string(length, 0);
  std::generate_n(new_string.begin(), length, random_char);
  return new_string;
}

template<typename EncT>
void BM_BufferRWString(benchmark::State& state) {
  std::random_device rd;
  std::mt19937 gen(rd());
  // NOTE: Generate at most 100 character length string.
  int8_t max_range = 100;
  std::uniform_real_distribution<int8_t> dis(1, max_range);
  auto n = dis(gen);

  Buffer buff(sizeof(n) + sizeof(Buffer::string_size_t));
  BufferRW<EncT> buff_rw;
  std::string new_string = random_string(n);
  std::string val;

  while (state.KeepRunning()) {
    buff_rw.write_string(buff, new_string);
    benchmark::DoNotOptimize(val = buff_rw.read_string(buff));
    assert(new_string == val);
  }

  std::ostream cnull(0);
  cnull << val;
}

BENCHMARK_TEMPLATE(BM_BufferRWString, ByteEncoder);
BENCHMARK_TEMPLATE(BM_BufferRWString, CastEncoder);

