add_subdirectory(generator)
add_subdirectory(datastructures)
add_subdirectory(algorithms)
add_subdirectory(control)
add_subdirectory(strings)
add_subdirectory(math)
add_subdirectory(libraries)
add_subdirectory(testhelpers)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main main.cc)

if(WITH_SYCL)
  target_compile_options(main
    PUBLIC
      -fsycl
      -fsycl-targets=nvptx64-nvidia-cuda
  )
  target_link_options(main
    PUBLIC
      -fsycl
      -fsycl-targets=nvptx64-nvidia-cuda
  )
endif()

target_link_libraries(main 
  generator_lib 
  datastructures_lib 
  algorithms_lib 
  control_lib 
  strings_lib
  math_lib
)

if(WITH_QUANTLIB)
  add_executable(ql ql.cc)
  target_link_libraries(ql
    ql_library lib_lib
  )
endif()
