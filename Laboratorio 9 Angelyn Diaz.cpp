//Angelyn Judith Diaz Zeceña 5090-23-1407

#include <iostream> //Aqui se utiliza para la entrada y salida de datos
#include <stack> //esta es una biblioteca que sirve para  crear y operar con una pila 
#include <queue> //Esta es una biblioteca para el uso de estructuras de cola
#include <string>

class AdministradorDeTareas {
private:
    // Aqui se utiliza una pila para manejar las tareas 
    std::stack<std::string> pilaDeTareas;
    //  Aqui se utiliza una Cola para manejar las tareas 
    std::queue<std::string> colaDeTareas;

public:
    // Función para agregar una tarea a la pila y la cola
    void agregarTarea(const std::string& tarea) {
        pilaDeTareas.push(tarea);
        colaDeTareas.push(tarea);
    }

    // Aqui se elimina la pila de la funcion
    void completarUltimaTarea() {
        if (!pilaDeTareas.empty()) {
            std::string ultimaTarea = pilaDeTareas.top();
            pilaDeTareas.pop();
            std::cout << "Tarea completada y eliminada: " << ultimaTarea << std::endl;
        }
        else {
            std::cout << "No hay tareas para completar." << std::endl;
        }
    }

    // Función para atender la tarea más antigua 
    void atenderTareaMasAntigua() {
        if (!colaDeTareas.empty()) {
            std::string tareaMasAntigua = colaDeTareas.front();
            colaDeTareas.pop();
            std::cout << "Tarea atendida y eliminada: " << tareaMasAntigua << std::endl;
        }
        else {
            std::cout << "No hay tareas para atender." << std::endl;
        }
    }

    // Función para mostrar todas las tareas en la cola 
    void mostrarTodasLasTareas() {
        if (colaDeTareas.empty()) {
            std::cout << "No hay tareas para mostrar." << std::endl;
            return;
        }

        std::cout << "Tareas actuales:" << std::endl;
        std::queue<std::string> colaTemp = colaDeTareas; // Copia de la cola para no modificar la original
        while (!colaTemp.empty()) {
            std::cout << "- " << colaTemp.front() << std::endl;
            colaTemp.pop();
        }
    }
};

int main() {
    std::cout << "-----Hola personita-----" << std::endl;

 
    AdministradorDeTareas adminTareas;
    int opcion;
    std::string tarea;

    // Aqui se utiliza un Bucle principal para el menu
    do {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Agregar una tarea" << std::endl;
        std::cout << "2. Completar la ultima tarea" << std::endl;
        std::cout << "3. Atender la tarea mas antigua" << std::endl;
        std::cout << "4. Mostrar todas las tareas" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); 

        switch (opcion) {
        case 1:
            std::cout << "Ingrese la descripcion de la tarea: ";
            std::getline(std::cin, tarea); 
            adminTareas.agregarTarea(tarea); // Aqui  Agrega la tarea
            break;
        case 2:
            adminTareas.completarUltimaTarea(); //  Aqui Completa la última tarea
            break;
        case 3:
            adminTareas.atenderTareaMasAntigua(); //  Aqui Atiende la tarea más antigua
            break;
        case 4:
            adminTareas.mostrarTodasLasTareas(); // Aqui  muestra todas las tareas
            break;
        case 5:
            std::cout << "Saliendo del programa." << std::endl; 
            break;
        default:
            std::cout << "Opcion invalida. Por favor, intente de nuevo." << std::endl; 
        }
    } while (opcion != 5); //  Aqui se utiliza un ciclio para repetir el menú hasta que el usuario elija salir

    return 0; // Aqui muestra que el programa ya ha finalizado
}
