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
	Nodo del arbol binario de votantes
	- char cedula[10]: cedula del votante
	- char codelec[7]: codigo electoral del votante
	- char sexo: sexo del votante
	- char fecha[9]: fecha de nacimiento del votante
	- char numjun[6]: numero de junta del votante
	- char nombre[31]: nombre del votante
	- char papellido[27]: primer apellido del votante
	- char sapellido[27]: segundo apellido del votante
	- T_Votante * PtrIzquierdo: puntero al nodo izquierdo del arbol
	- T_Votante * PtrDerecho: puntero al nodo derecho del arbol
*/
typedef struct T_Votante { //Se define la estructura para los votantes
	char cedula[10];
	char codelec[7];
	char sexo;
	char fecha[9];
	char numjun[6];
	char nombre[31];
	char papellido[27];
	char sapellido[27];
	T_Votante* PtrIzquierdo;
	T_Votante* PtrDerecho;
}*PtrT_Votante; //Se define el puntero para la estructura de votantes

//Funcion para agregar un votante, recibe como parametro la raiz del arbol de votantes y la LINEA DE TEXTO del padron electoral
//extrae cada uno de los atributos de la linea y los almacena en un nodo del arbol de votantes
void agregarVotanteBinario(PtrT_Votante& Raiz, char agregado[118]) {
	PtrT_Votante Aux = new (T_Votante);
	Aux->PtrIzquierdo = nullptr;
	Aux->PtrDerecho = nullptr;
	Raiz = Aux;

	for (int ce = 0; ce < 9; ce++) {
		Raiz->cedula[ce] = agregado[ce];
	}
	Raiz->cedula[9] = '\0';

	for (int co = 10; co < 16; co++) {
		Raiz->codelec[co - 10] = agregado[co];
	}
	Raiz->codelec[6] = '\0';

	Raiz->sexo = agregado[16];

	for (int fe = 17; fe < 26; fe++) {
		Raiz->fecha[fe - 17] = agregado[fe];
	}
	Raiz->fecha[9] = '\0';

	for (int nu = 26; nu < 31; nu++) {
		Raiz->numjun[nu - 26] = agregado[nu];
	}
	Raiz->numjun[5] = '\0';

	for (int no = 31; no < 62; no++) {
		Raiz->nombre[no - 31] = agregado[no];
	}
	Raiz->nombre[31] = '\0';

	for (int pa = 62; pa < 89; pa++) {
		Raiz->papellido[pa - 62] = agregado[pa];
	}
	Raiz->papellido[27] = '\0';

	for (int sa = 89; sa < 116; sa++) {
		Raiz->sapellido[sa - 89] = agregado[sa];
	}
	Raiz->sapellido[27] = '\0';
}

//Funcion para imprimir el arbol de votantes
void imprimirVotantesBinarios(PtrT_Votante Raiz) {
	if (Raiz != nullptr) {
		imprimirVotantesBinarios(Raiz->PtrIzquierdo);
		cout << "Cedula: " << Raiz->cedula << endl;
		cout << "Codigo Electoral: " << Raiz->codelec << endl;
		cout << "Sexo: " << Raiz->sexo << endl;
		cout << "Fecha de Nacimiento: " << Raiz->fecha << endl;
		cout << "Numero de Junta: " << Raiz->numjun << endl;
		cout << "Nombre: " << Raiz->nombre << endl;
		cout << "Primer Apellido: " << Raiz->papellido << endl;
		cout << "Segundo Apellido: " << Raiz->sapellido << endl;
		cout << endl;
		imprimirVotantesBinarios(Raiz->PtrDerecho);
	}
}

//Funcion para buscar un votante por cedula
PtrT_Votante buscarVotanteBinario(PtrT_Votante Raiz, char cedula[10]) {
	if (Raiz == nullptr) {
		return nullptr;
	}
	if (strcmp(Raiz->cedula, cedula) == 0) {
		return Raiz;
	}
	if (strcmp(cedula, Raiz->cedula) < 0) {
		return buscarVotanteBinario(Raiz->PtrIzquierdo, cedula);
	}
	else {
		return buscarVotanteBinario(Raiz->PtrDerecho, cedula);
	}
}

//Funcion para eliminar un votante por cedula
void eliminarVotanteBinario(PtrT_Votante& Raiz, char cedula[10]) {
	if (Raiz == nullptr) {
		return;
	}
	if (strcmp(cedula, Raiz->cedula) < 0) {
		eliminarVotanteBinario(Raiz->PtrIzquierdo, cedula);
	}
	else if (strcmp(cedula, Raiz->cedula) > 0) {
		eliminarVotanteBinario(Raiz->PtrDerecho, cedula);
	}
	else {
		if (Raiz->PtrIzquierdo == nullptr && Raiz->PtrDerecho == nullptr) {
			delete Raiz;
			Raiz = nullptr;
		}
		else if (Raiz->PtrIzquierdo == nullptr) {
			PtrT_Votante Aux = Raiz;
			Raiz = Raiz->PtrDerecho;
			delete Aux;
		}
		else if (Raiz->PtrDerecho == nullptr) {
			PtrT_Votante Aux = Raiz;
			Raiz = Raiz->PtrIzquierdo;
			delete Aux;
		}
		else {
			PtrT_Votante Aux = Raiz->PtrDerecho;
			while (Aux->PtrIzquierdo != nullptr) {
				Aux = Aux->PtrIzquierdo;
			}
			strcpy_s(Raiz->cedula, sizeof(Raiz->cedula), Aux->cedula);
			strcpy_s(Raiz->codelec, sizeof(Raiz->codelec), Aux->codelec);
			Raiz->sexo = Aux->sexo;
			strcpy_s(Raiz->fecha, sizeof(Raiz->fecha), Aux->fecha);
			strcpy_s(Raiz->numjun, sizeof(Raiz->numjun), Aux->numjun);
			strcpy_s(Raiz->nombre, sizeof(Raiz->nombre), Aux->nombre);
			strcpy_s(Raiz->papellido, sizeof(Raiz->papellido), Aux->papellido);
			strcpy_s(Raiz->sapellido, sizeof(Raiz->sapellido), Aux->sapellido);
			eliminarVotanteBinario(Raiz->PtrDerecho, Aux->cedula);
		}
	}
}


