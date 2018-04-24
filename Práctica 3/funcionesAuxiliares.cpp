/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author 
  \date   
*/


#include <iostream>

#include <fstream>

#include <string>

#include "funcionesAuxiliares.hpp"
          
#include "MonticuloMediciones.hpp"

#include "Medicion.hpp"

#include "macros.hpp"

void ed::cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo) {

 	std::ifstream fichero(nombreFichero.c_str());
 	ed::Medicion aux;

 	if(fichero.is_open()) {

// 		monticulo.removeAll(); //Limpiamos el montículo por si hubiera algo antes.

 		while(fichero >> aux) {

 			if(aux.getFecha().esCorrecta()) {

 				monticulo.insert(aux);
 			}
 		}

		std::cout<<BIGREEN<<"Archivo cargado con exito."<<RESET<<std::endl;
//		std::cin.ignore();
 	
 	} else {

 		std::cout<<BIRED<<"Error al cargar <"<<BIYELLOW<<nombreFichero<<BIRED<<"> Es posible que no exista el fichero o este corrupto."<<RESET<<std::endl;
// 		std::cin.ignore();
 		return;
 	}

 	fichero.close();
	return;
}


void ed::grabarMonticuloEnFichero(std::string const & nombreFichero, 
							      ed::MonticuloMediciones const & monticulo)
{

	ed::MonticuloMediciones aux = monticulo;
 	std::ofstream fichero(nombreFichero.c_str());

 	if(fichero.is_open()) {

 		while(!aux.isEmpty()) {

 			fichero<<aux.top();
 			aux.remove();
 		}
 	}

 	fichero.close();
	return;
}

int ed::menu() {

	int opcion;
	int posicion;

	posicion=2;

	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[1] CARGAR DATOS DESDE UN FICHERO.";

	PLACE(posicion++,10);
	std::cout << "[2] GUARDAR LOS DATOS EN UN FICHERO.";

	posicion++; //Para separar conjuntos de opciones.

	PLACE(posicion++,10);
	std::cout << "[3] INSERTAR UNA NUEVA MEDICION.";

	PLACE(posicion++,10);
	std::cout << "[4] MOSTRAR LOS ELEMENTOS DEL MONTICULO.";

	posicion++; //Para separar conjuntos de opciones.

	PLACE(posicion++,10);
	std::cout << "[5] MOSTRAR LA CABEZA DEL MONTICULO.";

	PLACE(posicion++,10);
	std::cout << "[6] BORRAR LA CABEZA DEL MONTICULO.";

	PLACE(posicion++,10);
	std::cout << "[7] BORRAR LOS ELEMENTOS DE UN MONTÍCULO.";

	posicion++; //Para separar conjuntos de opciones.

	PLACE(posicion++,10);
	std::cout << "[8] MOSTRAR CUANTOS ELEMENTOS HAY EN EL MONTICULO.";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";


	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();

	return opcion;
}


