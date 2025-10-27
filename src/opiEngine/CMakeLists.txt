cmake_minimum_required(VERSION 3.14)
project(opiEngine)

add_subdirectory(lib)

set(includePath "include/opiEngine")
set(includeCorePath "${includePath}/Core")

set(sourceFiles
    Application.cpp
    core/AppLayer.cpp
    core/Logger.cpp
    renderer/Window.cpp

    #includes
    ${includePath}/Application.h

    #core
    ${includeCorePath}/AppLayer.h
    ${includeCorePath}/Logger.h
    
    #renderer
    ${includePath}/Renderer/Window.h
)

add_library(opiEngine ${sourceFiles})

find_package(OpenGL REQUIRED)

target_include_directories(opiEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(opiEngine
    PUBLIC
        "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/pch.h>"
)

target_compile_definitions(opiEngine
    PRIVATE
        _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
)

target_link_libraries(opiEngine PRIVATE glfw glad glm TracyClient spdlog imgui)
