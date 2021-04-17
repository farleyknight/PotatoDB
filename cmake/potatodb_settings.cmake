# -----------------------------------------------------------------------------
# Compiler settings
# -----------------------------------------------------------------------------

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_CPPCHECK "cppcheck")

set(BUILD_SHARED_LIBS ON)

set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*)

# All target binaries are placed under the directory `builds/`
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/builds)

# -----------------------------------------------------------------------------
# Compiler Error Limit (+ more settings)
# -----------------------------------------------------------------------------

add_definitions(
  #######################################################
  # NOTE: If you want to see the entire list of errors,
  # change the next line from =1 to =0
  #######################################################
  "-ferror-limit=50"
  "-Wall"
  "-g"
  "-fexceptions"
  )

# -----------------------------------------------------------------------------
# Source files added to the include path
# -----------------------------------------------------------------------------

include_directories(src)
include_directories(tests)
include_directories(perf)

file(GLOB_RECURSE MAIN_SOURCES   "src/*.cpp")
file(GLOB_RECURSE TEST_SOURCES   "tests/*.cpp")
file(GLOB_RECURSE PERF_SOURCES   "perf/*cpp")
file(GLOB_RECURSE SERVER_SOURCES "server/*.cpp")
