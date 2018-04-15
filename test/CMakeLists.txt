cmake_minimum_required(VERSION 3.5)

project(perfAnalysis)
set(CMAKE_CXX_STANDARD 17)
// set(CMAKE_CXX_FLAGS "-std=c++17")

include_directories(${CMAKE_SOURCE_DIR}/lib/include ${CMAKE_SOURCE_DIR}/test/include)
add_executable(perfAnalysis main.cpp
        include/test.hpp
        include/performance_test_base.hpp
        source/performance_tests/encryption_performance_test.cpp
        source/performance_tests/encryption_performance_test.hpp
        include/algorithmic_test_base.hpp
        source/algorithmic_tests/encryption_algorithmic_test.cpp
        source/algorithmic_tests/encryption_algorithmic_test.hpp include/test_suite.hpp)

if (CMAKE_BUILD_TYPE MATCHES DEBUG)
    target_link_libraries(perfAnalysis ${CMAKE_SOURCE_DIR}/debug/lib/libfastAES.a)
ELSE ()
    target_link_libraries(perfAnalysis ${CMAKE_SOURCE_DIR}/release/lib/libfastAES.a)
ENDIF ()

