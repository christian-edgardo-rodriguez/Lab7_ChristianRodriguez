#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include "racional.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int menu();

int main(int argc, char const *argv[]){
	int opcion=menu();
	vector<Racional> racionales;
	vector<string> historial;
	do{
		if (opcion==1){
			/* code */
		}else if (opcion==2){
			/* code */
		}else if (opcion==3){
			/* code */
		}else if (opcion==4){
			/* code */
		}else if (opcion==5){
			/* code */
		}else if (opcion==6){
			if (historial.size()>0){
				for (int i = 0; i < historial.size(); ++i){
					printf("%d) %s\n", i, historial[i]);
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