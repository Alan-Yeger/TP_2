#include "../includes/PokemonInfo.hpp"

string PokemonInfo::getTipo() const {
    return tipo;
}

string PokemonInfo::getDesc() const {
    return desc;
}

pair<string,int> PokemonInfo::getAtaque(int nivel) const {
    return ataques[nivel];
}

int PokemonInfo::getNivel(int xp) const {
    int nivel = -1;
    for (int exp: experienciaNivel) {
        if (xp < exp) return nivel;
        nivel++;
    }
    return nivel;
}