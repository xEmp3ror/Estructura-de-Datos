/**
* @file vertex.hpp
* @brief Práctica 4: Vértice.
* @author Rafael Román de los Reeyes
* @date Mayo de 2018
*/

#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

#include <iostream>
#include "macros.hpp"

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>
#include <cstdlib>
#include <cmath>
// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed {

	/// Clase Vertex.
    class Vertex{
        private:
			/// Etiqueta del vértice.
			int _label;
			/// Abcisa del vértice.
			double _x;
            ///Ordenada del vértice.
            double _y;
        public:
			/** @name Observadores. */
			
			/**
			* @brief Devuelve la etiqueta del vértice.
			* @return Etiqueta del vértice.
			*/
			inline const int & getLabel() const { return _label; }
			
			/**
			* @brief Devuelve el dato X del vértice.
			* @return Dato del vértice.
			*/
			inline const double & getDataX() const { return _x; }

            /**
            * @brief Devuelve el dato Y del vértice.
            * @return Dato del vértice.
            */
            inline const double & getDataY() const { return _y; }

			/** @name Modificadores. */

			/**
			* @brief Establece la etiqueta del vértice.
			* @param label Etiqueta del vértice (int).
			*/
			inline void setLabel(const int &label) { _label = label; }

        	/**
        	* @brief Establece el dato del vértice.
        	* @param x Dato X del vértice.
            * @param y Dato Y del vértice.
        	*/
        	inline void setData(double x, double y) { 

                _x = x;
                _y = y;
            }

        	/** @name Sobrecarga de operadores. */

        	/**
        	* @brief Sobrecarga del operador =.
        	* @param v Vértice.
        	* @return Referencia al objeto actual.
        	*/
        	inline Vertex &operator=(const Vertex &v) {

                if(this != &v) {

                    setData(v.getDataX(),v.getDataY());
                    setLabel(v.getLabel());
                }

                return *this;
            }

            /**
            * @brief Sobrecarga del operador ==.
            * @param v Vértice.
            * @return true Si el item y la etiqueta son iguales, false en caso contrario.
            */
            inline bool operator==(const Vertex &v) const {

                return ((getLabel() == v.getLabel()) 
                         and (getDataX() == v.getDataX()) 
                         and (getDataY() == v.getDataY()));
            }
    };

            /**
            * @brief Operador de entrada.
            */
            std::istream &operator>>(std::istream &stream, ed::Vertex &v);

             /**
            * @brief Operador de salida.
            */
            std::ostream &operator<<(std::ostream &stream, const ed::Vertex &v);

}

#endif