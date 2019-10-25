#include "ListaPersonal.h"

ListaPersonal::ListaPersonal()
{
	cantActual = 0;
	primer = NULL;
	ultimo = NULL;
}

bool ListaPersonal::agregarCancionP(Cancion* cancioncita)
{
	//si la lista esta llena
	if (cantActual == cantMax) {
		return false;
	}
	//si la lista esta vacia
	if (cantActual == 0) {
		nodoP* n = new nodoP;
		primer = n;
		ultimo = n;
		n->siguiente = NULL;
		n->anterior = NULL;
		n->cancionP = cancioncita;
		cantActual++;
		return true;
	}
	nodoP* n = primer;
	//si la cancion ya se encuentra en la lista personal
	for (int a = 0; a < cantActual; a++) {
		if (n->cancionP == cancioncita) {
			return false;
		}
		if (n->siguiente != NULL) {
			n = n->siguiente;
		}
	}
	nodoP* nuevo = new nodoP;
	nuevo->cancionP = cancioncita;
	
	n->siguiente = nuevo;
	nuevo->anterior = n;
	nuevo->siguiente = NULL;

	ultimo = nuevo;
	cantActual++;

	return true;
	

}

bool ListaPersonal::eliminarCancionP(Cancion* cancioncita)
{
	if (cantActual == 0) {
		return false;
	}
	nodoP* n = primer;
	bool existe = false;
	//si la cancion NO se encuentra en la lista personal de paso busco el nodo
	for (int a = 0; a < cantActual; a++) {
		if (n->cancionP == cancioncita) {
			existe = true;
			break;
		}
		if (n->siguiente != NULL) {
			n = n->siguiente;
		}
	}
	if (!existe) {
		return false;
	}
	if (cantActual == 1) {
		delete primer;
		primer = NULL;
		ultimo = NULL;
		cantActual = 0;
		return true;
	}
	//porque es top
	if (n->anterior == NULL) {
		primer = n->siguiente;
		primer->anterior = NULL;
		cantActual--;
		delete n;
		return true;
	}
	//porque es ultimo
	if (n->siguiente == NULL) {
		ultimo = n->anterior;
		ultimo->siguiente = NULL;
		cantActual--;
		delete n;
		return true;
	}

	//sino esta entre 2 nodos

	nodoP* atras = n->anterior;
	nodoP* adelante = n->siguiente;
	delete n;
	cantActual--;
	atras->siguiente = adelante;
	adelante->anterior = atras;
	return true;

}

nodoP* ListaPersonal::getPrimerNodoP()
{
	return primer;
}

nodoP* ListaPersonal::getUltimoNodoP()
{
	return ultimo;
}
