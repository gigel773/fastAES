cmake_minimum_required(VERSION 3.5)

project(perfAnalysis)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/lib/include ${CMAKE_SOURCE_DIR}/test/include)
add_executable(perfAnalysis main.cpp include/ITest.h include/IPerformanceTest.h source/performanceTests/EncryptionTest.cpp source/performanceTests/EncryptionTest.h)
if (CMAKE_BUILD_TYPE MATCHES DEBUG)
    target_link_libraries(perfAnalysis ${CMAKE_SOURCE_DIR}/cmake-build-debug/lib/libfastAES.a)
ELSE ()
    target_link_libraries(perfAnalysis ${CMAKE_SOURCE_DIR}/cmake-build-release/lib/libfastAES.a)
ENDIF ()

