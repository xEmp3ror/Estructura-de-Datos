/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  
	\date  
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"

int ed::ListaDoblementeEnlazadaOrdenadaMunicipios::nItems() const {

	int i=0;

	if (isEmpty()) { 

		return 0; //Para que devuelva 0 en caso de estar vacia. No cuenta el i++ final.
	}

	ed::NodoDoblementeEnlazadoMunicipio * puntero = getHead();

	while (puntero->getNext() != NULL) {

		i++;
		puntero = puntero -> getNext();
	}

		i++; //Contar ultimo elemento.

	return i;
}

ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getCurrentItem() const {

	#ifndef NDEBUG
		assert(!isEmpty());
	#endif

	return getCurrent() -> getItem();
}

ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getPreviousItem() const {

	#ifndef NDEBUG
		assert(!isEmpty() and !isFirstItem());
	#endif

	return getCurrent() -> getPrevious() -> getItem();
}

ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getNextItem() const {

	#ifndef NDEBUG
		assert(!isEmpty() and !isLastItem());
	#endif

		return getCurrent() -> getNext() -> getItem();

}

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isFirstItem() const {

	#ifndef NDEBUG
		assert (!isEmpty());
	#endif

	if (getCurrent() -> getPrevious() == NULL) {

		return true;

	} else {

		return false;
	}
}

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem() const {

	#ifndef NDEBUG
		assert(!isEmpty());
	#endif

	if (getCurrent() -> getNext() == NULL) {

		return true;
	
	} else {

		return false;
	}

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast() {

	#ifndef NDEBUG
		assert(!isEmpty());
	#endif

	while(!isLastItem()) {

		gotoNext();
	}
}	

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(ed::Municipio const & item) {

	if(isEmpty()) {

		return false;
	}

	gotoHead();

	while(!isLastItem()) {

		if(item == (getCurrentItem())) {

			#ifndef NDEBUG
				assert(getCurrentItem() == item);
			#endif

			return true;
		}

		gotoNext();
	}

	if(item == (getCurrentItem())) {

		#ifndef NDEBUG
			assert(getCurrentItem() == item);
		#endif

		return true;
	}

	return false;
}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(ed::Municipio const & item) {

	ed::NodoDoblementeEnlazadoMunicipio * nuevo;
	nuevo = new ed::NodoDoblementeEnlazadoMunicipio(item, NULL, NULL);

	if(isEmpty()) { //Cuando la lista esta vacia.

		setHead(nuevo); //Item se coloca como cabeza y current.
		setCurrent(getHead());

	} else { //Si no esta vacia.

		gotoHead(); //Vamos a la cabeza.

		while(!isLastItem()) { //Recorremos la lista hasta que se llegue al final o nuestro item vaya antes.

			if(item < getCurrentItem()) {

				break;
			}

			gotoNext();
		}

		if(nItems() == 1) { //Si solo hay un item, veamos si lo colocamos antes o despues.

			if(item < getCurrentItem()) { //Si va antes.

				nuevo -> setNext(getCurrent()); //Enlazamos el puntero Next de nuestro item con el actual.
				getCurrent() -> setPrevious(nuevo); //Enlazamos el puntero previous del item actual con nuestro item.
				gotoPrevious(); //Colocamos puntero en item.
				setHead(getCurrent()); //Cambiamos cabeza a nuestro item.

			} else {

				nuevo -> setPrevious(getCurrent()); //Enlazamos el puntero previous de nuestro item con el tem actual.
				getCurrent() -> setNext(nuevo); //Enlazamos el puntero next del item actual con nuestro item.
				gotoNext(); //Colocamos puntero en item.
			}

		#ifndef NDEBUG
			assert(!isEmpty() and getCurrentItem() == item);
		#endif

		return; //Return, ya que Exit te saca del programa completo.

		}

		//Mas de un Item.

		if(isFirstItem()) { //Si es la cabeza.

			nuevo -> setNext(getCurrent()); //Enlazamos el puntero Next de nuestro Item con el Item actual.
			getCurrent() -> setPrevious(nuevo); //Enlazamos el puntero previous del item actual con nuestro item.
			gotoPrevious(); //Colocamos puntero en item.
			setHead(getCurrent()); //Cambiamos la cabeza a nuestro item.

		} else if (isLastItem()) { //Si es el ultimo elemento. 

			if(getCurrentItem() < item) { //Si nuestro item va despues del item actual.

				nuevo -> setPrevious(getCurrent()); //Enlazamos el putnero previous de nuestro item con el item actual.
				getCurrent() -> setNext(nuevo); //Enlazamos el putnero next del item actual con nuestro item.
				gotoNext(); //Colocamos puntero en item.

			} else { //Si nuestro item va antes del item actual.

				nuevo -> setPrevious(getCurrent() -> getPrevious()); //Enlazamos el puntero previous de nuestro item con el previous del item actual.
				nuevo -> setNext(getCurrent()); //Enlazamos el puntero Next de nuestro item con el item actual.
				getCurrent() -> setPrevious(nuevo); //Enlazamos el puntero previous del item actual con nuestro item.
				gotoPrevious(); //Colocamos puntero en item.
				getCurrent() -> getPrevious() -> setNext(getCurrent()); //Desde nuestro item, enlazamos el puntero next del item previo a nuestro item con nuestro item.
			}

		} else { //Si esta en medio, se hace lo mismo que en el caso de que este en la ultima posicion y nuestro item vaya antes que el item actual.

			nuevo -> setPrevious(getCurrent() -> getPrevious());
			nuevo -> setNext(getCurrent());
			getCurrent() -> setPrevious(nuevo);
			gotoPrevious();
			getCurrent() -> getPrevious() -> setNext(getCurrent());
		}
	}

	#ifndef NDEBUG
		assert(!isEmpty() and getCurrentItem() == item);
	#endif
}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove() {

	#ifndef NDEBUG
		assert(!isEmpty());
	#endif

	int PreRemoveItems = nItems();

	if(nItems() == 1) { //Si solo hay un item, se borra dicho item. Ponemos a NULL Current y Head.

		delete getCurrent();
		_current = NULL; //Si se hace con un setCurrent(NULL) peta el aserto.
		_head = NULL; //Si se hace con un setHead(NULL) peta el aserto.

		//No se puede hacer un SET si se hace un delete getCurrent() previamente.

	} else { //Si hay mas de un elemento.

		if (isFirstItem()) { //Si es el primero.

			setHead(getCurrent() -> getNext()); //Se cambia la cabeza al item siguiente al actual.
			delete getCurrent(); //Se borra el actual.
			setCurrent(getHead()); //Se cambia el puntero current a la nueva cabeza.
			getCurrent() -> setPrevious(NULL); //Se pone a NULL el previous de la nueva cabeza.

		} else if (isLastItem()) { //Si es el ultimo.

			gotoPrevious(); //Colocamos puntero en el penultimo. 
			delete getCurrent() -> getNext(); //Borramos el ultimo item.
			getCurrent() -> setNext(NULL); //Se pone a NULL el puntero Next del ultimo item.

		} else { //Si esta en medio. 

			ed::NodoDoblementeEnlazadoMunicipio * aux = getCurrent() -> getNext(); //Creamos  auxiliar que guarde el nodo siguiente al actual.

			getCurrent() -> getNext() -> setPrevious(getCurrent() -> getPrevious()); // Se enlaza el previous del nodo siguiente con el anterior.
			getCurrent() -> getPrevious() -> setNext(getCurrent() -> getNext()); //Se enlaza el next del nodo anterior con el siguiente.
			delete getCurrent(); //Se borra el item actual.
			setCurrent(aux); //Colocamos el Current en el antiguo nodo siguiente del nodo que acabamos de borrar.
		}
	}

	#ifndef NDEBUG
		assert(PreRemoveItems == nItems() + 1);
	#endif
}