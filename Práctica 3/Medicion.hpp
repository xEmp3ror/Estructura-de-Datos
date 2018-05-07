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

   		/*! 
		\brief     Constructor que crea una medicion
		\attention Función sobrecargada        
		\note      Función inline
	 	\warning   Los parámetros tienen valores por defecto
		\param     fecha: fecha en el calendario; valor por defecto: 1,1,1
		\param     precipitacion: cantidad de lluvia; valor por defecto: 0.0
		\pre       Ninguna
		\post      La fecha y precipitacion creadas deben ser iguales a las recibidas
		\sa        setDia, setMes(), setAgno(), esCorrecta
		*/
		inline Medicion(Fecha fecha = Fecha(1,1,1), float precipitacion = 0.0) {

			_f = fecha;

			esPositivo(precipitacion);
			_precip = precipitacion;

			#ifndef NDEBUG
   				assert(getFecha() == fecha);
   				assert((abs(getPrecipitacion() - precipitacion)) < COTA_ERROR);
			#endif

		}

		/*! 
		\brief     Constructor de "copia" que crea una medicion a partir de otra medicion
		\attention Función sobrecargada        
		\note      Función inline
		\param     m: objeto de la clase Medicion utilizado para proporcionar los valores iniciales de la nueva medicion. Objeto pasado como referencia constante.
		\post      Los atributos _fecha y precipitacion_de_lluvia deben tener los valores de los atributos del objeto pasado como argumento
		\sa        getFecha(), getPrecipitacion()
		*/
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

		/*! 
		\brief   Función que devuelve una fecha
		\attention Se utiliza el modificador const en la definición de la función 
		\note    Función inline
		\return  Valor del atributo que representa la fecha (tipo Fecha)
		\pre     Ninguna
		\post    Ninguna
		*/
		inline Fecha getFecha() const { return _f; };

		/*! 
		\brief   Función que devuelve una precipitacion
		\attention Se utiliza el modificador const en la definición de la función 
		\note    Función inline
		\return  Valor del atributo que representa la fecha (tipo Fecha)
		\pre     Ninguna
		\post    Ninguna
		*/
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
		/*! 
		\brief   Función que comprueba si la medición pasada es positiva y la modifica en caso contrario.
		\attention Se utiliza el modificador const en la definición de la función 
		\note    Función inline
		\param   precipitacion: Float pasado como referencia.
		\return  Valor del atributo que representa la fecha (tipo Fecha)
		\pre     Ninguna
		\post    Ninguna
		*/
		inline bool esPositivo(float &precipitacion) {

			if(precipitacion < 0) {

				while(precipitacion < 0) {

				std::cout<<BIRED<<"ATENCIÓN: "<<BYELLOW<<"El dato de precipitación introducido es "<<BIRED<<"negativo"<<RESET<<BYELLOW<<". Por favor, introduzca un dato postivo: "<<RESET;
				std::cin>>precipitacion;

					while(std::cin.fail()) {

				        std::cout<<BIRED<<"ATENCIÓN: "<<BYELLOW<<"El dato de precipitación introducido no se corresponde con un "<<BIRED<<"numero positivo"<<RESET<<BYELLOW<<". Por favor, introduzca un dato postivo: "<<RESET;
				        std::cin.clear();
				        std::cin.ignore(256,'\n');
				        std::cin >> precipitacion;

				        esPositivo(precipitacion);
    				}

				}
			}


			return true;
		}

		/*! 
		\brief Función que asigna un nuevo valor a un objeto Fecha
		\note  Función inline
		\param fecha: nuevo valor de la fecha
		\pre   ninguna
		\post  El atributo _fecha de Fecha debe tener el valor "fecha" 
		\sa    setPrecipitacion()
		*/
		inline void setFecha(Fecha f) {

			_f = f;

			#ifndef NDEBUG
				assert(getFecha() == f);
			#endif

		};

		/*! 
		\brief Función que asigna un nuevo valor a la precipitacion
		\note  Función inline
		\param precipitacion: nuevo valor de la precipitacion de una medicion
		\post  El atributo precipitacion_de_lluvia de Medicion debe tener el valor "precipitacion" 
		\sa    setDia, setAgno
		*/
		inline void setPrecipitacion(float p) {

			esPositivo(p);
			_precip = p;

			#ifndef NDEBUG
				assert((abs(getPrecipitacion() - p)) < COTA_ERROR);
			#endif
		}


	//! \name Operadores

		/*! 
		\brief     Operador de igualdad: compara si dos mediciones son iguales
		\attention Se sobrecarga el operador de asignación "=="
		\note      Función inline
		\param     medicion: Medicion pasada como referencia constante
		\pre       Ninguna
		\post      Ninguna
		*/
		bool operator == (Medicion const &m) const {

			if (m.getFecha() == getFecha()) {

				return true;

			} else {

				return false;
			}
		}

		/*! 
		\brief     Operador de asignación: operador que "copia" una medicion en otra medicion
		\attention Se sobrecarga el operador de asignación "="
		\note      Función inline
		\warning   Se requiere que las funciones de acceso getPrecipitacion y getFecha tengan el modificador const
		\param     medicion: objeto de la clase Medicion pasado como referencia constante
		\pre       El objeto es distinto del objeto actual
		\pre	   El objeto representa una medicion correcta
		*/
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

		/*! 
		\brief   Lee desde el teclado los nuevos valores de los atributos de una medicion
		\warning Se deben teclear números
		\note	 Funcion inline
		\pre     ninguna
		\post    ninguna
		*/
		void leerMedicion();

		/*! 
		\brief Escribe por pantalla los valores de los atributos de una medicion
		\pre   Ninguna
		\post  Ninguna
		*/
		inline void escribirMedicion() {

			std::cout<<BYELLOW<<"Medición del día "<<BIGREEN<<getFecha().getDia()<<"/"<<getFecha().getMes()<<"/"<<getFecha().getAgno()<<BYELLOW<<": "<<BIBLUE<<getPrecipitacion()<<BYELLOW<<" litros por metro cuadrado."<<RESET<<std::endl;
			//std::cout<<BIGREEN<<getFecha().getDia()<<"-"<<getFecha().getMes()<<"-"<<getFecha().getAgno()<<" "<<getPrecipitacion()<<std::endl;
		}


}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

		/*!
  		\brief     Sobrecarga del operador de entrada o lectura ">>"
		\param     stream Flujo de entrada
		\param     medicion: pasada como referencia 
		\pre       Ninguna
		\post      Ninguna
		\sa        operator<<()
    	*/
		ostream &operator<<(ostream &stream, ed::Medicion const &medicion);
		
		/*!
  		\brief     Sobrecarga del operador de salida o escritura "<<"
				   \n Se escribe la medicion por pantalla con el formato (d)d-(m)m--aaaa precipitacion
		\param     stream Flujo de salida
		\param     medicion: pasada como referencia constante
		\pre       Ninguna
		\post      Ninguna
		\sa        operator>>()
    	*/
		istream &operator>>(istream &stream, ed::Medicion &medicion);



} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif
