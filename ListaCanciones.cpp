#include "ListaCanciones.h"


bool ListaCanciones::lecturaCanciones(string nombreArchivo)
{
	ifstream archivo;
	int linea = 0;
	bool lecturaCorrecta = false;

	archivo.open(nombreArchivo.c_str(), ios::in); //Abrimos el archivo en modo lectura

	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo"<<endl;
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

		try {
			reproducciones = stoi(_reproducciones);
			lecturaCorrecta = true;
		}
		catch (...) {
			lecturaCorrecta = false;
			cout << "Error en linea : " <<linea<<" Archivo : " <<nombreArchivo<< endl;
			system("pause");
		}
		if (lecturaCorrecta) {
			agregarCancion(titulo, artista, genero, anno, reproducciones);
			cantidadCanciones++;
		}
		linea++;
	}


	archivo.close(); //Cerramos el archivo
	return true;
}

ListaCanciones::ListaCanciones()
{
	canciones = new Cancion*[maximaCantidadCanciones];
	cantidadCanciones = 0;
	string archivoCanciones = "Canciones.txt";
	if (lecturaCanciones(archivoCanciones)) {
		cout << "Lectura Correcta de " <<archivoCanciones<< endl;
	}
}

void ListaCanciones::agregarCancion(string _titulo, string _artista, string _genero, string _anno, int _reproducciones)
{
	Cancion* cancioncita = new Cancion(_titulo, _artista, _genero, _anno, _reproducciones);

	canciones[cantidadCanciones] = cancioncita;

}

int ListaCanciones::getCantCanciones()
{
	return cantidadCanciones;
}

int ListaCanciones::getCantMax()
{
	return maximaCantidadCanciones;
}

Cancion& ListaCanciones::getCancion(int pos)
{
	return *canciones[pos];
}
