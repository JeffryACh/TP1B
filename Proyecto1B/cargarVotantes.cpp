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
typedef struct T_Votante { //Se define la estructura para los votantes
	char cedula[10];
	char codelec[7];
	char sexo;
	char fecha[9];
	char numjun[6];
	char nombre[31];
	char papellido[27];
	char sapellido[27];
	T_Votante* PtrSiguiente;
}*PtrT_Votante; //Se define el puntero para la estructura de votantes

//Funcion para agregar un votante, recibe como parametro la lista de votantes y la LINEA DE TEXTO del padron electoral
//extrae cada uno de los atributos de la linea y los almacena en un nodo de la lista de votantes
void agregarvotante(PtrT_Votante& ListaV, char agregado[118]) {
	PtrT_Votante Aux = new (T_Votante);
	Aux->PtrSiguiente = ListaV;
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
void CargarVotantes(PtrT_Votante& ListaV) {
	int cont = 1;
	time_t inicio, fin;
	inicio = time(NULL);
	FILE* archivo;
	fopen_s(&archivo, "PADRON_COMPLETO.txt", "r");
	if (NULL == archivo) {
		printf("No se pudo abrir el archivo");
	}
	else {
		char agregado[119];
		while (fgets(agregado, 119, archivo) != NULL) {
			if (cont % 2 != 0) {
				agregarvotante(ListaV, agregado);
			}
			cont++;
		}
		fclose(archivo);
	}

	fin = time(NULL);
	cout << "----------------------------Padron cargado--------------------------------" << endl;
	printf("\nEl cargado del padron ha tardado : %f segundos.\n", difftime(fin, inicio));
	cout << "----------------------------Padron cargado--------------------------------" << endl;
	system("pause");
}


//Funcion para liberar los votantes en estructuras de memoria dinamica de la lista enlazada hasta dejar la lista en NULL

void LiberarVotantes(PtrT_Votante& ListaV) {
	PtrT_Votante Aux = ListaV;
	time_t inicio, fin;

	inicio = time(NULL);

	while (Aux != NULL) {
		ListaV = ListaV->PtrSiguiente;
		delete(Aux);
		//Globalfree(Aux);
		Aux = ListaV;
	}

	fin = time(NULL);

	cout << "----------------------------Padron liberado--------------------------------" << endl;
	printf("\nLa liberacion del padron ha tardado : %f segundos.\n", difftime(fin, inicio));
	cout << "----------------------------Padron liberado--------------------------------" << endl;
	system("pause");
}


//Funci?n para inicializar la lista de votantes
void inicializarvotantes(PtrT_Votante& ListaV) {
	ListaV = NULL;
}

PtrT_Votante BuscarVotante(PtrT_Votante& Lista, char cual[9])
{
	bool encontro = false;
	PtrT_Votante Aux;
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