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

/*
	Nodo del Arbol AVL de votantes
	- char cedula[10]: cedula del votante
	- char codelec[7]: codigo electoral del votante
	- char sexo: sexo del votante
	- char fecha[9]: fecha de nacimiento del votante
	- char numjun[6]: numero de junta del votante
	- char nombre[31]: nombre del votante
	- char papellido[27]: primer apellido del votante
	- char sapellido[27]: segundo apellido del votantE
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

void agregarvotante(PtrT_Votante& Raiz, char agregado[118]) {
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

	for (int fe = 18; fe < 26; fe++) {
		Raiz->fecha[fe - 18] = agregado[fe];
	}
	Raiz->fecha[8] = '\0';

	for (int nu = 27; nu < 32; nu++) {
		Raiz->numjun[nu - 27] = agregado[nu];
	}
	Raiz->numjun[5] = '\0';

	for (int no = 33; no < 64; no++) {
		Raiz->nombre[no - 33] = agregado[no];
	}
	Raiz->nombre[31] = '\0';

	for (int pa = 65; pa < 92; pa++) {
		Raiz->papellido[pa - 65] = agregado[pa];
	}
	Raiz->papellido[27] = '\0';

	for (int sa = 93; sa < 120; sa++) {
		Raiz->sapellido[sa - 93] = agregado[sa];
	}
	Raiz->sapellido[27] = '\0';
}

//Funcion para imprimir la lista de votantes
void imprimirvotantes(PtrT_Votante Raiz) {
	PtrT_Votante Aux = Raiz;
	if (Aux != NULL) {
		imprimirvotantes(Aux->PtrIzquierdo);
		cout << "Cedula: " << Aux->cedula << endl;
		cout << "Codigo Electoral: " << Aux->codelec << endl;
		cout << "Sexo: " << Aux->sexo << endl;
		cout << "Fecha de Nacimiento: " << Aux->fecha << endl;
		cout << "Numero de Junta: " << Aux->numjun << endl;
		cout << "Nombre: " << Aux->nombre << endl;
		cout << "Primer Apellido: " << Aux->papellido << endl;
		cout << "Segundo Apellido: " << Aux->sapellido << endl;
		cout << endl;
		imprimirvotantes(Aux->PtrDerecho);
	}
}

//Funcion para buscar un votante por cedula
PtrT_Votante buscarvotante(PtrT_Votante Raiz, char cedula[10]) {
	PtrT_Votante Aux = Raiz;
	while (Aux != NULL) {
		if (strcmp(Aux->cedula, cedula) == 0) {
			return Aux;
		}
		else if (strcmp(cedula, Aux->cedula) < 0) {
			Aux = Aux->PtrIzquierdo;
		}
		else {
			Aux = Aux->PtrDerecho;
		}
	}
	return NULL;
}

//Funcion para eliminar un votante por cedula
void eliminarvotante(PtrT_Votante& Raiz, char cedula[10]) {
	PtrT_Votante Aux = Raiz;
	PtrT_Votante Ant = NULL;
	while (Aux != NULL) {
		if (strcmp(Aux->cedula, cedula) == 0) {
			if (Aux->PtrIzquierdo == NULL && Aux->PtrDerecho == NULL) {
				if (Ant == NULL) {
					Raiz = NULL;
				}
				else if (Ant->PtrIzquierdo == Aux) {
					Ant->PtrIzquierdo = NULL;
				}
				else {
					Ant->PtrDerecho = NULL;
				}
				delete Aux;
			}
			else if (Aux->PtrIzquierdo == NULL) {
				if (Ant == NULL) {
					Raiz = Aux->PtrDerecho;
				}
				else if (Ant->PtrIzquierdo == Aux) {
					Ant->PtrIzquierdo = Aux->PtrDerecho;
				}
				else {
					Ant->PtrDerecho = Aux->PtrDerecho;
				}
				delete Aux;
			}
			else if (Aux->PtrDerecho == NULL) {
				if (Ant == NULL) {
					Raiz = Aux->PtrIzquierdo;
				}
				else if (Ant->PtrIzquierdo == Aux) {
					Ant->PtrIzquierdo = Aux->PtrIzquierdo;
				}
				else {
					Ant->PtrDerecho = Aux->PtrIzquierdo;
				}
				delete Aux;
			}
			else {
				PtrT_Votante Aux2 = Aux->PtrIzquierdo;
				PtrT_Votante Ant2 = Aux;
				while (Aux2->PtrDerecho != NULL) {
					Ant2 = Aux2;
					Aux2 = Aux2->PtrDerecho;
				}
				strcpy(Aux->cedula, Aux2->cedula);
				strcpy(Aux->codelec, Aux2->codelec);
				Aux->sexo = Aux2->sexo;
				strcpy(Aux->fecha, Aux2->fecha);
				strcpy(Aux->numjun, 
					Aux2->numjun);
				strcpy(Aux->nombre, Aux2->nombre);
				strcpy(Aux->papellido, Aux2->papellido);
				strcpy(Aux->sapellido, Aux2->sapellido);
			}
		}
	}
}

//Funcion para liberar la memoria de la lista de votantes
void liberarvotantes(PtrT_Votante& Raiz) {
	PtrT_Votante Aux = Raiz;
	if (Aux != NULL) {
		liberarvotantes(Aux->PtrIzquierdo);
		liberarvotantes(Aux->PtrDerecho);
		delete Aux;
	}
}

//Funcion para obtener la altura de un nodo
int altura(PtrT_Votante Raiz) {
	if (Raiz == NULL) {
		return 0;
	}
	else {
		int izq = altura(Raiz->PtrIzquierdo);
		int der = altura(Raiz->PtrDerecho);
		if (izq > der) {
			return izq + 1;
		}
		else {
			return der + 1;
		}
	}
}

//Funcion para obtener el factor de equilibrio de un nodo
int factorEquilibrio(PtrT_Votante Raiz) {
	if (Raiz == NULL) {
		return 0;
	}
	else {
		return altura(Raiz->PtrIzquierdo) - altura(Raiz->PtrDerecho);
	}
}

//Funcion para rotar a la derecha un nodo
void rotarDerecha(PtrT_Votante& Raiz) {
	PtrT_Votante Aux = Raiz->PtrIzquierdo;
	Raiz->PtrIzquierdo = Aux->PtrDerecho;
	Aux->PtrDerecho = Raiz;
	Raiz = Aux;
}

//Funcion para rotar a la izquierda un nodo
void rotarIzquierda(PtrT_Votante& Raiz) {
	PtrT_Votante Aux = Raiz->PtrDerecho;
	Raiz->PtrDerecho = Aux->PtrIzquierdo;
	Aux->PtrIzquierdo = Raiz;
	Raiz = Aux;
}

//Funcion para balancear un nodo
void balancear(PtrT_Votante& Raiz) {
	if (factorEquilibrio(Raiz) == 2) {
		if (factorEquilibrio(Raiz->PtrIzquierdo) == -1) {
			rotarIzquierda(Raiz->PtrIzquierdo);
		}
		rotarDerecha(Raiz);
	}
	else if (factorEquilibrio(Raiz) == -2) {
		if (factorEquilibrio(Raiz->PtrDerecho) == 1) {
			rotarDerecha(Raiz->PtrDerecho);
		}
		rotarIzquierda(Raiz);
	}
}

//Funcion para agregar un nodo al arbol AVL
void agregarAVL(PtrT_Votante& Raiz, char agregado[118]) {
	if (Raiz == NULL) {
		agregarvotante(Raiz, agregado);
	}
	else {
		if (strcmp(agregado, Raiz->cedula) < 0) {
			agregarAVL(Raiz->PtrIzquierdo, agregado);
		}
		else {
			agregarAVL(Raiz->PtrDerecho, agregado);
		}
		balancear(Raiz);
	}
}

//Funcion para eliminar un nodo del arbol AVL
void eliminarAVL(PtrT_Votante& Raiz, char cedula[10]) {
	if (Raiz == NULL) {
		return;
	}
	if (strcmp(cedula, Raiz->cedula) < 0) {
		eliminarAVL(Raiz->PtrIzquierdo, cedula);
	}
	else if (strcmp(cedula, Raiz->cedula) > 0) {
		eliminarAVL(Raiz->PtrDerecho, cedula);
	}
	else {
		if (Raiz->PtrIzquierdo == NULL && Raiz->PtrDerecho == NULL) {
			delete Raiz;
			Raiz = NULL;
		}
		else if (Raiz->PtrIzquierdo == NULL) {
			PtrT_Votante Aux = Raiz;
			Raiz = Raiz->PtrDerecho;
			delete Aux;
		}
		else if (Raiz->PtrDerecho == NULL) {
			PtrT_Votante Aux = Raiz;
			Raiz = Raiz->PtrIzquierdo;
			delete Aux;
		}
		else {
			PtrT_Votante Aux = Raiz->PtrDerecho;
			while (Aux->PtrIzquierdo != NULL) {
				Aux = Aux->PtrIzquierdo;
			}
			strcpy(Raiz->cedula, Aux->cedula);
			strcpy(Raiz->codelec, Aux->codelec);
			Raiz->sexo = Aux->sexo;
			strcpy(Raiz->fecha, Aux->fecha);
			strcpy(Raiz->numjun, Aux->numjun);
			strcpy(Raiz->nombre, Aux->nombre);
			strcpy(Raiz->papellido, Aux->papellido);
			strcpy(Raiz->sapellido, Aux->sapellido);
			eliminarAVL(Raiz->PtrDerecho, Aux->cedula);
		}
	}
	balancear(Raiz);
}

//Funcion para buscar un votante por cedula en el arbol AVL
PtrT_Votante buscarAVL(PtrT_Votante Raiz, char cedula[10]) {
	if (Raiz == nullptr) {
		return nullptr;
	}
	if (strcmp(Raiz->cedula, cedula) == 0) {
		return Raiz;
	}
	if (strcmp(cedula, Raiz->cedula) < 0) {
		return buscarAVL(Raiz->PtrIzquierdo, cedula);
	}
	else {
		return buscarAVL(Raiz->PtrDerecho, cedula);
	}
}

//Funcion para liberar la memoria de un arbol AVL
void liberarAVL(PtrT_Votante& Raiz) {
	if (Raiz == NULL) {
		return;
	}
	liberarAVL(Raiz->PtrIzquierdo);
	liberarAVL(Raiz->PtrDerecho);
	delete Raiz;
}

//Funcion para imprimir el arbol AVL
void imprimirAVL(PtrT_Votante Raiz) {
	if (Raiz != NULL) {
		imprimirAVL(Raiz->PtrIzquierdo);
		cout << "Cedula: " << Raiz->cedula << endl;
		cout << "Codigo Electoral: " << Raiz->codelec << endl;
		cout << "Sexo: " << Raiz->sexo << endl;
		cout << "Fecha de Nacimiento: " << Raiz->fecha << endl;
		cout << "Numero de Junta: " << Raiz->numjun << endl;
		cout << "Nombre: " << Raiz->nombre << endl;
		cout << "Primer Apellido: " << Raiz->papellido << endl;
		cout << "Segundo Apellido: " << Raiz->sapellido << endl;
		cout << endl;
		imprimirAVL(Raiz->PtrDerecho);
	}
}

//Funcion para cargar los votantes del padron electoral en un arbol AVL
void cargarVotantesAVL(PtrT_Votante& Raiz) {
	FILE* archivo;
	char agregado[118];
	archivo = fopen("padron.txt", "r");
	if (archivo == NULL) {
		cout << "Error al abrir el archivo" << endl;
	}
	else {
		while (!feof(archivo)) {
			fgets(agregado, 118, archivo);
			agregarAVL(Raiz, agregado);
		}
	}
	fclose(archivo);
}

//Funcion para guardar los votantes del arbol AVL en un archivo de texto a parte
void guardarVotantesAVL(PtrT_Votante Raiz) {
	FILE* archivo;
	archivo = fopen("VotantesAVL.txt", "w");
	if (archivo == NULL) {
		cout << "Error al abrir el archivo" << endl;
	}
	else {
		imprimirAVL(Raiz);
	}
	fclose(archivo);
}