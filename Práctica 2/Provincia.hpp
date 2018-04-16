/*!	
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author  
	\date  
	\version 

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>
#include <fstream>
#include <stdlib.h>

#include "macros.hpp"


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"

// DEBES COMPLETAR O MODIFICAR EL CÓDIGO DE LA CLASE Provincia

// DEBES COMPLETAR LOS COMENTARIOS DE DOXYGEN

// IMPORTANTE
// Se incluyen los prototipos de las funciones virtuales que hay que redefinir
// Hay que incluir los prototipos de las demás funciones


/*!	
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!	

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia
{
	//!	\name Métodos públicos de la clase Provincia

	private:
		std::string   	     _nombre;     //!<  \brief Nombre de la Provincia
		int                  _codigo;	  //!<  \brief Código de la Provincia

	  	ed::ListaDoblementeEnlazadaOrdenadaMunicipios _lista; //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public: 

	//! \name Constructor de la Clase Provincia.
	/*! 
		\brief     Constructor parametrizado con valores por defecto      
		\param     nombre: valor por defecto ""
		\param     codigo: valor por defecto 0.0
		\pre       Ninguna
		\post      Ninguna
	*/

  	Provincia(std::string nombre="", int codigo = 0) {

  		this -> setNombre(nombre);
  		this -> setCodigo(codigo);;
  	}

	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores

  	/*! 
		\brief   Función que devuelve el nombre de la Provincia.
		\attention Se utiliza el modificador const en la definición de la función.
		\note    Función inline
		\return  Nombre de la Provincia.
		\pre     Ninguna
		\post    Ninguna
	*/

  	inline std::string getNombre() const { return this -> _nombre; };

  	/*! 
		\brief   Función que devuelve el codigo de la Provincia.
		\attention Se utiliza el modificador const en la definición de la función.
		\note    Función inline
		\return  Codigo de la Provincia.
		\pre     Ninguna
		\post    Ninguna
	*/

  	inline int getCodigo() const { return this -> _codigo; };

  	/*! 
		\brief   Función que comprueba si hay municipios en la provincia.
		\attention Se utiliza el modificador const en la definición de la función.
		\note    Función inline
		\return  true: Si la provincia está vacía; false: En caso contrario.
		\pre     Ninguna
		\post    Ninguna
	*/

  	inline bool hayMunicipios() const { return _lista.isEmpty(); };

  	/*! 
		\brief   Función que devuelve el numero de municipios.
		\attention Se utiliza el modificador const en la definición de la función.
		\note    Función inline
		\return  Numero de municipios.
		\pre     Ninguna
		\post    Ninguna
	*/

  	inline int getNumeroMunicipios() const { return _lista.nItems(); };

  	/*! 
		\brief   Función que comprueba si existe el municipio en la provincia.
		\attention Se utiliza el modificador const en la definición de la función.
		\param     Cadena de caracteres pasada como referencia constante.
		\return  true: Si existe el municipio; false: En caso contrario.
		\pre     Ninguna
		\post    Ninguna
	*/

 	bool existeMunicipio (std::string const &nombre) {

		ed::Municipio m(nombre);
		return _lista.find(m);
	}

	/*! 
		\brief   Función que devuelve los datos de un municipio pasado como argumento.
		\attention Se utiliza el modificador const en la definición de la función.
		\param     Cadena de caracteres pasada como referencia constante.
		\return  Objeto de la clase Municipio.
		\pre     El municipio debe existir.
		\post    Ninguna
	*/

  	ed::Municipio const & getMunicipio(std::string const &nombre) {

		#ifndef NDEBUG
				assert(existeMunicipio(nombre));
		#endif

		existeMunicipio(nombre);
		return _lista.getCurrentItem();

	}

	/*! 
		\brief   Función que devuelve el total de Hombres en la provincia.
		\attention Se utiliza el modificador const en la definición de la función.
		\param     Ninguna.
		\return  Numero de Hombres de la provincia.
		\pre     La provincia debe existir.
		\post    Ninguna
	*/

	int const getTotalHombres();

	/*! 
		\brief   Función que devuelve el total de Mujeres en la provincia.
		\attention Se utiliza el modificador const en la definición de la función.
		\param     Ninguna.
		\return  Numero de Mujeres de la provincia.
		\pre     La provincia debe existir.
		\post    Ninguna
	*/

	int const getTotalMujeres();

	/*! 
		\brief   Función que devuelve el total de Habitantes en la provincia.
		\attention Se utiliza el modificador const en la definición de la función.
		\param     Ninguna.
		\return  Numero de Habitantes de la provincia.
		\pre     La provincia debe existir.
		\post    Ninguna
	*/

	int const getTotalHabitantes();


	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores

	/*! 
		\brief   Función que cambia el nombre de la provincia al pasado por argumento.
		\attention Se utiliza el modificador const en la definición del parametro.
		\param     Cadena pasada como referencia constante.
		\return  Nada.
		\pre     Ninguna.
		\post    El nombre fijado debe ser igual al nombre pasado como referencia constante.
	*/

	inline void setNombre(std::string const & nombre) {

		_nombre = nombre;

		#ifndef NDEBUG
				assert(getNombre() == nombre);
		#endif
	}

	/*! 
		\brief   Función que cambia el Codigo de la provincia al pasado por argumento.
		\attention Se utiliza el modificador const en la definición del parametro.
		\param     Entero pasado como referencia constante.
		\return  Nada.
		\pre     Ninguna.
		\post    El Codigo fijado debe ser igual al Codigo pasado como referencia constante.
	*/

	inline void setCodigo(int const & codigo) {

		this -> _codigo = codigo;

		#ifndef NDEBUG
				assert(getCodigo() == codigo);
		#endif
	}

	/*! 
		\brief   Función que inserta un municipio en la Provincia actual.
		\param   Objeto del tipo Municipio pasado como referencia constante.
		\return  true: Si el Insert se ha realizado correctamente; false: en caso contrario.
		\pre     El municipio no debe existir.
		\post    El numero de municipios debe haberse incrementado en uno.
	*/

	bool insertarMunicipio(ed::Municipio const & m) {

		#ifndef NDEBUG
				assert(!existeMunicipio(m.getNombre()));
		#endif

		if(!existeMunicipio(m.getNombre())) {

			int old = getNumeroMunicipios();

			_lista.insert(m);

			#ifndef NDEBUG
					assert (existeMunicipio(m.getNombre()) and old == getNumeroMunicipios() - 1);
			#endif

			return true;

		} else {

			return false;
		}
	}

	/*! 
		\brief   Función que borra un municipio de la Provincia actual.
		\param   Cadena pasada como referencia constante.
		\return  true: Si el Delete se ha realizado correctamente; false: en caso contrario.
		\pre     El municipio debe existir.
		\post    El numero de municipios debe haberse decrementado en uno.
	*/

	bool borrarMunicipio(std::string const &nombre) {

		#ifndef NDEBUG 
				assert(existeMunicipio(nombre));
		#endif

		if (existeMunicipio(nombre)) {

			int old = getNumeroMunicipios();
 			
 			ed::Municipio m(nombre);

 			_lista.find(m);
 			_lista.remove();

 			#ifndef NDEBUG
					assert (not existeMunicipio(m.getNombre()) and old == getNumeroMunicipios() + 1);
			#endif

			return true;

		} else {

			return false;
		}
	}

	/*! 
		\brief   Función que inserta un municipio en la Provincia actual.
		\return  Nada.
		\pre     Ninguna.
		\post    La lista debe de quedar vacía.
	*/

	void borraTodosLosMunicipios() {

		_lista.removeAll();

		#ifndef NDEBUG
				assert(_lista.isEmpty());
		#endif
	}

	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia

	/*! 
		\brief   Función que imprime el municipio pasado como argumento.
		\param   Objeto del tipo Municipio pasado como referencia constante.
		\return  Nada.
		\pre     Ninguna.
		\post    Ninguna.
	*/

	void const imprimeMunicipio(ed::Municipio const & m) {

		std::cout<<"Codigo postal: "<<IGREEN<<m.getCodigoPostal()<<RESET<<"  |  "<<m.getNombre()<<"  |  "<<IBLUE<<m.getHombres()<<RESET<<"  |  "<<CYAN<<m.getMujeres()<<RESET<<"  |  "<<m.getHabitantes()<<std::endl;
	}

	/*! 
		\brief   Función que escribe todos los municipios de la provincia actual por pantalla.
		\param   Ninguno.
		\return  Nada.
		\pre     La provincia no debe de estar vacía.
		\post    Ninguna.
	*/

	void escribirMunicipios() {

		if(!_lista.isEmpty()) { 

			_lista.gotoHead();

			while (!_lista.isLastItem()) {

				imprimeMunicipio(_lista.getCurrentItem());

				_lista.gotoNext();
			}

			imprimeMunicipio(_lista.getCurrentItem());

		} else {

			std::cout << BIRED << "La provincia esta vacia." << RESET << std::endl;
		}
	}


	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros

	/*! 
		\brief   Funcion que carga el fichero en memoria.
		\param   Cadena que contiene el nombre del fichero.
		\return  true: Si la carga se ha realizado correctamente; false: en caso contrario.
		\pre     Ninguna.
		\post    Ninguna.
	*/

	bool cargarFichero(std::string nombre) {

		ed::Municipio aux;
		std::string got;
		std::ifstream fich(nombre.c_str());

		if(fich.is_open()) {

			_lista.removeAll();

			getline(fich, got,' ');
			setCodigo(atoi(got.c_str()));

			getline(fich, got, '\n');
			setNombre(got);

			while(!fich.eof()) {

			  fich>>aux;
			  insertarMunicipio(aux);
			}

			fich.close();
			return true;

		} else {

			return false;
		}
	}

	/*! 
		\brief   Funcion que graba el fichero en memoria.
		\param   Cadena que contiene el nombre del fichero.
		\return  true: Si la grabación se ha realizado correctamente; false: en caso contrario.
		\pre     Ninguna.
		\post    Ninguna.
	*/

	bool grabarFichero(std::string nombre) {

		ed::Municipio aux;
		std::string got;
		std::ofstream fich(nombre.c_str());

		if(fich.is_open()) {

			fich<<getCodigo()<<' '<<getNombre()<<std::endl;

			while(!fich.eof()) {

				aux=_lista.getCurrentItem();
				fich<<aux;
			}

		fich.close();

		return true;

		} else {

			return false;
		}
	}


}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
