#include <string>
#include "cesar.h"
#include <iostream>

using namespace std;

Cesar::Cesar(int desplazamiento){
	this -> desplazamiento = desplazamiento;
}

string Cesar::cifrar(string mensaje){
	string cifrado;
	for(int i = 0; i < mensaje.size(); i++){
		cifrado[i] = mensaje[i] + desplazamiento;
		cout << "original: " << mensaje[i];
		cout << " cambiado: " << cifrado[i] << endl;
	}
	char aux[mensaje.size()] = mensaje.toCharArray();
	cout << "final: " << cifrado;
	return cifrado;
}

