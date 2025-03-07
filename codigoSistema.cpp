#include <iostream>
#include <conio.h> // Pausar sistema
#include "miLibreria.h" // Libreria Propia
//#include <fstream> // Archivos
//#include <string.h> // Libreria para uso de string varios
//#include <direct.h> //Crear directorios mkdir

using namespace std;

//void saludar();

// # Prototipos
void comandosTerminal();
void escribirArchivo();
void leerArchivos();
void agregarAlumnos();
void menu();

int main(){
	
	menu();

	return 0;
}
//ss
// Funcion MENU
void menu(){
	bool bandera = true;
	
	do{
	int opcion;
	
	cout<<"Sistema Alumnos"<<endl;
	cout<<"\n1. Generar lista Alumnos"<<endl;
	cout<<"2. Ver listado Alumnos"<<endl;
	cout<<"3. Agregar Alumno"<<endl;
	cout<<"4. Instrucciones"<<endl;
	cout<<"5. Salir"<<endl;
	cout<<"\nElige una opcion [1-6]: ";
	cin>>opcion;
	
	switch(opcion){
		case 1:
			escribirArchivo();
			bandera = false;
			break;
		case 2:
			leerArchivos();
			bandera = false;
			break;
		case 3:
			agregarAlumnos();
			bandera = false;
			break;
		case 4:
			break;
		case 5:
			cout<<"\nHas finalizado el uso del sistema."<<endl;
			bandera = false;
			break;			
		default:
		cout<<"\nEl dato ingresado no es correcto, intenta otra vez."<<endl;
	}
	}while(bandera);
	
	
	
}





	
