cmake_minimum_required(VERSION 3.14)
project(Pokedex LANGUAGES CXX)

add_executable(Pokedex main.cpp menu.cpp userstring.cpp)
target_include_directories(Pokedex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include(FetchContent)

FetchContent_Declare( cppmenu
    GIT_REPOSITORY  https://github.com/DanielRamirez404/CppMenu.git
    GIT_TAG         v1.0.0
    GIT_SHALLOW     TRUE 
) 

FetchContent_MakeAvailable(cppmenu)
target_link_libraries(Pokedex ${CPP_MENU})
cmake_minimum_required(VERSION 3.14)
project(Pokedex LANGUAGES CXX)
