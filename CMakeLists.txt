cmake_minimum_required(VERSION 4.2)
project(MultiArmBand C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(MultiArmBand
        bandit.c
        bandit.h
        main.c

)
