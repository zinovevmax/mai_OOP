cmake_minimum_required(VERSION 3.10)
project(Figures)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(figures_lib
    src/hexagon.cpp
    src/octagon.cpp
    src/triangle.cpp
)

add_executable(figures
    src/main.cpp
)

target_link_libraries(figures figures_lib)

enable_testing()
add_subdirectory(tests)
