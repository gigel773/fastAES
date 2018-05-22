cmake_minimum_required(VERSION 3.5)

project(javaWrapper)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include $ENV{JNI_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/lib/include)
if (WIN32)
    MESSAGE("Windows defined")
    include_directories($ENV{JNI_INCLUDE_DIRS}/win32)
endif (WIN32)
if (UNIX)
    MESSAGE("Unix defined")
    include_directories($ENV{JNI_INCLUDE_DIRS}/linux)
endif (UNIX)
add_library(javaWrapper SHARED include/com_nntu_aes_AesJavaWrapper.h sources/com_nntu_aes_AesJavaWrapper.c)

target_link_libraries(javaWrapper fastAES)
