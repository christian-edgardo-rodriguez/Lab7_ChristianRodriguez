#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "racional.h"

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::string;
using std::vector;

int menu();

int main(int argc, char const *argv[]){
	int opcion=menu(), numerador, denominador, primVec, segVec;
	vector<Racional> racionales;
	vector<string> historial;
	do{
		if (opcion==1){
			cout<<"Ingrese el numerador: ";
			cin>>numerador;
			cout<<"Ingrese el denominador: ";
			cin>>denominador;
			Racional temp(numerador, denominador);
			racionales.push_back(temp);
			cout<<"Racional agregado. "<<endl;
			cout<<endl;
			opcion=menu();
		}else if (opcion==2){
			if (racionales.size()>0){
				for (int i = 0; i < racionales.size(); ++i){
					cout<<i+1<<") "<<racionales[i].toString()<<endl;
				}
				cout<<"Ingrese el primer racional a sumar: ";
				cin>>primVec;
				cout<<"Ingrese el segundo racional a sumar: ";
				cin>>segVec;
				Racional suma = racionales[primVec-1] + racionales[segVec-1];
				stringstream ss;
				ss<<racionales[primVec-1]<<" + "<<racionales[segVec-1]<< " = "<<suma;
				historial.push_back(ss.str());
				cout<<"La suma se ha realizado. "<<endl;
				cout<<endl;
				opcion=menu();
			}else{
				cout<<"La lista de racionales esta vacia."<<endl;
				cout<<endl;
				opcion=menu();
			}
		}else if (opcion==3){
			if (racionales.size()>0){
				for (int i = 0; i < racionales.size(); ++i){
					cout<<i+1<<") "<<racionales[i].toString()<<endl;
				}
				cout<<"Ingrese el primer racional a restar: ";
				cin>>primVec;
				cout<<"Ingrese el segundo racional a restar: ";
				cin>>segVec;
				Racional resta = racionales[primVec-1] - racionales[segVec-1];
				stringstream ss;
				ss<<racionales[primVec-1]<<" - "<<racionales[segVec-1]<< " = "<<resta;
				historial.push_back(ss.str());
				cout<<"La resta se ha realizado. "<<endl;
				cout<<endl;
				opcion=menu();
			}else{
				cout<<"La lista de racionales esta vacia."<<endl;
				cout<<endl;
				opcion=menu();
			}
		}else if (opcion==4){
			if (racionales.size()>0){
				for (int i = 0; i < racionales.size(); ++i){
					cout<<i+1<<") "<<racionales[i].toString()<<endl;
				}
				cout<<"Ingrese el primer racional a multiplicar: ";
				cin>>primVec;
				cout<<"Ingrese el segundo racional a multiplicar: ";
				cin>>segVec;
				Racional multiplicacion = racionales[primVec-1] * racionales[segVec-1];
				stringstream ss;
				ss<<racionales[primVec-1]<<" * "<<racionales[segVec-1]<< " = "<<multiplicacion;
				historial.push_back(ss.str());
				cout<<"La multiplicacion se ha realizado. "<<endl;
				cout<<endl;
				opcion=menu();
			}else{
				cout<<"La lista de racionales esta vacia."<<endl;
				cout<<endl;
				opcion=menu();
			}
		}else if (opcion==5){
			if (racionales.size()>0){
				for (int i = 0; i < racionales.size(); ++i){
					cout<<i+1<<") "<<racionales[i].toString()<<endl;
				}
				cout<<"Ingrese el primer racional a dividir: ";
				cin>>primVec;
				cout<<"Ingrese el segundo racional a dividir: ";
				cin>>segVec;
				Racional division = racionales[primVec-1]  / racionales[segVec-1];
				stringstream ss;
				ss<<racionales[primVec-1]<<" / "<<racionales[segVec-1]<< " = "<<division;
				historial.push_back(ss.str());
				cout<<"La division se ha realizado. "<<endl;
				cout<<endl;
				opcion=menu();
			}else{
				cout<<"La lista de racionales esta vacia."<<endl;
				cout<<endl;
				opcion=menu();
			}
		}else if (opcion==6){
			if (historial.size()>0){
				for (int i = 0; i < historial.size(); ++i){
					cout<<historial[i]<<endl;
				}
				cout<<endl;
				opcion=menu();
			}else{
				cout<<"El historial esta vacio."<<endl;
				cout<<endl;
				opcion=menu();
			}
		}
	}while(opcion!=7);
	return 0;
}
int menu(){
	int opc;
	cout<<"1. Crear Racionales"<<endl;
	cout<<"2. Suma de Racionales"<<endl;
	cout<<"3. Resta de Racionales"<<endl;
	cout<<"4. Multiplicacion de Racionales"<<endl;
	cout<<"5. Division de Racionales"<<endl;
	cout<<"6. Ver Historial de Operaciones"<<endl;
	cout<<"7. Salir"<<endl;
	cout<<"Escoja su opcion: ";
	cin>>opc;
	if (opc<1&&opc>7){
		return 0;
	}else{
		return opc;
	}
}