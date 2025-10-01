cmake_minimum_required(VERSION 3.10)

project(multitool++ VERSION 1.1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include ./src/*.cpp
file(GLOB_RECURSE SOURCES "src/*.cpp")

# add include directories
include_directories("src")

# define executable
add_executable(multitool++ ${SOURCES})

# enable testing
enable_testing()

# Default to Release if nothing is set
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the build type." FORCE)
endif()

# Compiler-specific optimization flags
if (MSVC)
    # MSVC optimization flags
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG")
else()
    # GCC/Clang optimization flags
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
endif()
