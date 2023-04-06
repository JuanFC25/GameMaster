#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include "PaRes.h"
using namespace std;




void instruccionesPares(){
	cout<<"                                 ¡Bienvenido a PaRes!"<<endl<<endl;
	cout<<"El juego consta de encotrar la pareja de letras(mayuscula y minuscula) en un tablero de 6x6."<<endl;
	cout<<"Hay que ingresar las coordenadas de las posiciones,indicadacon una letra para las filas y "<<endl;
	cout<<"con numeros para las columnas.Se comenzara con una puntuacion de 100 puntos, y se descontaran "<<endl;
	cout<<"5 puntos por cada intento fallido."<<endl;
	cout<<"¡Buena Suerte!"<<endl<<endl;
	
	
}

void TableroFalso1(char TableroFalso[7][7],char Letras[], bool DESCUBIERTO[6][6],char Tablero[6][6]){
	cout<<"  ";//Imprime los numeros de la cabecera
	for(int i=1;i<=6;i++){
		cout<<"   "<<i; 
	}
	cout<<endl<<endl;
	for(int i=0;i<6;i++){
		cout<<Letras[i];//Imprime letras 
		cout<<" ";
		for(int j=0;j<6;j++){
			if(DESCUBIERTO[i][j]==0){
				cout<<"   "<<TableroFalso[i][j];//Imprime teclado falso
			}
			else{
				cout<<"   "<<Tablero[i][j];
			}
			
		}
		cout << endl;
	}

}

void RellenarTablero(char Tablero[6][6]){
	
	int i,j, aux1;
	
	for ( int filas = 0 ; filas<3 ; filas++) {
		for ( int columnas = 0 ; columnas <6 ; columnas ++) {
			
			Tablero [filas] [columnas] = 97 + rand () % 26 ; 
			
		}
		
	}
	for ( int filas = 3 ; filas<6 ; filas++) {
		for ( int columnas = 0 ; columnas <6 ; columnas ++) {
			
			Tablero [filas] [columnas] = Tablero [filas-3] [columnas] - 32 ; 
			
		}
		
	}
	for ( int filas = 0 ; filas<3 ; filas++) {
		for ( int columnas = 0 ; columnas <6 ; columnas ++) {
			
			i=rand()%6;
			j=rand()%6;
			aux1= Tablero [filas] [columnas];
			Tablero [filas] [columnas]=Tablero[i] [j];
			Tablero[i][j]=aux1;
		}
		
	}
	
}

void MostrarTablero(char Tablero[6][6]){
	for ( int filas = 0 ; filas<6 ; filas++) {
		for ( int columnas = 0 ; columnas <6 ; columnas ++) {
			
			cout << Tablero [filas] [columnas]<< "   "   ;
			
		}
		cout << endl ; 
	}
}

void controlar(char& filaletra, int& columna,bool DESCUBIERTO[6][6]){
	int fila=filaletra-65;
	bool valido=false;
	
	while(valido==false){
		
		if(filaletra<'A' or filaletra>'F'){
			cout<<"La letra ingresada no esta dentro del rango, intente nuevamente: ";
			cin>>filaletra>>columna;
		}
		else if (columna<0 or columna>6){
			cout<<"El numero ingresado no esta dentro del rango, intente nuevamente: ";
			cin>>filaletra>>columna;
		}
		else if (DESCUBIERTO[fila][columna-1]==1){
			cout<<"Ya ingreso estas coordenadas, intentelo nuevamente: ";
			cin>>filaletra>>columna;
		}
		else valido=true;
	}

}

void MostrarProgreso(bool DESCUBIERTO[6][6]){
	char SioNo;
	char Letra;
	int aux1=0;
	
	cout<<"¿Desea ver las posiciones adivinadas?"<<endl;
	cout<<"Pulse 'Y' para si y 'N' para no: ";
	do{
		cin >> SioNo;
		switch (SioNo){
		case 'Y':
			for(int i=0;i<6;i++){
				for (int j=0;j<6;j++){
					if(DESCUBIERTO[i][j]==1){
						aux1++;
						Letra= i+65;
						if(aux1==1){
							cout<<endl<<"Descubriste: "<<endl;
						}
						cout<<"Fila "<<Letra<<" columna "<<j+1<<endl;
						
					}
				}
			}
			if(aux1==0){
				cout<<endl<<"Todavia no has descubierto ningun par de letras"<<endl;
			}
				
				
			break;
		case 'N':
			system("cls");
			break;
		default:
			cout << "Por favor ingrese un valor correspondiente." << endl << endl;
			system("pause");
			break;
			
		}
	} while(SioNo != 'Y' and SioNo != 'N');
}

