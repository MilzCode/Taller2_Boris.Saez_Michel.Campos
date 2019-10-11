#include "Cancion.h"

wstring Cancion::stringToWs(string str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
	return conv.from_bytes(str);
}

Cancion::Cancion()
{
}

Cancion::Cancion(string _titulo, string _artista, string _genero, string _anno, int _reproducciones)
{

	titulo = _titulo;
	artista = _artista;
	genero = _genero;
	anno = _anno;
	reproducciones = _reproducciones;
}
//devuelve el titulo de la cancion pero en wstring (para imprimirlo hay que poner wcout <<titulo<<endl;)
string Cancion::getTitulo()
{
	return titulo;
}

string Cancion::getArtista()
{
	return artista;
}

string Cancion::getGenero()
{
	return genero;
}

string Cancion::getAnno()
{
	return anno;
}

int Cancion::getReproducciones()
{
	return reproducciones;
}

wstring Cancion::getCancion()
{
	wstring _titulo = stringToWs(titulo);
	return directorioCanciones.append(_titulo.append(formatoMp3));
}
