# -----------------------------------------------------------------------------
# Using CMake's module system to write readable CMake code
# -----------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.19)
project(potatodb VERSION 0.1.0)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Project level settings
include(potatodb_settings)

# C++ packages via vcpkg
include(potatodb_vcpkg)

include(potatodb_build_libraries)

# TODO: Set up SQL grammar generator with ANTLR4
# include(potatodb_antlr)
include(potatodb_sql_parser)

# Debug Build
set(CMAKE_BUILD_TYPE "Debug")
include(potatodb_build_tests)
include(potatodb_build_server)

# Release Build
#set(CMAKE_BUILD_TYPE "Release")
#include(potatodb_build_perf)
#include(potatodb_build_server)
