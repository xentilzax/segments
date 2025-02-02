cmake_minimum_required(VERSION 3.10)

project(segments_distance)

set(CMAKE_CXX_STANDARD 17)

# add headers
include_directories(include)

add_library(segments_lib STATIC 
                    src/Segment3D.cpp 
                    src/Vector3D.cpp)

target_include_directories(segments_lib PUBLIC include)
add_executable(segments_distance src/main.cpp)
target_link_libraries(segments_distance PRIVATE segments_lib)

# Google Test
enable_testing()
add_subdirectory(tests)
