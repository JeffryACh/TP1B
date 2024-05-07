/*
	Autores:
		- Victor Garro Abarca
		- Jeffry Araya Chaves
		- Gabriel Barrantes Villalobos
	FechaDeCreacion: 28/02/2024 17:55
	FechaDeUltimaModificacion: 02/03/2024
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cctype> 
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h> 
#include <math.h>
#include <sstream>
#include <random>
using namespace std;

//Funcion para agregar un votante, recibe como parametro la lista de votantes y la LINEA DE TEXTO del padron electoral
//extrae cada uno de los atributos de la linea y los almacena en un nodo de la lista de votantes
typedef struct T_VotanteDoble { //Se define la estructura para los votantes
    char cedula[10];
    char codelec[7];
    char sexo;
    char fecha[9];
    char numjun[6];
    char nombre[31];
    char papellido[27];
    char sapellido[27];
    T_VotanteDoble* PtrSiguiente;
    T_VotanteDoble* PtrAnterior;
}*PtrT_VotanteDoble; //Se define el puntero para la estructura de votantes

//Funcion para agregar un votante, recibe como parametro la lista de votantes y la LINEA DE TEXTO del padron electoral
//extrae cada uno de los atributos de la linea y los almacena en un nodo de la lista de votantes
void agregarvotante(PtrT_VotanteDoble& ListaV, char agregado[118]) {
    PtrT_VotanteDoble Aux = new (T_VotanteDoble);
    Aux->PtrSiguiente = ListaV;
    Aux->PtrAnterior = nullptr;
    if (ListaV != nullptr) {
        ListaV->PtrAnterior = Aux;
    }
    ListaV = Aux;

    for (int ce = 0; ce < 9; ce++) {
        ListaV->cedula[ce] = agregado[ce];
    }
    ListaV->cedula[9] = '\0';

    for (int co = 10; co < 16; co++) {
        ListaV->codelec[co - 10] = agregado[co];
    }
    ListaV->codelec[6] = '\0';

    ListaV->sexo = agregado[17];


    for (int fe = 19; fe < 27; fe++) {
        ListaV->fecha[fe - 19] = agregado[fe];
    }
    ListaV->fecha[8] = '\0';

    for (int nu = 28; nu < 33; nu++) {
        ListaV->numjun[nu - 28] = agregado[nu];
    }
    ListaV->numjun[5] = '\0';

    for (int nom = 34; nom < 64; nom++) {
        ListaV->nombre[nom - 34] = agregado[nom];
    }
    ListaV->nombre[30] = '\0';

    for (int pa = 65; pa < 91; pa++) {
        ListaV->papellido[pa - 65] = agregado[pa];
    }
    ListaV->papellido[26] = '\0';

    for (int sa = 92; sa < 118; sa++) {
        ListaV->sapellido[sa - 92] = agregado[sa];
    }
    ListaV->sapellido[26] = '\0';

}



//Funcion para cargar los votantes, se encarga de tomar cada una de las lineas
//directo del archivo de texto y enviarlo a la funci?n encargada de extraer cad uno
// de los datos e incorporarlos en un nodo de la lista.
    //Funcion para agregar un votante a una lista doblemente enlazada
void agregarvotante(PtrT_VotanteDoble& ListaV, char agregado[118]) {
    PtrT_VotanteDoble Aux = new (T_VotanteDoble);
    Aux->PtrSiguiente = ListaV;
    Aux->PtrAnterior = nullptr;
    if (ListaV != nullptr) {
        ListaV->PtrAnterior = Aux;
    }
    ListaV = Aux;

    for (int ce = 0; ce < 9; ce++) {
        ListaV->cedula[ce] = agregado[ce];
    }
    ListaV->cedula[9] = '\0';

    for (int co = 10; co < 16; co++) {
        ListaV->codelec[co - 10] = agregado[co];
    }
    ListaV->codelec[6] = '\0';

    ListaV->sexo = agregado[17];


    for (int fe = 19; fe < 27; fe++) {
        ListaV->fecha[fe - 19] = agregado[fe];
    }
    ListaV->fecha[8] = '\0';

    for (int nu = 28; nu < 33; nu++) {
        ListaV->numjun[nu - 28] = agregado[nu];
    }
    ListaV->numjun[5] = '\0';

    for (int nom = 34; nom < 64; nom++) {
        ListaV->nombre[nom - 34] = agregado[nom];
    }
    ListaV->nombre[30] = '\0';

    for (int pa = 65; pa < 91; pa++) {
        ListaV->papellido[pa - 65] = agregado[pa];
    }
    ListaV->papellido[26] = '\0';

    for (int sa = 92; sa < 118; sa++) {
        ListaV->sapellido[sa - 92] = agregado[sa];
    }
    ListaV->sapellido[26] = '\0';
}



//Funcion para liberar los votantes en estructuras de memoria dinamica de la lista enlazada hasta dejar la lista en NULL

//Funcion para liberar los votantes en estructuras de memoria dinamica de la lista doblemente enlazada hasta dejar la lista en NULL
void LiberarVotantes(PtrT_VotanteDoble& ListaV) {
    PtrT_VotanteDoble Aux = ListaV;
    time_t inicio, fin;

    inicio = time(NULL);

    while (Aux != NULL) {
        ListaV = ListaV->PtrSiguiente;
        delete(Aux);
        Aux = ListaV;
    }

    fin = time(NULL);

    cout << "----------------------------Padron liberado--------------------------------" << endl;
    printf("\nLa liberacion del padron ha tardado : %f segundos.\n", difftime(fin, inicio));
    cout << "----------------------------Padron liberado--------------------------------" << endl;
    system("pause");
}


//Funci?n para inicializar la lista de votantes
void inicializarvotantes(PtrT_VotanteDoble& ListaV) {
	ListaV = NULL;
}

PtrT_VotanteDoble BuscarVotante(PtrT_VotanteDoble& Lista, char cual[9])
{
    bool encontro = false;
    PtrT_VotanteDoble Aux;
    Aux = Lista;

    while ((!encontro == true) && (Aux != NULL))
    {
        if (strncmp(Aux->cedula, cual, 9) == 0)
            encontro = true;
        else
            Aux = Aux->PtrSiguiente;
    }
    return Aux;
}

// Ordena votantes por cedula
void OrdenarVotantes(PtrT_VotanteDoble& ListaV) {
    PtrT_VotanteDoble Aux1, Aux2, Aux3;
    char cedula[10], codelec[7], sexo, fecha[9], numjun[6], nombre[31], papellido[27], sapellido[27];
    Aux1 = ListaV;
    Aux2 = ListaV;
    Aux3 = ListaV;
    while (Aux1 != NULL) {
        while (Aux2 != NULL) {
            if (strncmp(Aux1->cedula, Aux2->cedula, 9) < 0) {
                strcpy(cedula, Aux1->cedula);
                strcpy(codelec, Aux1->codelec);
                sexo = Aux1->sexo;
                strcpy(fecha, Aux1->fecha);
                strcpy(numjun, Aux1->numjun);
                strcpy(nombre, Aux1->nombre);
                strcpy(papellido, Aux1->papellido);
                strcpy(sapellido, Aux1->sapellido);

                strcpy(Aux1->cedula, Aux2->cedula);
                strcpy(Aux1->codelec, Aux2->codelec);
                Aux1->sexo = Aux2->sexo;
                strcpy(Aux1->fecha, Aux2->fecha);
                strcpy(Aux1->numjun, Aux2->numjun);
                strcpy(Aux1->nombre, Aux2->nombre);
                strcpy(Aux1->papellido, Aux2->papellido);
                strcpy(Aux1->sapellido, Aux2->sapellido);

                strcpy(Aux2->cedula, cedula);
                strcpy(Aux2->codelec, codelec);
                Aux2->sexo = sexo;
                strcpy(Aux2->fecha, fecha);
                strcpy(Aux2->numjun, numjun);
                strcpy(Aux2->nombre, nombre);
                strcpy(Aux2->papellido, papellido);
                strcpy(Aux2->sapellido, sapellido);
            }
            Aux2 = Aux2->PtrSiguiente;
        }
        Aux1 = Aux1->PtrSiguiente;
        Aux2 = Aux1;
    }
}

// Funcion para guardar los votantes en un archivo de texto aparte
void GuardarVotantes(PtrT_VotanteDoble& ListaV) {
    FILE* archivo;
    fopen_s(&archivo, "Votantes.txt", "w");
    if (NULL == archivo) {
        printf("No se pudo abrir el archivo");
    }
    else {
        PtrT_VotanteDoble Aux = ListaV;
        while (Aux != NULL) {
            fprintf(archivo, "%s %s %c %s %s %s %s %s\n", Aux->cedula, Aux->codelec, Aux->sexo, Aux->fecha, Aux->numjun, Aux->nombre, Aux->papellido, Aux->sapellido);
            Aux = Aux->PtrSiguiente;
        }
        fclose(archivo);
    }
    cout << "----------------------------Votantes guardados--------------------------------" << endl;
    system("pause");
}

//Funcion para liberar los votantes en estructuras de memoria dinamica de la lista doblemente enlazada hasta dejar la lista en NULL
void LiberarVotantes(PtrT_VotanteDoble& ListaV) {
    PtrT_VotanteDoble Aux = ListaV;
    time_t inicio, fin;

    inicio = time(NULL);

    while (Aux != NULL) {
        ListaV = ListaV->PtrSiguiente;
        if (ListaV != NULL) {
            ListaV->PtrAnterior = NULL;
        }
        delete(Aux);
        Aux = ListaV;
    }

    fin = time(NULL);

    cout << "----------------------------Padron liberado--------------------------------" << endl;
    printf("\nLa liberacion del padron ha tardado : %f segundos.\n", difftime(fin, inicio));
    cout << "----------------------------Padron liberado--------------------------------" << endl;
    system("pause");
}
