include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_library(test_lib
  testervector.h
)
target_link_libraries(test_lib
  PRIVATE 
    Catch2::Catch2WithMain 
)

