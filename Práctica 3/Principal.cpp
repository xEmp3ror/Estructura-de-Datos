#include <iostream>

#include <string>

#include "MonticuloMediciones.hpp"
#include "Medicion.hpp"

#include "funcionesAuxiliares.hpp"
#include "macros.hpp"

int main() {

	ed::MonticuloMediciones monticulo;
	ed::Medicion aux;

	std::string nombreFichIn;
	std::string nombreFichOut;

	int opcion;

	/*--------------------------------------------------------------*/

	do {

		opcion = ed::menu();

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		switch(opcion) {

			case 0:

			std::cout << INVERSE;
			std::cout << "FIN DEL PROGRAMA." << RESET << std::endl;

			break;


			case 1:

			std::cout << "[1] CARGAR DATOS DESDE UN FICHERO." << std::endl;

			std::cout << BBLUE << "Introduzca el nombre del fichero seguido de la extension del mismo: " << GREEN;
			std::cin >> nombreFichIn;

			ed::cargarMonticuloDeFichero(nombreFichIn, monticulo);

			break;


			case 2:

			std::cout << "[2] GUARDAR LOS DATOS EN UN FICHERO." << std::endl;

			std::cout << BBLUE << "Introduzca el nombre del fichero seguido de la extension del mismo: " << GREEN;
			std::cin >> nombreFichOut;

			ed::grabarMonticuloEnFichero(nombreFichOut, monticulo);

			std::cout<<BIGREEN<<"Archivo cargado con exito."<<RESET<<std::endl;
			std::cin.ignore();

			break;

			/*-------------------*/

			case 3:

			std::cout << "[3] INSERTAR UNA NUEVA MEDICION." << std::endl;

			aux.leerMedicion();
			monticulo.insert(aux);

			break;


			case 4:

			std::cout << "[4] MOSTRAR LOS ELEMENTOS DEL MONTICULO." << std::endl;

			monticulo.print();

			break;

			/*--------------------*/

			case 5:

			std::cout << "[5] MOSTRAR LA CABEZA DEL MONTICULO." << std::endl;

			if(monticulo.isEmpty()) {

				std::cout<<BIRED<<"ATENCIÓN: "<<BYELLOW<<"No se puede operar con el montículo porque está "<<BIRED<<"vacío"<<RESET<<BYELLOW<<"."<<std::endl;
				break;
			
			} else {

				std::cout<<BIGREEN<<"La cabeza es: "<<BLUE<<monticulo.top()<<std::endl;
			}

			break;


			case 6:

			std::cout << "[6] BORRAR LA CABEZA DEL MONTICULO." << std::endl;

			std::cout<<std::endl;

			std::cout<<BIGREEN<<"INFORMACION: "<<BLUE<<"Esta opcion no eliminara la medicion mas reciente del monticulo."<<RESET<<std::endl;

			if(monticulo.isEmpty()) {

				std::cout<<BIRED<<"ATENCIÓN: "<<BYELLOW<<"No se puede operar con el montículo porque está "<<BIRED<<"vacío"<<RESET<<BYELLOW<<"."<<std::endl;
				break;
			
			} else {

				monticulo.remove();

				std::cout<<BIGREEN<<"La cabeza se ha eliminado con exito."<<RESET<<std::endl;
			}

			break;


			case 7:

			std::cout << "[7] BORRAR LOS ELEMENTOS DE UN MONTÍCULO." << std::endl;

			monticulo.removeAll();

			std::cout<<BIGREEN<<"Todos los elementos han sido borrados. El monticulo ya no existe."<<RESET<<std::endl;

			break;

			/*--------------------*/

			case 8:

			std::cout << "[8] MOSTRAR CUANTOS ELEMENTOS HAY EN EL MONTICULO." << std::endl;

			if(monticulo.isEmpty()) {

				std::cout<<BIRED<<"ATENCIÓN: "<<BYELLOW<<"No se puede operar con el montículo porque está "<<BIRED<<"vacío"<<RESET<<BYELLOW<<"."<<std::endl;
				break;
			
			} else {

				std::cout<<BIGREEN<<"Hay "<<BLUE<<monticulo.size()<<BIGREEN<<" elementos en el monticulo."<<RESET<<std::endl;
			}

			break;

			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;

    	} //SWITCH END.
  
	    if (opcion !=0) {

			PLACE(25,1);
			std::cout << "Pulse ";
			std::cout << BIGREEN;
			std::cout << "ENTER";
			std::cout << RESET;
			std::cout << " para mostrar el ";
			std::cout << INVERSE;
			std::cout << "menú"; 
			std::cout << RESET;

			// Pausa
			std::cin.ignore();

			std::cout << CLEAR_SCREEN;
	    }

	} while(opcion!=0);

	return 0;
}
	
