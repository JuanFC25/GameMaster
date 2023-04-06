#include <iostream>
#include <ctime>
#include <cstddef>
#include <cstdlib>
#include "Generala.h"

using namespace std;


int dado1(){
	int dado;
	dado=1+rand ()% 6;
	return dado;
}


int puntajeusuario(int a, int b, int c){
	int total=0;
	if(a==b and b==c){
		total=total+50;
	}
	else if(b==(a+1) and b==(c-1)){
		total=a+b+c;
	}
	else if(c==(a+1) and c==(b-1)){
		total=a+b+c;
	}
	else if(a==(b+1) and a==(c-1)){
		total=a+b+c;
	}
	else if(a==(c+1) and a==(b-1)){
		total=a+b+c;
	}
	else if(c==(b+1) and c==(a-1)){
		total=a+b+c;
	}
	else if(b==(c+1) and b==(a-1)){
		total=a+b+c;
	}
	else if(a==b){
		total=a+b;
	}
	else if(a==c){
		total=a+c;
	}
	else if(c==b){
		total=c+b;
	}

	return total;
	
}

int puntajeIA(int a, int b, int c){
	int total=0;
	if(a==b and b==c){
		total=total+50;
	}
	else if(b==(a+1) and b==(c-1)){
		total=a+b+c;
	}
	else if(c==(a+1) and c==(b-1)){
		total=a+b+c;
	}
	else if(a==(b+1) and a==(c-1)){
		total=a+b+c;
	}
	else if(a==(c+1) and a==(b-1)){
		total=a+b+c;
	}
	else if(c==(b+1) and c==(a-1)){
		total=a+b+c;
	}
	else if(b==(c+1) and b==(a-1)){
		total=a+b+c;
	}
	else if(a==b){
		total=a+b;
	}
	else if(a==c){
		total=a+c;
	}
	else if(c==b){
		total=c+b;
	}
	return total;
}

void instruccionesGenerala(){
	cout<<"               Puntajes"<<endl<<endl;
	cout<<"-Generala(cuando los tres dados tienen el mismo valor)=50 puntos."<<endl;
	cout<<"-Escalera: cuando el valor de los dados sea 1-2-3 , 2-3-4 , 3-4-5 o 4-5-6."<<endl;
	cout<<"-En caso de que dos dados tengan el mismo valor, estos se sumaran."<<endl;
	cout<<endl<<"¡Buena Suerte!"<<endl<<endl;
}
int repetirGenerala(){
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
int IniciarGenerala () {
	srand(time(NULL));
	int a,b,c,d,e,f,puntajeUsu,puntajePC,TotalUsu,TotalPC,empezar,DadoInicioPC,DadoInicioU,puntajeRetorno;
	bool Inicio=false;
	
	DadoInicioPC= dado1();
	DadoInicioU= dado1();
	
	system("cls");
	
	while(Inicio==false){
		
		cout<<"Pulse 1 para lanzar dados y determinar el orden de juego"<<endl;
		cin>>empezar;
		
		if(empezar==1){
			if(DadoInicioPC>DadoInicioU){
				cout<<"Dado PC: "<<DadoInicioPC<<"	Dado Usuario: "<<DadoInicioU<<endl;
				cout<<"Comienza la PC"<<endl<<endl;
				Inicio= true;
			}
			else{
				cout<<"Dado PC: "<<DadoInicioPC<<"	Dado Usuario: "<<DadoInicioU<<endl;
				cout<<"Comienza el Usuario"<<endl<<endl;
				Inicio=true;
			}}
		else{
			cout<<"El valor ingresado no es correcto"<<endl;
		}}
		
		TotalUsu=0;
		TotalPC=0;
		
		for(int i=1 ; i<=10 ; i++){
			
			cout<<"Pulse 1 para lanzar los dados"<<endl;
			cin>>empezar;	
			
			system("cls");	
			if (empezar == 1){
				
				a=dado1();            	//a,b,c son los dados del usuario
				b=dado1();
				c=dado1();
				
				d=dado1();				//d,e,f son los dados de la PC
				e=dado1();
				f=dado1();
				
				puntajeUsu=puntajeusuario(a,b,c);
				puntajePC=puntajeIA(d,e,f);
				
				cout<<"Ronda "<<i<<endl<<endl;
				cout<<"Dados Usuario:"<<a<<"-"<<b<<"-"<<c<<endl;
				cout<<"Dados PC:"<<d<<"-"<<e<<"-"<<f<<endl;
				cout<<"Puntaje Usuario: "<<puntajeUsu<<endl;
				cout<<"Puntaje PC: "<<puntajePC<<endl;
				
				TotalUsu=TotalUsu+puntajeUsu;
				TotalPC=TotalPC+puntajePC;
				
			}
			else{
				cout<<"el valor ingresado no es correcto"<<endl<<endl;
				i=i-1;
			}}
		cout<<endl;
		system("pause");
		system("cls");
		
		cout<<"Puntaje Total Usuario: "<<TotalUsu<<endl;
		cout<<"Puntaje Total PC: "<<TotalPC<<endl<<endl;
		
		if(TotalPC==TotalUsu){
			cout<<"¡Empate!"<<endl;
		}
		else { if(TotalPC>TotalUsu){
			cout<<"¡La PC ha ganado!"<<endl;
		}
		else{
			cout<<"¡El usuario ha ganado!"<<endl;
		}}
		
	cout<<endl<<"¡Gracias por jugar!"<<endl<<endl;
	system("pause");
	
	if(TotalUsu>TotalPC){
		puntajeRetorno=TotalUsu;
	}
	else{
		puntajeRetorno=TotalPC+1000;
	}
	
	return puntajeRetorno;
}
