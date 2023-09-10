cmake_minimum_required(VERSION 3.26)

project(opencv_tutorials
    VERSION 0.1
    LANGUAGES CXX
)

include(cmake/StandardProjectSettings.cmake)

# Global project options
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

add_subdirectory(src)

