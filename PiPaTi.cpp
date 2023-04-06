#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include "PiPaTi.h"
using namespace std;



	
	void instruccionesPiPaTi(){
		cout<<"El juego consta de 5 rondas, su puntaje se mostrara al final de la partida"<<endl;
		cout<<"Debera elegir un arma, teniendo en cuenta que:"<<endl;
		cout<<"-Piedra gana a tijera."<<endl<<"-Tijera gana a papel."<<endl<<"-Papel gana a piedra."<<endl<<endl;
	}
		

	int repetirPipati(){
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
				system("cls");
				break;
				
			}
		} while(SIoNO != 'y' and SIoNO != 'n');
		return a;
	}
	
	int IniciarPipati() {
		srand(time(NULL));
		
		// 1-Piedra  2-Papel  3-Tijera
		
		int Usuario,PC,Puntos;
		

		system("cls");
		
			Puntos=0;
			
			for(int i=1;i<=5;i++){
				PC=1+rand()%3;
				cout<<"Ingrese 1(Piedra), 2(Papel) o 3(Tijera): ";
				cin>>Usuario;
				cout<<endl;
				if(Usuario<1 or Usuario>3){
					cout<<"Por favor,ingrese 1, 2 o 3"<<endl;
					i--;
				}
				else{
					if(Usuario==PC){
						cout<<"La PC eligio: "<<PC<<endl;
						cout<<"Empate, no se otorgan puntos."<<endl;
						cout<<"Ronda: "<<i<<endl;
					}
					else if(Usuario==1 and PC==2){
						cout<<"La PC eligio: "<<PC<<endl;
						cout<<"Papel envuelve a Piedra."<<endl;
						cout<<"Punto para la PC."<<endl;
						cout<<"Ronda: "<<i;
					}
					else if(Usuario==1 and PC==3){
						cout<<"La PC eligio: "<<PC<<endl;
						cout<<"Piedra aplasta a Tijera."<<endl;
						cout<<"Punto para el Usuario."<<endl;
						cout<<"Ronda: "<<i;
						Puntos=Puntos+1;
					}
					else if(Usuario==2 and PC==1){
						cout<<"La PC eligio: "<<PC<<endl;
						cout<<"Papel envuelve a Piedra."<<endl;
						cout<<"Punto para el Usuario."<<endl;
						cout<<"Ronda: "<<i;
						Puntos=Puntos+1;
					}
					else if(Usuario==2 and PC==3){
						cout<<"La PC eligio: "<<PC<<endl;
						cout<<"Tijera corta a Papel."<<endl;
						cout<<"Punto para la PC."<<endl;
						cout<<"Ronda: "<<i;
					}
					else if(Usuario==3 and PC==1){
						cout<<"La PC eligio: "<<PC<<endl;
						cout<<"Piedra aplasta a Tijera."<<endl;
						cout<<"Punto para la PC."<<endl;
						cout<<"Ronda: "<<i;
					}
					else if(Usuario==3 and PC==2){
						cout<<"La PC eligio: "<<PC<<endl;
						cout<<"Tijera corta a Papel."<<endl;
						cout<<"Punto para el Usuario."<<endl;
						cout<<"Ronda: "<<i;
						Puntos=Puntos+1;
					}
				}
				cout<<endl;
				system("pause");
				system("cls");
			}
			
			cout<<"Han finalizado las cinco rondas."<<endl;
			cout<<"Puntaje final: "<<Puntos<<endl<<endl;
			cout<<"¡Gracias por jugar!"<<endl<<endl;
			system("pause");
			
			
			
		
		return Puntos;
		
	}
