#include "../includes/Dron.hpp"


void Dron::despegar(mutex* mizq, mutex* mder, mutex* printear) {

    printear->lock();
    cout << "Dron " << id << " esperando para despegar...\n";
    printear->unlock();

    lock(*mizq, *mder);
    
    printear->lock();
    cout << "Dron " << id << " despegando...\n";
    printear->unlock();

    this_thread::sleep_for(chrono::milliseconds(5000));
    
    printear->lock();
    cout << "Dron " << id << " alcanzó altura de 10m\n";
    printear->unlock();

    mizq->unlock(); mder->unlock();
}
