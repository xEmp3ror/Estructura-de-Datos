/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author 
  \date   
*/

#include <iostream>
#include <string> 
#include <time.h>

// Para usar atoi
#include <stdlib.h>

#include "Provincia.hpp"

#include "Municipio.hpp"

#include "funcionesAuxiliares.hpp"


#include "macros.hpp"

int ed::menu()
{
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,11);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,10);
	std::cout << "[6] Modificar datos de la provincia: código o nombre";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

	PLACE(posicion++,10);
	std::cout << "[11] Mostrar demografia de la provincia";

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


//////////////////////////////////////////////////////////////////////////////

void ed::comprobarProvinciaVacia(ed::Provincia &provincia)
{
	std::cout << std::endl;

	if(provincia.getNombre()=="" and provincia.getCodigo()==0 and provincia.hayMunicipios()) {

		std::cout << IRED << "La Provincia no existe." << std::endl;
		return;
	}

	if(provincia.getNombre() == "") {

		std::cout << "La Provincia con codigo <" << provincia.getCodigo() << "> ";
	} else {

		std::cout << "La Provincia de nombre <" << provincia.getNombre() << "> ";
	}

	if (provincia.hayMunicipios() == true) {

				  std::cout << IRED << "está vacía.";
	} else {

					std::cout << IGREEN << "no está vacía.";
	}

	return;
}

//////////////////////////////////////////////////////////////////////////////

void ed::cargarProvincia(ed::Provincia &provincia)
{

	std::cout<< std::endl;

/*	if(!provincia.hayMunicipios()){

		provincia.borraTodosLosMunicipios();
	}
*/
	std::string fichero;
	std::cout << "Introduzca nombre de archivo con extension: ";
	std::cin >>fichero;
	std::cin.ignore(); 
	
	if(provincia.cargarFichero(fichero)) {

		std::cout << IGREEN << "Archivo cargado con exito."<<std::endl;
	} else {

		std::cout << IRED << "Error al cargar."<<std::endl;
	}

  return;
}

void ed::grabarProvincia(ed::Provincia  &provincia)
{
	std::cout << std::endl;

	if(provincia.getNombre()=="" and provincia.getCodigo()==0 and provincia.hayMunicipios()) {

		std::cout << IRED <<"La Provincia no existe."<< std::endl;
		return;
	}

	std::string fichero;
	std::cout << "Introduzca nombre de archivo con extension: ";
	std::cin >>fichero;
	std::cin.ignore(); 
	
	if(provincia.grabarFichero(fichero))
		std::cout << IGREEN << "Archivo grabado con exito."<<std::endl;
	else
		std::cout << IRED << "Error al grabar."<<std::endl;

	return;

}

//////////////////////////////////////////////////////////////////////

void ed::consultarDatosDeProvincia(ed::Provincia &provincia)
{
	std::cout << std::endl;

	if (provincia.hayMunicipios() && provincia.getNombre()=="" && provincia.getCodigo()==0){
		std::cout << IRED <<"La provincia no existe."<< std::endl;
		return;
	}

	std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET 
				  << provincia.getNombre() << std::endl; 
	std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;
	std::cout << BIYELLOW << "Numero de municipios de la provincia: " << RESET
				  << provincia.getNumeroMunicipios()<< std::endl<< std::endl;

	return;
}


//
void ed::mostrarMunicipiosDeProvincia(ed::Provincia & provincia)
{

	std::cout << std::endl;

	if (provincia.hayMunicipios() && provincia.getNombre()=="" && provincia.getCodigo()==0) {
		std::cout << IRED <<"La provincia no existe."<< std::endl;
		return;
	}

	std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET 
				  << provincia.getNombre() << std::endl; 
	std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;
	std::cout << BIYELLOW << "Numero de municipios de la provincia: " << RESET
				  << provincia.getNumeroMunicipios()<< std::endl << std::endl;

//	sleep(3); //Para que se vea la info de la Provincia antes de meter todos los municipios.

	std::cout<< BIGREEN << "Los municipios de la provincia son los siguientes."<< RESET<< std::endl<<std::endl;
	provincia.escribirMunicipios();

	return;
}


