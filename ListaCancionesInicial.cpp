#include "ListaCancionesInicial.h"

ListaCancionesInicial::ListaCancionesInicial()
{
	primer = NULL;
	string archivoCanciones = "Canciones.txt";
	if (lecturaCanciones(archivoCanciones)) {
		cout << "Lectura Correcta de " << archivoCanciones << endl;
	}
	listaTop10 = new ListaTop10();
}

ListaTop10& ListaCancionesInicial::getListaTop10()
{
	return *listaTop10;
}

Cancion* ListaCancionesInicial::getCancion(string nombre)
{
	string letra = nombre;
	letra = letra.at(0);
	NodoLetraInicial* n = primer;
	if (primer == NULL) {
		return NULL;
	}
	while (true) {
		if (n->getLetra().compare(letra) == 0) {
			return  n->getCancion(nombre);
		}
		n = n->getSiguienteNodo();
		if (n == NULL) {
			break;
		}
	}
	return NULL;
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

		string titulo;//parsearlo a wstring
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
			cout << "Error en linea : " << linea << " Archivo : " << nombreArchivo << endl;
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

	//listaTop10->agregarCancionT10(cancioncita);

	string letra = _titulo;
	letra = letra.at(0);	

	NodoLetraInicial* buscando = primer;


	if (buscando == NULL) {
		NodoLetraInicial* n = new NodoLetraInicial(letra);
		primer = n;
		primer->setSiguienteNodo(NULL);

		n->agregarCancion(*cancioncita);

		return;
	}

	if (buscando->getLetra().compare(letra) > 0) {
		NodoLetraInicial* n = new NodoLetraInicial(letra);
		n->setSiguienteNodo(primer);
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
				buscando->setSiguienteNodo(n);
				n->setSiguienteNodo(NULL);

				n->agregarCancion(*cancioncita);

				return;
			}
			//si el siguiente del nodo buscando es mayor entonces el nodo n debe ir entre el buscando y el siguiente de este
			else if (buscando->getSiguienteNodo()->getLetra().compare(letra) > 0) {
				NodoLetraInicial* n = new NodoLetraInicial(letra);
				n->setSiguienteNodo(buscando->getSiguienteNodo());

				buscando->setSiguienteNodo(n);

				n->agregarCancion(*cancioncita);
	
				return;
			}
		}

		buscando = buscando->getSiguienteNodo();
	}

}
