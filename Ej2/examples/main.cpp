#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "../includes/Dron.hpp"
using namespace std;

mutex zonas[5];            // Mutex para zonas de interferencia
mutex printear;

int main() {
    vector<Dron> drones;
    vector<thread> hilos;

    // Crear 5 drones con ids del 0 al 4
    for (int i = 0; i < 5; ++i) {
        drones.emplace_back(i);
    }

    // Lanzar cada hilo de dron con sus zonas adyacentes
    for (int i = 0; i < 5; ++i) {
        mutex* izquierda = &zonas[i];
        mutex* derecha = &zonas[(i + 1) % 5];
        hilos.emplace_back(&Dron::despegar, &drones[i], izquierda, derecha, &printear);
    }

    // Esperar a que todos terminen
    for (auto& hilo : hilos) {
        hilo.join();
    }

    return 0;
}
