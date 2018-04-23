/*!
	\file MonticuloMediciones.cpp
	\brief Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author 
	\date 
*/

//#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMediciones.hpp"

#include "macros.hpp"

////////////////////////////////////////////////////////////////////

// Métodos privados de la clase MonticuloMediciones

	void ed::MonticuloMediciones::shiftUp(int pos) {

			if (pos > 0) {

				if(monticulo[pos].getPrecipitacion() > monticulo[getParent(pos)].getPrecipitacion()) { 

					std::swap (monticulo[pos], monticulo[getParent(pos)]);

					shiftUp(getParent(pos));
				}
			}
		}

	void ed::MonticuloMediciones::shiftDown(int pos) {

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

	bool ed::MonticuloMediciones::has(Medicion m) {

		int pos;

		for(pos = 0; pos < size(); pos++) {

			if (m == monticulo.at(pos)) {

				return true;
			
			} 
		}

		return false;
	}

////////////////////////////////////////////////////////////////////////////////////7

// Métodos públicos de la clase MonticuloMediciones

	void ed::MonticuloMediciones::insert(ed::Medicion &m) {

		if(size() == 0) {

			setElement(0, m);

		} else {

			setElement(size(), m);
			shiftUp(size());
		}
	}

	void ed::MonticuloMediciones::remove() {

		#ifndef NDEBUG
			assert(isEmpty() == false);
		#endif

		if(isEmpty()) {

			std::cout<<BIRED<<"El montículo está vacío."<<RESET<<std::endl;
			return;
		}

		ed::Medicion aux = getElement(size() - 1);

		setElement(0, aux);
		shiftDown(0);
	}

	void ed::MonticuloMediciones::removeAll() {

		int tam = size();

		if (isEmpty()) {

			std::cout<<BIRED<<"El montículo ya está vacío."<<RESET<<std::endl;
			return;
		}

		for (int i = 0; i < tam; i++) {

			remove();
		}

		#ifndef NDEBUG
			assert (isEmpty() == true);
		#endif
	}

	void ed::MonticuloMediciones::modify(ed::Medicion &m) {

		#ifndef NDEBUG
			assert (isEmpty() == false);
		#endif

		setElement( 0, m);
		shiftDown(0);

		#ifndef NDEBUG
			assert (has(m) == true);
		#endif
	}




