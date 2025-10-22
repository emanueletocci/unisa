cmake_minimum_required(VERSION 3.27)
project(cancellazione_duplicati_BST C)

set(CMAKE_C_STANDARD 99)

add_executable(cancellazione_duplicati_BST main.c
        TInfo.c
        TInfo.h
        TBST.c
        TBST.h
)
target_link_libraries(cancellazione_duplicati_BST m)
