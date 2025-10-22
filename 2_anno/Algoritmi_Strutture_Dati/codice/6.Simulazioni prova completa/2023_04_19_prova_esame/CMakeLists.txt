cmake_minimum_required(VERSION 3.27)
project(2023_04_19_prova_esame C)

set(CMAKE_C_STANDARD 99)

add_executable(2023_04_19_prova_esame main.c
        TInfo.c
        TInfo.h
        TList.c
        TList.h
        THT.c
        THT.h
        TBST.c
        TBST.h
)
target_link_libraries(2023_04_19_prova_esame m)
