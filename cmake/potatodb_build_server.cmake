# -----------------------------------------------------------------------------
# Server/ThreadPool binary executable
# -----------------------------------------------------------------------------

set(SERVER_BINARY "${CMAKE_PROJECT_NAME}_${CMAKE_BUILD_TYPE}_server")

add_executable(${SERVER_BINARY}
  ${MAIN_SOURCES}
  ${SERVER_SOURCES}
  ${PARSER_SOURCES}
  )

target_link_libraries(${SERVER_BINARY}
  PRIVATE asio asio::asio
  PRIVATE fmt::fmt
  PRIVATE murmurhash::murmurhash
  PRIVATE -fsanitize=address # Address Sanitizer
  PRIVATE antlr4_static
  )
