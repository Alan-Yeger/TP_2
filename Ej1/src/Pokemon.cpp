#include "../includes/Pokemon.hpp"

string Pokemon::getNombre() const {
    return nombre;
}

int Pokemon::getXp() const {
    return xp;
}

void Pokemon::serializar(ofstream& out) const {
    out << nombre << "," << xp << ",";
}