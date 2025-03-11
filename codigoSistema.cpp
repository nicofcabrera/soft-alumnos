#include <iostream>
#include <conio.h> // Pausar sistema
#include "libGotoxy.h" // Libreria propia para manejoss de gotoxy
#include "funcionesArchivos.h" //Libreria propia para manejo de archivos
#include <windows.h> // Manejo funciones propias de windows
#include <stdlib.h>	 // Manejo funciones


using namespace std;

// # Prototipos
bool vueltaAlMenu();
void limpiarConsola();
void menu();

int main(){
	
	menu();	

	getch();	
	return 0;
}

// Funcion MENU
void menu(){

	bool bandera = true;
	
	do{
	int opcion;
	limpiarConsola();
	definicionCuadroInicio();
	
	gotoxy(20,8);
	cout<<"1. Generar lista Alumnos";
	gotoxy(20,9);
	cout<<"2. Ver listado Alumnos"<<endl;
	gotoxy(20,10);
	cout<<"3. Agregar Alumno"<<endl;
	gotoxy(20,11);
	cout<<"4. Salir"<<endl;
	gotoxy(18,14);
	cout<<"Elige una opcion [1-4]: ";
	cin>>opcion;
	
	switch(opcion){
		case 1:
			escribirArchivo();
			bandera = vueltaAlMenu();
			//sgetch();sssssss
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
			gotoxy(16,18);
			cout<<"Has finalizado el uso del sistema."<<endl;
			bandera = false;
			break;			
		default:
		gotoxy(15,16);
		cout<<"El dato ingresado no es correcto, intenta otra vez."<<endl;
		gotoxy(15,17);
		cout<<"Presiona ENTER para continuar.";
		getch();
		limpiarConsola();
	}
	}while(bandera);
	
}

//Funcion para volver al menu
bool vueltaAlMenu(){
	
	limpiarConsola();
	definicionCuadroInicio();
	int opcion;
	bool bandera;
	while(true){
		gotoxy(18,8);
		cout<<"Desea volver al menu principal? "<<endl;
		gotoxy(18,9);
		cout<<"	1.Si      2.No"<<endl;
		gotoxy(18,10);
		cout<<"Elija una opcion[1 - 2]: ";
		cin>>opcion;	
		
		if(opcion == 1){
			bandera = true;
			limpiarConsola();
			break;
		} else if(opcion == 2){
			bandera = false;
			gotoxy(18,12);
			cout<<"Gracias por usar el sistema";
			break;
		} else{
			gotoxy(18,12);
			cout<<"El digito ingresado no es correcto.";
			getch();
			limpiarConsola();
		}
	}
	return bandera;
}

//Limpiar consola
void limpiarConsola(){
	system("cls");

}
	
