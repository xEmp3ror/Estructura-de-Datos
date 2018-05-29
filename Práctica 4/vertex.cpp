/**
* @file vertex.cpp
* @brief Práctica 4: Vértice.
* @author Rafael Román de los Reeyes
* @date Mayo de 2018
*/

#include <iostream>
#include <stdlib.h> //atof y atoi.

#include "vertex.hpp"

namespace ed {

	std::ostream &operator<<(std::ostream &o, const ed::Vertex &v) {

		o<<v.getDataX()<<" , "<<v.getDataY()<<std::endl;

		return o;
	}

	std::istream &operator>>(std::istream &stream, ed::Vertex &v) {

		std::string cad,cad2;
		getline(stream,cad,' ');
		getline(stream,cad2);
		v.setData(atof(cad.c_str()),atof(cad2.c_str()));

		return stream;
	}
}