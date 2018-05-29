/**
			* @brief Mueve el cursor de vértices a la posición i-ésima.
			* @note Esta función sirve de interfaz para setCursorV()
			* @param i Posición i-ésima a la que desplacar el cursor (uint).
			* @sa setCursorV()
			*/
			inline void goTo(const uint &i) { this->setCursorV(i); }
			
			/**
			* @brief Mueve el cursor de vértices al principio.
			* @sa goTo()
			*/
			inline void beginVertex() { this->goTo(0); }
			
			/**
			* @brief Mueve el cursor de vértices a la siguiente posición.
			* @sa setCursorV()
			* @sa getCursorV()
			*/
			inline void nextVertex() { this->setCursorV(this->getCursorV()+1); }
			
			/**
			* @brief Comprueba si el valor del cursor de vértices es igual al número de vértices del grafo.
			* @return true si this->getCursorV() == this->getVertexes(), false si no.
			* @sa getCursorV()
			* @sa getVertexes()
			*/
			inline bool afterEndVertex() const { return this->getCursorV() == this->getVertexes(); }
			
			/**
			* @brief Mueve los cursores para situarse en el principio del vértice pasado comoparámetro.
			* @note Si el peso del lado es infinito o no se llega al final, se va incrementando el cursor de lados.
			* @param v Vértice del cuál situarse al principio.
			* @sa setCursorV()
			* @sa setCursorE()
			* @sa getCursorV()
			* @sa getCursorE()
			* @sa afterEndEdge()
			*/
			inline void beginEdge(const Vertex<std::string> &v) {

			    this->setCursorV(v.getLabel());
			    this->setCursorE(0);

			    while((_matrix[this->getCursorV()][this->getCursorE()] == INFINITE) && !(this->afterEndEdge())) {

			        this->setCursorE(this->getCursorE()+1);
			    }
			}

			/**
			* @brief Mueve el cursor de lados a la siguiente posición válida.
			* @sa setCursorE()
			* @sa getCursorE()
			* @sa getCursorV()
			* @sa afterEndEdge()
			*/
			inline void nextEdge() {
			    this->setCursorE(this->getCursorE()+1);

			    while((_matrix[this->getCursorV()][this->getCursorE()] == INFINITE) && !(this->afterEndEdge())) {

			        this->setCursorE(this->getCursorE()+1);
			    }
			}

			/**
			* @brief Comprueba si el valor del cursor de lados es igual al número de lados del grafo.
			* @return true si this->getCursorE() == this->getEdges();
			* @sa getCursorE()
			* @sa setEdges()
			*/
			inline bool afterEndEdge() const { return this->getCursorE() == this->getEdges(); }

			Edge<double> curEdge() {
				Edge<double> e;
				uint oldCur = this->getCursorV();

				Vertex<std::string> first, second;
				first = this->curVertex();
				this->goTo(this->getCursorE());
				second = this->curVertex();
				this->setCursorV(oldCur);

				e.setData(this->adyacent(first, second));
				e.setFirst(first);
				e.setSecond(second);

				return e;
			}

			
			/**
			* @brief Devuelve la distancia entre dos vértices dados.
			* @return Distancia entre dos vértices dados. 
			*/
			inline double adyacent(const Vertex<std::string> &v1, const Vertex<std::string> &v2) const { return _matrix[v1.getLabel()][v2.getLabel()]; }
