#pragma once
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