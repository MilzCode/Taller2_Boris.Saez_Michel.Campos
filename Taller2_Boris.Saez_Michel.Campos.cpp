#include <iostream>
#include "ListaCanciones.h"
#include "Mp3.h"
using namespace std;

int main()
{
	CoInitialize(NULL);

	ListaCanciones* canciones = new ListaCanciones();

	Mp3 mp3;

	if (mp3.Load((canciones->getCancion(2).getCancionWs()).c_str()))
	{
		mp3.Play();
		cout << "\nReproduciendo " << canciones->getCancion(2).getTitulo() << endl;
		system("pause");
	}
	else {
		cout << "\nCancion No encontrada" << endl;
	}
}