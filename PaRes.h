#include <iostream>

using namespace std;

int repetirPares ();
void instruccionesPares();
void RellenarTablero(char Tablero[6][6]);
void MostrarTablero(char Tablero[6][6]);
void TableroFalso1(char TableroFalso[7][7],char Letras[],bool DESCUBIERTO[6][6],char Tablero[6][6]);
void controlar(char& , int &,bool DESCUBIERTO[6][6]);
void MostrarProgreso(bool DESCUBIERTO[6][6]);
int IniciarPares();
