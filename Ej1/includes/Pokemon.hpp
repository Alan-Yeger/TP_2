#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Pokemon {
    public:
        Pokemon(string nombre, int xp): nombre(nombre), xp(xp){}
        Pokemon(const Pokemon& other) = default;  // importante. Esto lo hacemos porque cuando se inicializa el unordered_map de la pokedex se llama a una copia del objeto
        Pokemon& operator=(const Pokemon& other) = default;
        
        string getNombre() const;
        int getXp() const;

        bool operator ==(const Pokemon& other) const {
            return nombre == other.nombre;
        }
        
        void serializar(ofstream& out) const;

    private:
        string nombre;
        int xp;
};