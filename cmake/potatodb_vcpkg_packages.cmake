# -----------------------------------------------------------------------------
# Packages - Manually maintained duplicate list of packages from `vcpkg.json`
# -----------------------------------------------------------------------------

# *****************************************
# MurmurHash - Creating a hash of an object
# https://github.com/aappleby/smhasher/wiki/MurmurHash3
# *****************************************
find_package(murmurhash CONFIG REQUIRED)

# *****************************************
# GTest - Tests
# https://github.com/google/googletest
# *****************************************
find_package(GTest CONFIG REQUIRED)

# *****************************************
# spdlog - Logging
# https://github.com/gabime/spdlog
# *****************************************
find_package(spdlog REQUIRED)


# TODO: Let's start using fmt instead of `std::cout`!
# *****************************************
# fmt -
# *****************************************
find_package(fmt CONFIG REQUIRED)

# NOTE: Networking features are dependent on POSIX system calls
# TODO: If/when we decide to make this DB Windows compatible,
#       we might want to switch to ASIO.
# ASIO -- networking
# find_package(asio CONFIG REQUIRED)

# *****************************************
# UUID -
# *****************************************
# find_package(crossguid CONFIG REQUIRED)

# *****************************************
# Google benchmark -
# *****************************************
find_package(benchmark CONFIG REQUIRED)

# *****************************************
# ANTLR4
# *****************************************
find_library(ANTLR4_LIB libantlr4-runtime.a)

message(STATUS "ANTLR4 library: ${ANTLR4_LIB}")

# NOTE: Not sure if I need this?
# find_package(Threads CONFIG REQUIRED)
