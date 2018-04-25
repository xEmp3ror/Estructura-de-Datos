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

#include <cstdlib>

// Definición de la clase Fecha
#include "Fecha.hpp"

#include "macros.hpp"

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

		Medicion(Fecha fecha = Fecha(1,1,1), float precipitacion = 0.0) {

			_f = fecha;

			esPositivo(precipitacion);
			_precip = precipitacion;

			#ifndef NDEBUG
   				assert(getFecha() == fecha);
   				assert((abs(getPrecipitacion() - precipitacion)) < COTA_ERROR);
			#endif

		}

		Medicion(const ed::Medicion & m) {

			Fecha aux;
			float precip;

			aux = m.getFecha();
			_f = aux;

			precip = m.getPrecipitacion();
			_precip = precip;

			#ifndef NDEBUG
   				assert(getFecha() == m.getFecha());
   				assert((abs(getPrecipitacion() - m.getPrecipitacion())) < COTA_ERROR);
			#endif

		}

	//! \name Observadores: funciones de consulta de la clase Medicion

		inline Fecha getFecha() const { return _f; };

		inline float getPrecipitacion() const { return _precip; }; 

	//! \name Funciones de modificación de la clase Medicion

/*		inline float toUnsigned(float p) { //DEPRECATED.

			if(p < 0) {

				return -p;

			} else {

				return p;
			}
		}
*/
		inline bool esPositivo(float &precipitacion) {

			if(precipitacion < 0) {

				while(precipitacion < 0) {

				std::cout<<BIRED<<"ATENCIÓN: "<<BYELLOW<<"El dato de precipitación introducido es "<<BIRED<<"negativo"<<RESET<<BYELLOW<<". Por favor, introduzca un dato postivo: "<<RESET;
				std::cin>>precipitacion;
				
				}
			}

			
			return true;
		}

		inline void setFecha(Fecha f) { 

			_f = f; 

			#ifndef NDEBUG
				assert(getFecha() == f);
			#endif

		};

		inline void setPrecipitacion(float p) {

			esPositivo(p);
			_precip = p;			

			#ifndef NDEBUG
				assert((abs(getPrecipitacion() - p)) < COTA_ERROR);
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

			if (this != &m) {

				setFecha(m.getFecha());
				setPrecipitacion(m.getPrecipitacion());

				#ifndef NDEBUG
					assert(getFecha() == m.getFecha());
					assert((abs(getPrecipitacion() - m.getPrecipitacion())) < COTA_ERROR);
				#endif

			}	

/*			Fecha f;
			float precip;

			Medicion *n = new Medicion;

			f = m.getFecha();
			precip = m.getPrecipitacion();

			n -> setPrecipitacion(precip);
			n -> setFecha(f);

*/			

			return *this;
		}


	//! \name Funciones de lectura y escritura de la clase Medicion

		void leerMedicion();

		inline void escribirMedicion() {

			std::cout<<BYELLOW<<"Medición del día "<<BIGREEN<<getFecha().getDia()<<"/"<<getFecha().getMes()<<"/"<<getFecha().getAgno()<<BYELLOW<<": "<<BIBLUE<<getPrecipitacion()<<BYELLOW<<" litros por metro cuadrado."<<RESET<<std::endl;
			//std::cout<<BIGREEN<<getFecha().getDia()<<"-"<<getFecha().getMes()<<"-"<<getFecha().getAgno()<<" "<<getPrecipitacion()<<std::endl;
		}


}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

		ostream &operator<<(ostream &stream, ed::Medicion const &medicion);
		istream &operator>>(istream &stream, ed::Medicion &medicion);



} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif 
