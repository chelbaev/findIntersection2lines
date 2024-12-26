cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option(BUILD_TESTS "Build the google tests" OFF)

add_subdirectory(lib)
target_include_directories(myLib PUBLIC .)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()