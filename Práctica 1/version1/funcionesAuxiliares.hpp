
/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author 
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Vector3D.hpp"


namespace ed
{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*! 
		\brief   Lee los vectores por teclado usando cin y sobrecarga de operadores. 
		\param   u: Objeto de tipo Vector3D. 
		\param   v: Objeto de tipo Vector3D.
		\param   w: Objeto de tipo Vector3D.
		\return  void
	    \sa      leerVectores().
	*/

	void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);

	/*! 
		\brief   Escribe los vectores por pantalla usando cout y sobrecarga de operadores. 
		\warning Referencias a los vectores constantes.
		\param   u: Objeto de tipo Vector3D. 
		\param   v: Objeto de tipo Vector3D.
		\param   w: Objeto de tipo Vector3D.
		\return  void
	    \sa      escribirVectores().
	*/

	void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);


	/*! 
		\brief   Escribe por pantalla todos las funciones de los observadores. 
		\warning Referencias a los vectores constantes.
		\param   u: Objeto de tipo Vector3D. 
		\param   v: Objeto de tipo Vector3D.
		\return  void
	    \sa      observadoresDeVectores().
	*/

	void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);

	/*! 
		\brief   Pide por teclado al usuario todos los datos para operar con los modificadores. 
		\warning Referencia a vector v constante.
		\param   u: Objeto de tipo Vector3D. 
		\param   v: Objeto de tipo Vector3D.
		\param   k: Constante de tipo Double.
		\return  void
	    \sa      modificarVector().
	*/

	void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);

	/*! 
		\brief   Muestra por pantalla el Producto escalar usando tanto las funciones como la sobrecarga de operadores. 
		\warning Referencias a los vectores constantes.
		\param   u: Objeto de tipo Vector3D. 
		\param   v: Objeto de tipo Vector3D.
		\return  void
	    \sa      mostrarProductoEscalar().
	*/

	void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v); 

	/*! 
		\brief   Muestra por pantalla el Producto vectorial usando tanto las funciones como la sobrecarga de operadores. 
		\warning Referencias a los vectores constantes.
		\param   u: Objeto de tipo Vector3D. 
		\param   v: Objeto de tipo Vector3D.
		\return  void
	    \sa      mostrarProductoVectorial().
	*/

	void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);

	/*! 
		\brief   Muestra por pantalla el Producto mixto usando tanto las funciones como la sobrecarga de operadores. 
		\warning Referencias a los vectores constantes.
		\param   u: Objeto de tipo Vector3D. 
		\param   v: Objeto de tipo Vector3D.
		\param   w: Objeto de tipo Vector3D.
		\return  void
	    \sa      mostrarProductoMixto().
	*/

	void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	/*! 
		\brief   Muestra por pantalla la sobrecarga de operadores. 
		\warning Referencias a los vectores constantes.
		\param   u: Objeto de tipo Vector3D. 
		\param   v: Objeto de tipo Vector3D.
		\param   w: Objeto de tipo Vector3D.
		\param   k: Constante de tipo Double.
		\return  void
	    \sa      mostrarOperadores().
	*/

	void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);



} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

