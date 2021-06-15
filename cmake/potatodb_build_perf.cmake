# -----------------------------------------------------------------------------
# Performance executable
# -----------------------------------------------------------------------------

set(PERF_BINARY perf)

add_executable(${PERF_BINARY}
  ${perf_sources}
  )

target_link_libraries(${PERF_BINARY}
  PRIVATE potatodb-main
  PRIVATE potatodb-parser
  PRIVATE benchmark::benchmark
  PRIVATE murmurhash::murmurhash
  PRIVATE antlr4_static
  PRIVATE fmt::fmt
  )
