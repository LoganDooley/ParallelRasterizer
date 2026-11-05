cmake_minimum_required(VERSION 3.25)
project(ParallelRasterizer
    VERSION 0.1.0
    DESCRIPTION "Rasterizer using parallelized instructions"
    LANGUAGES CXX)

add_subdirectory(core)

add_subdirectory(apps/viewer)