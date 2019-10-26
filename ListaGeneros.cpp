#include "ListaGeneros.h"


ListaGeneros::ListaGeneros()
{
	top = NULL;
	ultimo = NULL;
	cantActual = 0;
}

void ListaGeneros::agregarGenero(string genero, int cantidadReproducciones)
{
	if (top == NULL) {
		nodoG* n = new nodoG;
		n->genero = genero;
		n->cantidadReproducciones = cantidadReproducciones;
		n->anterior = NULL;
		n->siguiente = NULL;
		top = n;
		ultimo = n;
		cantActual++;
		return;
	}
	bool existe = false;
	nodoG* buscando = top;

	for (int a = 0; a < cantActual; a++) {
		if ((buscando->genero).compare(genero) == 0) {
			existe = true;
			break;
		}
		if (buscando->siguiente != NULL) {
			buscando = buscando->siguiente;
		}
	}
	if (!existe) {
		nodoG* n = new nodoG;
		n->genero = genero;
		n->cantidadReproducciones = cantidadReproducciones;

		if (cantidadReproducciones > top->cantidadReproducciones) {
			top->anterior = n;
			n->siguiente = top;
			n->anterior = NULL;
			top = n;
			cantActual++;
			return;
		}
		//ahora buscar entremedio
		buscando = top;
		while (true) {
			//si coinciden con alguna cantidad de reproducciones
			if (cantidadReproducciones == buscando->cantidadReproducciones) {
				nodoG* adelante = buscando->siguiente;
				if (adelante != NULL) {
					adelante->anterior = n;
					ultimo = n;
				}
				buscando->siguiente = n;
				n->anterior = buscando;
				n->siguiente = adelante;
				return;
			}
			//si el nodo a ingresar es menor que el nodo buscado actual
			if (cantidadReproducciones < buscando->cantidadReproducciones) {
				//que el nodo siguiente al buscado NULL
				if (buscando->siguiente == NULL) {
					n->siguiente = NULL;
					n->anterior = buscando;
					buscando->siguiente = n;
					ultimo = n;
					cantActual++;
					return;
				}
				//que el nodo siguiente al buscado sea menor (se ingresa entre esos 2)
				if (cantidadReproducciones > buscando->siguiente->cantidadReproducciones) {
					nodoG* adelante = buscando->siguiente;
					buscando->siguiente = n;
					n->anterior = buscando;
					n->siguiente = adelante;
					adelante->anterior = n;
					cantActual++;
					return;
				}
			}
			buscando = buscando->siguiente;
		}
	}
	//si ya esta el genero
	else {
		
		buscando->cantidadReproducciones += cantidadReproducciones;
		actualizarGenero(buscando);
	}
}

int ListaGeneros::getCantActual()
{
	return cantActual;
}

nodoG* ListaGeneros::getPrimerG()
{
	return top;
}

void ListaGeneros::actualizarGenero(nodoG* actualizar)
{
	if (actualizar->anterior == NULL) {
		top = actualizar;
		return;
	}
	if (actualizar->anterior->cantidadReproducciones > actualizar->cantidadReproducciones) {
		return;
	}
	
	nodoG* atras = actualizar->anterior;
	nodoG* atrasDAtras = atras->anterior;
	nodoG* adelante = actualizar->siguiente;

	if (adelante != NULL) {
		adelante->anterior = atras;
	}
	else {
		ultimo = atras;
	}
	if (atrasDAtras != NULL) {
		atrasDAtras->siguiente = actualizar;
	}
	else {
		top = actualizar;
	}
	actualizar->anterior = atrasDAtras;
	actualizar->siguiente = atras;
	atras->anterior = actualizar;
	atras->siguiente = adelante;
	actualizarGenero(actualizar);

}
