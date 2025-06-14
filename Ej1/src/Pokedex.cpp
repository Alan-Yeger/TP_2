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

    if (!arch.empty()) {
        ofstream out(arch, ios::app);
        if (out.is_open()) {
            pok.serializar(out);
            info.serializar(out);
        }
    }
}

void Pokedex::deserializarCSV(ifstream& in) {
    string linea;
    while (getline(in, linea)) {
        stringstream ss(linea);
        string nombre, experienciaStr;

        getline(ss, nombre, ',');
        getline(ss, experienciaStr, ',');

        int experiencia = stoi(experienciaStr);

        Pokemon pok(nombre, experiencia);

        string tipo, desc, ataquesStr, expNivelesStr;

        getline(ss, tipo, ',');
        getline(ss, desc, ',');
        getline(ss, ataquesStr, ',');
        getline(ss, expNivelesStr);

        array<pair<string, int>, 3> ataques;
        stringstream ataquesStream(ataquesStr);
        string ataqueInfo;
        int i = 0;
        while (getline(ataquesStream, ataqueInfo, '|') && i < 3) {
            size_t pos = ataqueInfo.find(':');
            string nombreAtaque = ataqueInfo.substr(0, pos);
            int daño = stoi(ataqueInfo.substr(pos + 1));
            ataques[i++] = { nombreAtaque, daño };
        }

        // Parsear niveles
        array<int, 3> experienciaNivel;
        stringstream nivelesStream(expNivelesStr);
        string nivelStr;
        i = 0;
        while (getline(nivelesStream, nivelStr, '|') && i < 3) {
            experienciaNivel[i++] = stoi(nivelStr);
        }

        // Crear el objeto
        PokemonInfo info(tipo, desc, ataques, experienciaNivel);

        pokedex[pok] = info;
    }
}