cmake_minimum_required(VERSION 3.25)
project(ParallelRasterizer
    VERSION 0.1.0
    DESCRIPTION "Rasterizer using parallelized instructions"
    LANGUAGES CXX)

add_executable(ParallelRasterizer src/main.cpp)

set_target_properties(ParallelRasterizer PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)