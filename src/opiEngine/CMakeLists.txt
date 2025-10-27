cmake_minimum_required(VERSION 3.14)
project(opiEngine)

add_subdirectory(lib)

set(sourceFiles
    Application.cpp
    include/opiEngine/Application.h
)

add_library(opiEngine ${sourceFiles})

find_package(OpenGL REQUIRED)

target_include_directories(opiEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(opiEngine PRIVATE glfw glad glm TracyClient spdlog imgui)
