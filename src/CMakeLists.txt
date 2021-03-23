cmake_minimum_required(VERSION 3.2)

project(ray_tracer LANGUAGES CXX)

add_executable(
test
"${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp"
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

target_link_libraries(
test
PUBLIC Tuple Vector Point
)

target_include_directories(
test
PUBLIC
Tuple
Vector
Point
)
