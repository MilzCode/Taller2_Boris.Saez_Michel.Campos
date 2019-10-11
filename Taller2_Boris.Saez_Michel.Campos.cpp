#include <iostream>
#include "ListaCanciones.h"
using namespace std;

int main()
{
	ListaCanciones* canciones = new ListaCanciones();
	
	cout << canciones->getCancion(2).getTitulo() << endl;

	wcout << canciones->getCancion(2).getCancion() << endl;

	wstring hola;
}