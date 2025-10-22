cmake_minimum_required(VERSION 3.27)
project(sim_1_drive C)

set(CMAKE_C_STANDARD 99)

add_executable(sim_1_drive main.c
        TArray.c
        TArray.h
        TBST.c
        TBST.h
        THT.c
        THT.h
        TInfo.c
        TInfo.h
        TList.c
        TList.h)
