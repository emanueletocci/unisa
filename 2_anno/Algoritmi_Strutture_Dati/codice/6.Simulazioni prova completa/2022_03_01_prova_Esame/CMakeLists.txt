cmake_minimum_required(VERSION 3.27)
project(2022_03_01_prova_Esame C)

set(CMAKE_C_STANDARD 99)

add_executable(2022_03_01_prova_Esame main.c
        TInfo.c
        TInfo.h
        TList.c
        TList.h
        THT.c
        THT.h
        TBST.c
        TBST.h
        TArray.c
        TArray.h
)
target_link_libraries(2022_03_01_prova_Esame m)