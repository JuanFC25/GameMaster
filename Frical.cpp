#include <iostream>
#include <cstddef>
#include <ctime>
#include <cstdlib>
#include "Frical.h"

using namespace std;




void InstruccionesFrical(){

	cout<< "INTRUCCIONES:" << endl; 
	cout<< "Se debera ingresar un numero en el intervalo comprendido" << endl; 
	cout<< "Tienes 10 intentos para adivinar" << endl;
	cout<< "Si el numero ingresado es mayor que el numero a adivinar, se mostrara -Caliente-" << endl; 
	cout<< "En caso contrario, se mostrara -Frio-" << endl; 
}

int repetirFrical(){
	char SIoNO;
	int a;
	do{
		cout <<endl<<"Desea jugar otra partida? y/n: \t";
		cin >> SIoNO;
		switch (SIoNO){
		case 'y':
			a=0;
			break;
		case 'n':
			a=1;
			break;
		default:
			cout << "Por favor ingrese un valor correspondiente." << endl << endl;
			system("pause");
			break;
			
		}
	} while(SIoNO != 'y' and SIoNO != 'n');
	return a;
}

int IniciarFrical() {
	srand(time(NULL));
	bool Acierto=false;
	int NumSecreto,NumIngresado,PuntajeFinal;
	
	
	cout<<endl;

	
	
		NumSecreto=1+rand()%100;
		system("cls");
		
		
		
		for(int i=1;i<=10;i++){
			cout<<"Ingresa un numero entre 1 y 100: ";
			cin>>NumIngresado;
			cout<<endl;
			
			if(NumIngresado<1 or NumIngresado>100){
				cout<<"el valor ingresado no esta dentro del intervalo, intente nuevamente"<<endl;
				cout<<"Ronda: "<<i<<endl;
				i--;
			}
			else if(NumIngresado<NumSecreto){
				cout<<"Frio"<<endl;
				cout<<"Ronda: "<<i<<endl<<endl;
				
			}
			else if(NumIngresado>NumSecreto){
				cout<<"Caliente"<<endl;
				cout<<"Ronda: "<<i<<endl<<endl;
				
			}
			else if(NumIngresado==NumSecreto){
				PuntajeFinal=11-i;
				i=10;
				Acierto=true;	
				cout<<"¡Felicidades! Has acertado el numero oculto"<<endl;
				cout<<"Este era: "<<NumSecreto<<endl;
				cout<<"Puntaje Final: "<<PuntajeFinal<<endl<<endl;
			}
			
			system("pause");
			system("cls");
		}
		if(Acierto==false){
			cout<<"¡Has fallado!"<<endl;
			cout<<"El numero oculto era: "<<NumSecreto<<endl;
			cout<<"No obtienes puntaje"<<endl<<endl;
		}
		
		cout<<" ¡Gracias por jugar!"<<endl<<endl;
		system("pause");
		
	
	return PuntajeFinal;
}
