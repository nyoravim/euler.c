cmake_minimum_required(VERSION 3.20)
project(euler LANGUAGES C)

file(GLOB_RECURSE COMMON_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.c")
add_library(common STATIC ${COMMON_SRC})
target_include_directories(common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/lib")
target_precompile_headers(common PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/pch.h")

file(GLOB PROBLEM_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
foreach(PROBLEM_SRC_FILE ${PROBLEM_SRC})
    cmake_path(GET PROBLEM_SRC_FILE FILENAME PROBLEM_FILENAME)
    cmake_path(GET PROBLEM_FILENAME STEM PROBLEM_NAME)

    set(PROBLEM_TARGET_NAME "problem${PROBLEM_NAME}")
    list(APPEND PROBLEMS ${PROBLEM_TARGET_NAME})

    add_executable(${PROBLEM_TARGET_NAME} ${PROBLEM_SRC_FILE})
    target_link_libraries(${PROBLEM_TARGET_NAME} PRIVATE common)
endforeach()

set_target_properties(common ${PROBLEMS} PROPERTIES C_STANDARD 99)
