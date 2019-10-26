#include "Sistema.h"

Sistema::Sistema()
{
	listaCanciones = new ListaCancionesInicial();
	listaPersonales = new ListaPersonal();
}
//metodo UPPERCASE;
template<typename C>
void toUpper2(basic_string<C>& s, const locale& loc = locale()) {
	typename basic_string<C>::iterator p;
	for (p = s.begin(); p != s.end(); ++p) {
		*p = use_facet<ctype<C> >(loc).toupper(*p);
	}
}

void Sistema::ejecutarSistema()
{

	while (true) {
		system("cls");
		printMenus(0);
		int opcion_0 = verificadorIngreso(7);

		switch (opcion_0){

			case 1: {
				printMenus(1);
				string cancion;
				v.eliminarBuffer();
				getline(cin, cancion, '\n');
				toUpper2(cancion);

				cout << cancion << endl;

				NodoLetraInicial* cancioncitaNodoLetra;
				nodosCanciones* cancioncitaNodo;
				Cancion* cancioncita;
				try {
					cancioncitaNodoLetra = listaCanciones->getCancion(cancion);
					if (cancioncitaNodoLetra == NULL) {
						cout << "No existen Canciones que inicien con esa Letra" << endl;
						system("pause");
						break;
					}
					cancioncitaNodo = cancioncitaNodoLetra->getCancionNodo(cancion);
					if (cancioncitaNodo == NULL) {
						cout << "No existe la Cancion " <<cancion<<" en el repertorio"<< endl;
						system("pause");
						break;
					}
					
					cancioncita = cancioncitaNodo->Cancion;
				}
				catch (...) {
					break;
				}


				if (cancioncita == NULL) {
					cout << "Cancion " << cancion << " NO encontrada..." << endl;
					system("pause");
				}
				else {
					listaCanciones->getTop10()->actualizarT10(cancioncita);
				
					listaCanciones->getListaGeneros()->agregarGenero(cancioncita->getGenero(), 1);
					int duracionDesdeMensaje = 0;
					bool mensajeAgregado = false;
					reproductor(cancioncita,0);
					char tecla;
					while (true) {
						if (mensajeAgregado && (((int)mp3.GetCurrentPosition() / 10000000) - duracionDesdeMensaje) >= 2) {
							menuReproduccion(0, cancioncita);
							mensajeAgregado = false;
						}
						if (_kbhit()) {
							tecla = _getch();
						}
						else {
							tecla = 'z';
						}
						//si termino reproduce de nuevo
						if (mp3.isFinal()) {
							reproductor(cancioncita, 0);
						}
						//agregar cancion
						if (tecla == '4') {
							short estadoCancion = listaPersonales->agregarCancionP(cancioncita);
							if (estadoCancion == 3) {
								cout << "AGREGADA..." << endl;
								duracionDesdeMensaje = (int)mp3.GetCurrentPosition() / 10000000;
								mensajeAgregado = true;

							}
							else if (estadoCancion == 1) {
								cout << "LISTA LLENA" << endl;
								duracionDesdeMensaje = (int)mp3.GetCurrentPosition() / 10000000;
								mensajeAgregado = true;
							}
							else {
								duracionDesdeMensaje = (int)mp3.GetCurrentPosition() / 10000000;
								mensajeAgregado = true;
							}

						}
						//stop
						if (tecla == '3') {
							mp3.Stop();
							break;
						}
						//siguiente
						if (tecla == '1') {
							mp3.Stop();
							if (cancioncitaNodo->siguiente != NULL) {
								cancioncitaNodo = cancioncitaNodo->siguiente;
							}
							else {
								cancioncitaNodoLetra = cancioncitaNodoLetra->getSiguienteNodo();
								if (cancioncitaNodoLetra == NULL) {
									cancioncitaNodoLetra = listaCanciones->getPrimeraLetra();
								}
								cancioncitaNodo = cancioncitaNodoLetra->getCancionNodoPrimera();
							}

							listaCanciones->getTop10()->actualizarT10(cancioncitaNodo->Cancion);
							cancioncita = cancioncitaNodo->Cancion;
							listaCanciones->getListaGeneros()->agregarGenero(cancioncita->getGenero(), 1);
							reproductor(cancioncitaNodo->Cancion,0);
						}
						//anterior
						if (tecla == '2') {
							mp3.Stop();
							if (cancioncitaNodo->anterior != NULL) {
								cancioncitaNodo = cancioncitaNodo->anterior;
							}
							else {
								cancioncitaNodoLetra = cancioncitaNodoLetra->getAnteriorNodo();
								if (cancioncitaNodoLetra == NULL) {
									cancioncitaNodoLetra = listaCanciones->getUltimaLetra();
								}
								cancioncitaNodo = cancioncitaNodoLetra->getCancionNodoUltima();
							}

							listaCanciones->getTop10()->actualizarT10(cancioncitaNodo->Cancion);
							cancioncita = cancioncitaNodo->Cancion;
							listaCanciones->getListaGeneros()->agregarGenero(cancioncita->getGenero(), 1);
							reproductor(cancioncitaNodo->Cancion,0);
						}

					}
				}
			break;
			}
			//Agregar Cancion a la playlist
			case 2: {

				break;
			}
			//Eliminar Cancion de la playlist
			case 3: {

				break;
			}
			//reproducir playlist
			case 4: {
				printMenus(4);
				int opcion_2 = v.verificadorIngreso(2);
				//top 10
				if (opcion_2 == 1) {
					playListT10();
				}
				//playlist personal
				else {
					personalPlaylist();
				}
				break;
			}
			//buscar cancion
			case 5: {
				printMenus(5);
				string cancion;
				v.eliminarBuffer();
				getline(cin, cancion, '\n');
				toUpper2(cancion);

				NodoLetraInicial* cancioncitaNodoLetra;
				nodosCanciones* cancioncitaNodo;
				Cancion* cancioncita;

				try {
					cancioncitaNodoLetra = listaCanciones->getCancion(cancion);
					if (cancioncitaNodoLetra == NULL) {
						cout << "No existen Canciones que inicien con esa Letra" << endl;
						system("pause");
						break;
					}
					cancioncitaNodo = cancioncitaNodoLetra->getCancionNodo(cancion);
					if (cancioncitaNodo == NULL) {
						cout << "No existe la Cancion " << cancion << " en el repertorio" << endl;
						system("pause");
						break;
					}

					cancioncita = cancioncitaNodo->Cancion;
				}
				catch (...) {
					break;
				}


				if (cancioncita == NULL) {
					cout << "Cancion " << cancion << " NO encontrada..." << endl;
					system("pause");
					break;
				}
				//nombre del título, el artista, género, año y la cantidad de reproducciones.
				else {
					cout << "Nombre: " << cancioncita->getTitulo() << endl;
					cout << "Artista: " << cancioncita->getArtista() << endl;
					cout << "Genero: " << cancioncita->getGenero() << endl;
					cout << "Anno: " << cancioncita->getAnno() << endl;
					cout << "Cantidad Reproducciones: " << cancioncita->getReproducciones() << endl;
					system("pause");
				}
				break;
			}
			case 6: {
				
				nodoG* n = listaCanciones->getListaGeneros()->getPrimerG();
				if (n == NULL) {
					break;
				}
				printMenus(6);
				while(n!=NULL){
					cout << n->genero << " Cantidad de Reproducciones = " << n->cantidadReproducciones << endl;
					n = n->siguiente;
				}
				escribirArchivoEstadisticas("Estadisticas.txt", ',');
				system("pause");

				break;
			}

			//Salir ojo aca hay que actualizar archivo canciones.txt
			case 7: {
				actualizarCanciones("Canciones.txt", ',');
				cout << "Actualizado Archivo Canciones.txt...\n ADIOS :D" << endl;
				system("pause");
				exit(0);
			}


		}
	}

}


