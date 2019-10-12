#pragma once
#include "Cancion.h"
#include <iostream>

struct nodosCanciones {
	Cancion* Cancion;
	nodosCanciones* siguiente;
	nodosCanciones* anterior;

};

class NodoLetraInicial
{


public:
	NodoLetraInicial(string letra);

	string getLetra();

	NodoLetraInicial* getSiguienteNodo();
	NodoLetraInicial* getAnteriorNodo();

	bool setSiguienteNodo(NodoLetraInicial*);
	bool setAnteriorNodo(NodoLetraInicial*);

	//de aca abajo estaran los contenidos del nodo Letra Inicial


	//Agrega Cancion En orden alfabetico
	void agregarCancion(Cancion& cancion);
	


	//retorna puntero a cancion
	nodosCanciones* getCancionNodo(string titulo);
	nodosCanciones* getCancionNodoUltima();
	nodosCanciones* getCancionNodoPrimera();

private:
	string letra;
	NodoLetraInicial* siguienteLetra;
	NodoLetraInicial* anteriorLetra;
	nodosCanciones* top;
	nodosCanciones* ultimo;
};

