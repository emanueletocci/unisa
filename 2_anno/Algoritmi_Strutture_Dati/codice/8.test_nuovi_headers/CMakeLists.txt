cmake_minimum_required(VERSION 3.27)
project(test_nuovi_headers C)

set(CMAKE_C_STANDARD 99)

add_executable(test_nuovi_headers main.c
        TBST.c
        TBST.h
        TInfo.c
        TInfo.h
        TList.c
        TList.h
        THT.c
        THT.h
        TArray.c
        TArray.h)