void Sistema::playListT10()
{
	Cancion* cancioncita = listaCanciones->getTop10()->getTopNodoT10()->cancionT10;
	nodoT10* cancioncitaNodo = listaCanciones->getTop10()->getTopNodoT10();
	listaCanciones->getTop10()->actualizarT10(cancioncita);
	listaCanciones->getListaGeneros()->agregarGenero(cancioncita->getGenero(), 1);//para agregar 1 reproduccion
	char tecla;
	int duracionDesdeMensaje = 0;
	bool mensajeAgregado= false;
	reproductor(cancioncita, 1);//si es 2 ya existe


	while (true) {
		
		if (mensajeAgregado && (((int)mp3.GetCurrentPosition() / 10000000)-duracionDesdeMensaje)>=2) {
			menuReproduccion(1, cancioncita);
			mensajeAgregado = false;
		}
		if (_kbhit()) {
			tecla = _getch();
		}
		else {
			tecla = 'z';
		}
		//si termino reproduce de nuevo
		if (mp3.isFinal()) {
			reproductor(cancioncita, 1);
		}
		//agregar cancion
		if (tecla == '4') {
			short estadoCancion = listaPersonales->agregarCancionP(cancioncita);
			if (estadoCancion == 3) {
				cout << "AGREGADA..." << endl;
				duracionDesdeMensaje = (int)mp3.GetCurrentPosition() / 10000000;
				mensajeAgregado = true;

			}
			else if (estadoCancion == 1) {
				cout << "LISTA LLENA" << endl;
				duracionDesdeMensaje = (int)mp3.GetCurrentPosition() / 10000000;
				mensajeAgregado = true;
			}
			else {
				duracionDesdeMensaje = (int)mp3.GetCurrentPosition() / 10000000;
				mensajeAgregado = true;
			}
			
		}
		//salir
		if (tecla == '3') {
			mp3.Stop();
			break;
		}
		//siguiente
		if (tecla == '1') {
			mp3.Stop();
			if (cancioncitaNodo->siguiente != NULL) {
				cancioncitaNodo = cancioncitaNodo->siguiente;
			}
			else {
				cancioncitaNodo = listaCanciones->getTop10()->getTopNodoT10();
			}

			listaCanciones->getTop10()->actualizarT10(cancioncitaNodo->cancionT10);
			cancioncita = cancioncitaNodo->cancionT10;
			listaCanciones->getListaGeneros()->agregarGenero(cancioncita->getGenero(), 1);
			reproductor(cancioncitaNodo->cancionT10,1);
		}
		//anterior
		if (tecla == '2') {
			mp3.Stop();
			if (cancioncitaNodo->anterior != NULL) {
				cancioncitaNodo = cancioncitaNodo->anterior;
			}
			else {
				cancioncitaNodo = listaCanciones->getTop10()->getUltimoNodoT10();
			}

			listaCanciones->getTop10()->actualizarT10(cancioncitaNodo->cancionT10);
			cancioncita = cancioncitaNodo->cancionT10;
			listaCanciones->getListaGeneros()->agregarGenero(cancioncita->getGenero(), 1);
			reproductor(cancioncitaNodo->cancionT10,1);
		}

	}
}

