cmake_minimum_required(VERSION 4.0)
project(Ex3_queue C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(Ex3_queue
        src/main.c
        src/MyQueue.c
        src/MyQueue.h)
