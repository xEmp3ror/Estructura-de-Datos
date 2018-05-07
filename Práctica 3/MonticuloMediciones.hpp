/*!
	\file MonticuloMediciones.hpp
	\brief Se define el TAD MonticuloMediciones.
	\author 
	\date 
*/

#ifndef _MONTICULO_MEDICIONES_HPP
#define _MONTICULO_MEDICIONES_HPP

#include <vector>
#include <iostream>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMedicionesInterfaz.hpp"


// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

namespace ed
{

// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

class MonticuloMediciones : public MonticuloMedicionesInterfaz
{
	private:

		//! \name Atributos privados de la clase MonticuloMediciones

		std::vector <Medicion> monticulo;//!< Variable monticulo de tipo vector <Medicion>

		//! \name Métodos privados de la clase MonticuloMediciones

		/*! 
	      \fn     Medicion getElement(int pos);
	      \brief  Función que devuelve el elemento pedido
	      \attention Se utiliza el modificador const en la definición de la función
	      \param  pos posición actual
	      \pre    pos debe ser mayor que 0 y menor que el tamaño del montículo.
	      \post   Ninguna
	      \sa     Medicion getElement(int pos); 
	    */

		inline Medicion getElement(int const &pos) const {

			#ifndef NDEBUG
				assert(pos >= 0 && pos < size());
			#endif 

			return monticulo[pos];	
		}

		/*! 
	      \fn     Medicion setElement(int pos);
	      \brief  Función que modifica el elemento i-ésimo del montículo.
	      \param  pos posición actual
	      \param  m Objeto de tipo medición.
	      \pre    pos debe ser mayor que 0 y menor que el tamaño del montículo.
	      \post   Ninguna
	      \sa     Medicion setElement(int pos); 
	    */

		inline void setElement(int pos, Medicion m) {
			
			#ifndef NDEBUG
				assert(pos >= 0 && pos < size());
			#endif 

//			Medicion aux(m);

			monticulo.at(pos).setFecha(m.getFecha());
			monticulo.at(pos).setPrecipitacion(m.getPrecipitacion());

			#ifndef NDEBUG
				assert(getElement(pos) == m);
			#endif 
		}

 		/*! 
	      \fn     int getLeftChild(const int pos);
	      \brief  Función que permite conocer la posicion del hijo izquierdo
	      \attention Se utiliza el modificador const en la definición de la función
	      \param  pos posición actual
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     int getLeftChild(const int pos); 
	    */

		inline int getLeftChild(const int pos) {

			return pos*2+1;
		}
		/*! 
	      \fn     int getRightChild(const int pos);
	      \brief  Función que permite conocer la posicion del hijo derecho
	      \attention Se utiliza el modificador const en la definición de la función
	      \param  pos posición actual
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     int getRightChild(const int pos); 
	    */
		inline int getRightChild(const int pos) {

			return pos*2+2;
		}
		/*! 
	      \fn     int getParent(const int pos);
	      \brief  Función que permite conocer la posicion del Padre
	      \attention Se utiliza el modificador const en la definición de la función
	      \param  pos posición actual
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     int getParent(const int pos); 
	    */
		inline int getParent(const int pos) {

			return (pos-1)/2;
		}
		/*! 
	      \fn     void shiftUp(int pos);
	      \brief  Función que permite subir el elemento de la posicion pos hasta su posicion correcta
	      \param  pos posición actual
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     void shiftUp(int pos); 
	    */
		void shiftUp(int pos);
		/*! 
	      \fn     void shiftDown(int pos);
	      \brief  Función que permite hundir el elemento de la posicion pos hasta su posicion correcta
	      \param  pos posición actual
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     void shiftDown(int pos); 
	    */
		void shiftDown(int pos);
		/*! 
	      \fn     bool has(Medicion m);
	      \brief  Función que comprueba si la medición está incluida en el montículo.
	      \param  m Objeto de tipo medicion a comprobar.
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     void has(Medicion m); 
	    */
		bool has(Medicion m);

	  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Métodos públicos de la clase MonticuloMediciones
	public:

