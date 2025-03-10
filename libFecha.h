#include <iostream>
#include <string> //Manejo de strings
#include <sstream> // Manejo de int a string
#include <ctime> // Manejo de captura de fecha

using namespace std;

/*
	STRUCT PROPIA DE LA LIBRERIA PARA TENERLO A MANO.
    struct tm {
      int tm_sec;   // seconds of minutes from 0 to 61
      int tm_min;   // minutes of hour from 0 to 59
      int tm_hour;  // hours of day from 0 to 24
      int tm_mday;  // day of month from 1 to 31
      int tm_mon;   // month of year from 0 to 11
      int tm_year;  // year since 1900
      int tm_wday;  // days since sunday
      int tm_yday;  // days since January 1st
      int tm_isdst; // hours of daylight savings time
    }
    Siempre devuelve un entero que luego hago referencia con los arrays creados.
    En este caso dias de la semana y meses del año
*/

string obtenerFecha(){
	
	// fecha/hora actual basado en el sistema actual - Devuelve segundos
	time_t now = time(0);
	
	//Objeto de una estructura tm con fecha/hora local - Envuelve el struct de la libreria en el objeto time 
	tm * time = localtime(&now);
	
	//Declaracion de arrays predeterminados
	string dias[] = {"Domingo", "Lunes", "Martes","Mircoles","Jueves","Viernes","Sabado"};
	string mes[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
	
	int anio = 1900 + time->tm_year;
	stringstream sa;
	sa<<anio;
	string anioStr = sa.str();
	
	int fecha = time->tm_mday;
	stringstream ss;
	ss<<fecha;
	string fechaStr = ss.str();
	
	
	
	string fechaObtenida = dias[time->tm_wday] + " " + fechaStr +
	" de " + mes[time->tm_mon] +
	" del " + anioStr;
	
	return fechaObtenida;
	
}
