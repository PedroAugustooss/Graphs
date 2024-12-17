cmake_minimum_required(VERSION 3.30)
project(Grafos C)

set(CMAKE_C_STANDARD 23)

add_executable(Grafos Main.c
        Engine.c
        Grafos.c
        Menu.c
        Assinaturas.h)
