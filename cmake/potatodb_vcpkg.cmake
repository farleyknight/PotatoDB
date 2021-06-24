# -----------------------------------------------------------------------------
# Bootstrap - Load the toolchain file
# -----------------------------------------------------------------------------

set(CMAKE_TOOLCHAIN_FILE "${PROJECT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
message(STATUS "Using toolchain file ${CMAKE_TOOLCHAIN_FILE}")
include(${CMAKE_TOOLCHAIN_FILE})

# NOTE: Previous build was not picking up "MurmurHash3.h"
include_directories(${CMAKE_BINARY_DIR}/vcpkg_installed/x64-osx/include)
# NOTE: GitHub Action build not picking up "antlr4-common.h"
include_directories(${CMAKE_BINARY_DIR}/vcpkg_installed/x64-osx/include/antlr4-runtime)
