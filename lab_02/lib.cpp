#include "lib.h"
#include <string>
#include <iostream>

using namespace std;

CifradoPorCajas::CifradoPorCajas(int claveTamanio,int claveVeces){
	this -> claveTamanio = claveTamanio;
	this -> claveVeces = claveVeces;
}

string CifradoPorCajas::cifrar(string original){
	int tamanio = original.size();
	string primerCuadrado;
	
	int i = 0;
	int j = claveTamanio - 1;
	int cont = 0;

	for(int a  = 0; a < j;a++){
		primerCuadrado += original[j*3+a];
	}

	primerCuadrado += original[cont];

	
	
/*	while( i != j){
		primerCuadrado[i][j] = original[cont];
		j--;
		cont++;
	}*/
	for(int a = 0; a < primerCuadrado.size();a++){
		cout << "primer cuadrado: " << primerCuadrado[a] << endl;
	}
	
	string segundoCuadrado;

	int comienzo;
	int aux;
	if(claveTamanio % 2 == 0){
		aux = comienzo % claveTamanio;
	}
	else{
		aux = claveTamanio % comienzo;
	}
	segundoCuadrado += original[claveTamanio + aux];
	

	return primerCuadrado;
}

string CifradoPorCajas::descifrar(string cipher){

}
