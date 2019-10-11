#pragma once
#include "Cancion.h"

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <codecvt>//para convertir a wstring

class ListaCanciones
{

private:
	Cancion** canciones;
	int cantidadCanciones;
	const int maximaCantidadCanciones = 100;
	bool lecturaCanciones(string nombreArchivo);

public:
	ListaCanciones();
	void agregarCancion(string _titulo, string _artista, string _genero, string _anno, int _reproducciones);
	int getCantCanciones();
	int getCantMax();
	Cancion& getCancion(int pos);
};

