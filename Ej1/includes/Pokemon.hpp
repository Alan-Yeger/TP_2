#pragma once
#include <iostream>

using namespace std;

class Pokemon {
    public:
        string getNombre();
        int getXp();

    private:
        string nombre;
        int xp;
};