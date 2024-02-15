add_library(math_lib
  vectoralgebra.cc
  matrixalgebra.cc
)
target_link_libraries(math_lib
  datastructures_lib
)
