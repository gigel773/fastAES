cmake_minimum_required(VERSION 3.5)
project(fastAES)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-maes -m64")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include sources/utils/include)
set(SOURCES sources/fastAESDecryptor.c
        include/fastAES.h
        sources/utils/src/owncopy.c
        sources/utils/include/owns.h
        include/definitions.h
        sources/fastAESEncryptor.c
        sources/utils/include/ownAES.h
        sources/utils/src/ownAES.c sources/fastAESPad.c)

add_library(fastAES ${SOURCES})
