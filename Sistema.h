#pragma once
#include "ListaCancionesInicial.h"
#include "Mp3.h"
#include "VerificadorIngreso.h"
#include "ListaPersonal.h"



#include <string>
#include <iostream>

#include <conio.h>
#include <chrono>
#include <thread>

#include<stdlib.h>
#include<fstream>

class Sistema
{

public:
	Sistema();
	void ejecutarSistema();




private:


	void playListT10();
	void personalPlaylist();
	ListaCancionesInicial* listaCanciones;
	ListaPersonal* listaPersonales;
	int verificadorIngreso(int max);
	void printMenus(float imprimirMenuNumero);
	int reproductor(Cancion* cancioncita, int modo);
	Mp3 mp3;
	//posee algunas funciones utiles
	VerificadorIngreso v;
	//lamaremos modo 0, al modo normal, modo 1 al modo playlistT10, y modo 2 al modo playlist personal
	void menuReproduccion(int modo,Cancion* cancioncita);
	void escribirArchivoEstadisticas(string nombreArchivo, char separador);
	void actualizarCanciones(string nombreArchivo, char separador);
	Trim trim;
	Cancion* buscarCancionPorNombre();
};

