cmake_minimum_required(VERSION 3.5)

project(t_vector LANGUAGES C)

add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-g3)

add_library(vector src/construct.c)
target_include_directories(vector PUBLIC .)

add_library(unity_test_runner test/test-framework/unity.c)
target_include_directories(unity_test_runner PUBLIC test/test-framework)

add_executable(test 
test/src/main.c
test/src/allocation.c
)
target_include_directories(test PUBLIC .)
target_include_directories(test PUBLIC test/test-framework)
target_link_libraries(test vector)
target_link_libraries(test unity_test_runner)

# LSP stuff, don't worry about it
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
