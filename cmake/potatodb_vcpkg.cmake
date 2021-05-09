# -----------------------------------------------------------------------------
# Bootstrap - Handle environment variables, print them for debugging
# -----------------------------------------------------------------------------

if(EXISTS "$ENV{HOME}/.vcpkg/vcpkg.path.txt")
  message(STATUS "Found vcpkg root path via local .vcpkg/")
  file(READ "$ENV{HOME}/.vcpkg/vcpkg.path.txt" VCPKG_ROOT)
elseif(EXISTS ENV{VCPKG_ROOT})
  message(STATUS "Found vcpkg root path via ENV variable.")
  set(VCPKG_ROOT ENV{VCPKG_ROOT})
endif()

# TODO: Should not have to set this here!
set(VCPKG_ROOT "/Users/fknight/code/vcpkg")

if(DEFINED VCPKG_ROOT)
  message(STATUS "VCPKG_ROOT is set to ${VCPKG_ROOT}")
else()
  message(FATAL_ERROR "VCPKG_ROOT is not set! Please set it before continuing.")
endif()

if(NOT DEFINED ENV{VCPKG_FEATURE_FLAGS})
  # NOTE: Turned off for now..
  # TODO: Turn this back on in a few.
  # message(FATAL_ERROR "VCPKG_FEATURE_FLAGS is not set! Please add `manifests` support!")
endif()

# TODO: Make sure that VCPKG_ROOT is always available as an ENV variable.
if(DEFINED VCPKG_ROOT)
  set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
  message(STATUS "Using toolchain file ${CMAKE_TOOLCHAIN_FILE}")
  include(${CMAKE_TOOLCHAIN_FILE})
else()
  message(FATAL_ERROR "Could not find vcpkg install! You may have to define VCPKG_ROOT.")
endif()

# NOTE: Previous build was not picking up "MurmurHash3.h"
include_directories(${CMAKE_BINARY_DIR}/vcpkg_installed/x64-osx/include)

# -----------------------------------------------------------------------------
# Packages - Manually maintained duplicate list of packages from `vcpkg.json`
# -----------------------------------------------------------------------------

# fmt
find_package(fmt CONFIG REQUIRED)
# MurmurHash
find_package(murmurhash CONFIG REQUIRED)
# GTest
find_package(GTest CONFIG REQUIRED)
# ASIO
find_package(asio CONFIG REQUIRED)
# Google benchmark
find_package(benchmark CONFIG REQUIRED)
# ANTLR4
# TODO: Use this to figure out setting up ANTLR4 w/ CMake
# https://github.com/antlr/antlr4/tree/master/runtime/Cpp/cmake
#find_package(antlr4-generator CONFIG REQUIRED)
#find_package(antlr4-runtime CONFIG REQUIRED)

# NOTE: Not sure if I need this?
# find_package(Threads CONFIG REQUIRED)
