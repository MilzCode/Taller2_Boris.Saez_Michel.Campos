#include "ListaTop10.h"

ListaTop10::ListaTop10()
{
	top = NULL;
	cantActual = 0;
}

void ListaTop10::agregarCancionT10(Cancion* cancion)
{

	nodosCancionesT10* buscando = top;

	

	if (buscando == NULL) {
		nodosCancionesT10* n = new nodosCancionesT10;
		top = n;
		top->siguiente = NULL;
		cantActual++;
		return;
	}

	if (cancion->getReproducciones() > top->Cancion->getReproducciones()) {
		nodosCancionesT10* n = new nodosCancionesT10;
		n->siguiente = top;
		top = n;
		cantActual++;
		if (cantActual == cantMax + 1) {
			eliminarUltimoNodo();
		}
		return;
	}
	int c = 0;
	while (true) {

		if (cancion->getReproducciones() == top->Cancion->getReproducciones()) {
			nodosCancionesT10* n = new nodosCancionesT10;
			n->siguiente = top;
			top = n;
			cantActual++;
			if (cantActual == cantMax + 1) {
				eliminarUltimoNodo();
			}
			return;
		}


		if (cancion->getReproducciones() < top->Cancion->getReproducciones()) {
			if (buscando->siguiente == NULL) {
				nodosCancionesT10* n = new nodosCancionesT10;
				buscando->siguiente = n;
				n->siguiente = NULL;
				cantActual++;
				if (cantActual == cantMax + 1) {
					eliminarUltimoNodo();
				}
				return;
			}
			//si el siguiente del nodo buscando es mayor entonces el nodo n debe ir entre el buscando y el siguiente de este
			else if (cancion->getReproducciones() > top->Cancion->getReproducciones()) {
				nodosCancionesT10* n = new nodosCancionesT10;
				n->siguiente = buscando->siguiente;
				buscando->siguiente = n;
				cantActual++;
				if (cantActual == cantMax + 1) {
					eliminarUltimoNodo();
				}
				return;
			}
		}

		buscando = buscando->siguiente;
		
	}
}

Cancion* ListaTop10::getCancion(int pos)
{
	if (pos >= 10) {
		return NULL;
	}
	if (top == NULL) {
		return NULL;
	}

	nodosCancionesT10* n = top;
	int c = 0;
	while (true)
	{
		if (c == pos) {
			return n->Cancion;
		}
		n = n->siguiente;

		if (n == NULL) {
			break;
		}
		c++;
	}
	return NULL;
}

void ListaTop10::eliminarUltimoNodo()
{
	if(cantActual<=10){
		return;
	}
	nodosCancionesT10* n = top;
	int c = 0;
	while (c==(cantMax-1)) {
		n = n->siguiente;
		c++;
	}

	if (n->siguiente != NULL) {
		if (n->siguiente->siguiente == NULL) {
			cout << "Actualizado TOP 10" << endl;
			delete n->siguiente;
			n->siguiente == NULL;
			cantActual--;
			return;
		}
	}
}
