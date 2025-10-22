cmake_minimum_required(VERSION 3.26)
project(ricerca_minimo_personalizzato C)

set(CMAKE_C_STANDARD 11)

add_executable(ricerca_minimo_personalizzato main.c
        generic.c
        generic.h)
