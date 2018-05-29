/**
* @file edge.hpp
* @brief Práctica 4: Lado.
* @author Rafael Román de los Reeyes
* @date Mayo de 2018
*/

#ifndef __EDGE_HPP__
#define __EDGE_HPP__

#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include <iostream>

#include "vertex.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed {

    /// Clase Edge.
    class Edge {
        private:
            /// Dato del lado.
            double _item;
            /// Primer vértice.
            ed::Vertex _first;
            /// Segundo vértice.
            ed::Vertex _second;
        public:
            /** @name Observadores. */
            
            /**
            * @brief Devuelve el dato del lado.
            * @return Dato del lado.
            */
            inline const double getItem() const { return _item; }

            /**
            * @brief Comprueba si el vértice pasado es el extremo de un lado.
            * @note Halecs Function.
            * @return true Si es el extremo, false en caso contrario.
            */
            inline bool has(ed::Vertex v) const {

                if(v == getFirst() || v == getSecond()) {

                    return true;

                } else {

                    return false;
                }
            }

            /**
            * @brief Devuelve el primer vértice del lado.
            * @return Primer vértice del lado (Vertex).
            */
            inline ed::Vertex getFirst() const { return _first; }

            /**
            * @brief Devuelve el segundo vértice del lado.
            * @return segundo vértice del lado (Vertex).
            */
            inline ed::Vertex getSecond() const { return _second; }

            /** @name Modificadores. */

            /**
            * @brief Fija el dato del lado.
            * @param data Dato del lado (T).
            */
            inline void setItem(const double & item) { _item = item; }

            /**
            * @brief Fija el primer vértice.
            * @param v Vértice 1 (Vertex).
            */
            inline void setFirst(const ed::Vertex &v) { _first = v; }
            
            /**
            * @brief Fija el segundo vértice.
            * @param v Vértice 2 (Vertex).
            */
            inline void setSecond(const ed::Vertex &v) { _second = v; }

            /** @name Sobrecarga de operadores. */

            /**
            * @brief Sobrecarga del operador ==.
            * @param l Lado.
            * @return true si this->getFirst() == l.getFirst() && this->getSecond() == e.getSecond(), false en caso contrario.
            * @sa getFirst().
            * @sa getSecond().
            */
            inline bool operator==(const Edge &l) const {

            return ((getItem() == l.getItem()) 
                     and (getFirst() == l.getFirst())
                     and (getSecond() == l.getSecond()));
            }

            /**
            * @brief Sobrecarga del operador =.
            * @return Referencia al objeto actual.
            */
            inline Edge &operator=(const Edge &l) {

                if(this != &l) {

                    setItem(l.getItem());
                    setFirst(l.getFirst());
                    setSecond(l.getSecond());
                }

                return *this;
            }

    };
}

#endif