cmake_minimum_required(VERSION 3.14)
project(Pokedex LANGUAGES CXX)

add_executable(Tests main.cpp menu.cpp userinput.cpp userstring.cpp)

target_include_directories(Tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

project(Pokedex)
