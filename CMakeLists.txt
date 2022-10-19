cmake_minimum_required(VERSION 3.24)
project(lexico_c C)

set(CMAKE_C_STANDARD 99)

add_executable(lexico_c main.c util.h lexico.c lexico.h)
