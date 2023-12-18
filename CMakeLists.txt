cmake_minimum_required(VERSION 3.18)

project(t_vector LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(vector)
target_sources(vector
PRIVATE
	src/construct.c
	src/destruct.c
	src/accessor.c
)
target_include_directories(vector PUBLIC ./include)
target_compile_options(vector PRIVATE -Wall -Wextra -Wpedantic -g3)

add_subdirectory(test)
