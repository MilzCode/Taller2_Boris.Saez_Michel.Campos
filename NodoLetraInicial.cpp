#include "NodoLetraInicial.h"

NodoLetraInicial::NodoLetraInicial(string letra)
{
	this->letra = letra;
	this->siguienteLetra = NULL;
	this->anteriorLetra = NULL;
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

NodoLetraInicial* NodoLetraInicial::getAnteriorNodo()
{
	return anteriorLetra;
}

//cambia el nodo siguiente enviando la direccion del nuevo nodo por parametro
bool NodoLetraInicial::setSiguienteNodo(NodoLetraInicial*nodo)
{
	siguienteLetra = nodo;
	return true;
}

bool NodoLetraInicial::setAnteriorNodo(NodoLetraInicial* nodo)
{
	anteriorLetra = nodo;
	return true;
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
		top->anterior = NULL;
		ultimo = top;
		return;
	}

	if (buscando->Cancion->getTitulo().compare(cancion.getTitulo()) > 0) {
		top->anterior = n;
		n->siguiente = top;
		n->anterior = NULL;
		top = n;
		return;
	}

	while (true) {

		if (buscando->Cancion->getTitulo().compare(cancion.getTitulo()) == 0) {
			
			n->siguiente = buscando->siguiente;
			if (buscando->siguiente != NULL) {
				(buscando->siguiente)->anterior = n;
			}
			else {
				ultimo = n;
			}

			buscando->siguiente = n;
			n->anterior = buscando;
			return;
		}


		if (buscando->Cancion->getTitulo().compare(cancion.getTitulo()) < 0) {
			if (buscando->siguiente == NULL) {

				buscando->siguiente = n;
				n->anterior = buscando;

				n->siguiente = NULL;
				ultimo = n;
				return;
			}
			//si el siguiente del nodo buscando es mayor entonces el nodo n debe ir entre el buscando y el siguiente de este
			else if (buscando->siguiente->Cancion->getTitulo().compare(cancion.getTitulo()) > 0) {

				n->siguiente = buscando->siguiente;
				if (buscando->siguiente != NULL) {
					(buscando->siguiente)->anterior = n;
				}
				else {
					ultimo = n;
				}

				buscando->siguiente = n;
				n->anterior = buscando;
				return;
			}
		}

		buscando = buscando->siguiente;
	}
}


nodosCanciones* NodoLetraInicial::getCancionNodo(string titulo)
{
	if (top == NULL) {
		return NULL;
	}

	nodosCanciones* n = top;

	while (true)
	{
		if (n->Cancion->getTitulo().compare(titulo) == 0) {
			return n;
		}
		n = n->siguiente;

		if (n == NULL) {
			break;
		}
		
	}
	return NULL;
}

nodosCanciones* NodoLetraInicial::getCancionNodoUltima()
{
	return ultimo;
}

nodosCanciones* NodoLetraInicial::getCancionNodoPrimera()
{
	return top;
}

