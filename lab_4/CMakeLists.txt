cmake_minimum_required(VERSION 3.10)
project(Figures)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(figures src/main.cpp src/figure.cpp src/hexagon.cpp src/octagon.cpp src/triangle.cpp)

enable_testing()
add_subdirectory(tests)
