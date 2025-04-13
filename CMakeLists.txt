cmake_minimum_required(VERSION 3.14)
project(Pokedex LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()
include(FetchContent)

message(STATUS "Fetching the CppMenu library...")

FetchContent_Declare( cppmenu
    GIT_REPOSITORY  https://github.com/DanielRamirez404/CppMenu.git
    GIT_TAG         v2.0.0
    GIT_SHALLOW     TRUE 
) 

FetchContent_MakeAvailable(cppmenu)

add_subdirectory(src)