		//! \name Constructor

		MonticuloMediciones() {

			#ifndef NDEBUG
				assert(isEmpty());
			#endif
		}


		//! \name Observadores

		/*! 
	      \fn     bool isEmpty()
	      \brief  Función que permite comprobar que el monticulo de mediciones esta vacio.
	      \attention Se utiliza el modificador const en la definición de la función
	      \return 
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     
	    */

		inline bool isEmpty() const { return monticulo.empty(); }

		/*! 
	      \fn     Medicion size()
	      \brief  Función que devuelve el numero de elementos del monticulo de mediciones.
	      \attention Se utiliza el modificador const en la definición de la función
	      \return 
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     
	    */
		inline int size() const { return monticulo.size(); }

		/*! 
	      \fn     Medicion top()
	      \brief  Función que permite acceder al primer elemento del monticulo de mediciones.
	      \attention Se utiliza el modificador const en la definición de la función
	      \return 
	      \pre    Monticulo no vacio
	      \post   El valor devuelto debe ser el superior
	      \sa     
	    */
		inline Medicion top() { 

			return monticulo.front();

			#ifndef NDEBUG
				assert(monticulo.front() == getElement(0));
			#endif

		}

		/*! 
	      \fn     Medicion totalMediciones()
	      \brief  Funcion que imprime por pantalla el total de mediciones.
	      \return 
	      \pre    
	      \post   
	      \sa     
	    */
		void totalMediciones();

		////////////////////////////////////////////////////////////

		//! \name Operaciones de modificación

		/*! 
	      \fn     void insert(Medicion const &m)
	      \brief  Función que permite insertar una medición en el monticulo actual.
	      \param  Objeto de tipo medicion pasado como referencia constante.
	      \return Funcion void.
	      \post   El monticulo no debe de estar vacío.
	      \sa     
	    */

		void insert(Medicion const &m);

		/*! 
	      \fn     void remove()
	      \brief  Función que permite eliminar una medición en el monticulo actual.
	      \param  Ninguno.
	      \return Funcion void.
	      \pre    Monticulo no vacio
	      \sa     
	    */

		void remove();

		/*! 
	      \fn     void removeAll()
	      \brief  Función que permite eliminar todas las mediciones en el monticulo actual.
	      \param  Ninguno.
	      \return Funcion void.
	      \pre    Ninguna.
	      \post   Monticulo no vacio.
	      \sa     
	    */

		void removeAll();

		/*! 
	      \fn     void modify()
	      \brief  Modifica la posición que ocupa la cima y actualiza el montículo para mantenerlo ordenado.
	      \param  Ninguno.
	      \return Funcion void.
	      \pre    Monticulo no vacio
	      \post   La medicion de la cima debe existir.
	      \sa     
	    */

		void modify(Medicion &m);


		//! \name Operadores
   
		/*! 
		\brief     Operador de asignación: operador que "copia" un monticulo en otro monticulo
		\attention Se sobrecarga el operador de asignación "="
		\note      Función inline
		\warning   Se requiere que las funciones tengan el modificador const
		\param     objeto: objeto de la clase MonticuloMediciones pasado como referencia constante
		\pre       El objeto es distinto del objeto actual
		*/
		inline MonticuloMediciones & operator=(MonticuloMediciones const &m) {

/*   		if (this != &m) {

   				for (int i = 0; i < size(); ++i) {

   					getElement(i) = m.getElement(i);;
   				}
   			}

   			return *this;
		} 
*/
			Medicion aux;

   			if (this != &m) {

   				for (int i = 0; i < m.size(); i++) {

   					this -> monticulo.push_back(m.getElement(i));
   				}
   			}

   			return *this;
		} 
 

		////////////////////////////////////////////////////////////////////

		//! \name Función de escritura

		/*! 
		\brief Escribe por pantalla los valores de los atributos de todas las mediciones
		\pre   No puede estar vacio
		\post  Ninguna
		*/
		void print();

	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
