# -----------------------------------------------------------------------------
# Performance executable
# -----------------------------------------------------------------------------

set(PERF_BINARY perf)

add_executable(${PERF_BINARY}
  ${perf_sources}
  )

set_target_properties(${PERF_BINARY}
  PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS ON)

target_link_libraries(${PERF_BINARY}
  PRIVATE potatodb-main
  PRIVATE potatodb-parser
  PRIVATE benchmark::benchmark
  PRIVATE murmurhash::murmurhash
  PRIVATE fmt::fmt
  PRIVATE ${ANTLR4_LIB})
