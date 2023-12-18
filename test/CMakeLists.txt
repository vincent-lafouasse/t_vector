#defines target `libunity.a`
add_subdirectory(Unity)

add_executable(test_runner)
target_include_directories(test_runner PUBLIC ../include)
target_include_directories(test_runner PUBLIC ./Unity/include)
target_sources(test_runner
PRIVATE
	src/main.c
	src/allocation.c
)
target_link_libraries(test_runner vector)
target_link_libraries(test_runner unity)
