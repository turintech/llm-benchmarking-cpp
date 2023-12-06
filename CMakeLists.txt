cmake_minimum_required(VERSION 3.5)

# Set the project name
project (llm_cpp_benchmark)
set (CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(main src/main.cc)
target_link_libraries(main algorithms_lib control_lib datastructures_lib strings_lib)