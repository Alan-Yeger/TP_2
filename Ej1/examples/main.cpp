#include "../includes/Pokedex.hpp"
#include <iostream>

int main() {

    //Creamos la Pokedex
    Pokedex poke;

    //Agregamos los 3 pokemones del enunciado
    poke.agregarPokemon(
    Pokemon("Squirtle", 100),
    PokemonInfo("Agua", "Una tortuga pequeña que lanza chorros de agua.", 
                {pair{"Pistola Agua", 4}, pair{"Hidrobomba", 6}, pair{"Danza Lluvia", 5}}, 
                {0, 400, 1000}));
    
    poke.agregarPokemon(
    Pokemon("Bulbasaur", 270),
    PokemonInfo("Planta", "Tiene una semilla en su lomo que crece con el tiempo",
                {pair{"Latigazo", 4}, pair{"Hoja Afilada", 6}, pair{"Rayo Solar", 5}},
                {0, 300, 1100}));


    poke.agregarPokemon(
    Pokemon("Charmander", 633),
    PokemonInfo("Fuego", "Una lagartija con una llama en su cola",
                {pair{"Ascuas", 4}, pair{"Lanzallamas", 6}, pair{"Giro Fuego", 5}},
                {0, 250, 1300}));

    
    poke.mostrarTodos();


    //c)
    poke.mostrar(Pokemon("Squirtle", 870));
    poke.mostrar(Pokemon("Pikachu", 390));


    //Tests Opcional
    Pokedex pokecsv("data.csv");

    pokecsv.agregarPokemon(
    Pokemon("Luis", 100),
    PokemonInfo("Agua", "Una tortuga pequeña que lanza chorros de agua.", 
                {pair{"Pistola Agua", 4}, pair{"Hidrobomba", 6}, pair{"Danza Lluvia", 5}}, 
                {0, 400, 1000}));
    
    pokecsv.agregarPokemon(
    Pokemon("Alan", 270),
    PokemonInfo("Planta", "Tiene una semilla en su lomo que crece con el tiempo",
                {pair{"Latigazo", 4}, pair{"Hoja Afilada", 6}, pair{"Rayo Solar", 5}},
                {0, 300, 1100}));


    pokecsv.agregarPokemon(
    Pokemon("Mariano", 633),
    PokemonInfo("Fuego", "Una lagartija con una llama en su cola",
                {pair{"Ascuas", 4}, pair{"Lanzallamas", 6}, pair{"Giro Fuego", 5}},
                {0, 250, 1300}));
    
    //Luego de agregar los pokemones vemos que se crea el archivo "data.csv" con todos los datos.

    Pokedex pokePermanencia("data.csv");
    
    //Para mostrar que se deserializan bien los datos, buscamos algunos pokemones.
    pokePermanencia.mostrar(Pokemon("Mariano", 870));
    pokePermanencia.mostrar(Pokemon("Juani", 390));
}