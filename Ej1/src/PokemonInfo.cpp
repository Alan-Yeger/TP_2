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

void PokemonInfo::serializar(ofstream& out) const {
    out << tipo << "," << desc << ",";
    
    for (int i = 0 ; i < 3; ++i) {
        out << ataques[i].first << ":" << ataques[i].second;
        if (i != ataques.size() - 1) out << "|";
    }

    out << ",";

    for (int i = 0 ; i < 3; ++i) {
        out << experienciaNivel[i];
        if (i != ataques.size() - 1) out << "|";
    }

    out << "\n";
}