////////////////////////////////////////////////////////////////////////
void ed::modificarDatosDeProvincia(ed::Provincia &provincia)
{

	int opcion, codigo;
	std::string nombre; 

	do{
		std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET 
				  << provincia.getNombre() << std::endl; 
		std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "(1) Nombre " << std::endl;
		std::cout << BIBLUE << "(2) Código" << std::endl  << std::endl;
		std::cout << BIRED << "(0) Salir" << std::endl << std::endl  << std::endl;
		std::cout << BIGREEN;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;
			
		switch(opcion)
		{
			case 0: 
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << BIGREEN;
					std::cout << "Nuevo nombre de la provincia: ";
					std::cout << RESET;
					std::getline(std::cin,nombre);
					provincia.setNombre(nombre);
					break;

			case 2:
					std::cout << BIGREEN;
					std::cout << "Nuevo código de la provincia: ";
					std::cout << RESET;
					std::cin >> codigo;
					provincia.setCodigo(codigo);
					break;
			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET 
							  << opcion << std::endl;
		}
	}while (opcion != 0);

	return;
}


void ed::borrarTodosLosMunicipiosDeProvincia(ed::Provincia &provincia)
{
	std::cout << std::endl;

	if (provincia.hayMunicipios() && provincia.getNombre()=="" && provincia.getCodigo()==0) {
		std::cout << IRED <<"La provincia no existe."<< std::endl;
		return;
	}

	provincia.borraTodosLosMunicipios();

	return;
}


void ed::consultarMunicipioDeProvincia(ed::Provincia &provincia)
{
	std::cout << std::endl;

	if (provincia.hayMunicipios()) {

		std::cout << IRED <<"La Provincia esta vacia."<< std::endl;
		return;
	}

	std::string nombre;
	ed::Municipio p;

	std::cout << "Nombre: ";
	std::getline(std::cin,nombre);

	if(!provincia.existeMunicipio(nombre)){
		std::cout << IRED << "El municipio " << IYELLOW << nombre << IRED << " no pertenece a la provincia." << RESET<< std::endl;
		return;
	}

	p = provincia.getMunicipio(nombre);
	std::cout << std::endl;
	provincia.imprimeMunicipio(p);
	return;

}


void ed::insertarMunicipioEnProvincia(ed::Provincia &provincia)
{
	
	std::cout << std::endl;

	Municipio m;
	std::string nombre;
	int codigo;

	std::cout << "Escriba el nombre del municipio: ";
	std::getline(std::cin,nombre);
	m.setNombre(nombre);

	std::cout << "Escriba el codigo postal del municipio: ";
	std::cin >> codigo;
	m.setCodigoPostal(codigo);

	if(provincia.insertarMunicipio(m) == true) {

		std::cout << BIRED << "Municipio insertado correctamente."<< RESET << std::endl;
		return;
	
	} else {

		std::cout << BIGREEN << "El municipio no ha podido ser insertado."<< RESET << std::endl;
		return;
	}
}


void ed::borrarMunicipioDeProvincia(ed::Provincia &provincia)
{
	std::cout << std::endl;

	if (provincia.hayMunicipios()){

		std::cout << IRED <<"No hay municipios en la provincia."<< std::endl;
		return;
	}

	bool control;
	std::string nombre;

	std::cout << "Nombre: ";
	std::getline(std::cin,nombre);

	control = provincia.existeMunicipio(nombre);	

	if (control == true) {

		provincia.borrarMunicipio(nombre);

		control = provincia.existeMunicipio(nombre);	

		if (control == true)
				std::cout << IRED << "El Municipio no ha podido ser borrado." << std::endl;
		else
				std::cout << IGREEN << "El Municipio ha sido borrado correctamente." << std::endl;
	} else {

		std::cout << IRED << "El municipio  "<< IYELLOW << nombre << " ";
		std::cout << IRED<< "no pertenece a la provincia seleccionada." << std::endl;
	}	

	return;

}

void ed::demografiaProvincia(ed::Provincia &provincia)
{

	std::cout << std::endl;

	if (provincia.hayMunicipios()){

		std::cout << IRED <<"No hay municipios en la provincia."<< std::endl;
		return;
	}


	std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET 
				  << provincia.getNombre() << std::endl; 
	std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;
	std::cout << BIYELLOW << "Numero de municipios de la provincia: " << RESET
				  << provincia.getNumeroMunicipios()<< std::endl << std::endl;

	std::cout << BIYELLOW << "El numero de hombres en la provincia es de: " << RESET
				  << BIGREEN << provincia.getTotalHombres() << RESET << std::endl;

	std::cout << BIYELLOW << "El numero de mujeres en la provincia es de: " << RESET
				  << BIGREEN << provincia.getTotalMujeres() << RESET << std::endl;

	std::cout << BIYELLOW << "El numero de habitantes en la provincia es de: " << RESET
				  << BIGREEN << provincia.getTotalHabitantes() << RESET << std::endl;

	return;
}


