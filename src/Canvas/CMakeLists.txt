message("adding Canvas library")

add_library(
  Canvas
  STATIC
  Canvas.h
  Canvas.cpp
)
target_include_directories(
  Canvas
  PUBLIC
  "../Color/"
)
target_link_libraries(
  Canvas
  PUBLIC
  Color
)
