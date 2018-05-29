/**
* @file funcionesAuxiliares.cpp
* @brief Práctica 4: Funciones Auxiliares.
* @author Rafael Román de los Reeyes
* @date Mayo de 2018
*/

#include "funcionesAuxiliares.hpp"
#include "vertex.hpp"

void isEmpty(ed::Graph const & graph) {

	if(graph.isEmpty()) {

		std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" El grafo está vacío."<<RESET<<std::endl;
		std::cin.ignore();
		return;
	
	} else {

		std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" El grafo tiene "<<graph.nVertexes()<<" vértices."<<RESET<<std::endl;
		std::cin.ignore();
		return;
	}
}

void ed::loadFile(std::string const & fileName, ed::Graph & graph) {

	ed::Vertex aux;
	
	graph.clear();
	std::ifstream f( fileName.c_str() );
	
	if(!f) {

		std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El archivo no se ha cargado. El fichero no existe o el nombre es incorrecto."<<std::endl;
		std::cin.ignore();
		return;
	}

	while(f>>aux) {

		if(!graph.searchVertex(aux))
		graph.addVertex(aux);
	}

	std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIGREEN<<" El fichero se ha cargado con éxito."<<std::endl;
	std::cin.ignore();
	f.close();
}

void ed::saveFile(std::string const & fileName, ed::Graph & graph, ed::Graph & gPrim, ed::Graph & gKruskal) {

	std::ofstream f(fileName.c_str());

	graph.firstVertex();

	f<<"Vertices (x , y):\n";

	while(graph.hasCurV()) {

		f<<graph.curVertex();
		graph.nextVertex();
	}

	f<<"\n"<<"Matriz de adyacencias:"<<"\n";
	f<<graph;

	if(!gKruskal.isEmpty()) {

		f<<"\n"<<"Matriz resultante de aplicar el algoritmo de Kruskal:"<<"\n";
		f<<gKruskal;
	}

	if(!gPrim.isEmpty()) {

		f<<"\n"<<"Matriz resultante de aplicar el algoritmo de Prim:"<<"\n";
		f<<gPrim;	
	}

	std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIGREEN<<" El fichero se ha guardado con éxito."<<std::endl;
	std::cin.ignore();
	f.close();
}

int ed::menu() {

	int opcion;
	int posicion;

	posicion=2;

	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++; //Para separar conjuntos de opciones.

	PLACE(posicion++,10);
	std::cout << "[1] CARGAR GRAFO DESDE UN FICHERO.";

	PLACE(posicion++,10);
	std::cout << "[2] GUARDAR GRAFOS EN UN FICHERO.";

	//////////////////////////////////////////////////////////////////////////////
	posicion++; //Para separar conjuntos de opciones.

	PLACE(posicion++,10);
	std::cout << "[3] MOSTRAR NUMERO DE ELEMENTOS DEL GRAFO.";

	PLACE(posicion++,10);
	std::cout << "[4] MOSTRAR MATRIZ DE ADYACENCIAS.";

	//////////////////////////////////////////////////////////////////////////////
	posicion++; //Para separar conjuntos de opciones.

	PLACE(posicion++,10);
	std::cout << "[5] APLICAR ALGORITMO DE PRIM.";

	PLACE(posicion++,10);
	std::cout << "[6] APLICAR ALGORITMO DE KRUSKAL.";

	PLACE(posicion++,10);
	std::cout << "[7] TAMAÑO DEL ARBOL ABARCADOR DE COSTE MÍNIMO.";

	//////////////////////////////////////////////////////////////////////////////
	posicion++; //Para separar conjuntos de opciones.

	PLACE(posicion++,10);
	std::cout << "[8] AGREGAR VÉRTICE AL GRAFO.";

	PLACE(posicion++,10);
	std::cout << "[9] BORRAR VÉRTICE DEL GRAFO.";

	PLACE(posicion++,10);
	std::cout << "[10] AGREGAR LADO AL GRAFO.";

	PLACE(posicion++,10);
	std::cout << "[11] BORRAR LADO DEL GRAFO.";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";


	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();

	return opcion;
}