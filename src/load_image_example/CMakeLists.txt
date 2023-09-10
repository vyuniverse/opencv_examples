cmake_minimum_required(VERSION 3.26)

find_package(OpenCV REQUIRED)

set(LOAD_IMAGE_EXAMPLE_SRCS
    load_image_example.cpp
)

add_executable(load_image_example
    ${LOAD_IMAGE_EXAMPLE_SRCS}
)

target_link_libraries(load_image_example
    PRIVATE
        project_options
        ${OpenCV_LIBS}
)

