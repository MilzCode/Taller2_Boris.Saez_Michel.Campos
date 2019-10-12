#include "NodoLetraInicial.h"

NodoLetraInicial::NodoLetraInicial(string letra)
{
	this->letra = letra;
	this->siguienteLetra = NULL;
	this->top = NULL;
}
//retorna la letra inicial del contenido del nodo
string NodoLetraInicial::getLetra()
{
	return letra;
}
//retorna el nodo siguiente si no existe retorna NULL
NodoLetraInicial* NodoLetraInicial::getSiguienteNodo()
{
	return siguienteLetra;
}

//cambia el nodo siguiente enviando la direccion del nuevo nodo por parametro
bool NodoLetraInicial::setSiguienteNodo(NodoLetraInicial*nodo)
{
	siguienteLetra = nodo;
	return true;
}

int NodoLetraInicial::buscarCancion(string tituloCancion)
{
	if (top == NULL) {
		return -1;
	}

	nodosCanciones* n = top;
	int c = 0;
	while (true)
	{
		if (n->Cancion->getTitulo().compare(tituloCancion) == 0) {
			return c;
		}
		n = n->siguiente;

		if (n == NULL) {
			break;
		}
		c++;
	}
	return -1;
}

//inserta una cancion en orden segun el titulo
void NodoLetraInicial::agregarCancion(Cancion& cancion)
{
	nodosCanciones* buscando = top;

	nodosCanciones* n = new nodosCanciones;

	n->Cancion = &cancion;

	if (buscando == NULL) {
		top = n;
		top->siguiente = NULL;
		return;
	}

	if (buscando->Cancion->getTitulo().compare(cancion.getTitulo()) > 0) {
		n->siguiente = top;
		top = n;
		return;
	}

	while (true) {

		if (buscando->Cancion->getTitulo().compare(cancion.getTitulo()) == 0) {
			n->siguiente = buscando->siguiente;
			buscando->siguiente = n;
			return;
		}


		if (buscando->Cancion->getTitulo().compare(cancion.getTitulo()) < 0) {
			if (buscando->siguiente == NULL) {
				buscando->siguiente = n;
				n->siguiente = NULL;
				return;
			}
			//si el siguiente del nodo buscando es mayor entonces el nodo n debe ir entre el buscando y el siguiente de este
			else if (buscando->Cancion->getTitulo().compare(cancion.getTitulo()) > 0) {
				n->siguiente = buscando->siguiente;
				buscando->siguiente = n;
				return;
			}
		}

		buscando = buscando->siguiente;
	}
}

Cancion* NodoLetraInicial::getCancion(int pos)
{
	if (top == NULL) {
		return NULL;
	}

	nodosCanciones* n = top;
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

