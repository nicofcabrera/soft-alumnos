#include "libGotoxy.h"


void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}


//FUNCION QUE DIBUJA EL CUADRO
void dibujarCuadro(int x1,int y1,int x2,int y2){
	int i;
	
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "\304"; //linea horizontal superior
		gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
		gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
	}
	
    gotoxy(x1,y1); cout<< "\332"; 
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
}

void definicionCuadroInicio(){
	system("mode con: cols=80 lines=30"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 30 FILAS
	system("COLOR 17"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(0,0,78,28); //SE DIBUJA EL CUADRO PRINCIPAL
	dibujarCuadro(1,1,77,5); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy (28,3);
	cout<<"Sistema Alumnos - ISET"<<endl;
}
