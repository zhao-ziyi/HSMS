cmake_minimum_required(VERSION 3.19)
project(HSMS C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(HSMS
        lib/api.c
        lib/api.h
        lib/meta.c
        lib/meta.h
        lib/util.c
        lib/util.h
        test/hsms_test.c)
