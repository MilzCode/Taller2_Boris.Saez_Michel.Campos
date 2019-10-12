#pragma once
#include "ListaCancionesInicial.h"
#include "Mp3.h"
#include "VerificadorIngreso.h"



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
	ListaCancionesInicial* listaCanciones;
	int verificadorIngreso(int max);
	void printMenus(float imprimirMenuNumero);
	void reproductor(Cancion* cancioncita);
	Mp3 mp3;
	//posee algunas funciones utiles
	VerificadorIngreso v;
};

