#include <iostream>
#include <conio.h> // Pausa
#include <fstream> // Archivos
#include <string.h> // Libreria para uso de string varios
#include <direct.h> //Crear directorios mkdir
#include "funcionesArchivos.h" // Libreria propia manejo prototipos archivos
#include "libFecha.h" //Libreria propia incluye funcionalidad de obtener fecha.
#include "libGotoxy.h" //Libreria propia para el manejo de gotoxy

using namespace std;
/*
Libreriapara el manejo de funciones de Archivos: Escritura, Leer y Edicion.
*/

/*
Funcion para poder introducir un comando de terminal
Esto me da la posibilidad de poder visualizar lo que se encuentra dentro del directorio.
*/

void comandosTerminal(){
	string directorio = "Archivos generados";
	string comando = "DIR \"" + directorio + "\" /B /A:-D";
	system(comando.c_str());	
}

//Escribiendo archivo
void escribirArchivo(){
	system("cls");
	cout<<"\n			Generando lista"<<endl;
	
	ofstream archivo; // OFSTREAM para crear el archivo y escribir en él. Output
	string nombreArchivo;
	string ruta = "Archivos generados//";
	string alumnos[100];
	int cAlum; //Cantidad de alumnos ingresado por le usuario
	
	//Si NO existe la carpeta creada, entonces crearla.	
	if(!mkdir(ruta.c_str())){
		mkdir(ruta.c_str());
	}
	//Interacción con el usuario - Nombre del archivo
	cout<<"\n		Coloque el nombre del archivo: ";
	cin.ignore();
	getline(cin,nombreArchivo);
	
	ruta = ruta + nombreArchivo + ".txt"; // Concatenación
	archivo.open(ruta.c_str(), ios::out); // Creación del archivo, parsear los datos del usuario y grabarlo.
	// Condicional de falla
	if(archivo.fail()){ 
		cout<<"\n		ERROR. No se pudo crear el archivo.";
		exit(1);
	}
	
	// Escribo fecha de creacion del archivo.
	archivo<<obtenerFecha()<<endl;
	archivo<<"\n";
	
	// Interaccion con el usuario - Creacion de la lista enumerada
	cout<<"\n		Cantidad de alumnos a registrar: ";
	cin>>cAlum;
	cout<<"\n		Digite el alumno uno por uno:"<<endl;
	cin.ignore();
	for(int i= 0; i<cAlum; i++){
		cout<<"		";
		getline(cin,alumnos[i]);
		archivo<<alumnos[i]<<endl;
	}
	
	//Finalización de la carga de informacion al archivo
	archivo.close();
	cout<<"\n		Agregados exitosamente"<<endl;
	cout<<"\n		Presione ENTER para continuar."<<endl;
	getch();
}

//##LECTURA DE ARCHIVOS
void leerArchivos(){
	system("cls");
	cout<<"\n";
	cout<<"\n";
	cout<<"			Visualizando archivos"<<endl;
	
	gotoxy(0,3);
	comandosTerminal();		
	
	ifstream archivo; // Lectura de un archivo. I-> Input
	string texto; // Se crea variable para hacer una copia de la lectura
	//string ruta = "C://Archivos Sistema Alumnos ISET//memo.txt";
	string ruta = "Archivos generados//";
	string extension = ".txt";	
	string archivoSeleccionado;
	
	
	cout<<"\n			Que archivo desea ver?: ";
	cin.ignore();
	getline(cin,archivoSeleccionado);
	
	ruta = ruta + archivoSeleccionado + extension;
	system("cls");
	cout<<"\n			Mostrando archivo..."<<endl;
	cout<<"\n"<<endl;
	archivo.open(ruta.c_str(),ios::in); //Abrir el archivo en lectura
	
	// Condicional de falla
	if(archivo.fail()){ 
		cout<<"ERROR. No se pudo leer el archivo. Intente otra vez";
		exit(1);
	}
	
	cin.ignore();
	while(!archivo.eof()){ //mientras no sea el final del archivo
		getline(archivo,texto); //realizando una copia en la variable texto
		cout<<texto<<endl;
	}
	
	archivo.close();
	
	cout<<"\n			Presione ENTER para continuar.";
	getch();
}

// ## AGREGAR TEXTO
// Funcion que me servira para agregar mas alumnos de una lista y archivo .txt
void agregarAlumnos(){
	system("cls");
	cout<<"\n";
	cout<<"\n";
	cout<<"			Visualizando archivos"<<endl;
	
	comandosTerminal();
	
	ofstream archivo;
	string nuevosAlumnos[100];
	string ruta = "Archivos generados//";
	string extension = ".txt";	
	string archivoSeleccionado;
	int cantidadAlumnos;
	
	cout<<"\n		Que archivo desea editar?: ";
	cin.ignore();
	getline(cin,archivoSeleccionado);
	
	ruta = ruta + archivoSeleccionado + extension;
	
	archivo.open(ruta.c_str(),ios::app);
	
	if(archivo.fail()){
		cout<<"ERROR abrir archivo";
		exit(1);
	}
	
	system("cls");
	cout<<"\n		Cuantos alumnos desea agregar?: ";
	cin>>cantidadAlumnos;
	cout<<"\n		Ingrese los alumnos"<<endl;
	
	cin.ignore();
	for(int i = 0; i < cantidadAlumnos; i++){
		cout<<"		";
		getline(cin,nuevosAlumnos[i]);
		archivo<<nuevosAlumnos[i]<<endl;
	}
	
	cout<<"\n		Agregados exitosamente"<<endl;
	cout<<"\n		Presione ENTER para continuar.";
	getch();
	archivo.close();	
}

