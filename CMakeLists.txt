cmake_minimum_required(VERSION 3.10)
project(Base)

set(CMAKE_CXX_STANDARD 17)
# GLFW
add_subdirectory(libs/glfw)
include_directories(
    ${CMAKE_SOURCE_DIR}/src/*
        libs/glfw/include
)

include_directories(
    ${CMAKE_SOURCE_DIR}/libs
    ${CMAKE_SOURCE_DIR}/libs/glfw/include
    ${CMAKE_SOURCE_DIR}/src/*
)
# GLM
include_directories(${CMAKE_SOURCE_DIR}/libs/glm)


# GLAD
add_library(glad src/glad.c)
target_include_directories(glad PUBLIC include)

# Collect all utility source files
file(GLOB_RECURSE UTILS_SOURCES 
${CMAKE_SOURCE_DIR}/src/util/*.cpp 
${CMAKE_SOURCE_DIR}/src/core/*.cpp 
${CMAKE_SOURCE_DIR}/src/renderer/*.cpp 
${CMAKE_SOURCE_DIR}/src/handler/*.cpp 

${CMAKE_SOURCE_DIR}/src/shader/*.cpp 
${CMAKE_SOURCE_DIR}/src/object/*.cpp)

# Your executable with all required source files
add_executable(OpenGLProject src/main.cpp ${UTILS_SOURCES} libs/stb/stb_image_implementation.cpp)

# Link libraries

target_link_libraries(OpenGLProject glad glfw ${CMAKE_DL_LIBS})
