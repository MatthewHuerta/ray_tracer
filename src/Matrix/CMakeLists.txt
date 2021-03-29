message("adding Matrix library")
# message("Matrix Current source directory: ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(
        Matrix
        STATIC
        Matrix.h
        Matrix.cpp
)
target_include_directories(
        Matrix
        PUBLIC
        "../Tuple/"
)
target_link_libraries(
        Matrix
        PUBLIC
        Tuple
)