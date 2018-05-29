/**
* @file lado.hpp
* @brief Práctica 4: Lado.
* @author Rafael Román de los Reeyes
* @date Mayo de 2018
*/

#include "Grafo.hpp"

double ed::Graph::ponderate(ed::Vertex u, ed::Vertex v) const {

	double res;
	double totX = pow(u.getDataX() - v.getDataX(), 2);
	double totY = pow(u.getDataY() - v.getDataX(), 2);

	res = sqrt(totX + totY);

	return res;
}

bool ed::Graph::hasAdy(ed::Vertex u, ed::Vertex v) const {

	#ifndef NDEBUG

		assert(!isEmpty());

	#endif

	for (int i = 0; i < (int)_edges.size(); ++i) {

		if((_edges[i].first() == u && _edges[i].second() == v) or (_edges[i].first() == v && _edges[i].second() == u)) {

			return true;
		}
	}

	return false;
}

void ed::Graph::addVertex(double x, double y) {

	ed::Vertex a;

	a.setData(x, y);
	a.setLabel(_vertexes.size() + 1);
	_vertexes.push_back(a);

	adjust();

	_cursorV =(int) _vertexes.size() - 1 ;
}

void ed::Graph::addEdge(ed::Vertex v, ed::Vertex u) {

	ed::Edge l;

	l.setItem(ponderate(v, u));
	l.setFirst(v);
	l.setSecond(u);
	_edges.push_back(l);

	_matrix[l.first().getLabel()-1][l.second().getLabel()-1] = l.getItem();
	_matrix[l.second().getLabel()-1][l.first().getLabel()-1] = l.getItem();

	_cursorE = (int) _edges.size() - 1;
}

void ed::Graph::adjust() {

	int i,j;

	_matrix.resize(nVertexes());

	for (i = 0; i < nVertexes(); ++i) {

		_matrix[i].resize(nVertexes(), std::numeric_limits<double>::infinity());
	}

	for (i = 0; i < nVertexes(); ++i) {

		for (j = 0; j < nVertexes(); ++j) {

			goToEdge(_vertexes[i],_vertexes[j]);

			if(i == j) {

				_matrix[i][j] = 0;
			
			} else {

			 	if(!hasCurrEdge()) {
			 		_matrix[i][j] = std::numeric_limits<double>::infinity();
			 	}
			}
		}
	}
}

void ed::Graph::removeVertex() {

	
	int aux, aux2;

	aux = _cursorV;

	_vertexes.erase(_vertexes.begin() + _cursorV);

	for (; aux <nVertices(); ++aux){

		_vertexes[aux].setLabel(_vertexes[aux].getLabel() -1);
	}

	for (int i = 0; i < (int)_edges.size(); ++i) {

		if(_edges[i].first().getLabel() == _cursorV +1 or _edges[i].second().getLabel() == _cursorV +1) {

			_edges.erase(_edges.begin() + _cursorV);
		}
	}

	for (int i = 0; i < (int)_edges.size(); ++i) {

		if(_edges[i].first().getLabel() > _cursorV +1) {

			aux2 = _edges[i].first().getLabel() -1;
			_edges[i].first().setLabel(aux2);
		}

		if(_edges[i].second().getLabel() > _cursorV +1) {

			_edges[i].second().setLabel(_edges[i].second().getLabel() -1);
		}
	}

	adjust();
}

void ed::Graph::findFirstV(double x, double y) {

	bool control = false;
	int i = 0;

	if(isEmpty()) {

		_cursorV = -1;
		return;
	}

	while(!control) {

		if(i >=(int) _vertexes.size()) {

			control = true;
			_cursorV = -1;
		}

		if(_vertexes[i].getDataX() == x && _vertexes[i].getDataY() == y && control == false) {

			_cursorV = i;
			control = true;
		}

		i++;
	}
}

void ed::Graph::findNextV(double x, double y) {

	bool control = false;
	int i = _cursorV;

	if(isEmpty()) {

		_cursorV = -1;
		return;
	}

	while(!control) {

		if(i >=(int) _vertexes.size()) {

			control = true;
			_cursorV = -1;
		}

		if(_vertexes[i].getDataX() == x && _vertexes[i].getDataY() == y && control == false) {

			_cursorV = i;
			control = true;
		}

		i++;
	}
}

