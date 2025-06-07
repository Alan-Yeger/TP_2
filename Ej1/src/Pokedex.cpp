#include "../includes/Pokedex.hpp"

void Pokedex::mostrar(Pokemon pok) const {

    auto it = pokedex.find(pok);
    if (it != pokedex.end()) {
    int xp = pok.getXp();
    int nivel = pokedex.at(pok).getNivel(xp);

    cout << "El pokemon: " << pok.getNombre() << "\n"
         << "Tiene: " << xp << "xp\n"
         << "Es de tipo: " << pokedex.at(pok).getTipo() << "\n"
         << "Descripción: " << pokedex.at(pok).getDesc() << "\n"
         << "Su ataque es: " << pokedex.at(pok).getAtaque(nivel).first << " y hace " << pokedex.at(pok).getAtaque(nivel).second << " de daño \n";

        }
    else {
        cout << "Pokemon no encontrado :( \n";
    }
    cout << "\n";

}

void Pokedex::mostrarTodos() const {
    for (const auto& [pok, info] : pokedex) {
        mostrar(pok);
        cout << "\n";
    }
}

void Pokedex::agregarPokemon(Pokemon pok, PokemonInfo info) {
    pokedex[pok] = info;
}