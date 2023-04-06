#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include "Generala Avanzada.h"

using namespace std;



int repetirGeneralaAvanzada (){
	
	
	char SIoNO;
	int a;
	do{
		cout <<endl<<"Desea jugar otra partida? y/n: " <<endl ;
		cin >> SIoNO;
		switch (SIoNO){
		case 'y':
			a=1;
			break;
		case 'n':
			a=0;
			cout<<endl<<"¡Gracias por jugar!"<<endl;
			break;
		default:
			cout << "Por favor ingrese un valor correspondiente." << endl << endl;
			system("pause");
			break;
			
		}
	} while(SIoNO != 'y' and SIoNO != 'n');
	
	return a;
	
}
void InstruccionesGeneralaAvanzada () {
	
		system("cls"); 
		cout << "                   PUNTAJES" << endl<<endl; ; 
		cout<<"1- Generala: Consiste en tener todos los dados iguales. Puede ser servida"<<endl;
		cout<<"(55 puntos) o armada(50 puntos)."<<endl<<endl;
		cout<<"2- Poker: Se forma con 4 dados iguales. Puede ser servido (45 puntos)"<<endl;
		cout<<"o armado(40 puntos)."<<endl<<endl;
		cout<<"3- Full: Se forma con 2 y 3 dados iguales. Puede ser servido (25 puntos)"<<endl;
		cout<<"o armado(20 puntos)."<<endl<<endl;
		cout<<"4- Escalera: Se forma con una progresion de numeros. Puede ser servida "<<endl;
		cout<<"(25 puntos) o armada(20 puntos)."<<endl<<endl;
		cout<<"5- Valores numericos: Se ponen puntos al valor del numero que no se haya"<<endl;
		cout<<"anotado y se repite mas veces. Si los numeros se repiten la misma cantidad"<<endl;
		cout<<"de veces, se anota puntaje al valor del numero mas chico."<<endl<<endl;
		cout<<"Los puntajes se mostraran en una tabla mediante se juega la partida."<<endl;
		cout<<"las filas del 1 al 6 corresponden a valores numericos, la fila 7 a"<<endl;
		cout<<"Escalera, la 8 a Full, la 9 a Poker y la 10 a Generala. La columna 1"<<endl;
		cout<<"sera el Usuario y la 2 la PC"<<endl<<endl;
		cout<<"En caso de no obtener puntaje en una tirada, se procedera a cancelar"<<endl;
		cout<<"la fila de mayor valor que aun no se haya obtenido puntaje, asignandole"<<endl;
		cout<<"un valor de 0."<<endl<<endl;
		cout<<"¡Eso es todo!, ¿Estas listo para jugar?"<<endl<<endl;
	

	
}


int dados () {
	int dado;
	dado = 1+rand () % 6 ;
	
	return dado; 
	
}




void tirada (int TIRADA []){
	for (int i=0 ; i<5 ; i++){
		
		TIRADA [i] = 1+rand () % 6  ; 
	}
	for (int i=0 ; i<5 ; i++) {
		
		cout <<"Dado "<< (i+1) << ":  " << TIRADA [i] << endl  ;
	}
	cout<<endl<<endl;
	
}
void CambioDado (int TIRADA []){
	
	int TiradaAUX [5] ;
	
	cout << "Indique los dados que desea dejar con un 0, y los que desea cambiar con un 1" << endl  ;
	
	for (int i = 0 ; i<5 ; i++ ) {
		
		cin >> TiradaAUX [i];
	}
	
	cout << endl ; 
	
	for (int i = 0 ; i<5 ; i++ ) {
		
		if ( TiradaAUX [i] == 1 ) {
			
			TIRADA [i] = 1+rand () % 6 ;
		}
	}
	for (int i=0 ; i<5 ; i++) {
		
		cout <<"Dado "<< (i+1) << ":  " << TIRADA [i] << endl  ;
	}
	cout<<endl<<endl;
}


void OrdenarDados(int TIRADA[]){
	int aux;
	
	for (int pasada=0; pasada<5; pasada++){
		for (int k=0 ; k< 4; k++){
			if (TIRADA[k] > TIRADA[k+1]){
				aux = TIRADA[k];
				TIRADA[k] = TIRADA[k+1];
				TIRADA[k+1] = aux;
			}
		}
	}
	
}

