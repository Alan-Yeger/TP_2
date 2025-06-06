#pragma once
#include <iostream>

using namespace std;

class Pokemon {
    public:
        string getNombre();
        int getXp();

        bool operator ==(const Pokemon& other) const {
            return nombre == other.nombre;
        }

    private:
        string nombre;
        int xp;
};