void Sistema::personalPlaylist()
{
	if (listaPersonales->getPrimerNodoP() == NULL){
		cout << "La lista de canciones personales esta Vacia" << endl;
		system("pause");
		return;
	}
	nodoP* nodoCancioncita = listaPersonales->getPrimerNodoP();
	Cancion* cancioncita = nodoCancioncita->cancionP;
	listaCanciones->getTop10()->actualizarT10(cancioncita);
	listaCanciones->getListaGeneros()->agregarGenero(cancioncita->getGenero(), 1);
	reproductor(cancioncita, 2);
	char tecla;
	while (true) {
		if (_kbhit()) {
			tecla = _getch();
		}
		else {
			tecla = 'z';
		}
		//si termino reproduce de nuevo
		if (mp3.isFinal()) {
			reproductor(cancioncita, 2);
		}
		//eliminar
		if (tecla == '4') {
			mp3.Stop();
			if (listaPersonales->eliminarCancionP(cancioncita)) {
				cout << "ELIMINADA" << endl;
			}
			if (listaPersonales->getPrimerNodoP() == NULL) {
				return;
			}
			reproductor(listaPersonales->getPrimerNodoP()->cancionP, 2);
			nodoCancioncita = listaPersonales->getPrimerNodoP();
			cancioncita = nodoCancioncita->cancionP;
			
		}
		//stop
		if (tecla == '3') {
			mp3.Stop();
			return;
		}
		//siguiente
		if (tecla == '1') {
			mp3.Stop();
			if (nodoCancioncita->siguiente == NULL) {
				nodoCancioncita = listaPersonales->getPrimerNodoP();
			}
			else {
				nodoCancioncita = nodoCancioncita->siguiente;
			}
			cancioncita = nodoCancioncita->cancionP;
			listaCanciones->getTop10()->actualizarT10(cancioncita);
			reproductor(cancioncita, 2);
			listaCanciones->getListaGeneros()->agregarGenero(cancioncita->getGenero(), 1);
			
		}
		//anterior
		if (tecla == '2') {
			if (nodoCancioncita->anterior == NULL) {
				nodoCancioncita = listaPersonales->getUltimoNodoP();
			}
			else {
				nodoCancioncita = nodoCancioncita->anterior;
			}
			cancioncita = nodoCancioncita->cancionP;
			listaCanciones->getTop10()->actualizarT10(cancioncita);
			listaCanciones->getListaGeneros()->agregarGenero(cancioncita->getGenero(), 1);
			reproductor(cancioncita, 2);
		}
	}

}

int Sistema::verificadorIngreso(int max)
{
	return v.verificadorIngreso(max);
}

