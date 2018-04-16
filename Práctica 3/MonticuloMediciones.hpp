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
	      \param  pos posición actual
	      \pre    pos debe ser mayor que 0 y menor que el tamaño del montículo.
	      \post   Ninguna
	      \sa     Medicion getElement(int pos); 
	    */

		Medicion getElement(int pos) const {

			#ifndef NDEBUG
				assert(pos >= 0 && pos < size());
			#endif 

			return monticulo.at(pos);	
		}

		void setElement(int pos, Medicion m) {
			
			#ifndef NDEBUG
				assert(pos >= 0 && pos < size());
			#endif 

			Medicion aux(m);

			monticulo.at(pos) = aux;

			#ifndef NDEBUG
				assert(getElement(pos) == m);
			#endif 
		}

 		/*! 
	      \fn     int getLeftChild(const int pos);
	      \brief  Función que permite conocer la posicion del hijo izquierdo
	      \param  pos posición actual
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     int getLeftChild(const int pos); 
	    */

		int getLeftChild(const int pos) {

			return pos*2+1;
		}
		/*! 
	      \fn     int getRightChild(const int pos);
	      \brief  Función que permite conocer la posicion del hijo derecho
	      \param  pos posición actual
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     int getRightChild(const int pos); 
	    */
		int getRightChild(const int pos) {

			return pos*2+2;
		}
		/*! 
	      \fn     int getParent(const int pos);
	      \brief  Función que permite conocer la posicion del Padre
	      \param  pos posición actual
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     int getParent(const int pos); 
	    */
		int getParent(const int pos) {

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
		void shiftUp(int pos) {

			if (pos > 0) {

				if(monticulo[pos].getPrecipitacion() > monticulo[getParent(pos)].getPrecipitacion()) { 

					std::swap (monticulo[pos], monticulo[getParent(pos)]);

					shiftUp(getParent(pos));
				}
			}
		}
		/*! 
	      \fn     void shiftDown(int pos);
	      \brief  Función que permite hundir el elemento de la posicion pos hasta su posicion correcta
	      \param  pos posición actual
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     void shiftDown(int pos); 
	    */
		void shiftDown(int pos) {

			int n = pos, 
				lChild = getLeftChild(pos), 
				rChild = getRightChild(pos);

			if( (unsigned)lChild < monticulo.size() and monticulo[lChild].getPrecipitacion() > monticulo[n].getPrecipitacion()) {

				n = lChild;
			}

			if((unsigned)rChild < monticulo.size() and monticulo[rChild].getPrecipitacion() > monticulo[n].getPrecipitacion()) {

				n = rChild;
			}
			if (pos != n) {

				std::swap (monticulo[pos],monticulo[n]);

				shiftDown(n);
			}
		}

		bool has(Medicion m) {

			int pos;

			for(pos = 0; pos < size(); pos++) {

				if (m == monticulo.at(pos)) {

					return true;
				
				} else {

					return false;
				}
			}
		}

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
	      \brief  Función que permite comprobar que el monticulo de mediciones esta vacio
	      \return 
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     
	    */

		inline bool isEmpty() const { return monticulo.empty(); }

		/*! 
	      \fn     Medicion size()
	      \brief  Función que devuelve el numero de elementos del monticulo de mediciones.
	      \return 
	      \pre    Ninguna
	      \post   Ninguna
	      \sa     
	    */
		inline int size() const { return monticulo.size(); }

		/*! 
	      \fn     Medicion top()
	      \brief  Función que permite acceder al primer elemento del monticulo de mediciones.
	      \return 
	      \pre    Monticulo no vacio
	      \post   El valor devuelto debe ser el superior
	      \sa     
	    */
		inline Medicion top() const { 

			return monticulo.front();

			#ifndef NDEBUG
				assert(monticulo.front() == getElement(0));
			#endif

		}

		////////////////////////////////////////////////////////////

		//! \name Operaciones de modificación

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN


		//! \name Operadores
   
		// COMPLETAR
 

		////////////////////////////////////////////////////////////////////

		//! \name Función de escritura

		// COMPLETAR

	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
