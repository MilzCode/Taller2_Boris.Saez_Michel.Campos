#pragma once
#include <string>
#include <codecvt>//para convertir a wstring
#include <iostream>


using namespace std;
class Cancion
{
	

private:
	string titulo;
	string artista;
	string genero;
	string anno;
	int reproducciones;
	const string formato = ".mp3";// NO CAMBIAR ESTO!!


	//para Cambiar directorio de cancion llenar "" pero en vez de <\> poner </> ej: C:/hola/  , no olividar ademas dejar / al final
	//esto SOLO MODIFICA LA UBICACION DE LOS MP3 MAS NO la ubicacion de canciones.txt esto editar en listaCancionesInicial.h
	string directorioCanciones = "";

public:
	Cancion();
	Cancion(string _titulo, string _artista, string _genero, string _anno, int _reproducciones);
	string getTitulo();
	string getArtista();
	string getGenero();
	string getAnno();
	int getReproducciones();
	wstring getCancionWs();
	bool setDirectorioCanciones(string directorio);
	void suma1Reproduccion(int add);

};

