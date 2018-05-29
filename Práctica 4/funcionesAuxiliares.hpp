/**
* @file funcionesAuxiliares.hpp
* @brief Práctica 4: Funciones Auxiliares.
* @author Rafael Román de los Reeyes
* @date Mayo de 2018
*/

#ifndef _AUXILIARES_
#define _AUXILIARES_

#include "macros.hpp"
#include "Graph.hpp"

namespace ed {

	/**
	* @brief Menú principal del programa que gestiona la Práctica 4.
	* @return Entero.
	*/
	int menu();

	/**
	* @brief Muestra por pantalla si el grafo estándar contiene algún dato.
	*/
	void isEmpty(ed::Graph const & graph);


	/**
	* @brief Carga un fichero que contenga un grafo.
	* @param fileName Nombre del fichero a abrir.
	* @param graph Grafo que se va a rellenar.
	*/
	void loadFile(std::string const & fileName, ed::Graph & graph);

	/**
	* @brief Guarda los grafos con los que se ha operado en el fichero indicado.
	* @param fileName Nombre del fichero con el que se va a guardar.
	* @param graph Grafo estándar que se guardará.
	* @param gPrim Grafo del algoritmo de Prim que se guardará.
	* @param gKruskal Grafo del algoritmo de Kruskal que se guardará.
	*/
	void saveFile(std::string const & fileName, ed::Graph & graph, ed::Graph & gPrim, ed::Graph & gKruskal);
}

#endif