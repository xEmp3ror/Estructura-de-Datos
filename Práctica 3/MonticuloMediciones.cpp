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

			if(monticulo.at(pos).getPrecipitacion() > monticulo.at(getParent(pos)).getPrecipitacion()) { 

				std::swap(monticulo.at(pos), monticulo.at(getParent(pos))); //NO INTERCAMBIA.

//				ed::Medicion aux = getElement(pos);

//	            setElement(getParent(pos), aux);  //a = aux a = b b = aux
//	            setElement(pos, getElement(getParent(pos)));

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

	void ed::MonticuloMediciones::insert(ed::Medicion const &m) {
		
//		monticulo.at(size()) = m;
//		shiftUp(size());

		monticulo.push_back(m);
		shiftUp(size()-1);		
	}

	void ed::MonticuloMediciones::remove() {

		#ifndef NDEBUG
			assert(isEmpty() == false);
		#endif

		if(isEmpty()) {

			std::cout<<BIRED<<"El montículo está vacío."<<RESET<<std::endl;
			return;
		}

		if(size() == 1) {
			
			ed::Medicion aux;
			setElement(0, aux);

		} else {

		ed::Medicion aux2 = getElement(size() - 1);

//		monticulo.pop_back(size() - 1);

		setElement(0, aux2);
		shiftDown(0);

		}
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


	void ed::MonticuloMediciones::print() {

		if (isEmpty() == true) {

			std::cout<<BIRED<<"ATENCIÓN: "<<BYELLOW<<"No se puede operar con el montículo porque está "<<BLINK<<"vacío"<<RESET<<BYELLOW<<"."<<RESET<<std::endl;
		}

		for (int i = 0; i < size(); i++) {
				
            	getElement(i).escribirMedicion();
        	}

/*		int tam = size();
		Medicion aux;
		Fecha f;

		std::string fecha, f1, f2, f3;

		for (int i = 0; i < tam; i++) {

			aux = getElement(i);
			f = aux.getFecha();

			f1 = f.getDia();
			f2 = f.getMes();
			f3 = f.getAgno();

			fecha = f1 + " de " + f2 + " de " + f3;

			std::cout<<BYELLOW<<"Medición del día "<<BIGREEN<<fecha<<BYELLOW<<": "<<BIBLUE<<aux.getPrecipitacion()<<BYELLOW<<" litros por metro cuadrado."<<RESET<<std::endl;
		}
*/	}

