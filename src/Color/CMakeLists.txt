 message("adding Color library")

add_library(
  Color
  STATIC
  Color.h
  Color.cpp
)
target_include_directories(
  Color
  PUBLIC
  "../Tuple/"
)
target_link_libraries(
  Color
  PUBLIC
  Tuple
)
