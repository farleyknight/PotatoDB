# -----------------------------------------------------------------------------
# Test Suite binary executable
# -----------------------------------------------------------------------------

set(TEST_BINARY tests)

add_executable(${TEST_BINARY}
  ${test_sources})

set_target_properties(${TEST_BINARY}
  PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS ON)

target_link_libraries(${TEST_BINARY}
  -fsanitize=address # Address Sanitizer
  potatodb-main
  potatodb-parser
  ${CONAN_LIBS})
