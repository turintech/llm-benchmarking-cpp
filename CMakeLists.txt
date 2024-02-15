cmake_minimum_required(VERSION 3.5)

# Set the project name
project (llm_cpp_benchmark)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(WITH_QUANTLIB "Enable compilation with QuantLib" ON)

# Include dependencies
include(FetchContent)

# QUANTLIB
if(WITH_QUANTLIB)
  # Find and specify boost
  find_package(Boost REQUIRED)

  set(FETCHCONTENT_QUIET OFF)
  FetchContent_Declare(
    QuantLib
    GIT_REPOSITORY https://github.com/lballabio/QuantLib.git
    GIT_TAG        v1.33
  )

  FetchContent_GetProperties(QuantLib)
  if(NOT QuantLib_POPULATED)
      FetchContent_Populate(QuantLib)
      # Before adding the subdirectory, potentially modify the QuantLib build configuration here

      # Example: Set a variable that QuantLib's CMakeLists.txt might check to disable tests
      # This requires QuantLib's CMakeLists.txt to support such a variable, which is not guaranteed
      set(QL_BUILD_BENCHMARK OFF CACHE BOOL "Disable QuantLib bench" FORCE)
      set(QL_BUILD_EXAMPLES OFF CACHE BOOL "Disable QuantLib examples" FORCE)
      set(QL_BUILD_TEST_SUITE OFF CACHE BOOL "Disable QuantLib tests" FORCE)

      add_subdirectory(${quantlib_SOURCE_DIR} ${quantlib_BINARY_DIR})
  endif()
endif()

add_subdirectory(src)
add_subdirectory(tests)

