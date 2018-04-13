#include "lib.h"
#include <string>
#include <iostream>

using namespace std;

CifradoPorCajas::CifradoPorCajas(int claveTamanio,int claveVeces){
	this -> claveTamanio = claveTamanio;
	this -> claveVeces = claveVeces;
}

string CifradoPorCajas::cifrar(string original){
	string cipher;
	int tamanio = original.size();
	int tope = 0;
	while(tope < tamanio){
		for(int i = 0; i < claveTamanio; i++){
			for(int j = 0; j < claveTamanio; j++){
				tope++;
				if(i == j){
					cipher += original[tope];
				}
				else if(i + j == claveTamanio && i >= j){
					cipher += original[tope];
				}
				else if(i + j == claveTamanio - 2 && i < j){
					cipher += original[tope];
				}
			}
		}
	}
	return cipher;
}

string CifradoPorCajas::descifrar(string cipher){

}
