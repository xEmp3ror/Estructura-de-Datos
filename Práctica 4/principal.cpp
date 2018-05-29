/**
* @file principal.cpp
* @brief Práctica 4: Programa principal.
* @author Rafael Román de los Reeyes
* @date Mayo de 2018
*/

#include <cassert>
#include "funcionesAuxiliares.hpp"

#include "edge.hpp"
#include "vertex.hpp"
#include "graph.hpp"

int main(){

	ed::Graph  g;
	ed::Graph  gKruskal;
	ed::Graph  gPrim;
	ed::Vertex v;

	int index, origin, destiny;

	double x, y;

	std::string inputName;
	std::string outputName;


	int opcion;

	do{
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		switch(opcion)
		{
			case 0: 
					std::cout << INVERSE;
					std::cout << "Fin del programa." << std::endl;
					std::cout << RESET;
			break;

		   ///////////////////////////////////////////////////////////////////

			case 1: 
					std::cout << "[1] CARGAR GRAFO DESDE UN FICHERO." << std::endl;

					std::cout<<RESET<<std::endl;
					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" Introduzca el nombre del fichero junto a su extensión: "<<GREEN;
				  	std::cin>>inputName;
				  	std::cout<<RESET<<std::endl;

				  	loadFile(inputName, g);

					break;
			case 2:
					std::cout << "[2] GUARDAR GRAFOS EN UN FICHERO." << std::endl;

					if (g.isEmpty()) {

						std::cout<<RESET<<std::endl;
						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El archivo no se puede crear porque el grafo está vacío."<<RESET<<std::endl;
						
						break;
					}

					std::cout<<RESET<<std::endl;
					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" Introduzca el nombre del fichero junto a su extensión: "<<GREEN;
				  	std::cin>>outputName;
				  	std::cout<<RESET<<std::endl;

				  	saveFile(outputName, g, gPrim, gKruskal);

				  	break;
			case 3:
					std::cout << "[3] MOSTRAR NÚMERO DE ELEMENTOS DEL GRAFO." << std::endl;

					if (g.isEmpty()) {

						std::cout<<RESET<<std::endl;
						std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" El grafo está vacío."<<RESET<<std::endl;
						
						break;
					}

					std::cout<<RESET<<std::endl;
					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" El grafo tiene "<<g.nVertexes()<<" vértices."<<RESET<<std::endl;

					break;
			case 4:
					std::cout << "[4] MOSTRAR MATRIZ DE ADYACENCIAS." << std::endl;

					if (g.isEmpty()) {

						std::cout<<RESET<<std::endl;
						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" La matriz no puede mostrarse: el grafo está vacío."<<RESET<<std::endl;

						break;
					}

					std::cout<<RESET<<std::endl;
					g.printMatrix();
					break;
			case 5:
					std::cout << "[5] APLICAR ALGORITMO DE PRIM." << std::endl;

					if (g.isEmpty()) {

						std::cout<<RESET<<std::endl;
						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El algortimo no puede ser aplicado: el grafo está vacío."<<RESET<<std::endl;

						break;
					}

					gPrim = g.algorithmPrim();

					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<"Resultado del algoritmo:"<<RESET<<std::endl;

					gPrim.printMatrix();

					break;
			case 6:
					std::cout << "[6] APLICAR ALGORITMO DE KRUSKAL." << std::endl;

					if (g.isEmpty()) {

						std::cout<<RESET<<std::endl;
						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El algortimo no puede ser aplicado: el grafo está vacío."<<RESET<<std::endl;

						break;
					}

					gKruskal = g.algorithmKruskal();

					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<"Resultado del algoritmo:"<<RESET<<std::endl;

					gKruskal.printMatrix();

					break;

			case 7:
					std::cout << "[7] TAMAÑO DEL ARBOL ABARCADOR DE COSTE MÍNIMO." << std::endl;

					if (gPrim.isEmpty()) {

						std::cout<<RESET<<std::endl;
						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El arbol abarcador de coste mínimo mediante Prim no puede ser mostrado: el grafo está vacío."<<RESET<<std::endl;

					} else {

						std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<"La longitud del árbol abarcador de coste mínimo mediante algoritmo de Prim es "<<gPrim.treeLength()<<" nodos."<<RESET<<std::endl;
					}

					if (gPrim.isEmpty()) {

						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El arbol de coste mínimo mediante Kruskal no puede ser mostrado: el grafo está vacío."<<RESET<<std::endl;

						break;

					} else {

						std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<"La longitud del árbol abarcador de coste mínimo mediante algoritmo de Kruskal es "<<gKruskal.treeLength()<<" nodos."<<RESET<<std::endl;
						break;
					}
			case 8:
					std::cout << "[8] AGREGAR VÉRTICE AL GRAFO." << std::endl;

					std::cout<<RESET<<std::endl;
					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" Introduzca la abcisa [X] del vértice: "<<GREEN;
				  	std::cin>>x;
				  	std::cout<<RESET<<std::endl;

					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" Introduzca la ordenada [Y] del vértice: "<<GREEN;
				  	std::cin>>y;
				  	std::cout<<RESET<<std::endl;

				  	v.setData(x, y);
				  	g.findFirstV(x, y);
				  	if (g.hasCurV()) {

				  		std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El grafo ya contiene este vértice."<<RESET<<std::endl;
				  		std::cin.ignore();
				  		break;
				  	}

				  	g.addVertex(v);

				  	std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIGREEN<<" Vértice añadido correctamente."<<RESET<<std::endl;
				  	std::cin.ignore();

					break;
			case 9:
					std::cout << "[9] BORRAR VÉRTICE DEL GRAFO." << std::endl;

					if (g.isEmpty()) {

						std::cout<<RESET<<std::endl;
						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" Ningún vértice puede ser borrado: el grafo está vacío."<<RESET<<std::endl;

						break;
					}

					std::cout<<RESET<<std::endl;
					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" Introduzca el vértice que quiere borrar [1 - "<<g.nVertexes()<<"]: "<<GREEN;
				  	std::cin>>index;
				  	std::cout<<RESET<<std::endl;

				  	if(not((index <= g.nVertexes()) && (index > 0.0))) {

						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El vértice no existe."<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}

					g.goToVertex(g.getVertex(index));

					if(!g.hasCurV()) {

						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El vértice no existe."<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}

					g.removeVertex();

					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIGREEN<<" Vértice borrado correctamente."<<RESET<<std::endl;
					std::cin.ignore();

					break;
			case 10:
					std::cout << "[10] AGREGAR LADO AL GRAFO." << std::endl;

					if (g.isEmpty()) {

						std::cout<<RESET<<std::endl;
						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" No se puede agregar un lado: el grafo está vacío."<<RESET<<std::endl;

						break;
					}

					std::cout<<RESET<<std::endl;
					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" Introduzca vértice de origen [1 - "<<g.nVertexes()<<"]: "<<GREEN;
				  	std::cin>>origin;
				  	std::cout<<RESET<<std::endl;

				  	if(not((origin <= g.nVertexes()) && (origin > 0.0))) {

						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El vértice de Origen es incorrecto."<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}

					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" Introduzca vértice de destino [1 - "<<g.nVertexes()<<"]: "<<GREEN;
				  	std::cin>>destiny;
				  	std::cout<<RESET<<std::endl;

				  	if(not((destiny <= g.nVertexes()) && (destiny > 0.0)) or (origin == destiny)) {

						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El vértice de Origen es incorrecto."<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}

					g.goToEdge(g.getVertex(origin), g.getVertex(destiny));

					if(g.hasCurE()) {

						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El grafo ya contiene ese lado."<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}

					g.addEdge(g.getVertex(origin),g.getVertex(destiny));

					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIGREEN<<" Lado añadido correctamente."<<RESET<<std::endl;
					std::cin.ignore();

					break;
			case 11:
					std::cout << "[11] BORRAR LADO DEL GRAFO." << std::endl;

					if (g.isEmpty()) {

						std::cout<<RESET<<std::endl;
						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" No se puede borrar ningún lado: el grafo está vacío."<<RESET<<std::endl;

						break;
					}

					std::cout<<RESET<<std::endl;
					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" Introduzca el primer vértice del lado que quiere borrar [1 - "<<g.nVertexes()<<"]: "<<GREEN;
				  	std::cin>>origin;
				  	std::cout<<RESET<<std::endl;

				  	if(not((origin <= g.nVertexes()) && (origin > 0.0))) {

						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El vértice de Origen es incorrecto."<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}

					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIYELLOW<<" Introduzca el segundo vértice del lado que quiere borrar [1 - "<<g.nVertexes()<<"]: "<<GREEN;
				  	std::cin>>destiny;
				  	std::cout<<RESET<<std::endl;

				  	if(not((destiny <= g.nVertexes()) && (destiny > 0.0)) or (origin == destiny)) {

						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El vértice de Origen es incorrecto."<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}

					g.goToEdge(g.getVertex(origin),g.getVertex(destiny));

					if(!g.hasCurE()) {

						std::cout<<BIRED<<INVERSE<<"[!] ERROR "<<RESET<<BIRED<<" El lado no es correcto o no está contenido en el grafo."<<RESET<<std::endl;
						std::cin.ignore();
						break;
					}

					g.removeEdge();

					std::cout<<BIBLUE<<INVERSE<<"[i] INFORMACIÓN "<<RESET<<BIGREEN<<" Lado borrado correctamente."<<RESET<<std::endl;
					std::cin.ignore();

					break;

			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;

    	} //SWITCH END.
  
	    if (opcion !=0) {

			PLACE(25,1);
			std::cout << "Pulse ";
			std::cout << BIGREEN;
			std::cout << "ENTER";
			std::cout << RESET;
			std::cout << " para mostrar el ";
			std::cout << INVERSE;
			std::cout << "menú"; 
			std::cout << RESET;

			// Pausa
			std::cin.ignore();

			std::cout << CLEAR_SCREEN;
	    }

	} while(opcion!=0);

	return 0;
}
	
