#include "ListaCancionesInicial.h"

ListaCancionesInicial::ListaCancionesInicial()
{
	primer = NULL;
	string archivoCanciones = "Canciones.txt";
	if (lecturaCanciones(archivoCanciones)) {
		cout << "Lectura Correcta de " << archivoCanciones << endl;
	}

}


NodoLetraInicial* ListaCancionesInicial::getCancion(string nombre)
{
	string letra = nombre;
	letra = letra.at(0);
	NodoLetraInicial* n = primer;
	if (primer == NULL) {
		return NULL;
	}
	while (true) {
		if (n->getLetra().compare(letra) == 0) {
			return  n;
		}
		n = n->getSiguienteNodo();
		if (n == NULL) {
			break;
		}
	}
	return NULL;
}

NodoLetraInicial* ListaCancionesInicial::getPrimeraLetra()
{
	return primer;
}

NodoLetraInicial* ListaCancionesInicial::getUltimaLetra()
{
	return ultima;
}

ListaT10* ListaCancionesInicial::getTop10()
{
	return listaT10;
}

//metodo para lectura de canciones asi todos los titulos quedaran en mayuscula
template<typename C>
void toUpper2(basic_string<C>& s, const locale& loc = locale()) {
	typename basic_string<C>::iterator p;
	for (p = s.begin(); p != s.end(); ++p) {
		*p = use_facet<ctype<C> >(loc).toupper(*p);
	}
}

//abre archivo de canciones

bool ListaCancionesInicial::lecturaCanciones(string nombreArchivo)
{
	ifstream archivo;
	int linea = 0;
	bool lecturaCorrecta = false;

	archivo.open(nombreArchivo.c_str(), ios::in); //Abrimos el archivo en modo lectura

	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo" << endl;
		return false;
	}
	//Aca los datos a obtener linea por linea
	while (!archivo.eof()) { //mientras no sea final del archivo

		string titulo;
		string artista;
		string genero;
		string anno;
		string _reproducciones;//parsearlo a int

		int reproducciones;

		getline(archivo, titulo, ',');
		getline(archivo, artista, ',');
		getline(archivo, genero, ',');
		getline(archivo, anno, ',');
		getline(archivo, _reproducciones);
		toUpper2(titulo);

		try {
			reproducciones = stoi(_reproducciones);
			lecturaCorrecta = true;
		}
		catch (...) {
			lecturaCorrecta = false;
			cout << "Error en linea : " << linea+1 << " Archivo : " << nombreArchivo << endl;
			system("pause");
		}
		if (lecturaCorrecta) {
			agregarCancion(titulo, artista, genero, anno, reproducciones);
		}
		linea++;
	}


	archivo.close(); //Cerramos el archivo
	return true;
}

void ListaCancionesInicial::agregarCancion(string _titulo, string _artista, string _genero, string _anno, int _reproducciones)
{
	Cancion* cancioncita = new Cancion(_titulo, _artista, _genero, _anno, _reproducciones);

	//de paso vamos agregando a la listaT10 esta misma a su vez se encarga de ingresarlos ordenados y solo manterlo en maximo 10
	listaT10->agregarCancionT10(cancioncita);

	string letra = _titulo;
	letra = letra.at(0);	

	NodoLetraInicial* buscando = primer;


	if (buscando == NULL) {
		NodoLetraInicial* n = new NodoLetraInicial(letra);
		primer = n;
		ultima = n;
		primer->setSiguienteNodo(NULL);
		primer->setAnteriorNodo(NULL);
		n->agregarCancion(*cancioncita);

		return;
	}

	if (buscando->getLetra().compare(letra) > 0) {
		NodoLetraInicial* n = new NodoLetraInicial(letra);
		primer->setAnteriorNodo(n);
		n->setSiguienteNodo(primer);
		n->setAnteriorNodo(NULL);
		primer = n;

		n->agregarCancion(*cancioncita);
		return;
	}

	while (true) {

		if (buscando->getLetra().compare(letra) == 0) {
			buscando->agregarCancion(*cancioncita);
			return;
		}

		if (buscando->getLetra().compare(letra) < 0) {
			if (buscando->getSiguienteNodo() == NULL) {
				NodoLetraInicial* n = new NodoLetraInicial(letra);
				n->setAnteriorNodo(buscando);

				buscando->setSiguienteNodo(n);
				n->setSiguienteNodo(NULL);
				ultima = n;

				n->agregarCancion(*cancioncita);

				return;
			}
			//si el siguiente del nodo buscando es mayor entonces el nodo n debe ir entre el buscando y el siguiente de este
			else if (buscando->getSiguienteNodo()->getLetra().compare(letra) > 0) {
				NodoLetraInicial* n = new NodoLetraInicial(letra);
				n->setSiguienteNodo(buscando->getSiguienteNodo());
				if (buscando->getSiguienteNodo() != NULL) {
					buscando->getSiguienteNodo()->setAnteriorNodo(n);
				}
				else {
					ultima = n;
				}
				n->setAnteriorNodo(buscando);
				buscando->setSiguienteNodo(n);

				n->agregarCancion(*cancioncita);
	
				return;
			}
		}

		buscando = buscando->getSiguienteNodo();
	}

}
