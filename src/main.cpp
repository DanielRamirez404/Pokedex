#include "menu.h"
#include "dynamic-array.h"
#include "pokemon.h"
#include "pokedex.h"
#include "cppmenu.h"
#include "cppsafeio.h"

void newPokemon(dynamic_array<pokemon>& pokedex) 
{
    addPokemon(pokedex);
    sortPokedex(pokedex);
    savePokedexData(pokedex);
}

void displayAllData(dynamic_array<pokemon>& pokedex)
{
    isPokedexEmpty(pokedex) ? printNoDataAvailableError() : printPokedexData(pokedex);
}

void deleteAllData(dynamic_array<pokemon>& pokedex)
{
    if (confirmDeletion())
        erasePokedexData(pokedex);
}

int main() 
{
    dynamic_array<pokemon> pokedex{};
    isThereLoadblePokemonData() ? readPokemonData(pokedex) : writeDefaultMessageToTextFile();
    
    CppMenu::CommonMenu menu
    {
        "PokeDex",

        {
            {"New Pokemon", [&]() { newPokemon(pokedex); } },
            {"See Current Data", [&]() { displayAllData(pokedex); } },
            {"Delete All Data", [&]() { deleteAllData(pokedex); } }
        },

        true
    };

    menu.run();
    
    printExitMessage();
    
    return 0;
}
