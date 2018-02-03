cmake_minimum_required(VERSION 3.9)

project(perfAnalysis)
include_directories(${CMAKE_SOURCE_DIR}/lib/include)
add_executable(perfAnalysis main.c)
if (CMAKE_BUILD_TYPE MATCHES DEBUG)
    target_link_libraries(perfAnalysis ${CMAKE_SOURCE_DIR}/cmake-build-debug/lib/libfastAES.a)
ELSE ()
    target_link_libraries(perfAnalysis ${CMAKE_SOURCE_DIR}/cmake-build-release/lib/libfastAES.a)
ENDIF ()

