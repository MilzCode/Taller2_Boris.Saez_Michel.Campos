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
	//retorna 1 llena, 2 ya existe, 3 todo ok
	short agregarCancionP(Cancion* cancioncita);
	bool eliminarCancionP(Cancion* cancioncita);
	bool existeCancion(Cancion* cancioncita);
	nodoP* getPrimerNodoP();
	nodoP* getUltimoNodoP();
	

private:

	const int cantMax = 15;
	int cantActual;
	nodoP* ultimo;
	nodoP* primer;
};

