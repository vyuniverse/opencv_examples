cmake_minimum_required(VERSION 3.26)

find_package(OpenCV REQUIRED)

set(GET_BUILD_INFORMATION_SRCS
    get_build_information.cpp
)

add_executable(get_build_information
    ${GET_BUILD_INFORMATION_SRCS}
)

target_link_libraries(get_build_information
    PRIVATE
        project_options
        ${OpenCV_LIBS}
)