//Funcion para liberar la memoria del arbol de votantes
void liberarVotantesBinarios(PtrT_Votante& Raiz) {
	if (Raiz != nullptr) {
		liberarVotantesBinarios(Raiz->PtrIzquierdo);
		liberarVotantesBinarios(Raiz->PtrDerecho);
		delete Raiz;
		Raiz = nullptr;
	}
}

//Funcion para ordenar los votantes por cedula
void OrdenarVotantesBinarios(PtrT_Votante& Raiz) {
	PtrT_Votante Aux1, Aux2, Aux3;
	char cedula[10], codelec[7], sexo, fecha[9], numjun[6], nombre[31], papellido[27], sapellido[27];
	Aux1 = Raiz;
	Aux2 = Raiz;
	Aux3 = Raiz;
	while (Aux1 != nullptr) {
		while (Aux2 != nullptr) {
			if (strncmp(Aux1->cedula, Aux2->cedula, 9) < 0) {
				strcpy_s(cedula, sizeof(cedula), Aux1->cedula);
				strcpy_s(codelec, sizeof(codelec), Aux1->codelec);
				sexo = Aux1->sexo;
				strcpy_s(fecha, sizeof(fecha), Aux1->fecha);
				strcpy_s(numjun, sizeof(numjun), Aux1->numjun);
				strcpy_s(nombre, sizeof(nombre), Aux1->nombre);
				strcpy_s(papellido, sizeof(papellido), Aux1->papellido);
				strcpy_s(sapellido, sizeof(sapellido), Aux1->sapellido);

				strcpy_s(Aux1->cedula, sizeof(Aux1->cedula), Aux2->cedula);
				strcpy_s(Aux1->codelec, sizeof(Aux1->codelec), Aux2->codelec);
				Aux1->sexo = Aux2->sexo;
				strcpy_s(Aux1->fecha, sizeof(Aux1->fecha), Aux2->fecha);
				strcpy_s(Aux1->numjun, sizeof(Aux1->numjun), Aux2->numjun);
				strcpy_s(Aux1->nombre, sizeof(Aux1->nombre), Aux2->nombre);
				strcpy_s(Aux1->papellido, sizeof(Aux1->papellido), Aux2->papellido);
				strcpy_s(Aux1->sapellido, sizeof(Aux1->sapellido), Aux2->sapellido);

				strcpy_s(Aux2->cedula, sizeof(Aux2->cedula), cedula);
				strcpy_s(Aux2->codelec, sizeof(Aux2->codelec), codelec);
				Aux2->sexo = sexo;
				strcpy_s(Aux2->fecha, sizeof(Aux2->fecha), fecha);
				strcpy_s(Aux2->numjun, sizeof(Aux2->numjun), numjun);
				strcpy_s(Aux2->nombre, sizeof(Aux2->nombre), nombre);
				strcpy_s(Aux2->papellido, sizeof(Aux2->papellido), papellido);
				strcpy_s(Aux2->sapellido, sizeof(Aux2->sapellido), sapellido);
			}
			Aux2 = Aux2->PtrDerecho;
		}
		Aux1 = Aux1->PtrDerecho;
		Aux2 = Aux1;
	}
}


//Funcion para inicializar la lista de votantes
void inicializarVotantesBinarios(PtrT_Votante& Raiz) {
	Raiz = nullptr;
}

void CargarVotantesBinarios(PtrT_Votante& Raiz) {
	FILE* archivo;
	errno_t err = fopen_s(&archivo, "PADRON_COMPLETO.txt", "r");
	if (err != 0) {
		cout << "No se pudo abrir el archivo" << endl;
	}
	else {
		char linea[118];
		while (fgets(linea, 118, archivo)) {
			agregarVotanteBinario(Raiz, linea);
		}
		fclose(archivo);
	}
}

// guarda en un archivo de nombre 'VotantesBinarios.txt'
void GuardarVotantesBinarios(PtrT_Votante& Raiz) {
	FILE* archivo;
	errno_t err = fopen_s(&archivo, "VotantesBinarios.txt", "w");
	if (err != 0) {
		cout << "Error al abrir el archivo" << endl;
	}
	else {
		guardarVotantesBinarios(Raiz, archivo);
	}
	fclose(archivo);
}

void guardarVotantesBinarios(PtrT_Votante& Raiz, FILE* archivo) {
	PtrT_Votante aux = Raiz;
	while (aux != nullptr) {
		fprintf(archivo, "%s %s %c %s %s %s %s %s\n", aux->cedula, aux->codelec, aux->sexo, aux->fecha, aux->numjun, aux->nombre, aux->papellido, aux->sapellido);
		aux = aux->PtrDerecho;
	}
}