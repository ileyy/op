cmake_minimum_required(VERSION 3.28)
project(op C)

set(CMAKE_C_STANDARD 17)

add_executable(op Gen_file.c
        Var_str.h
        Var_str.c
        File_out.c
        Alg.c)
