message("adding Point library")

add_library(
  Point
  STATIC
  Point.h
  Point.cpp
)
target_include_directories(
  Point
  PUBLIC
  "../Tuple/"
)
target_link_libraries(
  Point
  PUBLIC
  Tuple
)
