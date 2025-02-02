cmake_minimum_required(VERSION 3.10)

project(segments)

set(CMAKE_CXX_STANDARD 17)

# add headers
include_directories(include)

file(GLOB SOURCES src/*.cpp)

add_executable(segments_distance ${SOURCES})

# Google Test
enable_testing()
add_subdirectory(tests)
