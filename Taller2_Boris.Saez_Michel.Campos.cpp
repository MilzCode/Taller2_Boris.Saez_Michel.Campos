#include <iostream>
#include "ListaCanciones.h"
#include "Sistema.h"

using namespace std;

int main()
{
	CoInitialize(NULL);

	//ListaCanciones* canciones = new ListaCanciones();
	Sistema* sis = new Sistema();

	sis->ejecutarSistema();


	//Mp3 mp3;

	/*if (mp3.Load((canciones->getCancion(1).getCancionWs()).c_str()))
	{
		mp3.Play();
		cout << "\nReproduciendo " << canciones->getCancion(1).getTitulo() << endl;
		system("pause");
	}
	else {
		cout << "\nCancion No encontrada" << endl;
	}*/
}