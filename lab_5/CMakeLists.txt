cmake_minimum_required(VERSION 3.10)

project(lab_5)

add_executable(GCDTest test.cpp)
target_link_libraries(GCDTest gtest gtest_main)
target_compile_features(GCDTest PRIVATE cxx_std_17) 
