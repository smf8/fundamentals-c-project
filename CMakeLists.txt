cmake_minimum_required(VERSION 3.12)
project(FundamentalCProject C)

set(CMAKE_C_STANDARD 11)
set (" -std=c11")
add_executable(FundamentalCProject main.c LinkedList.c FileIO.c FileIO.h LinkedList.h game.c game.h misc.c misc.h)