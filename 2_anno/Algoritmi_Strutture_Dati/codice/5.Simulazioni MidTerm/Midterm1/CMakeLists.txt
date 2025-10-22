cmake_minimum_required(VERSION 3.27)
project(Midterm1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Midterm1 main.c
        TArray.c
        TArray.h
        TInfo.c
        TInfo.h
        TList.c
        TList.h
        TQueue.c
        TQueue.h
        TStack.c
        TStack.h)
