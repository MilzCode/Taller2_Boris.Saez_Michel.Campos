#pragma once
#include "ListaCancionesInicial.h"
#include "NodoLetraInicial.h"


struct nodoP {
	nodoP* siguiente;
	nodoP* anterior;
	Cancion* cancionP;


};
class ListaPersonal
{


public:
	ListaPersonal();
	bool agregarCancionP(Cancion* cancioncita);
	bool eliminarCancionP(Cancion* cancioncita);
	nodoP* getPrimerNodoP();
	nodoP* getUltimoNodoP();

private:

	const int cantMax = 15;
	int cantActual;
	nodoP* ultimo;
	nodoP* primer;
};

