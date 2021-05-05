# -----------------------------------------------------------------------------
# Test Suite binary executable
# -----------------------------------------------------------------------------

set(TEST_BINARY tests)

add_executable(${TEST_BINARY}
  ${test_sources}
  )

target_link_libraries(${TEST_BINARY}
  PRIVATE potatodb-main
  PRIVATE potatodb-parser
  PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main
  PRIVATE murmurhash::murmurhash
  PRIVATE antlr4_static
  PRIVATE -fsanitize=address # Address Sanitizer
  )
