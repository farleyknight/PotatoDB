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


# Google benchmark
find_package(benchmark CONFIG REQUIRED)
# ANTLR4
# TODO: Use this to figure out setting up ANTLR4 w/ CMake
# https://github.com/antlr/antlr4/tree/master/runtime/Cpp/cmake
#find_package(antlr4-generator CONFIG REQUIRED)
#find_package(antlr4-runtime CONFIG REQUIRED)

# NOTE: Not sure if I need this?
# find_package(Threads CONFIG REQUIRED)
