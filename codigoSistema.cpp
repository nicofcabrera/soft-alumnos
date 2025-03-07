#include <iostream>
#include <conio.h> // Pausar sistema
#include "funcionesArchivos.h" //Libreria Propias
#include <stdlib.h>	
//#include <fstream> // Archivos
//#include <string.h> // Libreria para uso de string varios
//#include <direct.h> //Crear directorios mkdir
#include<ctime>

using namespace std;

//void saludar();ss

// # Prototipos
void comandosTerminal();
void escribirArchivo();
void leerArchivos();
void agregarAlumnos();
bool vueltaAlMenu();
void limpiarConsola();
void menu();


int main(){
	// Logitud de un array estatico - PROBAR EN ARCHIVOS
	int array[] = {1,2,3,4,5,22,54};
	int longitud = sizeof(array) / sizeof(array[0]);
	cout<<longitud;
	getch();
	
	//Obtencion de fecha - PROBAR METODO.
	// Get the timestamp for the current date and time
//time_t timestamp;
//time(&timestamp);

// Display the date and time represented by the timestamp
//cout << ctime(&timestamp);
//getch();
	
	//menu();

	return 0;
}
//ssssssssssssssssss
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
			bandera = vueltaAlMenu();
			break;
		case 2:
			leerArchivos();
			bandera = vueltaAlMenu();
			break;
		case 3:
			agregarAlumnos();
			bandera = vueltaAlMenu();
			break;
		case 4:
			break;
		case 5:
			cout<<"\nHas finalizado el uso del sistema."<<endl;
			bandera = false;
			break;			
		default:
		cout<<"\nEl dato ingresado no es correcto, intenta otra vez."<<endl;
		cout<<"Presiona ENTER para continuar.";
		getch();
		limpiarConsola();
	}
	}while(bandera);
	
}

bool vueltaAlMenu(){
	int opcion;
	bool bandera;
	cout<<"\nDesea volver al menu principal? "<<endl;
	cout<<"1.Si      2.No"<<endl;
	cout<<"Elija una opcion[1 - 2]: ";
	cin>>opcion;
	
	
	if(opcion == 1){
		bandera = true;
			limpiarConsola();
	} else{
		bandera = false;
		cout<<"\nGracias por usar el sistema";
	}
	
	return bandera;
}

//Limpiar consola
void limpiarConsola(){
	system("cls");
}



	
