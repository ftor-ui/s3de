cmake_minimum_required(VERSION 3.31)

set(PROJECT_NAME s3de)
project(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC include/s3de/s3de.h src/s3de.c)
target_include_directories(${PROJECT_NAME} PUBLIC include/)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)
