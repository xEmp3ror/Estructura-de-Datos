/*!	

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author  
	\date  
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <iostream>

// Para comprobar las pre y post condiciones
#include <cassert>

#include "Provincia.hpp"


// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia



///////////////////////////////////////////////////////////////////////////////

// OSBSERVADORES

int const ed::Provincia::getTotalHombres() {

	#ifndef NFEBUG
			assert(!_lista.isEmpty());
	#endif

	int Hombres = 0;

	_lista.gotoHead();

	while  (!_lista.isLastItem()) {

		Hombres += _lista.getCurrentItem().getHombres();
		_lista.gotoNext();
	}

	Hombres += _lista.getCurrentItem().getHombres();

	return Hombres;
}


int const ed::Provincia::getTotalMujeres() {

	#ifndef NFEBUG
			assert(!_lista.isEmpty());
	#endif

	int Mujeres = 0;

	_lista.gotoHead();

	while  (!_lista.isLastItem()) {

		Mujeres += _lista.getCurrentItem().getMujeres();
		_lista.gotoNext();
	}

	Mujeres += _lista.getCurrentItem().getMujeres();

	return Mujeres;
}

int const ed::Provincia::getTotalHabitantes() {

	#ifndef NFEBUG
			assert(!_lista.isEmpty());
	#endif

	int Total = 0;

	Total = getTotalHombres() + getTotalMujeres();

	return Total;
}

/////////////////////////////////////////////////////////////////////////////////////////

// MODIFICADORES




///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA



/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS


