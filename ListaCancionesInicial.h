#pragma once
#include "NodoLetraInicial.h"
#include "ListaTop10.h"

#include "Cancion.h"

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>//leer archivos
#include <codecvt>//para convertir a wstring



class ListaCancionesInicial
{

public:
	ListaCancionesInicial();
	ListaTop10& getListaTop10();

private:

	ListaTop10* listaTop10;
	bool lecturaCanciones(string nombreArchivo);

	//ACCEDE A UNA SUBLISTA DE INICIALES INGRESANDO LA CANCION EN UNA DE ESAS LISTAS POR ORDEN ALFABETICO
	void agregarCancion(string _titulo, string _artista, string _genero, string _anno, int _reproducciones);
	NodoLetraInicial* primer;

};

