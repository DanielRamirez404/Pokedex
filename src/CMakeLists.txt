add_executable(Pokedex main.cpp menu.cpp userstring.cpp)
target_include_directories(Pokedex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Pokedex ${CPP_MENU})
