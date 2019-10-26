#pragma once
#include "NodoLetraInicial.h"
#include "ListaGeneros.h"
#include "ListaT10.h"

#include "Cancion.h"

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>//leer archivos
#include <codecvt>//para convertir a wstring
#include "Trim.h"



class ListaCancionesInicial
{

public:
	ListaCancionesInicial();
	NodoLetraInicial* getCancion(string nombre);
	NodoLetraInicial* getPrimeraLetra();
	NodoLetraInicial* getUltimaLetra();
	ListaT10* getTop10();
	ListaGeneros* getListaGeneros();

private:

	bool lecturaCanciones(string nombreArchivo);

	ListaT10* listaT10 = new ListaT10();
	ListaGeneros* listaG = new ListaGeneros();
	NodoLetraInicial* primer;
	NodoLetraInicial* ultima;
	//ACCEDE A UNA SUBLISTA DE INICIALES INGRESANDO LA CANCION EN UNA DE ESAS LISTAS POR ORDEN ALFABETICO
	void agregarCancion(string _titulo, string _artista, string _genero, string _anno, int _reproducciones);
	Trim trim;
};

