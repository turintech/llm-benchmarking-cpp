add_library(os_lib
  dataio.cc
  winheader.cc
)
target_include_directories(os_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

