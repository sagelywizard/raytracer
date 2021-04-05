cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(raytracer)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
add_subdirectory(example)
