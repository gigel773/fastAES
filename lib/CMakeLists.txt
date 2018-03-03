cmake_minimum_required(VERSION 3.5)
project(fastAES)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-maes")

include_directories(include sources/utils/include)

add_library(fastAES sources/fastAESDecryptor.c include/fastAESDecryptor.h sources/utils/src/owncopy.c sources/utils/include/owns.h include/definitions.h sources/utils/src/ownpadwithzeros.c sources/fastAESEncryptor.c sources/utils/include/ownAES.h sources/utils/src/ownAES.c)
