#pragma once
#include "NodoLetraInicial.h"


struct nodosCancionesT10 {
	Cancion* Cancion;
	nodosCancionesT10* siguiente;
};

class ListaTop10
{

public:
	ListaTop10();
	//agrega una cancion solo si esta en el t10 reproducciones true si es que pudo
	void agregarCancionT10(Cancion* cancion);
	//retorna puntero a cancion SOLO PUEDE RETORNAR SI ES MENOR O IGUAL A 10 (0 es la pos 1) sino retorna NULL
	Cancion* getCancion(int pos);

private:
	nodosCancionesT10* top;
	const int cantMax = 10;
	int cantActual;
	void eliminarUltimoNodo();
};

