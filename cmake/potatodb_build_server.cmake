# -----------------------------------------------------------------------------
# Server/ThreadPool binary executable
# -----------------------------------------------------------------------------

set(SERVER_BINARY "${CMAKE_BUILD_TYPE}_server")

add_executable(${SERVER_BINARY}
  ${server_sources}
  )

target_link_libraries(${SERVER_BINARY}
  PRIVATE potatodb-main
  PRIVATE potatodb-parser
  PRIVATE asio asio::asio
  PRIVATE fmt::fmt
  PRIVATE murmurhash::murmurhash
  PRIVATE -fsanitize=address # Address Sanitizer
  PRIVATE antlr4_static
  )
