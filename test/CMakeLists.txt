#defines target `libunity.a`
add_subdirectory(Unity)
target_compile_options(unity PRIVATE -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR)

add_executable(test_runner)
target_include_directories(test_runner PUBLIC ../include)
target_include_directories(test_runner PUBLIC ./Unity/src)
target_include_directories(test_runner PUBLIC ./Unity/extras/fixture/src)
target_sources(test_runner
PRIVATE
	src/main.c
	src/allocation.c
)
target_link_libraries(test_runner vector)
target_link_libraries(test_runner unity)
