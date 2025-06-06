#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class PokemonInfo {
    public:
        string getTipo();
        string getDesc();
        pair<string,int> getAtaque();
        tuple<int, int, int> getXpNivel();

    private:
        string tipo; //Indica el tipo del pokemon
        string desc; //Descripción del pokemon

        //Hay que justificar por qué usamos map
        map<int, pair<string, int>> ataquesDisponiblesPorNivel;

        //Hay que justificar por qué usamos vector
        vector<tuple<int, int, int>> experienciaProximoNivel;
};