cmake_minimum_required(VERSION 3.26)
project(Hanoi C)

set(CMAKE_C_STANDARD 11)

add_executable(Hanoi main.c)
target_link_libraries(Hanoi m)

