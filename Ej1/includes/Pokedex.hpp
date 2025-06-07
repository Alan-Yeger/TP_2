#pragma once
#include "Pokemon.hpp"
#include "PokemonInfo.hpp"

#include <iostream>
#include <unordered_map>

using namespace std;

class PokedexHash {
    public:
        size_t operator()(const Pokemon& pok) const {
            return hash<string>()(pok.getNombre());
        }
};

class Pokedex {
    public:
        Pokedex(){}
        void mostrar(Pokemon) const;
        void mostrarTodos() const;
        void agregarPokemon(Pokemon, PokemonInfo);

    private:
        unordered_map<Pokemon, PokemonInfo, PokedexHash> pokedex; //Almacena la info de todos los pokemones que queramos

};