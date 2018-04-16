/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 2
  \author 
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Provincia.hpp"


// SE DEBEN INCLUIR LOS COMENTARIOS DE DOXYGEN DE CADA FUNCIÓN

namespace ed
{

  int menu();

	///////////////////////////////////////////////////////////////////

  	/*!
		\brief   Comprueba que la provincia existe e imprime el resultado por pantalla.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void comprobarProvinciaVacia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!
		\brief   Carga la provincia en memoria, pidiendo al usuario el nombre del fichero.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void cargarProvincia(ed::Provincia & provincia);

	/*!
		\brief   Graba la provincia en memoria, pidiendo al usuario el nombre del fichero.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void grabarProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!
		\brief   Consulta los datos de la Provincia e imprime por pantalla el Nombre, Codigo y numero de habitantes.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void consultarDatosDeProvincia(ed::Provincia & provincia);

	/*!
		\brief   Imprime por pantalla los datos de la provincia y sus municipios.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void mostrarMunicipiosDeProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!
		\brief   Permite al usuario modificar los datos de la provincia.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void modificarDatosDeProvincia(ed::Provincia & provincia);

	/*!
		\brief   Borra todos los Municipios de la Provincia.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia);


	///////////////////////////////////////////////////////////////////

	/*!
		\brief   Permite al usuario comprobar la existencia de un municipio en la provincia.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void consultarMunicipioDeProvincia(ed::Provincia & provincia);

	/*!
		\brief   Permite al usuario insertar un municipio en la provincia.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void insertarMunicipioEnProvincia(ed::Provincia & provincia);

	/*!
		\brief   Permite al usuario borrar un municipio en la provincia.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void borrarMunicipioDeProvincia(ed::Provincia & provincia);

	/*!
		\brief   Muestra por pantalla el numero de habitantes de la provincia.
		\param   Objeto de la clase provincia pasado como referencia NO constante. 
		\return  Nada.
 	*/

	void demografiaProvincia(ed::Provincia &provincia);


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

