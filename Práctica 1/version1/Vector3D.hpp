/*! 
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

// Entrada y salida 
#include <iostream>

// Para usar abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

// COMPLETAR, SI ES PRECISO


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$ 
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
   private: 

	double v1_;
	double v2_;
	double v3_;


   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D

	/*! 
		\brief     Constructor que crea un Vector3D inicializado a 0.
		\attention Función sobrecargada        
		\note      Función inline
	 	\warning   El  constructor no recibe parámetros.
		\param     Ninguno
		\pre       Ninguna
		\post      (get1()==0) and (get2()==0) and (get3()==0)
	*/

	Vector3D() {

		v1_ = 0;
		v2_ = 0;
		v3_ = 0;

	}

	/*! 
		\brief     Constructor que crea un Vector3D con los parámetros pasados como argumento.
		\attention Función sobrecargada        
		\note      Función inline
	 	\warning   El constructor recibe tres parámetros obligatorios.
		\param     v1: Primera componente del vector.
		\param     v2: Segunda componente del vector.
		\param     v3: Tercera componente del vector.
		\pre       Ninguna
		\post      (get1()==v1) and (get2()==v2) and (get3()==v3)
	*/

	Vector3D(double v1, double v2, double v3) {

		v1_ = v1;
		v2_ = v2;
		v3_ = v3;
	}

	/*! 
		\brief     Constructor de copia que crea un Vector3D a partir del vector pasado como argumento.
		\attention Función sobrecargada        
		\note      Función inline
	 	\warning   El  constructor recibe un parámetro obligatorio.
		\param     &v: Objeto Vector3D que se usará para la copia.
		\pre       Ninguna
		\post      (get1()==v.get1()) and (get2()==v.get2()) and (get3()==v.get3())
	*/

	Vector3D(const ed::Vector3D &v) {

		v1_ = v.get1();
		v2_ = v.get2();
		v3_ = v.get3();
	}

	//! \name Observadores: funciones de consulta de Vector3D

	/*! 
		\brief   Función que devuelve el primer parámetro del vector.
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "=".
		\note    Función inline.
		\return  Primera componente del vector (tipo double).
		\pre     Ninguna.
		\post    Ninguna.
		\sa      get1().
	*/

	inline double get1() const { return v1_; };

	/*! 
		\brief   Función que devuelve el segundo parámetro del vector.
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "=".
		\note    Función inline.
		\return  Segunda componente del vector (tipo double).
		\pre     Ninguna.
		\post    Ninguna.
		\sa      get2().
	*/

	inline double get2() const { return v2_; };

	/*! 
		\brief   Función que devuelve el tercer parámetro del vector.
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "=".
		\note    Función inline.
		\return  Tercera componente del vector (tipo double).
		\pre     Ninguna.
		\post    Ninguna.
		\sa      get3().
	*/

	inline double get3() const { return v3_; };

	/*! 
		\brief   Función que calcula el modulo del vector.
		\warning Se utiliza el modificador const al final de la declaración.
		\return  Módulo del vector (tipo double).
		\pre     Ninguna.
		\post    valorDevuelto == sqrt ( get1()*get1() + get2()*get2() + get3()*get3() ).
		\sa      modulo().
	*/

	double modulo() const;

	/*! 
		\brief   Función que calcula el angulo entre dos vectores.
		\warning Se utiliza el modificador const al final de la declaración.
		\return  Ángulo entre los dos vectores.
		\param   &v: Objeto del tipo Vector3D que contiene el segundo vector.
		\pre     modulo() * v.modulo() > 0.
		\post    valorDevuelto == acos( dotProduct(v) / (modulo() * v.modulo()) ).
		\sa      angulo().
	*/

	double angulo(ed::Vector3D const &v) const;

	/*! 
		\brief   Función que calcula el producto escalar entre dos vectores.
		\warning Se utiliza el modificador const al final de la declaración.
		\return  Producto escalar.
		\param   &v: Objeto del tipo Vector3D que contiene el segundo vector.
		\post    valorDevuelto == get1() * v.get1() + get2() * v.get2() + get3() * v.get3()
		\sa      dotProduct().
	*/

	double dotProduct(const ed::Vector3D &v) const;

	/*! 
		\brief   Función que calcula el ángulo del vector con el eje X.
		\warning Se utiliza el modificador const al final de la declaración.
		\return  Ángulo con el eje X.
		\pre 	 modulo()>0.
		\post    valorDevuelto == angulo(Vector3D(1,0,0))
		\sa      alfa().
	*/

	double alfa() const;

	/*! 
		\brief   Función que calcula el ángulo del vector con el eje Y.
		\warning Se utiliza el modificador const al final de la declaración.
		\return  Ángulo con el eje Y.
		\pre 	 modulo()>0.
		\post    valorDevuelto == angulo(Vector3D(0,1,0))
		\sa      beta().
	*/

	double beta() const;

	/*! 
		\brief   Función que calcula el ángulo del vector con el eje Z.
		\warning Se utiliza el modificador const al final de la declaración.
		\return  Ángulo con el eje Z.
		\pre 	 modulo()>0.
		\post    valorDevuelto == angulo(Vector3D(0,0,1))
		\sa      gamma().
	*/

	double gamma() const;

	/*! 
		\brief   Función que calcula el producto vectorial de los vectores u y v.
		\warning Se utiliza el modificador const al final de la declaración.
		\return  Devuelve un Vector3D que es el resultado del producto vectorial de dos vectores.
		\post    (dotProduct(valorDevuelto) == 0) and (v.dotProduct(valorDevuelto) == 0)
		\sa      crossProduct().
	*/

	Vector3D crossProduct(ed::Vector3D v) const;

	/*! 
		\brief   Función que calcula el producto mixto de los vectores u, v y w.
		\note	 Función inline.
		\warning Se utiliza el modificador const al final de la declaración.
		\param 	 v: Vector con el que se calculará el producto mixto (Tipo Vector3D).
		\return  Devuelve el resultado de calcular el producto escalar del vector obtenido con el vector obtenido al calcular el producto vectorial de otros dos vectores.
		\post    valorDevuelto == dotProduct(crossProduct(v,w))
		\sa      productoMixto().
	*/

	inline double productoMixto(ed::Vector3D v, ed::Vector3D w) const{ return dotProduct(v.crossProduct(w)); };



	//! \name Modificadores: funciones de modificación de Vector3D

	/*! 
		\brief   Función que asigna el valor v1 a la primera componente del vector.
		\note	 Función inline
		\param	 v1: Nuevo primer componente (Tipo Double)
		\post  	 get1()== v1.
		\sa      set1().
	*/

	inline void   set1(int v1) { v1_ = v1; };

	/*! 
		\brief   Función que asigna el valor v2 a la segunda componente del vector.
		\note	 Función inline
		\param	 v2: Nuevo segundo componente (Tipo Double)
		\post  	 get2()== v2.
		\sa      set2().
	*/

	inline void   set2(int v2) { v2_ = v2; };

	/*! 
		\brief   Función que asigna el valor v3 a la tercera componente del vector.
		\note	 Función inline
		\param	 v3: Nuevo tercer componente (Tipo Double)
		\post  	 get3()== v3.
		\sa      set3().
	*/

	inline void   set3(int v3) { v3_ = v3; };

	/*! 
		\brief   Función que suma una constante a cada componente del vector.
		\param	 k: Constante a sumar (Tipo Double)
		\post  	 (get1() == old.get1() + k) and (get2() == old.get2() + k) and (get3() == old.get3() + k).
		\sa      sumConst().
	*/

	void sumConst(double k);

	/*! 
		\brief   Función que suma a cada compontente del vector, la componente correspondiente del vector pasado como argumento.
		\param	 v: Vector que se sumará al vector actual (Tipo Vector3D)
		\post  	 (get1() == old.get1() + v.get1()) and (get2() == old.get2() + v.get2()) and (get3() == old.get3() + v.get3()).
		\sa      sumVect().
	*/

	void sumVect(ed::Vector3D v);

	/*! 
		\brief   Función que multiplica una constante a cada componente del vector.
		\param	 k: Constante a multiplicar (Tipo Double)
		\post  	 (get1() == old.get1() * k) and (get2() == old.get2() * k) and (get3() == old.get3() * k).
		\sa      multConst().
	*/

	void multConst(double k);

	/*! 
		\brief   Función que multiplica a cada compontente del vector, la componente correspondiente del vector pasado como argumento.
		\param	 v: Vector que se multiplicará al vector actual (Tipo Vector3D)
		\post  	 (get1() == old.get1() * v.get1()) and (get2() == old.get2() * v.get2()) and (get3() == old.get3() * v.get3()).
		\sa      multVect().
	*/

	void multVect(ed::Vector3D v);


    //! \name Operadores de la clase
   
	/*!
		\brief     Operador de asigacion: Asigna las componentes del vector v al vector u.
		\param     v: Vector que se va a usar para copiar pasado como referencia constante (Tipo Vector3D).
		\post      (get1() == v.get1()) and (get2() == v.get2()) and (get3() == v.get3()).
	*/

	Vector3D & operator=(Vector3D const &v);

	/*!
		\brief     Operador de igualdad: compara si un Vector3D es igual a otro Vector3D
		\param     v: Vector con el que comparar pasado como referencia constante (Tipo Vector3D).
		\return	   Valor lógico al comparar la igualdad.
		\post      valorDevuelto == (get1() == v.get1()) and (get2() == v.get2()) and (get3() == v.get3()).
	*/

	bool operator == (Vector3D const &v) const;

	// COMPLETAR EL RESTO DE OPERADORES

	double operator*(Vector3D const &v) const;
	Vector3D & operator* (double k) const;
	Vector3D & operator+ (Vector3D const &v) const;
	Vector3D & operator+ () const;
	Vector3D & operator-(ed::Vector3D const &v) const;
	Vector3D & operator-() const;
	Vector3D & operator^(ed::Vector3D const &v) const;

	//! \name Funciones lectura y escritura de la clase Vector3D

	void leerVector3D();
	void escribirVector3D() const;

}; // Fin de la definición de la clase Vector3D


//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	/*!
		\brief     Operador que devuelve otro vector cuyas componentes se obtienen multiplicando por “k” las componentes del vector “objeto” pasado como parámetro.
		\param     k: Constante de tipo Double.
		\param     v: Vector con el que comparar pasado como referencia constante (Tipo Vector3D).
		\return	   Vector operado.
		\post      (valorDevuelto.get1() == v.get1() * k) and (valorDevuelto.get2() == v.get2() * k) and (valorDevuelto.get3() == v.get3() * k)
	*/

    Vector3D & operator* (double k, Vector3D const &v);

	/*!
		\brief     Operador que recoge por teclado las componentes del vector.
		\param     stream: Flujo de entrada de datos.
		\param     v: Vector que modificar. (Tipo Vector3D).
		\return	   Componentes modificadas.
	*/

    istream &operator>>(istream &stream, Vector3D &v);

	/*!
		\brief     Operador que muestra por pantalla las componentes del vector.
		\param     stream: Flujo de salida de datos.
		\param     v: Vector que mostrar. (Tipo Vector3D).
		\return	   Componentes mostradas.
	*/
	   
	ostream &operator<<(ostream &stream, Vector3D const &v);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif 
