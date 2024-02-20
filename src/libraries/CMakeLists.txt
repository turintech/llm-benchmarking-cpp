if(WITH_QUANTLIB)
  add_library(lib_lib
    quantlib.cc
  )
  # target_include_directories(lib_lib ${QuantLib_INCLUDE_DIRS})
  target_link_libraries(lib_lib
    PRIVATE 
      ql_library
  )
endif()

