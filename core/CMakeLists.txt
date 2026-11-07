add_library(core STATIC 
    src/core.cpp
    src/image.cpp
    src/raster.cpp)

target_include_directories(core PUBLIC include)

# This should be public since public header files may use c++ 20 features
target_compile_features(core PUBLIC cxx_std_20)
