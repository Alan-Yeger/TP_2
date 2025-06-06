#pragma once
#include "Pokemon.hpp"
#include "PokemonInfo.hpp"

#include <iostream>
#include <unordered_map>

using namespace std;

class Pokedex {
    public:
        void mostrar(Pokemon);

    private:
        unordered_map<Pokemon, PokemonInfo, PokedexHash> pokedex; //Almacena la info de todos los pokemones que queramos

};

class PokedexHash {
    public:
        size_t operator()(Pokemon& pok) const {
            return hash<string>()(pok.getNombre());
        }
};