cmake_minimum_required(VERSION 3.27)
project(2021_02_11_prova_esame_cp C)

set(CMAKE_C_STANDARD 99)
add_executable(2021_02_11_prova_esame_cp main.c
        TArray.c
        TArray.h
        TBST.c
        TBST.h
        THT.c
        THT.h
        TInfo.c
        TInfo.h
        TList.c
        TList.h
)

target_link_libraries(2021_02_11_prova_esame_cp m)
