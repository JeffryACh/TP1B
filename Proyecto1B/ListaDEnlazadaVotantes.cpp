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

//T_Votante
/*
	Struct Nodo de la lista enlazada de votantes
	- char cedula[10]: cedula del votante
	- char codelec[7]: codigo electoral del votante
	- char sexo: sexo del votante
	- char fecha[9]: fecha de nacimiento del votante
	- char numjun[6]: numero de junta del votante
	- char nombre[31]: nombre del votante
	- char papellido[27]: primer apellido del votante
	- char sapellido[27]: segundo apellido del votante
	- T_Votante * PtrSiguiente: puntero al siguiente nodo de la lista
*/
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
void agregarVotanteDoble(PtrT_VotanteDoble& ListaVD, char agregado[118]) {
	PtrT_VotanteDoble Aux = new (T_VotanteDoble);
	Aux->PtrSiguiente = ListaVD;
	Aux->PtrAnterior = NULL;
	if (ListaVD != NULL) {
		ListaVD->PtrAnterior = Aux;
	}
	ListaVD = Aux;

}

//Funcion para imprimir la lista de votantes
void imprimirVotantesDobles(PtrT_VotanteDoble ListaVD) {
PtrT_VotanteDoble Aux = ListaVD;
	while (Aux != NULL) {
		cout << Aux->cedula << " " << Aux->codelec << " " << Aux->sexo << " " << Aux->fecha << " " << Aux->numjun << " " << Aux->nombre << " " << Aux->papellido << " " << Aux->sapellido << endl;
		Aux = Aux->PtrSiguiente;
	}}
}

//Funcion para buscar un votante por cedula
PtrT_Votante buscarvotante(PtrT_Votante ListaV, char cedula[10]) {
	PtrT_Votante Aux = ListaV;
	while (Aux != NULL) {
		if (strcmp(Aux->cedula, cedula) == 0) {
			return Aux;
		}
		Aux = Aux->PtrSiguiente;
	}
	return NULL;
}

//Funcion para eliminar un votante por cedula
void eliminarvotante(PtrT_Votante& ListaV, char cedula[10]) {
	PtrT_Votante Aux = ListaV;
	PtrT_Votante Ant = NULL;
	while (Aux != NULL) {
		if (strcmp(Aux->cedula, cedula) == 0) {
			if (Ant == NULL) {
				ListaV = Aux->PtrSiguiente;
			}
			else {
				Ant->PtrSiguiente = Aux->PtrSiguiente;
			}
			delete Aux;
			return;
		}
		Ant = Aux;
		Aux = Aux->PtrSiguiente;
	}
}

//Funcion para liberar la memoria de la lista de votantes
void liberarvotantes(PtrT_Votante& ListaV) {
	PtrT_Votante Aux = ListaV;
	while (Aux != NULL) {
		ListaV = Aux->PtrSiguiente;
		delete Aux;
		Aux = ListaV;
	}
	cout << "----------------------------Padron liberado--------------------------------" << endl;
	system("pause");
}

//Funcion para inicializar la lista de votantes
void inicializarvotantes(PtrT_Votante& ListaV) {
	ListaV = NULL;
}

////Funcion para guardar la lista de votantes en un archivo de texto aparte
//void guardarvotantes(PtrT_Votante ListaV) {
//	PtrT_Votante Aux = ListaV;
//	FILE* archivo;
//	archivo = fopen("Votantes.txt", "w");
//	while (Aux != NULL) {
//		fprintf(archivo, "%s %s %c %s %s %s %s %s\n", Aux->cedula, Aux->codelec, Aux->sexo, Aux->fecha, Aux->numjun, Aux->nombre, Aux->papellido, Aux->sapellido);
//		Aux = Aux->PtrSiguiente;
//	}
//	fclose(archivo);
//}

//Funcion para cargar la lista de votantes desde un archivo de texto
void cargarvotantes(PtrT_Votante& ListaV) {
	FILE* archivo;
	errno_t err = fopen_s(&archivo, "PADRON_COMPLETO.txt", "r");
	if (err != 0) {
		cout << "No se pudo abrir el archivo" << endl;
	}
	else {
		while (!feof(archivo)) {
			char agregado[118];
			fgets(agregado, 118, archivo);
			agregarvotante(ListaV, agregado);
		}
		fclose(archivo);
	}
}