# -----------------------------------------------------------------------------
# Compiler settings
# -----------------------------------------------------------------------------

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# NOTE: Turning this off to make builds faster
# set(CMAKE_CXX_CPPCHECK "cppcheck")

# NOTE: Turning this off to make builds faster
set(BUILD_SHARED_LIBS OFF)
# set(BUILD_SHARED_LIBS ON)

# NOTE: Turning this off to make builds faster
# set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*)

# All target binaries are placed under the directory `builds/`
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/builds)

# -----------------------------------------------------------------------------
# Compiler Error Limit (+ more settings)
# -----------------------------------------------------------------------------

add_definitions(
  #######################################################
  # NOTE: If you want to see the entire list of errors,
  # change the next line from =N to =0
  #######################################################
  "-ferror-limit=50"
  "-Wall"
  "-Wextra"
  "-pedantic"
  "-g"
  "-fexceptions"
  )

# -----------------------------------------------------------------------------
# Source files added to the include path
# -----------------------------------------------------------------------------

include_directories(src)
include_directories(tests)
include_directories(perf)
include_directories(parser)

# NOTE: Using GLOB_RECURSE means we have to recompile everything!
# Need to switch to listing these files by hand..
file(GLOB_RECURSE main_sources   CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE test_sources   CONFIGURE_DEPENDS "tests/*.cpp")
file(GLOB_RECURSE perf_sources   CONFIGURE_DEPENDS "perf/*cpp")
file(GLOB_RECURSE server_sources CONFIGURE_DEPENDS "server/*.cpp")
#file(GLOB_RECURSE PARSER_SOURCES "parser/PotatoSQL*.cpp")

set(parser_sources "parser/PotatoSQLLexer.cpp;parser/PotatoSQLParser.cpp")
