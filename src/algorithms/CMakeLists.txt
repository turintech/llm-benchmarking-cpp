add_library(algorithms_lib 
    primes.cc
    sort.cc
)
target_link_libraries(algorithms_lib datastructures_lib)
target_include_directories(algorithms_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
