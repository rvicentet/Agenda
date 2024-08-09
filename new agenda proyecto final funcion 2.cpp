#include <iostream>
#include <iomanip>
#include <cstdlib> 
using namespace std;

// Creado por Renzo Julian Vicente Ticona
// creado por jairo zegarra gutierrez

struct DatosPersona {
    bool escrito;
    string nombre;
    string genero;
    int edad;
    string correo;
    string codigo;

    DatosPersona() : escrito(false), nombre("Vacio"), genero("Vacio"), edad(0), correo("Vacio"), codigo("Vacio") {}
};

// Función para limpiar la pantalla
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Función para mostrar el menú de opciones
void mostrarMenu() {
    cout << "\n=== Agenda de Contactos ===\n";
    cout << "1. Ver lista de registrados\n";
    cout << "2. Agregar persona\n";
    cout << "3. Borrar persona\n";
    cout << "4. Editar persona\n";
    cout << "5. Buscar persona\n";
    cout << "6. Cerrar programa\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    const int size = 50;
    DatosPersona persona[size];

    while (true) {
        mostrarMenu();
        int selec;
        cin >> selec;
        switch (selec) {
            case 1:
                mostrarLista(persona, size);
                break;
            case 2:
                anadirPersona(persona, size);
                break;
            case 3:
                borrarPersona(persona, size);
                break;
            case 4:
                editarPersona(persona, size);
                break;
            case 5:
                buscarPersona(persona, size);
                break;
            case 6:
                cout << "Cerrando programa...\n";
                return 0;
            default:
                cout << "Opción invalida. Intente de nuevo.\n";
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                limpiarPantalla();
                break;
        }
    }
}
