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
  control/test_single.cc
  control/test_double.cc
  datastructures/test_vector.cc
  datastructures/test_linkedlist.cc
)
target_link_libraries(tests 
  PRIVATE 
    Catch2::Catch2WithMain 
  PUBLIC 
    generator_lib
    algorithms_lib 
    control_lib 
    datastructures_lib 
    strings_lib
)
