add_library(platform STATIC 
    src/window.cpp
    src/glfw_context.cpp)

target_include_directories(platform PUBLIC include)

# This should be public since public header files may use c++ 20 features
target_compile_features(platform PUBLIC cxx_std_20)

target_link_libraries(platform PRIVATE glfw)
