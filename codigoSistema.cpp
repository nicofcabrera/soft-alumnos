#include <iostream>
#include <conio.h> // Pausar sistema
#include "miLibreria.h" // Libreria Propia
#include <fstream> // Archivos
#include <string.h> // Libreria para uso de string varios
#include <direct.h> //Crear directorios mkdir

using namespace std;

//void saludar();

// # Prototipos
void escribirArchivo();
void leerArchivos();

int main(){
//ss
	
	//escribirArchivo();
	leerArchivos();
	getch();
	
	
	
	return 0;
}

void escribirArchivo(){
	ofstream archivo; // OFSTREAM para crear el archivo y escribir en él. Output
	string nombreArchivo, dato;
	string ruta = "C://Archivos Sistema Alumnos ISET//";
	string alumnos[100];
	int cAlum; //Cantidad de alumnos ingresado por le usuario
	
	//Si NO existe la carpeta creada, entonces crearla.	
	if(!mkdir(ruta.c_str())){
		mkdir(ruta.c_str());
	}

	//Interacción con el usuario - Nombre del archivo
	cout<<"Coloque el nombre del archivo: ";
	getline(cin,nombreArchivo);
	
	ruta = ruta + nombreArchivo + ".txt"; // Concatenación
	archivo.open(ruta.c_str(), ios::out); // Creación del archivo, parsear los datos del usuario y grabarlo.
	
	// Condicional de falla
	if(archivo.fail()){ 
		cout<<"ERROR. No se pudo crear el archivo.";
		exit(1);
	}
	
	// Interaccion con el usuario - Creacion de la lista enumerada
	cout<<"Ingresar la cantidad de alumnos a registrar"<<endl;
	cin>>cAlum;
	cout<<"\nDigite el alumno uno por uno:"<<endl;
	
	for(int i= 0; i<=cAlum; i++){
		getline(cin,alumnos[i]);
		archivo<<i<<"_"<<alumnos[i]<<endl;
	}
	
	cout<<"\nAgregados exitosamente";
	
	//Finalización de la carga de informacion al archivo
	archivo.close();
}

void leerArchivos(){
	ifstream archivo; // Lectura de un archivo. I-> Input
	string texto; // Se crea variable para hacer una copia de la lectura
	string ruta = "C://Archivos Sistema Alumnos ISET//memo.txt";
	
	archivo.open(ruta.c_str(),ios::in); //Abrir el archivo en lectura
	
	// Condicional de falla
	if(archivo.fail()){ 
		cout<<"ERROR. No se pudo crear el archivo.";
		exit(1);
	}
	
	while(!archivo.eof()){ //mientras no sea el final del archivo
		getline(archivo,texto); //realizando una opcia en la variable texto
		cout<<texto<<endl;
	}
	
	archivo.close();
	
	
}
