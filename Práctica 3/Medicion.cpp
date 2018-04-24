/*! 
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
*/


// Ficheros de cabecera
#include <iostream>

// atoi, atof
#include <stdlib.h>

#include "Medicion.hpp"
#include "macros.hpp"


// COMPLETAR

//FUNCION DE ESCRITURA

void ed::Medicion::leerMedicion() {

	float p;
	Fecha f;
	bool aux = false;
	int dia, mes, anno;

	std::cout<<BIBLUE<<"Introduzca los datos de la nueva medicion: "<<YELLOW;
	std::cin>>p;
	std::cout<<RESET<<std::endl<<std::endl;

	esPositivo(p);

	while(aux!=true) {

		std::cout<<BYELLOW<<"Introduzca el día: "<<GREEN;
		std::cin>>dia;

		if(dia>0 && dia<32) {

			aux = true;

		}
	}

	aux = false;

	while(aux!=true) {

		std::cout<<BYELLOW<<"Introduzca el mes: "<<GREEN;
		std::cin>>mes;

		if(mes>0 && mes<13) {

			aux = true;

		}
	}

	aux = false;

	while(aux!=true) {

		std::cout<<BYELLOW<<"Introduzca el año: "<<GREEN;
		std::cin>>anno;

		if(anno>1900 && anno<2099) {

			aux = true;

		}
	}

	f.setDia(dia);
	f.setMes(mes);
	f.setAgno(anno);

	setFecha(f);
	setPrecipitacion(p);
}


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

// Sobrecarga del operador de salida

ostream &operator<<(ostream &stream, ed::Medicion const &medicion) {
	
	stream<<medicion.getFecha().getDia()<<"-"<<medicion.getFecha().getMes()<<"-"<<medicion.getFecha().getAgno()<<" "<<medicion.getPrecipitacion()<<" "<<std::endl;
	return stream;
}

/*
ostream &operator<<(ostream &stream, ed::Medicion const &medicion)
{

	std::cout << BIBLUE << "Precipitación: ";
	stream << medicion.getPrecipitacion();
	std::cout << RESET << std::endl;
	std::cout << BIGREEN << "Fecha: ";
	stream << medicion.getFecha();
	std::cout << RESET << std::endl;

	return stream;
}
*/

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Medicion &medicion)
{

 	std::string cadena;

	std::getline(stream,cadena,'-');
    int dia = atoi(cadena.c_str());

	std::getline(stream,cadena,'-');
    int mes = atoi(cadena.c_str());

	std::getline(stream,cadena,' ');
	int agno = atoi(cadena.c_str());


	std::getline(stream, cadena);
	medicion.setPrecipitacion(atof(cadena.c_str()));

	ed::Fecha *aux = new ed::Fecha(dia, mes, agno);
	medicion.setFecha(*aux);

	return stream;
} 

} // Fin del espacio de nombres ed
