cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)
set(CMAKE_CXX_STANDARD 17)

# add_subdirectory(${CMAKE_SOURCE_DIR}/googletest)
add_executable(${PROJECT_NAME} main.cpp candle.cpp)
# target_link_libraries(${PROJECT_NAME} gtest gtest_main)

# enable_testing()
# add_test(NAME testproj_test COMMAND ${PROJECT_NAME})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)
add_test(NAME testproj_test COMMAND ${PROJECT_NAME})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})