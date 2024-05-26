#include "listaSimpleVotantes.cpp"

#include <iostream>

using namespace std;

// Declaraciones de funciones para cada submen�
void submenu1();
void submenu2();
void submenu3();
void submenu4();
void submenu5();
void submenu6();

int main() {
    int choice;

    do {
        // Imprimir el men� principal
        cout << "========== Menu Principal ==========\n";
        cout << "1. Submenu 1\n";
        cout << "2. Submenu 2\n";
        cout << "3. Submenu 3\n";
        cout << "4. Submenu 4\n";
        cout << "5. Submenu 5\n";
        cout << "6. Submenu 6\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opci�n: ";
        cin >> choice;

        // Controlar la selecci�n del men�
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
            cout << "Opci�n no v�lida, intente de nuevo.\n";
        }
    } while (choice != 0);

    return 0;
}

// Definiciones de funciones para cada submen�
void submenu1() {
    int subChoice;
    do {
        cout << "\n--- Submenu 1 ---\n";
        cout << "1. Opci�n 1.1\n";
        cout << "2. Opci�n 1.2\n";
        cout << "0. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opci�n 1.1\n";
            break;
        case 2:
            cout << "Ejecutando opci�n 1.2\n";
            break;
        case 0:
            cout << "Volviendo al men� principal...\n";
            break;
        default:
            cout << "Opci�n no v�lida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}

void submenu2() {
    int subChoice;
    do {
        cout << "\n--- Submenu 2 ---\n";
        cout << "1. Opci�n 2.1\n";
        cout << "2. Opci�n 2.2\n";
        cout << "0. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opci�n 2.1\n";
            break;
        case 2:
            cout << "Ejecutando opci�n 2.2\n";
            break;
        case 0:
            cout << "Volviendo al men� principal...\n";
            break;
        default:
            cout << "Opci�n no v�lida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}

void submenu3() {
    int subChoice;
    do {
        cout << "\n--- Submenu 3 ---\n";
        cout << "1. Opci�n 3.1\n";
        cout << "2. Opci�n 3.2\n";
        cout << "0. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opci�n 3.1\n";
            break;
        case 2:
            cout << "Ejecutando opci�n 3.2\n";
            break;
        case 0:
            cout << "Volviendo al men� principal...\n";
            break;
        default:
            cout << "Opci�n no v�lida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}

void submenu4() {
    int subChoice;
    do {
        cout << "\n--- Submenu 4 ---\n";
        cout << "1. Opci�n 4.1\n";
        cout << "2. Opci�n 4.2\n";
        cout << "0. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opci�n 4.1\n";
            break;
        case 2:
            cout << "Ejecutando opci�n 4.2\n";
            break;
        case 0:
            cout << "Volviendo al men� principal...\n";
            break;
        default:
            cout << "Opci�n no v�lida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}

void submenu5() {
    int subChoice;
    do {
        cout << "\n--- Submenu 5 ---\n";
        cout << "1. Opci�n 5.1\n";
        cout << "2. Opci�n 5.2\n";
        cout << "0. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opci�n 5.1\n";
            break;
        case 2:
            cout << "Ejecutando opci�n 5.2\n";
            break;
        case 0:
            cout << "Volviendo al men� principal...\n";
            break;
        default:
            cout << "Opci�n no v�lida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}

void submenu6() {
    int subChoice;
    do {
        cout << "\n--- Submenu 6 ---\n";
        cout << "1. Opci�n 6.1\n";
        cout << "2. Opci�n 6.2\n";
        cout << "0. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Ejecutando opci�n 6.1\n";
            break;
        case 2:
            cout << "Ejecutando opci�n 6.2\n";
            break;
        case 0:
            cout << "Volviendo al men� principal...\n";
            break;
        default:
            cout << "Opci�n no v�lida, intente de nuevo.\n";
        }
    } while (subChoice != 0);
}
