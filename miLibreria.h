#include <iostream>

using namespace std;
void saludar (){
	int opcion;
	
	cout<<"Menu Alumnos"<<endl;
	cout<<"\n1. Tomar Asistencia"<<endl;
	cout<<"2. Ver listado"<<endl;
	cout<<"3. Agregar Alumno"<<endl;
	cout<<"4. Quitar Alumno"<<endl;
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
