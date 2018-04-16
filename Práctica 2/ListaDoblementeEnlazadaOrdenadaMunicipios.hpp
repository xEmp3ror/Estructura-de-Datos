/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.hpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  
	\date  
	\version 1.0

*/

#ifndef __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
#define __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaOrdenadaMunicipiosInterfaz.hpp"

#include "NodoDoblementeEnlazadoMunicipio.hpp"

#include "Municipio.hpp"

// DEBES ESPECIFICAR LAS FUNCIONES DE LA CLASE ListaDoblementeEnlazadaOrdenadaMunicipios


/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos

*/ 
namespace ed {
 
/*!	
  \class ListaDoblementeEnlazadaOrdenadaMunicipios 
  \brief Definición de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
	  	\n Lista doblemente enlazada de nodos de municipios ordenados alfabéticamente de forma ascendente 
*/
  class ListaDoblementeEnlazadaOrdenadaMunicipios: public ed::ListaOrdenadaMunicipiosInterfaz
  {
	//! \name  Atributos y métodos privados 

	private:
		ed::NodoDoblementeEnlazadoMunicipio *_head;    //!< \brief puntero al primer nodo de la lista
		ed::NodoDoblementeEnlazadoMunicipio *_current; //!< \brief puntero al nodo current de la lista

    // \name Observadores privados 

    inline ed::NodoDoblementeEnlazadoMunicipio * getHead() const
	{

		#ifndef NDEBUG
			// Se comprueba la precondición
			assert(!isEmpty());
		#endif //NDEBUG	

		return this->_head;
	}

	inline ed::NodoDoblementeEnlazadoMunicipio * getCurrent() const
	{

		#ifndef NDEBUG
			// Se comprueba la precondición
			assert(!isEmpty());
		#endif //NDEBUG	

		return this->_current;
	}

    //! \name Modificadores privados 

	inline void setHead(ed::NodoDoblementeEnlazadoMunicipio *head) 
	{
		this->_head = head;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getHead() == head);
		#endif //NDEBUG		
	}

    inline void setCurrent(ed::NodoDoblementeEnlazadoMunicipio *current) 
	{
		this->_current = current;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getCurrent() == current);
		#endif //NDEBUG		
	}


	//! \name  Métodos públicos

	public:

	//! \name Constructores

    /*! 
		\brief Construye una lista vacía
		\note  Función inline
		\post  isEmpty() == true
	*/
	inline ListaDoblementeEnlazadaOrdenadaMunicipios()
    {
		  this -> _head    = NULL;
		  this -> _current = NULL;

		  #ifndef NDEBUG
		  //Comprobacion de la Postcondicion.
		  	assert(this -> isEmpty());
		  #endif //NDEBUG.	
	}	
  
	//! \name Destructor 

    /*! 
		\brief Destruye una lista liberando la memoria de sus nodos
		\note Función codificada en el fichero cpp
		\post isEmpty() == true
	*/

	~ListaDoblementeEnlazadaOrdenadaMunicipios ()
     {
		  removeAll();
     }


	//! \name Observadores públicos 

	/*!
		\brief  Comprueba si la lista está vacía
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
        \return true, si la lista está vacía; false, en caso contrario
    */

	inline bool isEmpty() const
	{
  		if(this -> _head == NULL) {

  			return true;

  		} else {

  			return false;
  		}
	}

	int nItems() const;

	ed::Municipio const & getCurrentItem() const;

	ed::Municipio const & getPreviousItem() const;

	ed::Municipio const & getNextItem() const;

	bool isFirstItem() const;

	bool isLastItem() const;

    //! \name Modificadores públicos

	inline void gotoHead() {

		#ifndef NDEBUG
			assert(!isEmpty());
		#endif //NDEBUG

		setCurrent(getHead());

		#ifndef NDEBUG
			assert(isFirstItem());
		#endif //NDEBUG

	}

	void gotoLast();

	inline void gotoPrevious() {

		#ifndef NDEBUG
			assert(!isEmpty() and !isFirstItem());
		#endif

		setCurrent(getCurrent()->getPrevious());

	}

	inline void gotoNext() {

		#ifndef NDEBUG
			assert(!isEmpty() and !isLastItem());
		#endif //NDEBUG

		setCurrent(getCurrent()->getNext());
	}

	bool find(ed::Municipio const & item);

	void insert(ed::Municipio const & item);

	void remove();

	void removeAll() {

		if(!isEmpty()) {

		  	gotoHead();

		  	while(!isEmpty()) {

		  		remove();
		  	}
		  }

		  #ifndef NDEBUG
		  		assert(isEmpty());
		  #endif
	}

	//setHead y setCurrent (pag 8 PDF)
	

}; // Fin de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
 
} //namespace ed
 
#endif // __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
