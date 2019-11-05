#define WIN32_LEAN_AND_MEAN           //necesaria para el funcionamiento de las librerias

#include <windows.h>
#include <mmsystem.h>
#include <strmif.h>
#include <control.h>

#pragma comment(lib, "strmiids.lib")

class Mp3
{
public:
	Mp3();
	~Mp3();

	bool Load(LPCWSTR filename);
	

	bool Play();
	bool Stop();



	//retorna true si es el final de la cancion
	bool isFinal();

	//metodo interno de isFinal() retorna la duracion actual del sonido donde 10,000,000 == 1 segundo
	__int64 GetCurrentPosition();

	//metodo interno de isFinal() retorna la duracion total del sonido donde 10,000,000 == 1 segundo
	__int64 GetDuration();
private:
	void Cleanup();
	IGraphBuilder* pigb;
	IMediaControl* pimc;
	IMediaEventEx* pimex;
	IBasicAudio* piba;
	IMediaSeeking* pims;
	bool    ready;
	// duracion del mp3
	__int64 duration;

	
	

};