/**
* @file lado.hpp
* @brief Práctica 4: Lado.
* @author Rafael Román de los Reeyes
* @date Mayo de 2018
*/

#ifndef __EDGE_HPP__
#define __EDGE_HPP__

#include <string>
#include "vertex.hpp"

/**
* @brief Espacio de nombres para la asignatura Estructuras de Datos.
*/

namespace ed {
    /// Clase Edge.
    template <class T>
    class Edge {
        private:
            /// Dato del lado.
            T _data;
            /// Primer vértice.
            Vertex<std::string> _first;
            /// Segundo vértice.
            Vertex<std::string> _second;
        public:
            /** @name Observadores. */
            
            /**
            * @brief Devuelve el dato del lado.
            * @return Dato del lado.
            */
            inline T getData() const { return _data; }

            /**
            * @brief Devuelve el primer vértice del lado.
            * @return Primer vértice del lado (Vertex).
            */
            inline Vertex<std::string> getFirst() const { return _first; }

            /**
            * @brief Devuelve el segundo vértice del lado.
            * @return segundo vértice del lado (Vertex).
            */
            inline Vertex<std::string> getSecond() const { return _second; }

            /** @name Modificadores. */

            /**
            * @brief Fija el dato del lado.
            * @param data Dato del lado (T).
            */
            inline void setData(const T &data) { _data = data; }

            /**
            * @brief Fija el primer vértice.
            * @param first Vértice 1 (Vertex).
            */
            inline void setFirst(const Vertex<std::string> &first) { _first = first; }
            
            /**
            * @brief Fija el segundo vértice.
            * @param second Vértice 2 (Vertex).
            */
            inline void setSecond(const Vertex<std::string> &second) { _second = second; }

            /** @name Sobrecarga de operadores. */

            /**
            * @brief Sobrecarga del operador ==.
            * @param l Lado.
            * @return true si this->getFirst() == l.getFirst() && this->getSecond() == e.getSecond(), false en caso contrario.
            * @sa getFirst().
            * @sa getSecond().
            */
            inline bool operator == (const Edge<T> &l) const { return this->getFirst() == l.getFirst() && this->getSecond() == l.getSecond(); };
        };
    }

    #endif