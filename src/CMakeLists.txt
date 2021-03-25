cmake_minimum_required(VERSION 3.2)

project(ray_tracer LANGUAGES CXX)

add_executable(
test
tests/test.cpp
)

set_property(TARGET test PROPERTY CXX_STANDARD 20)

add_library(
  Debug
  STATIC
  tests/Debug.cpp
)
target_include_directories(
  Debug
  PUBLIC
  tests
)


add_subdirectory(
        Tuple
)

add_subdirectory(
        Vector
)

add_subdirectory(
       Point
)

add_subdirectory(
        Color
)

add_subdirectory(
        Canvas
)

target_link_libraries(
test
PRIVATE Tuple Vector Point Color Canvas
)

target_include_directories(
test
PRIVATE
Tuple
Vector
Point
Color
Canvas
)
