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

#define MAX 4
#define MIN 2

/*
	Estructura de un nodo del arbol B, Votante
	- char cedula[10]: cedula del votante
	- char codelec[7]: codigo electoral del votante
	- char sexo: sexo del votante
	- char fecha[9]: fecha de nacimiento del votante
	- char numjun[6]: numero de junta del votante
	- char nombre[31]: nombre del votante
	- char papellido[27]: primer apellido del votante
	- char sapellido[27]: segundo apellido del votantE
	- link[MAX + 1]: puntero a los hijos del nodo
*/
typedef struct T_Votante
{
	char cedula[10];
	char codelec[7];
	char sexo;
	char fecha[9];
	char numjun[6];
	char nombre[31];
	char papellido[27];
	char sapellido[27];
	T_Votante* link[MAX + 1];
} *PtrT_Votantes;

// Variables globales
PtrT_Votantes root;

// Creando un nuevo nodo
PtrT_Votantes CrearNodo(char cedula[10], char codelec[7], char sexo, char fecha[9], char numjun[6], char nombre[31], char papellido[27], char sapellido[27], PtrT_Votantes hijo)
{
    PtrT_Votantes NuevoNodo = new T_Votante;
    strcpy_s(NuevoNodo->cedula, sizeof(NuevoNodo->cedula), cedula);
    strcpy_s(NuevoNodo->codelec, sizeof(NuevoNodo->codelec), codelec);
    NuevoNodo->sexo = sexo;
    strcpy_s(NuevoNodo->fecha, sizeof(NuevoNodo->fecha), fecha);
    strcpy_s(NuevoNodo->numjun, sizeof(NuevoNodo->numjun), numjun);
    strcpy_s(NuevoNodo->nombre, sizeof(NuevoNodo->nombre), nombre);
    strcpy_s(NuevoNodo->papellido, sizeof(NuevoNodo->papellido), papellido);
    strcpy_s(NuevoNodo->sapellido, sizeof(NuevoNodo->sapellido), sapellido);
    NuevoNodo->link[0] = root;
    NuevoNodo->link[1] = hijo;
    return NuevoNodo;
}

//Cargar datos de los votantes desde un archivo txt
void CargarDatosVotantesB()
{
	FILE* archivo;
	errno_t err = fopen_s(&archivo, "PADRON_COMPLETO.txt", "r");
	if (err != 0)
	{
		cout << "Error al abrir el archivo" << endl;
	}
	else
	{
		char cedula[10], codelec[7], sexo, fecha[9], numjun[6], nombre[31], papellido[27], sapellido[27];
		while (!feof(archivo))
		{
			fscanf_s(archivo, "%s %s %c %s %s %s %s %s\n", cedula, sizeof(cedula), codelec, sizeof(codelec), &sexo, fecha, sizeof(fecha), numjun, sizeof(numjun), nombre, sizeof(nombre), papellido, sizeof(papellido), sapellido, sizeof(sapellido));
			cout << cedula << " " << codelec << " " << sexo << " " << fecha << " " << numjun << " " << nombre << " " << papellido << " " << sapellido << endl;
		}
	}
	fclose(archivo);
}

// Funcion que guarda los votantes en un archivo llamado 'VotantesB'
void GuardarVotantesB()
{
	FILE* archivo;
	errno_t err = fopen_s(&archivo, "VotantesB.txt", "w");
	if (err != 0)
	{
		cout << "Error al abrir el archivo" << endl;
	}
	else
	{
		PtrT_Votantes aux = root;
		while (aux != NULL)
		{
			fprintf(archivo, "%s %s %c %s %s %s %s %s\n", aux->cedula, aux->codelec, aux->sexo, aux->fecha, aux->numjun, aux->nombre, aux->papellido, aux->sapellido);
			aux = aux->link[0];
		}
	}
	fclose(archivo);
}

//Ordenar los votantes por cedula
void OrdenarVotantesB()
{
	PtrT_Votantes aux = root;
	PtrT_Votantes aux2 = root;
	while (aux != NULL)
	{
		while (aux2 != NULL)
		{
			if (strcmp(aux->cedula, aux2->cedula) < 0)
			{
				PtrT_Votantes temp = aux;
				aux = aux2;
				aux2 = temp;
			}
			aux2 = aux2->link[0];
		}
		aux = aux->link[0];
	}
}

// Esta funcion elimina un votante
void EliminarVotanteB(char cedula[10])
{
	PtrT_Votantes aux = root;
	PtrT_Votantes aux2 = root;
	while (aux != NULL)
	{
		if (strcmp(aux->cedula, cedula) == 0)
		{
			if (aux == root)
			{
				root = root->link[0];
			}
			else
			{
				aux2->link[0] = aux->link[0];
			}
			delete aux;
			return;
		}
		aux2 = aux;
		aux = aux->link[0];
	}
}

// Esta funcion guarda los votantes en un archivo de nombre 'VotantesB.txt'
void GuardarVotantesB()
{
	FILE* archivo;
	errno_t err = fopen_s(&archivo, "VotantesB.txt", "w");
	if (err != 0)
	{
		cout << "Error al abrir el archivo" << endl;
	}
	else
	{
		PtrT_Votantes aux = root;
		while (aux != NULL)
		{
			fprintf(archivo, "%s %s %c %s %s %s %s %s\n", aux->cedula, aux->codelec, aux->sexo, aux->fecha, aux->numjun, aux->nombre, aux->papellido, aux->sapellido);
			aux = aux->link[0];
		}
	}
	fclose(archivo);
}

// esta funcion limpia la memoria
void LimpiarMemoriaB()
{
	PtrT_Votantes aux = root;
	PtrT_Votantes aux2 = root;
	while (aux != NULL)
	{
		aux2 = aux;
		aux = aux->link[0];
		delete aux2;
	}
}

// esta funcion busca y retorna un votante por numero de cedula
PtrT_Votantes BuscarVotanteB(char cedula[10])
{
	PtrT_Votantes aux = root;
	while (aux != NULL)
	{
		if (strcmp(aux->cedula, cedula) == 0)
		{
			return aux;
		}
		aux = aux->link[0];
	}
	return NULL;
}

// Funcion que imprime a los votantes en consola
void ImprimirVotantesB()
{
	PtrT_Votantes aux = root;
	while (aux != NULL)
	{
		cout << aux->cedula << " " << aux->codelec << " " << aux->sexo << " " << aux->fecha << " " << aux->numjun << " " << aux->nombre << " " << aux->papellido << " " << aux->sapellido << endl;
		aux = aux->link[0];
	}
}