cmake_minimum_required(VERSION 3.9)

project(perfAnalysis)

add_executable(perfAnalysis main.c)
target_link_libraries(perfAnalysis ${CMAKE_SOURCE_DIR}/cmake-build-debug/lib/libfastAES.a)