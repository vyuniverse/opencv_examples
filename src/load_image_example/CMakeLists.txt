cmake_minimum_required(VERSION 3.26)

find_package(OpenCV REQUIRED)

add_executable(load_image_example load_image_example.cpp)

target_link_libraries(load_image_example
    PRIVATE
        project_options
        ${OpenCV_LIBS}
)

