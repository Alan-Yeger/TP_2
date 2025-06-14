#pragma once
#include "Pokemon.hpp"
#include "PokemonInfo.hpp"

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>

using namespace std;

class PokedexHash {
    public:
        size_t operator()(const Pokemon& pok) const {
            return hash<string>()(pok.getNombre());
        }
};

class Pokedex {
    public:
        Pokedex(){} //Constructor default
        Pokedex(string arch): arch(arch) {
            ifstream in(arch);
            if (in.good()) {
                deserializarCSV(in);
            }

        } //Constructor para serializar y deserializar los datos
        
        void mostrar(Pokemon) const;
        void mostrarTodos() const;
        void agregarPokemon(Pokemon, PokemonInfo);
        void deserializarCSV(ifstream& in);

    private:
        unordered_map<Pokemon, PokemonInfo, PokedexHash> pokedex; //Almacena la info de todos los pokemones que queramos
        string arch;
};