# -----------------------------------------------------------------------------
# Test Suite binary executable
# -----------------------------------------------------------------------------

set(TEST_BINARY "${CMAKE_PROJECT_NAME}_tests")

add_executable(${TEST_BINARY}
  ${MAIN_SOURCES}
  ${TEST_SOURCES}
  ${PARSER_SOURCES}
  )

target_link_libraries(${TEST_BINARY}
  PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main
  PRIVATE murmurhash::murmurhash
  PRIVATE antlr4_static
  PRIVATE -fsanitize=address # Address Sanitizer
  )
