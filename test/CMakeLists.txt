cmake_minimum_required(VERSION 3.5)

project(perfAnalysis)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(${CMAKE_SOURCE_DIR}/lib/include ${CMAKE_SOURCE_DIR}/test/include)
add_executable(perfAnalysis main.cpp
        source/performance_tests/encryption_performance_test.cpp
        source/performance_tests/encryption_performance_test.hpp
        source/algorithmic_tests/encryption_algorithmic_test.cpp
        source/algorithmic_tests/encryption_algorithmic_test.hpp)

target_link_libraries(perfAnalysis fastAES)

