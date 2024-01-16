add_subdirectory(generator)
add_subdirectory(datastructures)
add_subdirectory(algorithms)
add_subdirectory(control)
add_subdirectory(strings)
add_subdirectory(math)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main main.cc)
target_link_libraries(main 
  generator_lib 
  datastructures_lib 
  algorithms_lib 
  control_lib 
  strings_lib
  math_lib
)
