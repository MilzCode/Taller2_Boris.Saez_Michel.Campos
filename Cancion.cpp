#include "Cancion.h"
#include "Mp3.h"//necesario para que funcione s2ws

//Un metodo para convertir de string a wstring
std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
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

wstring Cancion::getCancionWs()
{
	string cancion = directorioCanciones + titulo + formato;
	std::wstring stemp = s2ws(cancion);
	return stemp;
}

/*metodo para modificar el directorio de las canciones
 *	//para Cambiar directorio de cancion llenar "" 
 *pero en vez de <\> poner </> ej: C:/hola/  , no olividar ademas dejar / al final
 */
bool Cancion::setDirectorioCanciones(string directorio)
{
	try {
		directorioCanciones = directorio;
		return true;
	}
	catch (...) {
		return false;
	}
}


