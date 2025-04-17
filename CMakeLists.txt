cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_SOURCE_DIR}/googletest)
add_executable(${PROJECT_NAME} main.cpp candle.cpp)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

enable_testing()
add_test(NAME testproj_test COMMAND ${PROJECT_NAME})