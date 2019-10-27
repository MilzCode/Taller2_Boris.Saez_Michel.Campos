#include "ListaPersonal.h"

ListaPersonal::ListaPersonal()
{
	cantActual = 0;
	primer = NULL;
	ultimo = NULL;
}

short ListaPersonal::agregarCancionP(Cancion* cancioncita)
{
	//si la lista esta llena
	if (cantActual == cantMax) {
		return 1;
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
		return 3;
	}
	nodoP* n = primer;
	//si la cancion ya se encuentra en la lista personal
	while (n!=NULL) {
		if (n->cancionP == cancioncita) {
			return 2;
		}
		if (n->siguiente != NULL) {
			n = n->siguiente;
		}
		else {
			break;
		}
		

	}
	nodoP* nuevo = new nodoP;
	nuevo->cancionP = cancioncita;
	
	n->siguiente = nuevo;
	nuevo->anterior = n;
	nuevo->siguiente = NULL;

	ultimo = nuevo;
	cantActual++;

	return 3;
	

}

bool ListaPersonal::eliminarCancionP(Cancion* cancioncita)
{
	if (primer == NULL) {
		return false;
	}
	nodoP* n = primer;
	bool existe = false;
	//si la cancion NO se encuentra en la lista personal de paso busco el nodo
	while (n!=NULL) {
		if (n->cancionP == cancioncita) {
			existe = true;
			break;
		}

		n = n->siguiente;
		
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

bool ListaPersonal::existeCancion(Cancion* cancioncita)
{
	nodoP* n = primer;
	//si la cancion ya se encuentra en la lista personal
	while(n!=NULL) {
		if (n->cancionP == cancioncita) {
			return true;
		}

		n = n->siguiente;

	}
	return false;
}

nodoP* ListaPersonal::getPrimerNodoP()
{
	return primer;
}

nodoP* ListaPersonal::getUltimoNodoP()
{
	return ultimo;
}
