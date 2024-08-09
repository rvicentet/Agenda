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