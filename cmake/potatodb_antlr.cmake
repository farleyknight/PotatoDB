# -----------------------------------------------------------------------------
# ANTLR4 based SQL Parser configurations
# -----------------------------------------------------------------------------

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# NOTE: Setting the zip repository is preferred since the git repository doesn't work
# Every time I used the git respository, it tired to reclone/reset the source
# each time. This should only need to happen once.
# set(ANTLR4_ZIP_REPOSITORY "https://www.antlr.org/download/antlr4-cpp-runtime-4.9.2-macos.zip")
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

# TODO Maybe output dir should be `generated/`?
# That could allow us to `.gitignore` it.
antlr_target(SQLParser "parser/PotatoSQL.g4" PARSER
  PACKAGE potatodb
  OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/antlr_generated/")


if(DEFINED ANTLR_SQLParser_CXX_OUTPUTS)
  message(STATUS "The ANTLR parser generator has the following OUTPUTS: ${ANTLR_SQLParser_CXX_OUTPUT}")
else()
  message(FATAL_ERROR "No CXX OUPUTS for ANTLR SQLParser!")
endif()

# include generated files in project environment
include_directories(${ANTLR_SQLParser_OUTPUT_DIR})

# -----------------------------------------------------------------------------
# SQL Parser executable
# -----------------------------------------------------------------------------

set(PARSE_BINARY "${CMAKE_PROJECT_NAME}_parse")

# add generated grammar to demo binary target
add_executable(PARSE_BINARY "parser/main.cpp"
  ${ANTLR_SQLParser_CXX_OUTPUTS})

target_link_libraries(PARSE_BINARY antlr4_static)
