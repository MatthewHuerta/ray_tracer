message("adding Pixel library")

add_library(
  Pixel
  STATIC
  Pixel.h
  Pixel.cpp
)
target_include_directories(
  Pixel
  PUBLIC
  "../Tuple/"
)
target_link_libraries(
  Pixel
  PUBLIC
  Tuple
)