void Puntajes(int TIRADA[5],int PUNTAJE [10][2],int CantTirada,int Jugador){
	
	
	if(TIRADA[0]==TIRADA[4] and PUNTAJE[9][Jugador]==99){
		if(CantTirada==0){
			PUNTAJE[9][Jugador]=55;
			cout<<"Generala Servida"<<endl;
		}
		else{
			PUNTAJE[9][Jugador]=50;
			cout<<"Generala armada"<<endl;
		}
	}
	else if((TIRADA[0]==TIRADA[3] or TIRADA[1]==TIRADA[4])and PUNTAJE[8][Jugador]==99){
		if(CantTirada==0){
			PUNTAJE[8][Jugador]=45;
			cout<<"Poker Servido"<<endl;
		}
		else{
			PUNTAJE[8][Jugador]=40;
			cout<<"Poker armado"<<endl;
		}
	}
	else if(((TIRADA[0]==TIRADA[1] and TIRADA[2]==TIRADA[4])or (TIRADA[0]==TIRADA[2] and TIRADA[3]==TIRADA[4])) and PUNTAJE[7][Jugador]==99){
		if(CantTirada==0){
			PUNTAJE[7][Jugador]=35;
			cout<<"Full Servido"<<endl;
		}
		else{
			PUNTAJE[7][Jugador]=30;
			cout<<"Full armado"<<endl;
		}
	}
	else if ((TIRADA[0]+1 == TIRADA[1] and TIRADA[1]+1 == TIRADA[2] and TIRADA[2]+1 == TIRADA[3] and TIRADA[3]+1 == TIRADA[4] ) and PUNTAJE[6][Jugador]==99){
		if(CantTirada==0){
			PUNTAJE[6][Jugador]= 25;
			cout<<"Escalera Servida"<<endl;
		}
		else{
			PUNTAJE[6][Jugador]= 20;
			cout<<"Escalera armada"<<endl;
		}
	}
	else {
		
		NumeroMasRepetido(TIRADA,PUNTAJE,Jugador);
		
		
	}
	
	
	
	
}



void NumeroMasRepetido(int TIRADA[5],int PUNTAJE[10][2],int Jugador){
	int NumRep=0,CanRep=0,aux,Puntaje=0;
	
	for (int i=1;i<7;i++){
		aux=0;
		for(int j=0;j<5;j++){
			if(TIRADA[j]==i){
				aux=aux+1;
			}
		}
		if(aux>CanRep and PUNTAJE[i-1][Jugador]==99){
			
			NumRep=i;
			CanRep=aux;
			Puntaje=NumRep*CanRep;
		}
	}
	if(NumRep==0 and CanRep==0){
		CancelarPuntaje(PUNTAJE,Jugador);
	}
	else{
		PUNTAJE[NumRep-1][Jugador]=Puntaje;
		cout<<"¡Valor Numerico!,Se repite "<<CanRep<<" ves(es) el Numero "<<NumRep<<endl;
		cout<<"Obtienes un Puntaje de: "<<Puntaje;
	}
}

void CancelarPuntaje(int PUNTAJE[10][2],int Jugador){
	int fila;
	for (int i=9;i>=0;i--){
		if(PUNTAJE[i][Jugador]==99){
			PUNTAJE[i][Jugador]=0;
			fila=i+1;
			i=0;
		}
	}
	cout<<"Se ha cancelado la fila "<<fila<<endl;
	
	
}



void MostrarPuntajes(int PUNTAJE[10][2]){
	cout<<"              Puntajes"<<endl<<endl;
	cout<<"        Usuario         PC"<<endl;
	for(int i=1;i<=10;i++){
		if(i<10){
			cout<<"fila "<<i<<"    ";
		}
		else{
			cout<<"fila "<<i<<"   ";
		}
		for(int col=0;col<2;col++){
			if(PUNTAJE[i-1][col]==99){
				cout<<"--"<<"            ";
			}
			else{
				if(PUNTAJE[i-1][col]>9){
					cout<<PUNTAJE[i-1][col]<<"            ";
				}
				else{
					cout<<PUNTAJE[i-1][col]<<"             ";
				}
			}
		}
		cout<<endl;
	}
	
}




