cmake_minimum_required(VERSION 3.31.6)
project(unitsnet-cpp CXX)

set(CMAKE_CXX_STANDARD 20)
enable_language(C ASM CXX)

file(GLOB_RECURSE LIB_INCLUDES "source/generated/*.h" "source/generated/*.hpp")
file(GLOB_RECURSE LIB_SOURCES "source/generated/*.c" "source/generated/*.cpp")

add_library(${PROJECT_NAME} ${LIB_INCLUDES} ${LIB_SOURCES})

# Collect and de-duplicate parent directories
set(LIB_INCLUDE_DIRS "")
foreach(hdr IN LISTS LIB_INCLUDES)
    get_filename_component(dir "${hdr}" DIRECTORY)
    list(APPEND LIB_INCLUDE_DIRS "${dir}")
endforeach()
list(REMOVE_DUPLICATES LIB_INCLUDE_DIRS)

target_include_directories (${PROJECT_NAME} PUBLIC ${LIB_INCLUDE_DIRS})

