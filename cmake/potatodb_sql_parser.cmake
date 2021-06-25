# -----------------------------------------------------------------------------
# ANTLR4 based SQL Parser configurations
# -----------------------------------------------------------------------------

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# NOTE: Setting the zip repository is preferred since the git repository doesn't work
# Every time I used the git respository, it tired to reclone/reset the source
# each time. This should only need to happen once.
set(ANTLR4_ZIP_REPOSITORY "https://github.com/antlr/antlr4/archive/refs/tags/4.9.2.zip")

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
# set(ANTLR4_WITH_STATIC_CRT ON)

set(ANTLR4_WITH_STATIC_CRT OFF)

# -----------------------------------------------------------------------------
# ANTLR target directive
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
