include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests 
  test.cc 
  algorithms/test_primes.cc
  algorithms/test_sort.cc
  control/test_single.cc
  control/test_double.cc
  datastructures/test_vector.cc
  datastructures/test_linkedlist.cc
  datastructures/test_list.cc
  math/test_vectoralgebra.cc
  math/test_matrixalgebra.cc
  math/test_simulation.cc
)
if(WITH_QUANTLIB)
  add_executable(
    tests
    libraries/test_quantlib.cc
  )
endif()
if(WITH_SYCL)
  target_compile_options(tests
    PUBLIC
      -fsycl
      -fsycl-targets=nvptx64-nvidia-cuda
  )
  target_link_options(tests
    PUBLIC
      -fsycl
      -fsycl-targets=nvptx64-nvidia-cuda
  )
endif()

target_link_libraries(tests 
  PRIVATE 
    Catch2::Catch2WithMain 
  PUBLIC 
    generator_lib
    datastructures_lib 
    algorithms_lib 
    control_lib 
    strings_lib
    math_lib
    test_lib
)
if(WITH_QUANTLIB)
  target_link_libraries(
    tests
    PRIVATE
      ql_library
    PUBLIC
      lib_lib
  )
endif()
