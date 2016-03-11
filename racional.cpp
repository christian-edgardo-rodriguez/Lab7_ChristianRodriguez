#include "racional.h"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::stringstream;
using std::ostream;
using std::istream;

Racional::Racional(int numerador, int imag2):numerador(numerador), denominador(denominador){
}


const Racional& Racional::operator=(const Racional& r){
	numerador = r.numerador;
	denominador = r.denominador;
	return *this;
}

string Racional::toString() const{
	stringstream ss;
	ss << numerador << " + " << denominador << "i";
	return ss.str();
}

const Racional operator+(const Racional& lhs, const Racional& rhs){
	Racional retVal = lhs;
	retVal += rhs;
	return retVal;
}
const Racional operator-(const Racional& lhs, const Racional& rhs){
	Racional retVal = lhs;
	retVal -= rhs;
	return retVal;
}
const Racional operator*(const Racional& lhs, const Racional& rhs){
	Racional retVal = lhs;
	retVal *= rhs;
	return retVal;
}
const Racional operator/(const Racional& lhs, const Racional& rhs){
	Racional retVal = lhs;
	retVal /= rhs;
	return retVal;
}

const Racional& Racional::operator+=(const Racional& r){
   numerador += r.numerador;
   denominador += r.denominador;
   return *this;
}

const Racional& Racional::operator-=(const Racional& r){
   numerador -= r.numerador;
   denominador -= r.denominador;
   return *this;
}
const Racional& Racional::operator*=(const Racional& r){
   numerador *= r.numerador;
   denominador *= r.denominador;
   return *this;
}
const Racional& Racional::operator/=(const Racional& r){
   numerador /= r.denominador;
   denominador /= r.numerador;
   return *this;
}
ostream& operator<<(ostream& output, const Racional& c){
	if (c.numerador == 0){
			output<<0.0;
	}else{
		if (c.denominador == 0 || c.denominador==1)
			output << c.numerador;
	}
	return output;
}
istream& operator>>(istream& input, Racional& c){
	input >> c.numerador >> c.denominador;
	return input;
}
