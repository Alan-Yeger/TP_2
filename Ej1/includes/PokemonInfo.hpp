#pragma once
#include <iostream>
#include <map>
#include <array>
#include <vector>

using namespace std;

class PokemonInfo {
    public:
        PokemonInfo(string tipo, string desc, array<pair<string, int>, 3> ataques, array<int, 3> experienciaNivel): tipo(tipo), desc(desc), ataques(ataques), experienciaNivel(experienciaNivel){}
        PokemonInfo() = default; //Esto es necesario ya que al agregar los objetos a la pokedex estos crean copias con este constructor default

        string getTipo() const;
        string getDesc() const;
        pair<string,int> getAtaque(int nivel) const;
        int getNivel(int xp) const;

    private:
        string tipo; //Indica el tipo del pokemon
        string desc; //Descripción del pokemon

        //Hay que justificar por qué usamos array, preguntar la semana que viene si está bien asumir que siempre hay 3 niveles.
        array<pair<string, int>, 3> ataques; //Ataques disponibles por nivel

        //Hay que justificar por qué usamos array
        array<int, 3> experienciaNivel; //Experiencia necesaria para el próximo nivel
};