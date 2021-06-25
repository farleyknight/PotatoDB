# -----------------------------------------------------------------------------
# Server/ThreadPool binary executable
# -----------------------------------------------------------------------------

set(SERVER_BINARY "${CMAKE_BUILD_TYPE}_server")

add_executable(${SERVER_BINARY}
  ${server_sources}
  )

target_link_libraries(${SERVER_BINARY}
  -fsanitize=address # Address Sanitizer
  potatodb-main
  potatodb-parser
  ${CONAN_LIBS})