void findFirstE(ed::Vertex v, ed::Vertex u) {

	bool control = false;
	int i = 0;

	while(!control) {

		if(i >=(int) _edges.size()) {

			control = true;
			_cursorE = -1;
		}

		if(_edges[i].first() == v && _edges[i].second() == u && control == false) {

			_cursorE = i;
			control = true;
		}

		i++;
	}
}

void findNextE(ed::Vertex v, ed::Vertex u) {

	bool control = false;
	int i = _cursorE;

	while(!control) {

		if(i >=(int) _edges.size()) {

			control = true;
			_cursorE = -1;
		}

		if(_edges[i].first() == v && _edges[i].second() == u && control == false) {

			_cursorE = i;
			control = true;
		}

		i++;
	}
}

void ed::Graph::goToEdge(ed::Vertex u, ed::Vertex v) {
	
	bool control;
	for (int i = 0; i < (int)_edges.size(); ++i) {

		if((_edges[i].first() == u && _edges[i].second() == v) or (_edges[i].second() == u && _edges[i].first() == v)) {

			_cursorE = i;
			control = true;
		}
	}

	if(control == false) {

		_cursorE = -1;
	}
}

ed::Graph ed::Graph::algorithmPrim() {

	ed::Graph coste_minimo;
	std::vector<int> visited; //Guarda los nodos visitados
	std::vector<int> nVisited;	//Guarda los nodos no visitados

	//Añadimos al grafo todos los vertices
	for (int i = 0; i < nVertices(); ++i) {

		coste_minimo.addVertexN(_vertexes[i].getDataX(), _vertexes[i].getDataY());
	}

	visited.push_back(0);

	//Llenamos el vector de no visitados con los vertices (empezamos en i+1 porque mis etiquetas empiezan en 1 no en 0)
	for (int i = 0; i < nVertices(); ++i) {

		nVisited.push_back(i+1);
	}

	while(!nVisited.empty()) {

		int old = -1;
		int _new = -1; // Barra baja porque "new" es una palabra reservada.

		std::vector<int>::iterator erase; //Se encarga de borrar un nodo que ya no se va a mover

		double peso = std::numeric_limits<double>::infinity();

		for (std::vector<int>::iterator it=nVisited.begin();it!=nVisited.end(); ++it) {

			for (std::vector<int>::iterator jt=visited.begin();jt!=visited.end(); ++jt) {

				//Para cada elemento del vector no visitado, comprobamos todos los visitados
				//Comprobamos que el vertice no visitado es adyacente con el visitado
				if(hasAdy(_vertexes[*it], _vertexes[*jt])) {

					//Si son adyacentes vamos al lado que los une y comprobamos que el peso, que inicialmente es infinito,
					//Sea menor que infinito, asignamos el peso del lado a la variable peso, asi nos aseguramos de buscar siempre el menor peso posible			
					goToEdge(_vertexes[*it], _vertexes[*jt]);
					
					if(currEdge().getItem() < peso) {

						peso = currEdge().getItem();
						old = *jt;
						erase = it;
						_new = *it;
					}
				}
			}
		}

		//Si se hubiera cambiado el valor del peso, se entra en este if 
		if (old != -1 && _new != -1) {

			//Metemos el lado de coste minimo en el grafo nuevo
			coste_minimo.addEdge(_vertexes[old],_vertexes[_new]);
			//Borramos el nodo de la lista de no visitados
			nVisited.erase(erase);
			//Y lo metemos en visitados
			visited.push_back(_new);
		} else { //Se mete aqui si no ha encontrado un lado de coste minimo

			//Incluimos el primer vertice sin visitar a la lista de visitados
			visited.push_back(nVisited[0]);
			//Y borramos de la lista de pendientes el nodo que hemos metido visitados, asi no se tendra en cuenta 
			nVisited.erase(nVisited.begin());
		}
	}

	return coste_minimo;
}