void Sistema::printMenus(float imprimir)
{
	//menu principal
	if (imprimir == 0) {
		system("cls");
		cout << "Bienvenido Al Reproductor De Musica UCN!" << endl;
		cout << "------------------------------\n" << endl;
		cout << "Ingrese alguna opcion\n" << endl;
		cout << "[1] Reproducir Cancion" << endl;
		cout << "[2] Agregar Cancion a la playlist" << endl;
		cout << "[3] Eliminar Cancion de la playlist" << endl;
		cout << "[4] Reproducir Playlist" << endl;
		cout << "[5] Buscar Cancion" << endl;
		cout << "[6] Estadisticas" << endl;
		cout << "[7] Salir" << endl;

	}
	//Menu reproduccion (OPCION 1)
	if (imprimir == 1) {
		system("cls");
		cout << "Ingrese Titulo De Cancion Para reproducir...\n : " << endl;
		return;
	}
	//Menu reproduccion(CONTROLES)
	if (imprimir == 1.5) {
		cout << "Ingrese alguna opcion\n" << endl;
		cout << "[1] Siguiente" << endl;
		cout << "[2] Anterior" << endl;
		cout << "[3] Stop" << endl;
		return;
	}
	//Reproducir Playlist
	if (imprimir == 4) {
		system("cls");
		cout << "Ingrese alguna opcion\n" << endl;
		cout << "[1] Playlist TOP 10" << endl;
		cout << "[2] Playlist Personal" << endl;
		return;
	}
	//Buscar Cancion
	if (imprimir == 5) {
		system("cls");
		cout << "Ingrese Titulo De Cancion\n : " << endl;
		return;
	}
	//estadisticas
	if (imprimir == 6) {
		system("cls");
		cout << "Creado Archivo Estadistica.txt...\n Desplegando Estadisticas\n" << endl;
		return;
	}
}
//lamaremos modo 0, al modo normal, modo 1 al modo playlistT10, y modo 2 al modo playlist personal
int Sistema::reproductor(Cancion* cancioncita, int modo)
{
	CoInitialize(NULL);
	wstring cancionWs = cancioncita->getCancionWs();
	if (mp3.Load( cancionWs.c_str() ) )

	{
		mp3.Play();

		
		menuReproduccion(modo, cancioncita);

		return 1;
		
		
	}
	else {
		cout << "\nCancion No encontrada" << endl;
		system("pause");
		return 0;
	}
}

void Sistema::menuReproduccion(int modo, Cancion* cancioncita)
{
	system("cls");
	if (modo == 1) {
		cout << "-----------TOP CANCIONES-----------\n" << endl;
	}
	cout << "ESCUCHAS : " << cancioncita->getTitulo() << endl;
	cout << "DE : " << cancioncita->getArtista() << "\n" << endl;
	if (modo == 1) {
		cout << "Reproducciones : " << cancioncita->getReproducciones() << endl;
	}
	printMenus(1.5);
	if (modo != 2) {
		if(!listaPersonales->existeCancion(cancioncita)){
			cout << "[4] Agregar a Playlist Personal" << endl;
		}
	}
	else {
		cout << "[4] Eliminar de Playlist Personal" << endl;
	}
}

void Sistema::escribirArchivoEstadisticas(string nombreArchivo,char separador)
{
	ofstream archivo;

	archivo.open(nombreArchivo.c_str(), ios::out); //Creamos el archivo

	if (archivo.fail()) { //Si a ocurrido algun error
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	nodoG* n = listaCanciones->getListaGeneros()->getPrimerG();
	while(n!= NULL){
		string genero = n->genero;
		int reproducciones = n->cantidadReproducciones;
		archivo << genero << separador << reproducciones<< endl;
		
		n = n->siguiente;
	}

	archivo.close(); //Cerramos el archivo
}

void Sistema::actualizarCanciones(string nombreArchivo, char separador)
{
	ofstream archivo;

	archivo.open(nombreArchivo.c_str(), ios::out); //Creamos el archivo

	if (archivo.fail()) { //Si a ocurrido algun error
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	NodoLetraInicial* letra = listaCanciones->getPrimeraLetra();
	nodosCanciones* cancionNodo = letra->getCancionNodoPrimera();
	bool inicio = true;
	while(letra != NULL) {
		Cancion* cancioncitap;
		if (cancionNodo != NULL) {
			cancioncitap = cancionNodo->Cancion;

			string titulo = cancioncitap->getTitulo();
			string artista = cancioncitap->getArtista();
			string genero = cancioncitap->getGenero();
			string anno = cancioncitap->getAnno();
			int reproducciones = cancioncitap->getReproducciones();
			//para evitar hacer un salto de linea al final del archivo
			if (!inicio) {
				archivo << endl;
			}
			archivo << titulo << separador << artista << separador << genero << separador << anno << separador << reproducciones;
			cancionNodo = cancionNodo->siguiente;
			inicio = false;
		}

		if (cancionNodo == NULL) {
			letra = letra->getSiguienteNodo();
			if(letra!=NULL){
				cancionNodo = letra->getCancionNodoPrimera();
			}
		}
	}

	archivo.close(); //Cerramos el archivo
}


