cmake_minimum_required(VERSION 3.5)

project(t_vector LANGUAGES C)

add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-g3)

include_directories(.)
add_library(vector src/construct.c)

# LSP stuff, don't worry about it
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
