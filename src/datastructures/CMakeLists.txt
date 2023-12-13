add_library(datastructures_lib
    linkedlist.cc
    list.cc
    vector.cc
)
target_include_directories(datastructures_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
