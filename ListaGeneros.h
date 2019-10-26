#pragma once
#include <string>
using namespace std;

struct nodoG {
	string genero;
	int cantidadReproducciones;
	nodoG* siguiente;
	nodoG* anterior;
};


class ListaGeneros
{
public:
	ListaGeneros();
	void agregarGenero(string genero, int cantidadReproducciones);
	int getCantActual();
	nodoG* getPrimerG();
	
private:
	nodoG* top;
	nodoG* ultimo;
	bool actualizando = false;
	int cantActual;
	//ordena de mayor a menor los generos
	void actualizarGenero(nodoG* actualizar);
};

