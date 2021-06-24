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
  PRIVATE murmurhash::murmurhash
  PRIVATE antlr4-runtime
  PRIVATE fmt::fmt
  PRIVATE -fsanitize=address # Address Sanitizer
  )
