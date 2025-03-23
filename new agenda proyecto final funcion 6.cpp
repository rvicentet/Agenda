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

// Función para mostrar la lista de contactos
void mostrarLista(DatosPersona persona[], int size) {
    cout << "\n--- Lista de Registrados ---\n";
    int enumer = 0;
    for (int i = 0; i < size; i++) {
        if (persona[i].escrito) {
            enumer++;
            cout << setw(3) << enumer << ". "
                 << "Nombre: " << persona[i].nombre << ", "
                 << "Genero: " << persona[i].genero << ", "
                 << "Edad: " << persona[i].edad << "\n"
                 << "Correo: " << persona[i].correo << "\n"
                 << "Codigo: " << persona[i].codigo << "\n";
        }
    }
    if (enumer == 0) {
        cout << "No hay personas registradas.\n";
    }
    cout << "Presione enter para continuar...";
    cin.ignore();
    cin.get();
    limpiarPantalla();
}

// Función para añadir un nuevo contacto
void anadirPersona(DatosPersona persona[], int size) {
    for (int i = 0; i < size; i++) {
        if (!persona[i].escrito) {
            persona[i].escrito = true;
            cout << "Ingrese el nombre de la persona: ";
            cin.ignore();
            getline(cin, persona[i].nombre);
            cout << "Ingrese el genero: ";
            getline(cin, persona[i].genero);
            cout << "Ingrese la edad: ";
            cin >> persona[i].edad;
            cin.ignore();
            cout << "Ingrese el correo: ";
            getline(cin, persona[i].correo);
            cout << "Ingrese el codigo universitario: ";
            getline(cin, persona[i].codigo);
            cout << "Persona agregada con exito.\n";
            break;
        }
    }
    cout << "Presione enter para continuar...";
    cin.get();
    limpiarPantalla();
}

// Función para borrar un contacto
void borrarPersona(DatosPersona persona[], int size) {
    int proce;
    cout << "¿Que entrada en la lista quiere borrar? ";
    cin >> proce;
    int enumer = 0;
    for (int i = 0; i < size; i++) {
        if (persona[i].escrito) {
            enumer++;
            if (enumer == proce) {
                persona[i].escrito = false;
                cout << "Persona borrada con exito.\n";
                break;
            }
        }
    }
    if (enumer != proce) {
        cout << "Entrada no encontrada.\n";
    }
    cout << "Presione enter para continuar...";
    cin.ignore();
    cin.get();
    limpiarPantalla();
}

// Función para editar un contacto
void editarPersona(DatosPersona persona[], int size) {
    int proce;
    cout << "¿Que entrada en la lista quiere editar? ";
    cin >> proce;
    int enumer = 0;
    for (int i = 0; i < size; i++) {
        if (persona[i].escrito) {
            enumer++;
            if (enumer == proce) {
                cout << "Ingrese el nuevo nombre de la persona: ";
                cin.ignore();
                getline(cin, persona[i].nombre);
                cout << "Ingrese el nuevo genero: ";
                getline(cin, persona[i].genero);
                cout << "Ingrese la nueva edad: ";
                cin >> persona[i].edad;
                cin.ignore();
                cout << "Ingrese el nuevo correo: ";
                getline(cin, persona[i].correo);
                cout << "Ingrese el nuevo codigo universitario: ";
                getline(cin, persona[i].codigo);
                cout << "Persona editada con exito.\n";
                break;
            }
        }
    }
    if (enumer != proce) {
        cout << "Entrada no encontrada.\n";
    }
    cout << "Presione enter para continuar...";
    cin.ignore();
    cin.get();
    limpiarPantalla();
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
