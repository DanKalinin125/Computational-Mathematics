cmake_minimum_required(VERSION 3.24)
project(CM_Lab_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(CM_Lab_1 main.c utils/utils.h methods/gauss_method.h options.h utils/utils.c methods/gauss_method.c utils/reader.h utils/reader.c)
