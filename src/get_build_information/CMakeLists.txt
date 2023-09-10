cmake_minimum_required(VERSION 3.26)

find_package(OpenCV REQUIRED)

add_executable(get_build_information get_build_information.cpp)

target_link_libraries(get_build_information
    PRIVATE
        project_options
        ${OpenCV_LIBS}
)

