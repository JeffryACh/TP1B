#include "listaSimpleVotantes.cpp"

#include <iostream>

using namespace std;

// Declaraciones de funciones para cada submenú
void submenu1();
void submenu2();
void submenu3();
void submenu4();
void submenu5();
void submenu6();

int main() {
    int choice;

    do {
        // Imprimir el menú principal
        cout << "========== Menu Principal ==========\n";
        cout << "1. Submenu 1\n";
        cout << "2. Submenu 2\n";
        cout << "3. Submenu 3\n";
        cout << "4. Submenu 4\n";
        cout << "5. Submenu 5\n";
        cout << "6. Submenu 6\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> choice;

        // Controlar la selección del menú
        switch (choice) {
        case 1:
            submenu1();
            break;
        case 2:
            submenu2();
            break;
        case 3:
            submenu3();
            break;
        case 4:
            submenu4();
            break;
        case 5:
            submenu5();
            break;
        case 6:
            submenu6();
            break;
        case 0:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (choice != 0);

    return 0;
}

// Definiciones de funciones para cada submenú
void submenu1() {
    int subChoice;
    do {
        cout << "\n--- Submenu 1 ---\n";
        cout << "1. Opción 1.1\n";
        cout << "2. Opción 1.2\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opción 1.1\n";
            break;
        case 2:
            cout << "Ejecutando opción 1.2\n";
            break;
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}

void submenu2() {
    int subChoice;
    do {
        cout << "\n--- Submenu 2 ---\n";
        cout << "1. Opción 2.1\n";
        cout << "2. Opción 2.2\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opción 2.1\n";
            break;
        case 2:
            cout << "Ejecutando opción 2.2\n";
            break;
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}

void submenu3() {
    int subChoice;
    do {
        cout << "\n--- Submenu 3 ---\n";
        cout << "1. Opción 3.1\n";
        cout << "2. Opción 3.2\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opción 3.1\n";
            break;
        case 2:
            cout << "Ejecutando opción 3.2\n";
            break;
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}

void submenu4() {
    int subChoice;
    do {
        cout << "\n--- Submenu 4 ---\n";
        cout << "1. Opción 4.1\n";
        cout << "2. Opción 4.2\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opción 4.1\n";
            break;
        case 2:
            cout << "Ejecutando opción 4.2\n";
            break;
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}

void submenu5() {
    int subChoice;
    do {
        cout << "\n--- Submenu 5 ---\n";
        cout << "1. Opción 5.1\n";
        cout << "2. Opción 5.2\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opción 5.1\n";
            break;
        case 2:
            cout << "Ejecutando opción 5.2\n";
            break;
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}

void submenu6() {
    int subChoice;
    do {
        cout << "\n--- Submenu 6 ---\n";
        cout << "1. Opción 6.1\n";
        cout << "2. Opción 6.2\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opción 6.1\n";
            break;
        case 2:
            cout << "Ejecutando opción 6.2\n";
            break;
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}
