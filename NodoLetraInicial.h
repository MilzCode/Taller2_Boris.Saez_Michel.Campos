#pragma once
#include "Cancion.h"
#include <iostream>

struct nodosCanciones {
	Cancion* Cancion;
	nodosCanciones* siguiente;
};

class NodoLetraInicial
{


public:
	NodoLetraInicial(string letra);

	string getLetra();

	NodoLetraInicial* getSiguienteNodo();

	bool setSiguienteNodo(NodoLetraInicial*);

	//de aca abajo estaran los contenidos del nodo Letra Inicial

	//OJOOOOOO QUIZA ESTE METODO NO SIRVA
	//devuelve -1 sino encuentra alguna cancion
	//int buscarCancion(string tituloCancion);

	//Agrega Cancion En orden alfabetico
	void agregarCancion(Cancion& cancion);
	
	//retorna puntero a cancion OJO QUIZA ESTE METODO NO SIRVA
	//Cancion* getCancion(int pos);

	//retorna puntero a cancion
	Cancion* getCancion(string titulo);

private:
	string letra;
	NodoLetraInicial* siguienteLetra;
	nodosCanciones* top;

};

