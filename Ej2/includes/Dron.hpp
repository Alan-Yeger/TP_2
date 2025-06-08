#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

using namespace std;

class Dron {
    public:
    
        //Dron(int id, bool estaVolando = false): id(id), estaVolando(estaVolando){ }
        Dron(int id): id(id){}

        void despegar(mutex* mizq, mutex* mder, mutex* printear);
        //void alturaSuficiente();

    private:
        int id;
        //bool estaVolando;
};