add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE segments_lib gtest gtest_main)
add_test(NAME RunTests COMMAND tests)
