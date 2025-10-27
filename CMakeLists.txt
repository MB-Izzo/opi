cmake_minimum_required(VERSION 3.14)

project(game)

set(CMAKE_CXX_STANDARD 20)

option(TRACY_PROFILING "Enable Tracy profiling in release builds" OFF)
option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)
if (${FORCE_COLORED_OUTPUT})
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       add_compile_options (-fdiagnostics-color=always)
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       add_compile_options (-fcolor-diagnostics)
    endif ()
endif ()

add_subdirectory(lib)
add_subdirectory(src/opiEngine)
add_subdirectory(src/game)
