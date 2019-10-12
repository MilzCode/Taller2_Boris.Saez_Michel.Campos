#include "Sistema.h"

Sistema::Sistema()
{
	listaCanciones = new ListaCancionesInicial();
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

				Cancion* cancioncita = listaCanciones->getCancion(cancion);
				if (cancioncita == NULL) {
					cout << "Cancion " << cancion << " NO encontrada..." << endl;
					system("pause");
				}
				else {
					reproductor(cancioncita);

				}
			break;
			}
			case 2: {
				printMenus(2);
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

void Sistema::reproductor(Cancion* cancioncita)
{
	wstring cancion = cancioncita->getCancionWs();
	if (mp3.Load( cancion.c_str() ) )

	{

		mp3.Play();
		system("cls");
		cout << "ESCUCHAS : " << cancioncita->getTitulo() << endl;
		cout << "DE : " << cancioncita->getArtista() <<"\n"<< endl;
		printMenus(1.5);
		system("pause");

	}
	else {
		cout << "\nCancion No encontrada" << endl;
	}
}
