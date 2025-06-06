#pragma once
#include "Pokemon.hpp"
#include "PokemonInfo.hpp"

#include <iostream>
#include <unordered_map>

using namespace std;

class Pokedex {
    public:

    private:
        unordered_map<Pokemon, PokemonInfo> pokedex; //Almacena la info de todos los pokemones que queramos

};

class HashingFunction: public Pokedex {

};