# -----------------------------------------------------------------------------
# ANTLR4 based SQL Parser configurations
# -----------------------------------------------------------------------------

#antlr_target(PotatoSQL "parser/PotatoSQL.g4" LEXER PARSER LISTENER VISITOR
#  PACKAGE potatosql
#  OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

#message(STATUS "Current binary directory is ${CMAKE_CURRENT_BINARY_DIR}")
#message(STATUS "The output files for PotatoSQL are ${ANTLR_PotatoSQL_CXX_OUTPUTS}")

# -----------------------------------------------------------------------------
# SQL Parser target binary
# -----------------------------------------------------------------------------

set(PARSER_BINARY parser)

message(STATUS "Parser binary target is ${PARSER_BINARY}")
message(STATUS "Parser sources are ${parser_sources}")

# add generated grammar to demo binary target
add_executable(${PARSER_BINARY}
  "parser/main.cpp"
  ${parser_sources})

target_link_libraries(${PARSER_BINARY}
  -fstandalone-debug # So we can see full parse results in lldb
  ${CONAN_LIBS})
