# -----------------------------------------------------------------------------
# Test Suite binary executable
# -----------------------------------------------------------------------------

set(TEST_BINARY tests)

add_executable(${TEST_BINARY}
  ${test_sources})

target_link_libraries(${TEST_BINARY}
  -fsanitize=address # Address Sanitizer
  potatodb-main
  potatodb-parser
  ${CONAN_LIBS})
