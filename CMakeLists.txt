cmake_minimum_required(VERSION 3.5)

project(t_vector LANGUAGES C)

add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-g3)

add_library(vector src/construct.c)
target_include_directories(vector PUBLIC .)

add_executable(test test/src/test.c)
target_include_directories(test PUBLIC .)
target_link_libraries(test vector)

# LSP stuff, don't worry about it
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
