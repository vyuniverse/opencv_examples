cmake_minimum_required(VERSION 3.26)

find_package(OpenCV REQUIRED)

add_executable(basic_drawing_example basic_drawing_example.cpp)

target_link_libraries(basic_drawing_example
    PRIVATE
        project_options
        ${OpenCV_LIBS}
)

