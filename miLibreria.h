#include <iostream>
// El usuario siempre decide SALIR de la APP.
using namespace std;
void saludar (){
	int opcion;
	
	cout<<"Menu Alumnos"<<endl;
	cout<<"\n1. Generar lista Alumnos"<<endl;
	cout<<"2. Ver listado Alumnos"<<endl;
	cout<<"3. Agregar Alumno"<<endl;
	cout<<"4. Quitar Alumno"<<endl; // no se si  puedo quitar
	cout<<"5. Instrucciones"<<endl;
	cout<<"6. Salir"<<endl;
	//
	cout<<"\n Elige una opcion [1-6]: ";
	cin>>opcion;
	//cout<<"\nElegiste el "<<opcion;
	
	if(opcion < 1 || opcion > 6){
		cout<<"La opcion elegida no es correcta";
	}
}
