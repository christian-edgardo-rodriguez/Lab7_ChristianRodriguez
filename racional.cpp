#include "racional.h"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::stringstream;
using std::ostream;

void numeroSimp(int*, int, int);

Racional::Racional(int numerador, int denominador):numerador(numerador), denominador(denominador){
	int arreglo[2];
  if (denominador==0){
    denominador=1;
  }else if(denominador<0){
    numerador=numerador*-1;
    denominador=denominador*-1;
  }
  numeroSimp(arreglo, numerador, denominador);
  this -> numerador = arreglo[0];
  this -> denominador = arreglo[1];
}


const Racional& Racional::operator=(const Racional& r){
	numerador = r.numerador;
	denominador = r.denominador;
	return *this;
}

string Racional::toString() const{
	stringstream ss;
	ss << numerador << "/" << denominador;
	return ss.str();
}
const Racional Racional::operator+(const Racional& rac){
	if (denominador == rac.denominador){
    int newNumer=numerador+rac.numerador;
    return Racional (newNumer, denominador);
  }else{
    int num1=numerador*rac.denominador;
    int num2=rac.numerador*denominador;
    int newNumer=(num1+num2);
    int newDenom=(denominador*rac.denominador);
    return Racional(newNumer, newDenom);
  }
}
const Racional Racional::operator-(const Racional& rac){
	if (denominador == rac.denominador){
    int newNumer=numerador-rac.numerador;
    return Racional(newNumer, denominador);
  }else{
    int num1=numerador*rac.denominador;
    int num2=rac.numerador*denominador;
    int newNumer=(num1-num2);
    int newDenom=(denominador*rac.denominador);
    return Racional(newNumer, newDenom);
  }
}
const Racional Racional::operator*(const Racional& rac){
  int newNumer=(numerador*rac.numerador);
  int newDenom=(denominador*rac.denominador);
  return Racional(newNumer, newDenom);
}
const Racional Racional::operator/(const Racional& rac){
	int newNumer=(numerador*rac.denominador);
  int newDenom=(denominador*rac.numerador);
  return Racional(newNumer, newDenom);
}
ostream& operator<<(ostream& output, const Racional& c){
	if (c.numerador == 0){
		output<< 0;
	}
  if(c.denominador == 0 || c.denominador==1){
		output << c.numerador;
	}
  else{
    output << c.toString();
  }
	return output;
}
void numeroSimp(int* arreglo, const int num, const int den){
    int temNum = num;
    int temDen = den;
    int LCM, numCompPrim;
    while(true){
        if ((temNum < temDen) && (temNum != 1) && (temDen != 1)){
            numCompPrim = temNum;
        }else if ((temDen < temNum) && (temNum != 1) && (temDen != 1)){
            numCompPrim = temDen;
        }else if((temNum == 1) || (temDen == 1)){
            break;
        }
        if ((temDen%numCompPrim==0) && (temNum%numCompPrim==0)){
            LCM = numCompPrim;
        }else if ((temDen%2==0) && ((temNum%2==0))){
            LCM = 2;
        }else if ((temDen%3==0) && ((temNum%3==0))){
            LCM = 3;
        }else if ((temDen%5==0) && ((temNum%5==0))){
            LCM = 5;
        }else if ((temDen%7==0) && ((temNum%7==0))){
            LCM = 7;
        }else{
            break;
        }
        temDen /= LCM;
        temNum /= LCM;
    }
    arreglo[0] = temNum;
    arreglo[1] = temDen;
}