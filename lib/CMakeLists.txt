cmake_minimum_required(VERSION 3.5)
project(fastAES)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-maes")

include_directories(include)

add_library(fastAES sources/fastAES.c include/fastAES.h)
