cmake_minimum_required(VERSION 3.15)
project(untitled5 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled5 main.c game_init.c game_init.h input_output.c input_output.h game_movement.c game_movement.h winner.c winner.h keptPiece_movement.c keptPiece_movement.h)