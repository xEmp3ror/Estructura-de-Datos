/*! 
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/


// Ficheros de cabecera
#include <iostream>

// Para usar sqrt, acos
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include "Vector3D.hpp"

// OBSERVADORES

double ed::Vector3D::modulo() const {

	double result;

	result = ( sqrt(get1() * get1() +
					get2() * get2() +
					get3() * get3()
					)
			  );

	return result;
}

double ed::Vector3D::angulo(ed::Vector3D const &v) const {

	double result;

	result = acos( dotProduct(v) / (modulo() * v.modulo()) );

	return result; 
}

double ed::Vector3D::dotProduct(const ed::Vector3D &v) const {

	double result;

	result = (get1() * v.get1() +
		      get2() * v.get2() +
 		      get3() * v.get3()
 		      );

	return result;
}

double ed::Vector3D::alfa() const {

	double result;

	Vector3D w(1, 0, 0);

	result = ( angulo(w) ); //SE PUEDE CREAR UN ELEMENTO VECTOR3D Y PASARLO A LA FUNCION ORIGINAL.

	return result;
}

double ed::Vector3D::beta() const {

	double result;

	Vector3D w(0, 1, 0);

	result = ( angulo(w) );

	return result;
}


double ed::Vector3D::gamma() const {

	double result;

	Vector3D w(0, 0, 1);

	result = ( angulo(w) );

	return result;
}

ed::Vector3D ed::Vector3D::crossProduct(ed::Vector3D v) const {

	Vector3D w;

	w.set1(get2()*v.get3() - get3()*v.get2());
	w.set2(get1()*v.get3() - get3()*v.get1());
	w.set3(get1()*v.get2() - get2()*v.get1());

	return w;
}

////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Vector3D::sumConst(double k) {

	set1(get1() + k);
	set2(get2() + k);
	set3(get3() + k);

}

void ed::Vector3D::sumVect(ed::Vector3D v) {

	set1(get1() + v.get1());
	set2(get2() + v.get2());
	set3(get3() + v.get3());

}

void ed::Vector3D::multConst(double k) {

	set1(get1() * k);
	set2(get2() * k);
	set3(get3() * k);
}

void ed::Vector3D::multVect(ed::Vector3D v) {

	set1(get1() * v.get1());
	set2(get2() * v.get2());
	set3(get3() * v.get3());
}

////////////////////////////////////////////////////////////////////////////////

// OPERADORES

ed::Vector3D & ed::Vector3D::operator=(ed::Vector3D const &v) {

	double x, y, z;

	Vector3D *w = new Vector3D;

	x = v.get1();
	y = v.get2();
	z = v.get3();

	w->set1(x);
	w->set2(y);
	w->set3(z);

	return *w;
}

double ed::Vector3D::operator*(ed::Vector3D const &v) const {

	double result;

	result = dotProduct(v);

	return result;
}

ed::Vector3D & ed::Vector3D::operator*(double k) const {

	double x, y, z;

	Vector3D *w = new Vector3D;

	x = k * get1();
	y = k * get2();
	z = k * get3();

	w->set1(x);
	w->set2(y);
	w->set3(z);

	return *w;
}

bool ed::Vector3D::operator==(ed::Vector3D const &v) const {

	if (
                 (std::abs (v.get1() - this->get1()) < COTA_ERROR)   
              && (std::abs (v.get2() - this->get2()) < COTA_ERROR)
              && (std::abs (v.get3() - this->get3()) < COTA_ERROR)
            ) { return true; } else { return false; };
}

ed::Vector3D & ed::Vector3D::operator+(ed::Vector3D const &v) const {

	double x, y, z;

	Vector3D *w = new Vector3D;

	x = get1() + v.get1();
	y = get2() + v.get2();
	z = get3() + v.get3();

	w->set1(x);
	w->set2(y);
	w->set3(z);

	return *w;
}

ed::Vector3D & ed::Vector3D::operator+() const {

	double x, y, z;

	Vector3D *w = new Vector3D;

	x = get1();
	y = get2();
	z = get3();

	w->set1(x);
	w->set2(y);
	w->set3(z);

	return *w;
}

ed::Vector3D & ed::Vector3D::operator-(ed::Vector3D const &v) const {

	double x, y, z;

	Vector3D *w = new Vector3D;

	x = get1() - v.get1();
	y = get2() - v.get2();
	z = get3() - v.get3();

	w->set1(x);
	w->set2(y);
	w->set3(z);

	return *w;
}

ed::Vector3D & ed::Vector3D::operator-() const {

	double x, y, z;

	Vector3D *w = new Vector3D;

	x = (-1) * get1();
	y = (-1) * get2();
	z = (-1) * get3();

	w->set1(x);
	w->set2(y);
	w->set3(z);

	return *w;
}

ed::Vector3D & ed::Vector3D::operator^(ed::Vector3D const &v) const {

	Vector3D *w = new Vector3D;

	w -> crossProduct(v);

	return *w;
}


////////////////////////////////////////////////////////////////////////////////

// FUNCIONES DE LECTURA Y ESCRITURA

void ed::Vector3D::leerVector3D() {

	int x, y, z;

	std::cout<<"Leyendo componenetes del vector."<<std::endl;
	std::cin>>x>>y>>z;

	set1(x);
	set2(y);
	set3(z);
}

void ed::Vector3D::escribirVector3D() const {

	std::cout<<"("<<get1()<<","<<get2()<<","<<get3()<<")"<<std::endl;
}


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{


// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const &v) {

	double x, y, z;

	Vector3D *w = new Vector3D;

	x = k * v.get1();
	y = k * v.get2();
	z = k * v.get3();

	w->set1(x);
	w->set2(y);
	w->set3(z);

	return *w;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &v) {

	std::cout << "(";
	stream << v.get1();
	stream << ", ";
	stream << v.get2();
	stream << ", ";
	stream << v.get3();
	std::cout << ")";

	return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &v) {

	double val;

	stream >> val;
	v.set1(val);

	stream >> val;
	v.set2(val);

	stream >> val;
	v.set3(val);

	return stream;
} 

} // Fin del espacio de nombres ed