int repetirPares (){
	
	
	char SIoNO;
	int a;
	do{
		cout <<endl<<"¿Desea jugar otra partida?" <<endl ;
		cout <<"Pulse 'Y' para jugar nuevamente o 'N' Para salir: ";
		cin >> SIoNO;
		switch (SIoNO){
		case 'Y':
			a=1;
			system("cls");
			break;
		case 'N':
			a=0;
			cout<<endl<<"¡Gracias por jugar!"<<endl;
			break;
		default:
			cout << "Por favor ingrese un valor correspondiente." << endl << endl;
			system("pause");
			break;
			
		}
	} while(SIoNO != 'Y' and SIoNO != 'N');
	
	return a;
	
}

int IniciarPares() {
	
	srand (time(NULL));
	
	char  filasascii[6]={'A','B','C','D','E','F'} ;
	char  Tablero [6][6] ; 
	char  TableroFalso[7][7];
	bool  DESCUBIERTO[6][6];
	int   PuntajeInicial,columna0,columna1,conv0,conv1,modo;
	char  fila0,fila1,comparacion0,comparacion1;
	
	
		
		PuntajeInicial=100;
		int intento=20;
			
		for(int filas=0;filas<7;filas++){
			for(int col=0;col<7;col++){
				TableroFalso[filas][col]='?';
			}
		}
		
		for(int filas=0;filas<6;filas++){
			for(int col=0;col<6;col++){
				DESCUBIERTO[filas][col]=false;
			}
		}
		
		RellenarTablero(Tablero);
		system("cls");
		cout<<"1- JUGAR EN MODO GRAFICO"<<endl;
		cout<<"2- JUGAR EN MODO TEXTO"<<endl<<endl;
		
		cin >>  modo ; 
		
		if (modo == 1 ) {
			
			
			
			while(intento>0){
				
				system("cls");
				cout<<endl<<"Puntos: "<<PuntajeInicial<<endl<<endl;
				
				TableroFalso1(TableroFalso,filasascii,DESCUBIERTO,Tablero);
				cout<<endl<<endl;
				
				cout<< endl;
				cout<<"Para indicar las coordenadas, Primero se ingresa la letra en mayuscula"<<endl;
				cout<<"correspondiente a la fila, seguido del numero correspondiente a la columna"<<endl<<endl;
				
				cout<<"Ingrese las primeras coordenadas: ";
				cin >> fila0 >> columna0;
				controlar(fila0,columna0,DESCUBIERTO);
				do{
					cout<<"Ingrese las segundas coordenadas: ";
					cin>> fila1 >> columna1;
					
					if (fila0==fila1 and columna0==columna1){
						cout<<"Se ingresaron las mismas coordenadas, por favor intente nuevamente"<<endl;
					}
					else{
						controlar(fila1,columna1,DESCUBIERTO);
					}
					
				} while(fila0==fila1 and columna0==columna1);
				
				conv0=(fila0)-65;
				conv1=(fila1)-65;
				
				comparacion0=Tablero[conv0][columna0-1];
				comparacion1=Tablero[conv1][columna1-1];
				
				if (comparacion0==(comparacion1-32) or (comparacion0-32)==comparacion1){
					cout<<endl<<"¡Bien Hecho!, has encontrado la pareja."<<endl<<endl;
					DESCUBIERTO[conv0][columna0-1]=1;
					DESCUBIERTO[conv1][columna1-1]=1;
					system("pause");
				}
				else{
					cout<<endl<<"Fallaste, se te restan 5 puntos"<<endl<<endl;
					cout<<"En la Primer coordenada ingresada se encuentra: "<<Tablero[conv0][columna0-1]<<endl;
					cout<<"En la Segunda coordenada ingresada se encuentra: "<<Tablero[conv1][columna1-1]<<endl<<endl;
					PuntajeInicial=PuntajeInicial-5;
					system("pause");
				}
			
				
				int resuelto=0;
			
				for(int i=0;i<6;i++){
					for(int j=0;j<6;j++){
						if(DESCUBIERTO[i][j]==false){
							resuelto++;
						}
					}
				}
				if(resuelto==0){
					intento=0;
				}
				intento--;
			}
			system("cls");
			
			if(PuntajeInicial<5){
				cout<<"¡Has perdido!"<<endl<<"No obtienes puntaje."<<endl;
				cout<<"Las posiciones ocultas eran: "<<endl<<endl;
				MostrarTablero(Tablero);
				cout<<endl;
				system("pause");
				system("cls");
			}
			else{
				cout<<"¡Has Ganado!"<<endl<<"Tu puntaje es de: "<<PuntajeInicial<<endl;
				system("pause");
				system("cls");
			}
			
	}
		
		else if (modo ==2) {
			
			while(intento>0){
				
				system("cls");
				cout<<endl<<"Puntos: "<<PuntajeInicial<<endl<<endl;
				
				
				cout<< endl;
				cout<<"Para indicar las coordenadas, Primero se ingresa la letra en mayuscula"<<endl;
				cout<<"correspondiente a la fila, seguido del numero correspondiente a la columna"<<endl<<endl;
				
				cout<<"Ingrese las primeras coordenadas: ";
				cin >> fila0 >> columna0;
				controlar(fila0,columna0,DESCUBIERTO);
				do{
					cout<<"Ingrese las segundas coordenadas: ";
					cin>> fila1 >> columna1;
					
					if (fila0==fila1 and columna0==columna1){
						cout<<"Se ingresaron las mismas coordenadas, por favor intente nuevamente"<<endl;
					}
					else{
						controlar(fila1,columna1,DESCUBIERTO);
					}
					
				} while(fila0==fila1 and columna0==columna1);
				
				
				conv0=(fila0)-65;
				conv1=(fila1)-65;
				
				comparacion0=Tablero[conv0][columna0-1];
				comparacion1=Tablero[conv1][columna1-1];
				
				
				
				cout<<endl<<"En la fila "<<fila0<<" Columna "<<columna0<<" se encuentra la letra "<<Tablero[conv0][columna0-1]<<" ";
				
				if (97<=comparacion0 and  comparacion0<=122){
					
					cout<<"minuscula"<<endl;
				}
				else{
					
					cout<<" mayuscula"<<endl;
				}
				
				cout<<"En la fila "<<fila1<<" Columna "<<columna1<<" se encuentra la letra "<<Tablero[conv1][columna1-1]<<" ";
				
				if (97 <=comparacion1 and  comparacion1<=122){
					
					cout<<"minuscula"<<endl;
				}
				else{
					
					cout<<" mayuscula"<<endl;
				}
				
				
				
				
				if (comparacion0==(comparacion1-32) or (comparacion0-32)==comparacion1){
					cout<<endl<<"¡Bien Hecho!, has encontrado la pareja."<<endl<<endl;
					DESCUBIERTO[conv0][columna0-1]=1;
					DESCUBIERTO[conv1][columna1-1]=1;
					
					MostrarProgreso(DESCUBIERTO);
					
					cout<<endl;
					
					system("pause");
					
					
				}
				else{
					
					cout<<endl<<"Fallaste, se te restan 5 puntos"<<endl<<endl;
					PuntajeInicial=PuntajeInicial-5;
					
					MostrarProgreso(DESCUBIERTO);
					
					cout<<endl;
					
					system("pause");
				}
				
				int resuelto=0;
				
				for(int i=0;i<6;i++){
					for(int j=0;j<6;j++){
						if(DESCUBIERTO[i][j]==false){
							resuelto++;
						}
					}
				}
				if(resuelto==0){
					intento=0;
				}
				intento--;
			}
			
			system("cls");
			
			if(PuntajeInicial<5){
				cout<<"¡Has perdido!"<<endl<<"No obtienes puntaje."<<endl;
				cout<<"Las posiciones ocultas eran: "<<endl<<endl;
				
				MostrarTablero(Tablero);
				
				cout<<endl<<endl;
				
				system("pause");
				system("cls");
			}
			else{
				cout<<"¡Has Ganado!"<<endl<<"Tu puntaje es de: "<<PuntajeInicial<<endl<<endl;
				system("pause");
				system("cls");
			}
			
		}
		
	
	
	
	return PuntajeInicial;
}
