#include <queue>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

struct Tarea
{
    int idSensor;
    int idTarea;
    string descripcionTarea;
};

queue<Tarea> colaTareas;
mutex mtx;
mutex cout_mtx;
condition_variable cv;
bool terminado = false;

int tareas_terminadas = 0;
const int NUM_TAREAS_POR_SENSOR = 3;
const int NUM_SENSORES = 3;
const int NUM_ROBOTS = 3;

void crearTarea(int idSensor) {
    for (int i = 1; i <= NUM_TAREAS_POR_SENSOR; ++i) {
        Tarea tarea;
        tarea.idSensor = idSensor;
        tarea.idTarea = i;
        tarea.descripcionTarea = "Descripcion tarea #" + to_string(i) + " del sensor " + to_string(idSensor);
    
    {                              // Lo metemos en un scope porque porque el lockguard se libera automaticamente
        lock_guard<mutex> lg(mtx); // se usa el mismo mutex con lockguard y este asegura que solo uno pueda acceder a la vez
        colaTareas.push(tarea);
        cout << "[Sensor " << idSensor << "] Tarea creada: ID_Tarea=" << tarea.idTarea 
                 << ", Descripción=" << tarea.descripcionTarea << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(175));
    cv.notify_all(); // llamo a los robots HAY QUE VER SI DEJAMOS EL NOTIFY_ALL O CAMBIAMOS NOTIFY_ONE COMO DIJO JUANI
    }

    {
        lock_guard<mutex> lg(mtx);
        tareas_terminadas++;
        if (tareas_terminadas == NUM_SENSORES)
        {
            terminado = true;
            cv.notify_all(); // El último productor notifica que se terminó
        }
    }
}

void realizarTarea(int id) {
    while (true) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul, [] { return !colaTareas.empty() || terminado; });

        if (!colaTareas.empty()) {
            Tarea tarea = colaTareas.front();
            colaTareas.pop();
            cout << "[Robot " << id << "] Procesando tarea: Sensor=" << tarea.idSensor 
                 << ", ID_Tarea=" << tarea.idTarea 
                 << ", Descripción=" << tarea.descripcionTarea << endl;
            ul.unlock(); // unlockeamos aca para que ya vaya procesando otra tarea y funcione el multithreading
            this_thread::sleep_for(chrono::milliseconds(250));
        }
        else if (terminado) {
            break;
        }
    }
    {
        lock_guard<mutex> lock(cout_mtx);
        cout << "[Robot con id: " << id << "] terminó su tarea.\n";
    }
}

int main()
{
    {
        vector<jthread> sensores;
        vector<jthread> robots;

        // Crear sensores
        for (int i = 1; i <= NUM_SENSORES; ++i) {
            sensores.emplace_back(crearTarea, i);
        }

        // Crear robots
        for (int i = 1; i <= NUM_ROBOTS; ++i) {
            robots.emplace_back(realizarTarea, i);
        }
    }
    
    cout << ">>> Todos los sensores y robots han terminado." << endl;
    
    return 0;
}
