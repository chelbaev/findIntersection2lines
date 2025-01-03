cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest
 URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_app test.cpp) # to run tests

target_link_libraries(test_app PRIVATE GTest::gtest_main myLib)

include(GoogleTest)
gtest_discover_tests(test_app)