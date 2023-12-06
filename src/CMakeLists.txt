add_subdirectory(algorithms)
add_subdirectory(control)
add_subdirectory(datastructures)
add_subdirectory(strings)

target_include_directories(algorithms_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(control_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(datastructures_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(strings_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})