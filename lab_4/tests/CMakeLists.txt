add_executable(test_figures test_figures.cpp)
target_link_libraries(test_figures gtest gtest_main)
add_test(NAME test_figures COMMAND test_figures)
