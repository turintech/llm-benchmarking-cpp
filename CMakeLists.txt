cmake_minimum_required(VERSION 3.5)

# Set the project name
project (llm_cpp_benchmark)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find and specify boost
find_package(Boost REQUIRED)

# Include dependencies
include(FetchContent)

# QUANTLIB
set(FETCHCONTENT_QUIET OFF)
FetchContent_Declare(
  QuantLib
  GIT_REPOSITORY https://github.com/lballabio/QuantLib.git
  GIT_TAG        v1.33
)

FetchContent_MakeAvailable(QuantLib)

add_subdirectory(src)
add_subdirectory(tests)

