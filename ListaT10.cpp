#include "ListaT10.h"

void ListaT10::eliminarUltimo()
{
	if(cantActual<=cantMax){
		return;
	}
	nodoT10* eliminar = ultimo;
	ultimo = ultimo->anterior;
	ultimo->siguiente = NULL;
	delete eliminar;
	cantActual--;
}

void ListaT10::actualizarT10(Cancion* cancion)
{
	if (!actualizando) {
		cancion->suma1Reproduccion(1);
	}

	if (cancion == top->cancionT10) {
		actualizando = false;
		return;
	}
	bool estaEnT10 = false;
	
	nodoT10* buscando = top;
	for (int i = 0; i < cantMax; i++) {
		if (cancion == buscando->cancionT10) {
			estaEnT10 = true;
			break;
		}
		buscando = buscando->siguiente;
	}
	if (estaEnT10) {
		//si la cancion es mayor que su anterior (es decir la que esta mas arriba en el top) habra que ordenar usaremos recursividad
		if (buscando->anterior->cancionT10->getReproducciones() < buscando->cancionT10->getReproducciones()) {
			actualizando = true;

			nodoT10* anterior = buscando->anterior;
			nodoT10* anteriorAanterior = anterior->anterior;
			nodoT10* siguiente = buscando->siguiente;

			//buscando = es el nodo que tenemos que cambiar
			if (anterior->anterior== NULL) {
				top = buscando;
			}
			else {
				anteriorAanterior->siguiente = buscando;
			}
			anterior->siguiente = siguiente;

			if (siguiente != NULL) {
				siguiente->anterior = anterior;
			}
			else {
				ultimo = anterior;
			}
			buscando->siguiente = anterior;
			buscando->anterior = anteriorAanterior;
			
			anterior->anterior = buscando;
			
			actualizarT10(cancion);
		}
		else {
			actualizando = false;
			return;
		}
		return;
	}
	else {
		agregarCancionT10(cancion);
		actualizando = false;
		return;
	}
}

ListaT10::ListaT10()
{
	top = NULL;
	ultimo = NULL;

	cantActual = 0;
}

void ListaT10::agregarCancionT10(Cancion* cancion)
{
	nodoT10* n = new nodoT10;
	
	if (this->top == NULL) {
		
		n->cancionT10 = cancion;
		
		top = n;
		ultimo = n;
		top->anterior = NULL;
		top->siguiente = NULL;

		cantActual++;

		return;
	}
	//verifica si supera a algun top 10
	if (cancion->getReproducciones() < ultimo->cancionT10->getReproducciones() && cantActual == cantMax) {
		return;
	}

	if (cancion->getReproducciones() > top->cancionT10->getReproducciones()) {
		n->cancionT10 = cancion;
		n->siguiente = top;
		top->anterior = n;

		n->anterior = NULL;

		top = n;
		cantActual++;
		eliminarUltimo();
		return;
	}

	//ahora buscaremos entremedio de la lista su posicion correspondiente
	nodoT10* buscando = top;

	while (true) {

		//si coinciden con alguna cantidad de reproducciones
		if (cancion->getReproducciones() == buscando->cancionT10->getReproducciones()) {
			n->cancionT10 = cancion;
			n->siguiente = buscando->siguiente;
			if (buscando->siguiente != NULL) {
				(buscando->siguiente)->anterior = n;
			}
			buscando->siguiente = n;
			n->anterior = buscando;
			cantActual++;
			eliminarUltimo();
			return;
		}

		//si el nodo a ingresar es menor que el nodo buscado actual
		if (cancion->getReproducciones() < buscando->cancionT10->getReproducciones()) {
			//que el nodo siguiente al buscado sea NULL
			if (buscando->siguiente == NULL) {
				n->cancionT10 = cancion;
				n->siguiente = buscando->siguiente;
				buscando->siguiente = n;
				n->anterior = buscando;
				cantActual++;
				eliminarUltimo();
				return;
			}
			//que el nodo siguiente al buscado sea menor (se ingresa entre esos 2)
			if (cancion->getReproducciones() > buscando->siguiente->cancionT10->getReproducciones()) {
				n->cancionT10 = cancion;
				(buscando->siguiente)->anterior = n;
				n->siguiente = buscando->siguiente;
				buscando->siguiente = n;
				n->anterior = buscando;
				cantActual++;
				eliminarUltimo();
				return;
			}

			buscando = buscando->siguiente;

		}

	}

}

nodoT10* ListaT10::getTopNodoT10()
{
	return top;
}

nodoT10* ListaT10::getUltimoNodoT10()
{
	return ultimo;
}
