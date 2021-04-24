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
set(ANTLR4_WITH_STATIC_CRT ON)

# set(ANTLR4_WITH_STATIC_CRT OFF)

# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
# set(ANTLR_EXECUTABLE /home/user/antlr-4.9.2-complete.jar)

# This JAR was installed with homebrew
# For now we'll hard-code it, until we can find a better way for
# `brew` and `CMake` to get along.
set(ANTLR_EXECUTABLE "/usr/local/Cellar/antlr/4.9.2/antlr-4.9.2-complete.jar")

# add macros to generate ANTLR C++ code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.

# -----------------------------------------------------------------------------
# PotatoSQLLexer
# -----------------------------------------------------------------------------

antlr_target(PotatoSQLLexer "parser/PotatoSQLLexer.g4" LEXER
  PACKAGE potatosql
  OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

if(DEFINED ANTLR_PotatoSQLLexer_OUTPUT_DIR)
  message(STATUS "The ANTLR Lexer will go to the following OUTPUT DIR: ${ANTLR_PotatoSQLLexer_OUTPUT_DIR}")
else()
  message(FATAL_ERROR "No OUTPUT DIR for ANTLR PotatoSQLLexer!")
endif()

if(DEFINED ANTLR_PotatoSQLLexer_CXX_OUTPUTS)
  message(STATUS "The ANTLR Lexer has the following CXX OUTPUTS: ${ANTLR_PotatoSQLLexer_CXX_OUTPUTS}")
else()
  message(FATAL_ERROR "No CXX OUTPUTS for ANTLR PotatoSQLLexer!")
endif()

# include generated files in project environment
include_directories(${ANTLR_PotatoSQLLexer_OUTPUT_DIR})
include_directories(${ANTLR_PotatoSQLLexer_OUTPUT_DIR}/parser)
# -----------------------------------------------------------------------------
# PotatoSQLParser
# -----------------------------------------------------------------------------

antlr_target(PotatoSQLParser "parser/PotatoSQLParser.g4" PARSER
  DEPENDS_ANTLR PotatoSQLLexer
  PACKAGE potatosql
  OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMPILE_FLAGS "-lib;${ANTLR_PotatoSQLLexer_OUTPUT_DIR}/parser")

if(DEFINED ANTLR_PotatoSQLParser_OUTPUT_DIR)
  message(STATUS "The ANTLR Parser will go to the following OUTPUT DIR: ${ANTLR_PotatoSQLParser_OUTPUT_DIR}")
else()
  message(FATAL_ERROR "No OUTPUT DIR for ANTLR PotatoSQLParser!")
endif()

if(DEFINED ANTLR_PotatoSQLParser_CXX_OUTPUTS)
  message(STATUS "The ANTLR Parser has the following CXX OUTPUTS: ${ANTLR_PotatoSQLParser_CXX_OUTPUTS}")
else()
  message(FATAL_ERROR "No CXX OUTPUTS for ANTLR PotatoSQLParser!")
endif()

# include generated files in project environment
include_directories(${ANTLR_PotatoSQLParser_OUTPUT_DIR})

# -----------------------------------------------------------------------------
# SQL Parser target binary
# -----------------------------------------------------------------------------

set(PARSER_BINARY "${CMAKE_PROJECT_NAME}_parser")

message(STATUS "Parser binary target is ${PARSER_BINARY}")

# add generated grammar to demo binary target
add_executable(${PARSER_BINARY} "parser/main.cpp"
  ${ANTLR_PotatoSQLLexer_CXX_OUTPUTS}
  ${ANTLR_PotatoSQLParser_CXX_OUTPUTS}
  "parser/PotatoSQLLexer.cpp"
  "parser/PotatoSQLParser.cpp"
  )

target_link_libraries(${PARSER_BINARY} antlr4_static)
