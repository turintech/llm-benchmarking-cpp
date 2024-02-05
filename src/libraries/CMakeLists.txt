add_library(lib_lib
  quantlib.cc
)
target_link_libraries(lib_lib
  PRIVATE 
    QuantLib
)

