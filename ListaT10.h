#pragma once
#include "Cancion.h"

struct nodoT10 {
	Cancion* cancionT10;
	nodoT10* siguiente;
	nodoT10* anterior;
};

class ListaT10
{

private:
	nodoT10* top;
	nodoT10* ultimo;
	bool actualizando = false;

	// este metodo solo sirve para eliminar el ultimo nodo si la cantidad supera a cantMaxx
	void eliminarUltimo();

	int cantActual;
	const int cantMax = 10;
	
public:
	ListaT10();
	void actualizarT10(Cancion* cancion);
	void agregarCancionT10(Cancion* cancion);

	nodoT10* getTopNodoT10();
	nodoT10* getUltimoNodoT10();
};

