#include<iostream>
#include "Frical.h"
#include "Generala Avanzada.h"
#include "Generala.h"
#include "PaRes.h"
#include "PiPaTi.h"
#include "ahorcado.h"
#include "batallanaval.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

void MenuJuegos();
void MenuFrical();
void MenuGeneralaAvanzada();
void MenuGenerala();
void MenuPares();
void MenuPipati();
void MenuBatallaNaval();
void MenuAhorcado();
void MenuEstadisticas();
void GuardarPuntaje(int id,int usuario,int puntaje);
void Inicio();

struct Partidas{
	int tipo_jugador;
	int id_juego;
	int puntaje=-1;
}PartJugadas[1000];


int main (int argc, char *argv[]) {
	
	int MenuPrincipal,IniciarParar=0;
	bool Detener=false;
	char salir;
	
	SetConsoleTitle("GameMaster");
	ifstream datos;
	
	
	datos.open("Partidas.dat",ios::binary);
	if(datos.fail()){
		ofstream aux;
		cout<<"No se ha encontrado el archivo con las estadisticas, creando.."<<endl<<endl;
		aux.open("Partidas.dat",ios::binary);
		aux.close();
		datos.open("Partidas.dat",ios::binary);
		system("pause");
	}
	
	datos.read((char *)(&(PartJugadas[0])), sizeof(PartJugadas));
	datos.close();
	
	clock_t tiempoinicio=clock();
	
	Inicio();
	
	while(Detener==false){
	system("cls");
	cout<<"Menu Principal"<<endl<<endl;
	cout<<"1-Juegos"<<endl<<"2-Estadisticas"<<endl<<"3-Iniciar/Parar Musica"<<endl<<endl<<"9-Salir"<<endl<<endl;
	cout << "Ingrese un numero: ";
	
	cin>>MenuPrincipal;
	system("cls");
		
		switch (MenuPrincipal){
		case 1:
			MenuJuegos();
			break;
		case 2:
			MenuEstadisticas();
			break;
		case 3:
			if(IniciarParar==0){
				
				PlaySound ("Bit Rush.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
				IniciarParar=1;
			}	
			else{
				
				PlaySound(NULL, 0, 0);
				IniciarParar=0;
				
			}
			break;
		case 9:
			cout<<"Desea salir de la aplicacion?"<<endl<<endl;
			cout<<"Pulse 'y' para salir, otra tecla si desea continuar"<<endl;
			cout<<"Ingrese una letra: ";
			cin>>salir;
			system("cls");
			if(salir=='y' or salir=='Y'){
				cout<<"Gracias por Jugar"<<endl<<endl;
				clock_t tiempofinal=clock();
				double tiempo=(tiempofinal-tiempoinicio)/CLOCKS_PER_SEC;
				if(tiempo<60){
				cout<<"Duracion de la sesion: "<<tiempo<<" segundos"<<endl<<endl;
				}
				else{
					cout<<fixed<<setprecision(2)<<"Duracion de la sesion: "<<(tiempo/60)<<" minutos"<<endl<<endl;
				}
				system("pause");
				exit(0);
			}
		}
	}
	
	
	
	
	return 0;
}


void MenuJuegos(){
	int juego;
	bool volver=false;
	
	while(volver==false){
	system("cls");
	cout<<"   Menu de Juegos "<<endl;
	cout<<"======================="<<endl<<endl;
	cout<<"Juegos Numericos:"<<endl<<"1-Frical"<<endl<<"2-PiPaTi"<<endl;
	cout<<"3-Generala Basica"<<endl<<"4-Generala Avanzada"<<endl<<endl;
	cout<<"Juegos de Letras:"<<endl<<"5-Ahorcado"<<endl<<endl<<"Juegos con Tablas";
	cout<<endl<<endl<<"6-ParEs"<<endl<<"7-Batalla Naval"<<endl<<endl;
	cout<<"9-Volver al menu anterior"<<endl<<endl;
	cout << "Ingrese un numero: ";
	
	cin>>juego;
	system("cls");
	
	switch (juego) {
	case 1: 
		MenuFrical();
		break;
	case 2:
		MenuPipati();
		break;
	case 3:
		MenuGenerala();
		break;
	case 4:
		MenuGeneralaAvanzada();
		break;
	case 5:
		MenuAhorcado();
		break;
	case 6:
		MenuPares();
		break;
	case 7:
		MenuBatallaNaval();
		break;
	case 9:
		return;
	default: 
		cout<<"el numero ingresado no es correcto"<<endl<<endl;
		system("pause");
	
	};
	}
}

void MenuFrical(){
	int opcion,puntaje,id=1,usuario=1;
	bool volver=false;
	while(volver==false){
	system("cls");
	cout<<"Juego Frical - Categoria Numeros"<<endl;
	cout<<"================================"<<endl<<endl;
	cout<< "                      BIENVENIDO A FRICAL" << endl; 
	cout<< "¿Podras adivinar el numero?, el mismo esta comprendido entre 1 y 100. ¡Buena suerte!" << endl <<endl;
	cout<<"1-Ver Instrucciones"<<endl<<"2-Jugar"<<endl<<endl<<"9-Volver al menu anterior"<<endl<<endl;
	cout << "Ingrese un numero: ";
	
	cin>>opcion;
	switch (opcion){
	case 1:
		system("cls");
		InstruccionesFrical();
		cout<<endl;
		system("pause");
		break;
	case 2:
		puntaje=IniciarFrical();
		if(puntaje!=0){
			GuardarPuntaje(id,usuario,puntaje);
		}
		volver=true;
		break;
	case 9:
		system("cls");
		return;
	default: 
		system("cls");
		cout<<"el numero ingresado no es correcto"<<endl<<endl;
		system("pause");
	}
	}
}
void MenuGeneralaAvanzada(){
	int opcion,puntaje,id=4,usuario;
	bool volver=false;
	while(volver==false){
		system("cls");
		cout<<"Juego Generala Avanzada - Categoria Numericos"<<endl;
		cout<<"================================"<<endl<<endl;
		cout << "                 BIENVENIDO A LA GENERALA AVANZADA" << endl<<endl; ; 
		cout << "El objetivo del juego es lograr el mayor puntaje en 10 tiradas." << endl ; 
		cout << "Cada tirada consiste en el lanzamiento de 5 dados. El usuario tendra" << endl ; 
		cout << "la posibilidad de lanzar 2 veces en una misma ronda." << endl <<endl; 
		cout << "1- Informacion sobre Puntajes" << endl; 
		cout << "2- Jugar" << endl <<endl; 
		cout << "9- Volver al menu anterior"<<endl<<endl;
		cout << "Ingrese un numero: ";
		cin>>opcion;
		switch (opcion){
		case 1:
			system("cls");
			InstruccionesGeneralaAvanzada();
			cout<<endl;
			system("pause");
			break;
		case 2:
			puntaje=IniciarGeneralaAvanzada();
			if(puntaje>=1000){
				usuario=0;
				puntaje=puntaje-1000;
			}
			else{
				usuario=1;
			}
			GuardarPuntaje(id,usuario,puntaje);
			volver=true;
			break;
		case 9:
			system("cls");
			return;
		default: 
			system("cls");
			cout<<"el numero ingresado no es correcto"<<endl<<endl;
			system("pause");
		}
	}
}
void MenuGenerala(){
	int opcion,puntaje,id=3,usuario;
	bool volver=false;
	while(volver==false){
		system("cls");
		cout<<"Juego Generala Basica - Categoria Numericos"<<endl;
		cout<<"================================"<<endl<<endl;
		cout << "                 BIENVENIDO A LA GENERALA BASICA" << endl<<endl; ; 
		cout << "El juego consta en lanzar 3 dados por 10 rondas y obtener el"<<endl;
		cout << "mayor puntaje. ¡Buena Suerte!"<<endl<<endl;
		cout << "1- Informacion sobre Puntajes" << endl; 
		cout << "2- Jugar" << endl <<endl; 
		cout << "9- Volver al menu anterior"<<endl<<endl;
		cout << "Ingrese un numero: ";
		cin>>opcion;
		switch (opcion){
		case 1:
			system("cls");
			instruccionesGenerala();
			cout<<endl;
			system("pause");
			break;
		case 2:
			puntaje=IniciarGenerala();
			if(puntaje>=1000){
				usuario=0;
				puntaje=puntaje-1000;
			}
			else{
				usuario=1;
			}
			GuardarPuntaje(id,usuario,puntaje);
			volver=true;
			break;
		case 9:
			system("cls");
			return;
		default: 
			system("cls");
			cout<<"el numero ingresado no es correcto"<<endl<<endl;
			system("pause");
		}
	}
}
void MenuPares(){
	int opcion,puntaje,id=6,usuario=1;
	bool volver=false;
	while(volver==false){
		system("cls");
		cout<<"Juego ParEs - Categoria Tablas"<<endl;
		cout<<"================================"<<endl<<endl;
		cout<<"                                 BIENVENIDO A PARES"<<endl<<endl;
		cout<<"El juego consta de encotrar la pareja de letras(mayuscula y minuscula) en un tablero de 6x6."<<endl;
		cout<<endl<<"1-Ver Instrucciones"<<endl<<"2-Jugar"<<endl<<endl<<"9-Volver al menu anterior"<<endl<<endl;
		cout << "Ingrese un numero: ";
		
		cin>>opcion;
		switch (opcion){
		case 1:
			system("cls");
			instruccionesPares();
			cout<<endl;
			system("pause");
			break;
		case 2:
			puntaje=IniciarPares();
			if(puntaje!=0){
				GuardarPuntaje(id,usuario,puntaje);
			}
			volver=true;
			break;
		case 9:
			system("cls");
			return;
		default: 
			system("cls");
			cout<<"el numero ingresado no es correcto"<<endl<<endl;
			system("pause");
		}
	}
}
void MenuPipati(){
	int opcion,puntaje,id=2,usuario=1;
	bool volver=false;
	while(volver==false){
		system("cls");
		cout<<"Juego PiPaTi - Categoria Numericos"<<endl;
		cout<<"================================"<<endl<<endl;
		cout<<"                                 BINVENIDO A PIAPTI"<<endl<<endl;
		cout<<"El juego consta de 5 rondas, su puntaje se mostrara al final de la partida"<<endl<<endl;
		cout<<endl<<"1-Ver Instrucciones"<<endl<<"2-Jugar"<<endl<<endl<<"9-Volver al menu anterior"<<endl<<endl;
		cout << "Ingrese un numero: ";
		
		cin>>opcion;
		switch (opcion){
		case 1:
			system("cls");
			instruccionesPiPaTi();
			cout<<endl;
			system("pause");
			break;
		case 2:
			puntaje=IniciarPipati();
			if(puntaje!=0){
				GuardarPuntaje(id,usuario,puntaje);
			}
			volver=true;
			break;
		case 9:
			system("cls");
			return;
		default: 
			system("cls");
			cout<<"el numero ingresado no es correcto"<<endl<<endl;
			system("pause");
		}
	}
}
void MenuBatallaNaval(){
	int opcion,puntaje,id=7,usuario=1;
	bool volver=false;
	while(volver==false){
		system("cls");
		cout<<"Juego Batalla Naval - Categoria Tablas"<<endl;
		cout<<"======================================"<<endl<<endl;
		cout<<"                                 BINVENIDO A BATALLA NAVAL"<<endl<<endl;
		cout<<"El objetivo del juego es hundir los 7 barcos que se encuentran distribuidos en el tablero"<<endl<<endl;
		cout<<endl<<"1-Ver Instrucciones"<<endl<<"2-Jugar"<<endl<<endl<<"9-Volver al menu anterior"<<endl<<endl;
		cout << "Ingrese un numero: ";
		
		cin>>opcion;
		switch (opcion){
		case 1:
			system("cls");
			instruccionesBatalla();
			cout<<endl;
			system("pause");
			break;
		case 2:
			puntaje=batallanaval();
			if(puntaje!=0){
				GuardarPuntaje(id,usuario,puntaje);
			}
			volver=true;
			break;
		case 9:
			system("cls");
			return;
		default: 
			system("cls");
			cout<<"el numero ingresado no es correcto"<<endl<<endl;
			system("pause");
		}
	}
}
void MenuAhorcado(){
	int opcion,puntaje,id=5,usuario=1;
	bool volver=false;
	while(volver==false){
		system("cls");
		cout<<"Juego Ahorcado - Categoria Letras"<<endl;
		cout<<"================================="<<endl<<endl;
		cout<<"                                 BINVENIDO A AHORCADO"<<endl<<endl;
		cout<<"El objetivo del juego es descubrir la palabra oculta. ¡Buena suerte!"<<endl<<endl;
		cout<<endl<<"1-Ver Instrucciones"<<endl<<"2-Jugar"<<endl<<endl<<"9-Volver al menu anterior"<<endl<<endl;
		cout << "Ingrese un numero: ";
		
		cin>>opcion;
		switch (opcion){
		case 1:
			system("cls");
			instruccionesAhorcado();
			cout<<endl;
			system("pause");
			break;
		case 2:
			puntaje=ahorcado();
			if(puntaje!=0){
				GuardarPuntaje(id,usuario,puntaje);
			}
			volver=true;
			break;
		case 9:
			system("cls");
			return;
		default: 
			system("cls");
			cout<<"el numero ingresado no es correcto"<<endl<<endl;
			system("pause");
		}
	}
}
void MenuEstadisticas(){
	int seleccion;
	bool volver=false;
	while(volver==false){
	system("cls");
	cout<<" Menu de Estadisticas"<<endl;
	cout<<" ===================="<<endl<<endl;
	cout<<" Seleccione el juego sobre el cual desea informacion."<<endl<<endl;
	cout<<"Juegos Numericos:"<<endl<<"1-Frical"<<endl<<"2-PiPaTi"<<endl;
	cout<<"3-Generala Basica"<<endl<<"4-Generala Avanzada"<<endl<<endl;
	cout<<"Juegos de Letras:"<<endl<<"5-Ahorcado"<<endl<<endl<<"Juegos con Tablas";
	cout<<endl<<endl<<"6-ParEs"<<endl<<"7-Batalla Naval"<<endl<<endl;
	cout<<"9-Volver al menu anterior"<<endl<<endl;
	cout << "Ingrese un numero: ";
	
	cin>>seleccion;
	switch (seleccion) {
	case 1:{
		system("cls");
		int posicion=0,cant=0;
		double prom=0;
		
		while(PartJugadas[posicion].puntaje!=-1){
			if(PartJugadas[posicion].id_juego==1){
				prom=prom+PartJugadas[posicion].puntaje;
				cant++;
			}
			posicion++;
		}
		if(cant!=0){
			cout<<"Cantidad de partidad ganadas: "<<cant<<" Partidas"<<endl;
			cout<<fixed<<setprecision(2)<<"Promedio de puntaje obtenido: "<<(prom/cant)<<" Pts"<<endl<<endl;
		}
		else{
			cout<<endl<<"Aun no ha ganado partidas"<<endl<<endl;
		}
		system("pause");
		break;
	}
	case 2:{
		system("cls");
		int posicion=0,cant=0;
		double prom=0;
		
		while(PartJugadas[posicion].puntaje!=-1){
		if(PartJugadas[posicion].id_juego==2){
		prom=prom+PartJugadas[posicion].puntaje;
		cant++;
		}
		posicion++;
		}
		if(cant!=0){
		cout<<"Cantidad de partidad ganadas: "<<cant<<" Partidas"<<endl;
		cout<<fixed<<setprecision(2)<<"Promedio de puntaje obtenido: "<<(prom/cant)<<" Pts"<<endl<<endl;
		}
		else{
		cout<<endl<<"Aun no ha ganado partidas"<<endl<<endl;
		}
		system("pause");
		break;
	}
	case 3:{
		int posicion=0,cantPC=0,cantUSU=0,cantTotal=0,promCPU=0,promUSU=0;
	
		system("cls");
		while(PartJugadas[posicion].puntaje!=-1){
			if(PartJugadas[posicion].id_juego==3){
				cantTotal++;
				
				if(PartJugadas[posicion].tipo_jugador==0){
					promCPU=promCPU+PartJugadas[posicion].puntaje;
					cantPC++;
				}
				if(PartJugadas[posicion].tipo_jugador==1){
					promUSU=promUSU+PartJugadas[posicion].puntaje;
					cantUSU++;
				}
			}
		posicion++;
		}
		if(cantPC!=0){
		cout<<endl<<fixed<<setprecision(2)<<"Porcentaje de partidas ganadas por la CPU: "<<((cantPC*100)/cantTotal)<<"%"<<endl;
		cout<<fixed<<setprecision(2)<<"Promedio de puntaje obtenido por la CPU: "<<(promCPU/cantPC)<<" Pts"<<endl<<endl;
		}
		else{
			cout<<endl<<"La PC na ha ganado todavia."<<endl<<endl;
		}
		if(cantUSU!=0){
		cout<<fixed<<setprecision(2)<<"Promedio de puntaje obtenido por EL Usuario: "<<(promUSU/cantUSU)<<" Pts"<<endl<<endl;
		}
		else{
			cout<<"El usuario no ha ganado todavia."<<endl<<endl;
		}
		system("pause");
		break;
	}
	case 4:{
			int posicion=0,cantPC=0,cantUSU=0;
			double promCPU=0,promUSU=0;
			
			system("cls");
			while(PartJugadas[posicion].puntaje!=-1){
				if(PartJugadas[posicion].id_juego==4){
					if(PartJugadas[posicion].tipo_jugador==0){
						promCPU=promCPU+PartJugadas[posicion].puntaje;
						cantPC++;
					}
					if(PartJugadas[posicion].tipo_jugador==1){
						promUSU=promUSU+PartJugadas[posicion].puntaje;
						cantUSU++;
					}
				}
				posicion++;
			}
			if(cantPC!=0){
				cout<<endl<<"La CPU gano: "<<cantPC<<" Partidas"<<endl;
				cout<<fixed<<setprecision(2)<<"Promedio de puntaje obtenido por la CPU: "<<(promCPU/cantPC)<<" Pts"<<endl<<endl;
			}
			else{
				cout<<endl<<"La PC na ha ganado todavia."<<endl<<endl;
			}
			if(cantUSU!=0){
				cout<<endl<<"El usuario gano: "<<cantUSU<<" Partidas"<<endl;
				cout<<fixed<<setprecision(2)<<"Promedio de puntaje obtenido por EL Usuario: "<<(promUSU/cantUSU)<<" Pts"<<endl<<endl;
			}
			else{
				cout<<"El usuario no ha ganado todavia."<<endl<<endl;
			}
			system("pause");
		break;
		}
	case 5:{
				system("cls");
				int posicion=0,cant=0,Peorpunt1=1000,Peorpunt2=1000,Peorpunt3=1000,aux,aux2,menor,posicionvector=0;
				int MejoresPuntajes[10]={0,0,0,0,0,0,0,0,0,0};
				double prom=0;
				
				while(PartJugadas[posicion].puntaje!=-1){
					if(PartJugadas[posicion].id_juego==5){
						prom=prom+PartJugadas[posicion].puntaje;
						if(PartJugadas[posicion].puntaje<Peorpunt3){
						Peorpunt3=PartJugadas[posicion].puntaje;
						}
						if(Peorpunt3<Peorpunt2){
								aux=Peorpunt2;
								Peorpunt2=Peorpunt3;
								Peorpunt3=aux;
						}
						if(Peorpunt2<Peorpunt1){
						aux2=Peorpunt1;  
						Peorpunt1=Peorpunt2;
						Peorpunt2=aux2;
						}
						menor=MejoresPuntajes[0];
						posicionvector=0;
						for(int i=0;i<10;i++){
						  if(menor>MejoresPuntajes[i]){
							menor=MejoresPuntajes[i];
							posicionvector=i;
						  }
						}
						if(PartJugadas[posicion].puntaje>menor){
							MejoresPuntajes[posicionvector]=PartJugadas[posicion].puntaje;
						}
						
						cant++;
					}
					posicion++;
				}
				//ordenamiento vector
				for(int pasada=1;pasada<10;pasada++){
					for(int k=0;k<9;k++){
						if(MejoresPuntajes[k]<MejoresPuntajes[k+1]){
							int aux=MejoresPuntajes[k];
							MejoresPuntajes[k]=MejoresPuntajes[k+1];
							MejoresPuntajes[k+1]=aux;
						}
					}
				}
				if(cant!=0){
					cout<<fixed<<setprecision(2)<<"Promedio de puntaje obtenido: "<<(prom/cant)<<" Pts"<<endl<<endl;
					if(Peorpunt1==1000 or Peorpunt2==1000 or Peorpunt3==1000){
						cout<<"Aun no ha ganado las suficientes vececes para mostrar los 3 peores puntajes"<<endl<<endl;
					}
					else{
						cout<<"Los 3 peores puntajes son:"<<endl<<"1."<<Peorpunt1<<" Pts"<<endl<<"2."<<Peorpunt2<<" Pts"<<endl<<"3."<<Peorpunt3<<" Pts"<<endl<<endl;
					}
					cout<<endl<<"Los mejores puntajes(hasta 10) son: "<<endl;
					
					for (int i=0;i<10;i++){
						if(MejoresPuntajes[i]!=0){
							if(i<9){
							cout<<i+1<<". "<<MejoresPuntajes[i]<<"  pts"<<endl;
							}
							else{
							cout<<i+1<<"."<<MejoresPuntajes[i]<<"  pts"<<endl;
							}
						}
						else{
							i=10;
						}
					}
				}
				else{
					cout<<endl<<"Aun no ha ganado partidas"<<endl<<endl;
				}
				cout<<endl;
				system("pause");
		break;
		}
	case 6:{
		system("cls");
		int posicion=0,cant=0,part025=0,part2650=0,part5175=0,part76100=0,cantidad50=0;
		double prom=0;
					
		while(PartJugadas[posicion].puntaje!=-1){
			if(PartJugadas[posicion].id_juego==6){
				prom=prom+PartJugadas[posicion].puntaje;
				cant++;
				if(PartJugadas[posicion].puntaje<26){
					part025++;
					cantidad50++;
				}
				else if(PartJugadas[posicion].puntaje>25 and PartJugadas[posicion].puntaje<51){
					part2650++;
					cantidad50++;
				}
				else if(PartJugadas[posicion].puntaje>50 and PartJugadas[posicion].puntaje<76){
					part5175++;
				}
				else{
					part76100++;
				}
			}
			posicion++;
		}
		if(cant!=0){
			cout<<fixed<<setprecision(2)<<"Promedio de puntaje obtenido: "<<(prom/cant)<<" Pts"<<endl<<endl;
			cout<<"Rango de partidas ganadas; "<<endl<<"[0-25]-"<<part025<<" Partida/s"<<endl;
			cout<<"[26-50]-"<<part2650<<" Partida/s"<<endl;
			cout<<"[51-75]-"<<part5175<<" Partida/s"<<endl;
			cout<<"[76-100]-"<<part76100<<" Partida/s"<<endl;
			cout<<"Cantidad de partidas ganadas con puntaje menor a 50: "<<cantidad50++<<endl;
		}
		else{
			cout<<endl<<"Aun no ha ganado partidas"<<endl<<endl;
		}
		system("pause");
		break;
				}
	case 7:{
			system("cls");
			int posicion=0,cant=0;
			double prom=0;
			
			while(PartJugadas[posicion].puntaje!=-1){
				if(PartJugadas[posicion].id_juego==7){
					prom=prom+PartJugadas[posicion].puntaje;
					cant++;
				}
				posicion++;
			}
			if(cant!=0){
				cout<<"Cantidad de partidad ganadas: "<<cant<<" Partidas"<<endl;
				cout<<fixed<<setprecision(2)<<"Promedio de puntaje obtenido: "<<(prom/cant)<<" Pts"<<endl<<endl;
			}
			else{
				cout<<endl<<"Aun no ha ganado partidas"<<endl<<endl;
			}
			system("pause");
			break;
		}
	case 9:
		return;
	default: 
		cout<<"el numero ingresado no es correcto"<<endl<<endl;
		system("pause");
}
}
}

void GuardarPuntaje(int id,int usuario,int puntaje){
	int posicion=0;
	
	while(PartJugadas[posicion].puntaje!=-1){
		posicion++;
	}
	if(posicion<1000){
		PartJugadas[posicion].tipo_jugador=usuario;
		PartJugadas[posicion].id_juego=id;
		PartJugadas[posicion].puntaje=puntaje;
	
	
		ofstream datos;
		datos.open("Partidas.dat",ios::binary);
		datos.write((char*)(&(PartJugadas[0])),sizeof(PartJugadas));
		datos.close();
	}
	else{
		system("cls");
		cout<<"Se alcanzo el limite maximo de partidas guardadas."<<endl;
		cout<<"No se guardara la partida."<<endl<<endl;
		system("pause");
	}
	
}
void Inicio(){
{	
	PlaySound ("Efecto de sonido Bomba.wav", NULL, SND_ASYNC|SND_FILENAME);
	
	Sleep(0160);Sleep(0160);Sleep(0160);Sleep(0160);
	cout<<"   B"; Sleep(0160); cout<<"i"; Sleep(0160); cout<<"e"; Sleep(0160); cout<<"n"; Sleep(0160); cout<<"v"; Sleep(0160);
	cout<<"e"; Sleep(0160); cout<<"n"; Sleep(0160); cout<<"i"; Sleep(0160); cout<<"d"; Sleep(0160); cout<<"o"; Sleep(0160);
	cout<<" "; Sleep(0160); cout<<"a"<<endl<<endl;; Sleep(0160);Sleep(0160);Sleep(0160);Sleep(0160);
	
	cout<<"		          _______  _______  __   __  _______          "<<endl;
	cout<<"		         |       ||   _   ||  |_|  ||       |         "<<endl;	
	cout<<"		         |    ___||  |_|  ||       ||    ___|         "<<endl;
	cout<<"		         |   | __ |       ||       ||   |___          "<<endl;
	cout<<"	                 |   ||  ||       ||       ||    ___|         "<<endl;
	cout<<"		         |   |_| ||   _   || ||_|| ||   |___          "<<endl;
	cout<<"	                 |_______||__| |__||_|   |_||_______|         "<<endl;
	cout<<"		 __   __  _______  _______  _______  _______  ______   "<<endl;
	cout<<"		|  |_|  ||   _   ||       ||       ||       ||    _ |  "<<endl;
	cout<<"		|       ||  |_|  ||  _____||_     _||    ___||   | ||  "<<endl;
	cout<<"		|       ||       || |_____   |   |  |   |___ |   |_||_ "<<endl;
	cout<<"		|       ||       ||_____  |  |   |  |    ___||    __  |"<<endl;
	cout<<"		| ||_|| ||   _   | _____| |  |   |  |   |___ |   |  | |"<<endl;
	cout<<"		|_|   |_||__| |__||_______|  |___|  |_______||___|  |_|"<<endl<<endl<<endl<<endl;

}

Sleep(2000);
system("cls");

{
	cout<<"                     ALGORITMOS Y ESTRUCTURAS DE DATOS                           "<<endl;
	cout<<"                       Trabajo Practico Integrador                               "<<endl;
	cout<<"                                Etapa 3                                          "<<endl;
	cout<<"                               10/2/2019                                         "<<endl;
	cout<<"                                                                                 "<<endl;
	cout<<"                                                                                 "<<endl;
	cout<<"             En esta ultima etapa del trabajo se desarrollara una                "<<endl;
	cout<<"             aplicacion que permite acceder a los diferentes juegos              "<<endl;
	cout<<"             agrupados en categorias.Los mismos se integran en un                "<<endl;
	cout<<"             unico proyecto haciendo uso de librerias, una por juego,            "<<endl;
	cout<<"             donde cada una tendra su archivo de cabecera y su archivo           "<<endl;
	cout<<"             de implementacion.                                                  "<<endl;
	cout<<"                                                                                 "<<endl;
	cout<<"                                                                                 "<<endl;
	cout<<"                                                                                 "<<endl;
	cout<<" Profesores: Blas Maria Julia, Lozano Diego                                      "<<endl;
	cout<<" Alumnos: Briani Nicolas, Caprin Juan, Velazquez Juan                            "<<endl;
	cout<<"                                                                                 "<<endl;
	cout<<"                                                                                 "<<endl;
	cout<<"                                                                                 "<<endl;
	cout<<"                                                                                 "<<endl;
}
			
	system("pause");
	
		
}
