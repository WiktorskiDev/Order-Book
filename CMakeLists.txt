cmake_minimum_required(VERSION 3.20)

project(
    OrderBook
    VERSION 0.1.0
    DESCRIPTION "A Low-Latency Focused Orderbook implementation Project usign C++17"
    LANGUAGES CXX
)

include(FetchContent)

include(GoogleTest)

FetchContent_Declare(
    googleBench
    URL https://github.com/google/benchmark/archive/refs/tags/v1.9.5.zip
)

set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    googleTest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googleTest)
FetchContent_MakeAvailable(googleBench)

add_executable(orderbook
    src/main.cpp

    include/core_data_structs.h
    include/orderbook.h

    src/orderbook.cpp
)

add_executable(orderbook_benchmark
    src/benchmark.cpp
)

add_executable(orderbook_test
    src/test.cpp
)


enable_testing()

gtest_discover_tests(orderbook_test)

target_link_libraries(orderbook_benchmark benchmark::benchmark)

target_link_libraries(orderbook_test GTest::gtest_main)


target_include_directories(orderbook
    PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
)

target_include_directories(orderbook_benchmark
    PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
)


target_include_directories(orderbook_test
    PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
)
    

target_compile_features(orderbook PRIVATE cxx_std_17)
target_compile_features(orderbook_benchmark PRIVATE cxx_std_17)
target_compile_features(orderbook_test PRIVATE cxx_std_17)

set_target_properties(orderbook PROPERTIES
    CXX_EXTENSIONS OFF
)

set_target_properties(orderbook_benchmark PROPERTIES
    CXX_EXTENSIONS OFF
)

set_target_properties(orderbook_test PROPERTIES
    CXX_EXTENSIONS OFF
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(orderbook PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
        target_compile_options(orderbook_benchmark PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
        target_compile_options(orderbook_test PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()