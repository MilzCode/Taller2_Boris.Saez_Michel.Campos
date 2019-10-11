#pragma once
#include <string>
#include <codecvt>//para convertir a wstring

using namespace std;
class Cancion
{
	

private:
	string titulo;
	string artista;
	string genero;
	string anno;
	int reproducciones;
	const wchar_t formatoMp3[4] = { '.','m', 'p', '3' };
	wstring stringToWs(string str);
	//para Cambiar directorio de cancion llenar "" pero en vez de <\> poner / ej: C:/hola/  , ademas dejar / al final
	wstring directorioCanciones = L"";

public:
	Cancion();
	Cancion(string _titulo, string _artista, string _genero, string _anno, int _reproducciones);
	string getTitulo();
	string getArtista();
	string getGenero();
	string getAnno();
	int getReproducciones();
	wstring getCancion();

};

