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