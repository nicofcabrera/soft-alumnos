#include <iostream>
#include <fstream> // Archivos
#include <string.h> // Libreria para uso de string varios
#include <direct.h> //Crear directorios mkdir
#include "libFecha.h" //Libreria propia incluye funcionalidad de obtener fecha.
#include "libGotoxy.h" //Libreria propia para el manejo de gotoxy

using namespace std;

string obtenerFecha();
void gotoxy(int x, int y);

/*
Libreria .h para el manejo de funciones de Archivos: Escritura, Leer y Edicion.
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
int escribirArchivo(){
	system("cls");
	definicionCuadroInicio();
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
	gotoxy(18,8);
	cout<<"Coloque el nombre del archivo: ";
	cin.ignore();
	getline(cin,nombreArchivo);
	
	ruta = ruta + nombreArchivo + ".txt"; // Concatenación
	archivo.open(ruta.c_str(), ios::out); // Creación del archivo, parsear los datos del usuario y grabarlo.
	// Condicional de falla
	if(archivo.fail()){ 
		cout<<"ERROR. No se pudo crear el archivo.";
		exit(1);
	}
	
	// Escribo fecha de creacion del archivo.
	archivo<<obtenerFecha()<<endl;
	archivo<<"\n";
	
	// Interaccion con el usuario - Creacion de la lista enumerada
	gotoxy(18,9);
	cout<<"Cantidad de alumnos a registrar: ";
	cin>>cAlum;
	gotoxy(18,10);
	cout<<"Digite el alumno uno por uno:"<<endl;
	
	cin.ignore();
	int valorI = 0;
	for(int i= 0; i<cAlum; i++){
		gotoxy(18,12+i);
		getline(cin,alumnos[i]);
		archivo<<alumnos[i]<<endl;
		valorI = valorI + i;
	}
	valorI++;
	valorI = valorI + 12;
	gotoxy(18,valorI+1);
	//cout<<valorI;
	cout<<"Agregados exitosamente"<<endl;
	
	//Finalización de la carga de informacion al archivo
	archivo.close();
	
	return valorI+1;
}

//##LECTURA DE ARCHIVOS
void leerArchivos(){
	cout<<"\nVisualizando archivos"<<endl;
	cout<<"\n";
	comandosTerminal();
	
	ifstream archivo; // Lectura de un archivo. I-> Input
	string texto; // Se crea variable para hacer una copia de la lectura
	//string ruta = "C://Archivos Sistema Alumnos ISET//memo.txt";
	string ruta = "Archivos generados//";
	string extension = ".txt";	
	string archivoSeleccionado;
	
	
	cout<<"\nEscriba el archivo que desea abrir: ";
	cin.ignore();
	getline(cin,archivoSeleccionado);
	
	ruta = ruta + archivoSeleccionado + extension;
	
	cout<<"\n";
	archivo.open(ruta.c_str(),ios::in); //Abrir el archivo en lectura
	
	// Condicional de falla
	if(archivo.fail()){ 
		cout<<"ERROR. No se pudo leer el archivo. Intente otra vez";
		exit(1);
	}
	
	while(!archivo.eof()){ //mientras no sea el final del archivo
		getline(archivo,texto); //realizando una copia en la variable texto
		cout<<texto<<endl;
	}
	
	archivo.close();
	
}

// ## AGREGAR TEXTO
// Funcion que me servira para agregar mas alumnos de una lista y archivo .txt
void agregarAlumnos(){
	cout<<"\nVisualizacion de archivos"<<endl;
	cout<<"\n";
	comandosTerminal();
	
	ofstream archivo;
	string nuevosAlumnos[100];
	string ruta = "Archivos generados//";
	string extension = ".txt";	
	string archivoSeleccionado;
	int cantidadAlumnos;
	
	cout<<"\nEscriba el nombre del archivo a seleccionar: ";
	cin.ignore();
	getline(cin,archivoSeleccionado);
	
	ruta = ruta + archivoSeleccionado + extension;
	
	archivo.open(ruta.c_str(),ios::app);
	
	if(archivo.fail()){
		cout<<"ERROR abrir archivo";
		exit(1);
	}
	
	
	cout<<"Cuantos alumnos desea agregar?: ";
	cin>>cantidadAlumnos;
	cout<<"\nIngrese los alumnos"<<endl;
	
	cin.ignore();
	for(int i = 0; i < cantidadAlumnos; i++){
		getline(cin,nuevosAlumnos[i]);
		archivo<<nuevosAlumnos[i]<<endl;
	}
	
	cout<<"\nAgregados exitosamente"<<endl;
	
	archivo.close();	
}

