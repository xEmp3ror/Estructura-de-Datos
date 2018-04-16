/*! 
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica 
*/

#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_

#include <ctime>

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

// Definición de la clase Fecha
#include "Fecha.hpp"


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {

//!  Definición de la clase Medicion 
class Medicion
{
  //! \name Atributos privados de la clase Medicion
   private: 

		Fecha _f;
		float _precip;

   //! \name Funciones o métodos públicos de la clase Medicion
   public:

	//! \name Constructor de la clase Medicion

		Medicion(int dia=1, int mes=1, int anno=1, float precipitacion = 0.0) {

			_f.setDia(dia);
			_f.setMes(mes);
			_f.setAgno(anno);

			_precip = toUnsigned(precipitacion);

		}

		Medicion(const ed::Medicion & m) {

			Fecha aux;

			aux = m.getFecha();

			_f = aux;

		}

	//! \name Observadores: funciones de consulta de la clase Medicion

		inline Fecha getFecha() const { return _f; };

		inline float getPrecipitacion() const { return _precip; }; 

	//! \name Funciones de modificación de la clase Medicion

		inline float toUnsigned(float p) {

			if(p < 0) {

				return -p;

			} else {

				return p;
			}
		}

		inline bool esPositivo(float p) {

			if(p < 0) {

				return false;

			} else {

				return true;
			}

		}

		inline void setFecha(Fecha f) { 

			_f = f; 

			#ifndef NDEBUG
				assert(getFecha() == f);
			#endif

		};

		inline void setPrecipitacion(float p) {

			p = toUnsigned(p); //PREGUNTAR SI HACE FALTA ASERTO.

			_precip = p;

			#ifndef NDEBUG
				assert(getPrecipitacion() == p);
			#endif
		}


	//! \name Operadores
   
		bool operator == (Medicion const &m) const {

			if (m.getFecha() == getFecha()) {

				return true;

			} else {

				return false;
			}
		}

		Medicion & operator = (Medicion const & m) {

			Fecha f;
			float precip;

			Medicion *n = new Medicion;

			f = m.getFecha();
			precip = m.getPrecipitacion();

			n -> setPrecipitacion(precip);
			n -> setFecha(f);

			return *n;
		}


	//! \name Funciones de lectura y escritura de la clase Medicion

		void leerMedicion();


}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

		ostream &operator<<(ostream &stream, ed::Medicion const &medicion);
		istream &operator>>(istream &stream, ed::Medicion &medicion);



} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif 
