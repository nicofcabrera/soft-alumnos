#include <iostream>
#include <conio.h> // Pausar sistema
#include "miLibreria.h" // Libreria Propia
#include <fstream> // Archivos
#include <string.h> // Libreria para uso de string varios

using namespace std;

//void saludar();

//Prototipos
void escribirArchivo();

int main(){
//ss
	//saludar();
	
	escribirArchivo();
	
	return 0;
}

void escribirArchivo(){
	ofstream archivo;
	string nombreArchivo, dato;
	string ruta = "C://Users//nico-//Downloads//";
	string alumnos[100];
	int cAlum; //Cantidad de alumnos
	
	
	
	cout<<"Coloque el nombre del archivo: ";
	getline(cin,nombreArchivo);
	
	ruta = ruta + nombreArchivo + ".csv"; 
	
	
	archivo.open(ruta.c_str(), ios::out);
	
	if(archivo.fail()){
		cout<<"Error";
		exit(1);
	}
	
	//archivo<<"texto vario archivo";
	/*
	Realizar un bucle para que se pueda poner cantidad de alumnos e ir listando.
	
	*/
	
	cout<<"Ingresar la cantidad de alumnos a registrar"<<endl;
	cin>>cAlum;
	cout<<"\nDigite el alumno uno por uno:"<<endl;
	
	for(int i= 0; i<=cAlum; i++){
		//cin>>alumnos[i];
		getline(cin,alumnos[i]);
		archivo<<alumnos[i]<<endl;
	}
	
	cout<<"\nAgregados exitosamente";
	
	//cout<<"Ingresar texto: "<<endl;
	//getline(cin,dato);
	
	//archivo<<dato;
	
	archivo.close();
	
	
}
