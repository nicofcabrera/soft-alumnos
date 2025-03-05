#include <iostream>
#include <conio.h> // Pausar sistema
#include "miLibreria.h" // Libreria Propia
#include <fstream> // Archivos
#include <string.h> // Libreria para uso de string varios
#include <direct.h> //Crear directorios mkdir

using namespace std;

//void saludar();

// # Prototipos
void comandosTerminal(); //Idea para poder utilizar comandos de terminal, ver directorios, crearlos, etc.
void escribirArchivo();
void leerArchivos();
void agregarAlumnos();

int main(){
	
	int opcion;
	bool bandera = true;
	
	//do{
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
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;				
		}
	//}while(bandera);

	//saludar();
	//escribirArchivo();
	//leerArchivos();
	//comandosTerminal();
	//agregarAlumnos();
	//getch();
	
	
	
	return 0;
}


void comandosTerminal(){
	/*while(true){
		cout<<"Comando: ";
		string comandos;
		getline(cin, comandos);
		system(comandos.c_str());
		if(comandos == "EXIT" || comandos == "exit") break;
	}*/
	
	string comando = "DIR prueba  /B /A:-D";
	system(comando.c_str());
	getch();
	
}

//Escribiendo archivo
void escribirArchivo(){
	ofstream archivo; // OFSTREAM para crear el archivo y escribir en él. Output
	string nombreArchivo;
	//string ruta = "C://Archivos Sistema Alumnos ISET//";
	string ruta = "prueba//";
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
	//getline(cin,nombreArchivo);
	
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
		archivo<<i<<"_"<<alumnos[i]<<endl;
	}
	
	cout<<"\nAgregados exitosamente";
	
	//Finalización de la carga de informacion al archivo
	archivo.close();
}

//##LECTURA DE ARCHIVOS
void leerArchivos(){
	comandosTerminal();
	
	ifstream archivo; // Lectura de un archivo. I-> Input
	string texto; // Se crea variable para hacer una copia de la lectura
	//string ruta = "C://Archivos Sistema Alumnos ISET//memo.txt";
	string ruta = "prueba//";
	string extension = ".txt";	
	string archivoSeleccionado;
	
	cout<<"\nEscriba el archivo que desea abrir: ";
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
	cout<<"Visualizacion de archivos"<<endl;
	cout<<"\n";
	comandosTerminal();
	
	ofstream archivo;
	string nuevosAlumnos[100];
	string ruta = "prueba//";
	string extension = ".txt";	
	string archivoSeleccionado;
	int cantidadAlumnos;
	
	cout<<"\nEscriba el archivo que desea agregar alumnos: ";
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
		
	for(int i = 0; i <= cantidadAlumnos; i++){
		getline(cin,nuevosAlumnos[i]);
		archivo<<nuevosAlumnos[i]<<endl;
	}
	
	
	
	
	archivo.close();
	
}
