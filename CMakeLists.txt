cmake_minimum_required(VERSION 3.18)

project(t_vector LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-g3)

add_library(vector)
target_include_directories(vector PUBLIC ./include)
target_sources(vector
PRIVATE
	src/construct.c
	src/destruct.c
	src/accessor.c
)

#defines target `libunity.a`
add_subdirectory(test/Unity)
