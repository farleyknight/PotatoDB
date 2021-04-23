# -----------------------------------------------------------------------------
# Performance executable
# -----------------------------------------------------------------------------

set(PERF_BINARY "${CMAKE_PROJECT_NAME}_perf")

add_executable(${PERF_BINARY}
  ${MAIN_SOURCES}
  ${PERF_SOURCES})

target_link_libraries(${PERF_BINARY}
  PRIVATE benchmark::benchmark
  PRIVATE murmurhash::murmurhash)
