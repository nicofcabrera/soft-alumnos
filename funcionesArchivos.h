#include <iostream>
#include <fstream> // Archivos
#include <string.h> // Libreria para uso de string varios
#include <direct.h> //Crear directorios mkdir

using namespace std;

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
void escribirArchivo(){
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
	
	// Interaccion con el usuario - Creacion de la lista enumerada
	cout<<"\nIngresar la cantidad de alumnos a registrar"<<endl;
	cin>>cAlum;
	cout<<"Digite el alumno uno por uno:"<<endl;
	
	cin.ignore();
	for(int i= 0; i<cAlum; i++){
		getline(cin,alumnos[i]);
		archivo<<alumnos[i]<<endl;
	}
	
	cout<<"\nAgregados exitosamente"<<endl;
	
	//Finalización de la carga de informacion al archivo
	archivo.close();
}

//##LECTURA DE ARCHIVOS
void leerArchivos(){
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

