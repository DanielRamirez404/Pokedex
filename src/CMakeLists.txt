add_executable(Pokedex main.cpp menu.cpp userstring.cpp input.cpp pokedex.cpp)
target_include_directories(Pokedex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Pokedex ${CPP_MENU})
