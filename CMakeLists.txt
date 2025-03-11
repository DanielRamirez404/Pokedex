cmake_minimum_required(VERSION 3.14)
project(Pokedex LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(src)

include(FetchContent)

FetchContent_Declare( cppmenu
    GIT_REPOSITORY  https://github.com/DanielRamirez404/CppMenu.git
    GIT_TAG         v1.0.0
    GIT_SHALLOW     TRUE 
) 

FetchContent_MakeAvailable(cppmenu)
target_link_libraries(Pokedex ${CPP_MENU})
