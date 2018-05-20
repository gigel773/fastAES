cmake_minimum_required(VERSION 3.5)
project(fastAES)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-maes -m64")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include sources/utils/include)
set(SOURCES sources/fastaesdecryptor.c
        sources/utils/src/owncopy.c
        sources/fastaesencryptor.c
        sources/utils/src/ownaes.c
       	sources/fastaespad.c)

add_library(fastAES ${SOURCES})
