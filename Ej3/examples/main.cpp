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
condition_variable cv;
bool terminado = false;

int tareas_terminadas = 0;
const int NUM_TAREAS = 3;

void crearTarea(int idSensor, int idTarea, string descripcionTarea)
{
    Tarea tarea;
    tarea.idSensor = idSensor;
    tarea.idTarea = idTarea;
    tarea.descripcionTarea = descripcionTarea;
    {                              // Lo metemos en un scope porque porque el lockguard se libera automaticamente
        lock_guard<mutex> lg(mtx); // se usa el mismo mutex con lockguard y este asegura que solo uno pueda acceder a la vez
        colaTareas.push(tarea);
        cout << "Tarea creada con id: " << tarea.idTarea << " con descripcion: " << tarea.descripcionTarea << " y con el id del sensor correspondiente a"
             << tarea.idSensor << endl;
    }
    cv.notify_all(); // llamo a los robots
    this_thread::sleep_for(chrono::milliseconds(175));

    {
        lock_guard<mutex> lg(mtx);
        tareas_terminadas++;
        if (tareas_terminadas == NUM_TAREAS)
        {
            terminado = true;
            cv.notify_all(); // El último productor notifica que se terminó
        }
    }
}

void realizarTarea(int id)
{
    while (true)
    {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul, []
                { return !colaTareas.empty() || terminado; });

        if (!colaTareas.empty())
        {
            Tarea valor = colaTareas.front();
            colaTareas.pop();
            cout << "[Robot " << id
                 << "] Procesando la tarea con las siguintes caracteristicas " << "id sensor: " << valor.idSensor << " id tarea: " << valor.idTarea << " descripcion: " << valor.descripcionTarea << endl;
            ul.unlock(); // unlockeamos aca para que ya vaya procesando otra tarea y funcione el multithreading
            this_thread::sleep_for(chrono::milliseconds(250));
        }
        else if (terminado)
        {
            break;
        }
    }
    cout << "[Robot con id: " << id << "] terminó su tarea.\n";
}

int main()
{
    const int NUM_SENSORES = 3;
    const int NUM_TAREAS_POR_SENSOR = 3;
    const int NUM_ROBOTS = 3;

    vector<thread> sensores;
    // Crear tareas: 3 tareas por sensor → en total 9 tareas generadas
    for (int idSensor = 1; idSensor <= NUM_SENSORES; ++idSensor)
    {
        for (int idTarea = 1; idTarea <= NUM_TAREAS_POR_SENSOR; ++idTarea)
        {
            string descripcion = "Descripcion tarea #" + to_string(idTarea) + " del sensor " + to_string(idSensor);
            sensores.emplace_back(crearTarea, idSensor, idTarea, descripcion);
        }
    }

    vector<thread> robots;
    for (int i = 1; i <= NUM_ROBOTS; ++i)
        robots.emplace_back(realizarTarea, i);

    // Esperar que terminen todos los sensores
    for (auto &s : sensores)
        s.join();

    // Esperar que terminen todos los robots
    for (auto &r : robots)
        r.join();

    cout << ">>> Todos los sensores y robots han terminado." << endl;

    return 0;
}
