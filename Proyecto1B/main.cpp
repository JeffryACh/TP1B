#include "listaSimpleVotantes.cpp"

using namespace std;

void main()
{
	// Cargar votantes a la lista simple
	PtrT_VotanteDoble ListaVotantes = nullptr;
	cargarVotantes();
	// Ordenar votantes por cedula
	OrdenarVotantes(ListaVotantes);
	// Mostrar votantes
	mostrarVotantes(ListaVotantes);
	// Liberar memoria de la lista de votantes
	LiberarVotantes(ListaVotantes);

	system("pause");
}