int IniciarGeneralaAvanzada() {
	
	srand (time(NULL));
	
	int DadoInicioPC, DadoInicioU, Empezar, TIRADA[5], CambiodeDado,PUNTAJE[10][2],CantTirada=0,Jugador,Rondas=1,PuntajeTotalUsu=0,PuntajeTotalPC=0,puntajeRetorno;
	
	system("pause");
	system("cls");
	DadoInicioPC = dados() ;
	DadoInicioU = dados() ;
	
	
		
		PuntajeTotalUsu=0;
		PuntajeTotalPC=0;
		Rondas=1;
		
		for(int filas=0;filas<10;filas++){
			for(int columnas=0;columnas<10;columnas++){
				PUNTAJE[filas][columnas]=99;
			}
		}
		
		while(Rondas !=11){
			
			
			
			if(Rondas==1){
				cout<<"Pulse 1 para lanzar dados y determinar quien comienza el juego"<<endl;
				cout<<"Comienza el que obtenga el valor más alto. ¡Suerte! "<<endl;
				cin>>Empezar;
				system("cls");
			}
			
			if(Empezar==1){
				if(DadoInicioPC>DadoInicioU){
					
					cout<<"Ronda "<<Rondas<<endl<<endl;
					
					if(Rondas==1){
						cout<<"Dado PC: "<<DadoInicioPC<<"	Dado Usuario: "<<DadoInicioU<<endl;
						cout<<"Comienza la PC"<<endl<<endl;
					}
					cout<<endl;
					system("pause");
					cout<<endl;
					
					tirada (TIRADA) ;
					Jugador=1;
					OrdenarDados(TIRADA);
					
					
					Puntajes(TIRADA,PUNTAJE,CantTirada,Jugador);
					
					
					
					cout<<endl<<endl;
					MostrarPuntajes(PUNTAJE);
					system("pause");
					system("cls");
					
					cout<<"Ronda "<<Rondas<<endl<<endl;
					
					cout<<endl;
					system("pause");
					cout<<endl;
					
					tirada (TIRADA) ;
					Jugador=0;
					cout << "¿Desea cambiar algún dado?" << endl << "Si es así marque 1, de lo contrario marque 2" << endl ;
					
					cin >> CambiodeDado ; 
					
					if ( CambiodeDado == 1 ) {
						
						CantTirada=1;
						CambioDado(TIRADA) ;
						
						OrdenarDados(TIRADA);
						
						
						Puntajes(TIRADA,PUNTAJE,CantTirada,Jugador);
						Rondas=Rondas+1;
						
						cout<<endl<<endl;
						
						MostrarPuntajes(PUNTAJE);
						
						system("pause");
						system("cls");
					}
					else {
						OrdenarDados(TIRADA);
						
						
						Puntajes(TIRADA,PUNTAJE,CantTirada,Jugador);
						Rondas=Rondas+1;
						
						cout<<endl<<endl;
						
						MostrarPuntajes(PUNTAJE);
						
						system("pause");
						system("cls");
					}
					
				}
				else{
					cout<<"Ronda "<<Rondas<<endl<<endl;
					
					if(Rondas==1){
						cout<<"Dado PC: "<<DadoInicioPC<<"	Dado Usuario: "<<DadoInicioU<<endl;
						cout<<"Comienza el Usuario"<<endl<<endl;
					}
					
					cout<<endl;
					system("pause");
					cout<<endl;
					
					tirada (TIRADA) ;
					Jugador=0;
					cout << "¿Desea cambiar algún dado?" << endl << "Si es así marque 1 " << endl ;
					
					cin >> CambiodeDado ; 
					
					if ( CambiodeDado == 1 ) {
						
						CantTirada=1;
						CambioDado(TIRADA) ;
					}
					
					OrdenarDados(TIRADA);
					
					
					Puntajes(TIRADA,PUNTAJE,CantTirada,Jugador);
					
					cout<<endl<<endl;
					
					MostrarPuntajes(PUNTAJE);
					
					system("pause");
					system("cls");
					
					cout<<"Ronda "<<Rondas<<endl<<endl;
					
					cout<<endl;
					system("pause");
					cout<<endl;
					
					tirada (TIRADA) ;
					Jugador=1;
					OrdenarDados(TIRADA);
					
					
					Puntajes(TIRADA,PUNTAJE,CantTirada,Jugador);
					
					Rondas=Rondas+1;
					
					cout<<endl<<endl;
					
					MostrarPuntajes(PUNTAJE);
					
					
					system("pause");
					system("cls");
				}
			}
			
			else{
				cout<<"El valor ingresado no es correcto"<<endl;
			}
		}
		
		for(int fil=0;fil<10;fil++){
			for(int col=0;col<2;col++){
				PuntajeTotalUsu=PuntajeTotalUsu+PUNTAJE[fil][0];
				PuntajeTotalPC=PuntajeTotalPC+PUNTAJE[fil][1];
			}
		}
		
		if(PuntajeTotalPC==PuntajeTotalUsu){
			cout<<endl<<"¡Es un Empate!"<<endl;
			cout<<"Han terminado con un puntaje de: "<<PuntajeTotalPC/2<<endl;
		}
		else if (PuntajeTotalUsu>PuntajeTotalPC){
			cout<<"¡Has ganado!"<<endl;
			cout<<"Finalizaste con un puntaje de: "<<PuntajeTotalUsu/2<<endl;
			cout<<"La PC finalizo con: "<<PuntajeTotalPC/2<<endl;
		}
		else {
			cout<<"¡Has perdido!"<<endl;
			cout<<"Finalizaste con un puntaje de: "<<PuntajeTotalUsu/2<<endl;
			cout<<"La PC finalizo con: "<<PuntajeTotalPC/2<<endl;
		}
		
		system("pause");
		
		if(PuntajeTotalUsu>PuntajeTotalPC){
			puntajeRetorno=PuntajeTotalUsu/2;
		}
		else{
			puntajeRetorno=(PuntajeTotalPC/2)+1000;
		}
	
	return puntajeRetorno;
}
