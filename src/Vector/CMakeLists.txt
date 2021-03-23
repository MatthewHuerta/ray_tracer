message("adding Vector library")
message("Vector Current source directory: ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(
  Vector
  STATIC
  Vector.h
  Vector.cpp
)
target_include_directories(
  Vector
  PUBLIC
  "../Tuple/"
)
target_link_libraries(
  Vector
  PUBLIC
  Tuple
)
