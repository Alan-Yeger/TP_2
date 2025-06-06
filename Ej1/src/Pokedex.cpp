#include "../includes/Pokedex.hpp"

void Pokedex::mostrar(Pokemon pok) {
    cout << "El pokemon: " << pok.getNombre() << "\n"
         << "Tiene: " << pok.getXp() << "xp\n"
         << "Es de tipo: " << pokedex.at(pok).getTipo() << "\n"
         << pokedex.at(pok).getDesc() << "\n"
         << "Su ataque es: " << pokedex.at(pok).getAtaque().first << " y hace " << pokedex.at(pok).getAtaque().second << " de daño\n";
}