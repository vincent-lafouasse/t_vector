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
target_compile_options(unity PRIVATE -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR)

add_executable(test_runner)
target_include_directories(test_runner PUBLIC ./include)
target_include_directories(test_runner PUBLIC ./test/Unity/src)
target_include_directories(test_runner PUBLIC ./test/Unity/extras/fixture/src)
target_sources(test_runner
PRIVATE
	test/src/main.c
	test/src/allocation.c
)
target_link_libraries(test_runner vector)
target_link_libraries(test_runner unity)
