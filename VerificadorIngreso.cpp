#include "VerificadorIngreso.h"

//pregunta hasta que se ingrese un valor valido entre 0 y el valor indicado
int VerificadorIngreso::verificadorIngreso(int max)
{
	while (true) {
		int opcion;

		cin >> opcion;
		if (!cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Opcion no valida ingresa Numero!" << endl;
		}
		else if (opcion <= max && opcion >= 1) {
			return opcion;
		}
		else {
			cout << "Opcion no valida" << endl;
		}
	}
}

void VerificadorIngreso::eliminarBuffer()
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
