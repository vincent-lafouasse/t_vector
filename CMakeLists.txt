cmake_minimum_required(VERSION 3.18)

project(t_vector LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-g3)

add_subdirectory(test/Unity)


# run tests on all builds
add_custom_target(run_tests ALL DEPENDS test COMMAND test)
