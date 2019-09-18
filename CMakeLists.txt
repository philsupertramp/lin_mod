cmake_minimum_required(VERSION 3.15.2)

project(ccc C)
set(SOURCES vector.h vector.c main.c stat.h stat.c
  matrix.h matrix.c plot.h plot.c)

add_executable(ccc ${SOURCES})

