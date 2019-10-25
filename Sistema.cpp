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
		int opcion_0 = verificadorIngreso(5);

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
					reproductor(cancioncita,0);
					int opcionControles;
					while (true) {
						opcionControles = verificadorIngreso(4);
						//salir
						if (opcionControles == 3) {
							mp3.Stop();
							break;
						}
						//siguiente
						if (opcionControles == 1) {
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
							reproductor(cancioncitaNodo->Cancion,0);
						}
						//anterior
						if (opcionControles == 2) {
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
							reproductor(cancioncitaNodo->Cancion,0);
						}

					}
				}
			break;
			}

			//reproducir playlist
			case 2: {
				printMenus(2);
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
			case 3: {
				printMenus(3);
				break;
			}
			case 4: {
				printMenus(4);
				break;
			}

			//Salir ojo aca hay que actualizar archivo canciones.txt
			case 5: {
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
	reproductor(cancioncita,1);
	int opcionControles;
	while (true) {
		opcionControles = verificadorIngreso(4);
		//salir
		if (opcionControles == 3) {
			mp3.Stop();
			break;
		}
		//siguiente
		if (opcionControles == 1) {
			mp3.Stop();
			if (cancioncitaNodo->siguiente != NULL) {
				cancioncitaNodo = cancioncitaNodo->siguiente;
			}
			else {
				cancioncitaNodo = listaCanciones->getTop10()->getTopNodoT10();
			}

			listaCanciones->getTop10()->actualizarT10(cancioncitaNodo->cancionT10);
			reproductor(cancioncitaNodo->cancionT10,1);
		}
		//anterior
		if (opcionControles == 2) {
			mp3.Stop();
			if (cancioncitaNodo->anterior != NULL) {
				cancioncitaNodo = cancioncitaNodo->anterior;
			}
			else {
				cancioncitaNodo = listaCanciones->getTop10()->getUltimoNodoT10();
			}

			listaCanciones->getTop10()->actualizarT10(cancioncitaNodo->cancionT10);
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
	reproductor(cancioncita, 2);
	int opcionesControl = verificadorIngreso(4);

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
		cout << "[2] Reproducir Playlist" << endl;
		cout << "[3] Buscar Cancion" << endl;
		cout << "[4] Estadisticas" << endl;
		cout << "[5] Salir" << endl;

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
	if (imprimir == 2) {
		system("cls");
		cout << "Ingrese alguna opcion\n" << endl;
		cout << "[1] Playlist TOP 10" << endl;
		cout << "[2] Playlist Personal" << endl;
		return;
	}
	//Buscar Cancion
	if (imprimir == 3) {
		system("cls");
		cout << "Ingrese Titulo De Cancion\n : " << endl;
		return;
	}
	//estadisticas
	if (imprimir == 4) {
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
		system("cls");
		if (modo == 1) {
			cout << "-----------TOP CANCIONES-----------\n" << endl;
		}
		cout << "ESCUCHAS : " << cancioncita->getTitulo() << endl;
		cout << "DE : " << cancioncita->getArtista() <<"\n"<< endl;
		if (modo == 1) {
			cout << "Reproducciones : " << cancioncita->getReproducciones() << endl;
		}
		printMenus(1.5);
		if (modo != 2) {
			cout << "[4] Agregar a Playlist Personal" << endl;
		}
		else {
			cout << "[4] Eliminar de Playlist Personal" << endl;
		}
		
		return 1;
	}
	else {
		cout << "\nCancion No encontrada" << endl;
		system("pause");
		return 0;
	}
}
