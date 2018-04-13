#include <iostream>
#include <string>
#include "grilla.h"

using namespace std;

Clave::Clave(int clave){
	alfabeto = "abcdefghijklmnopqrstuvwxyz ";
	this-> clave = clave;
}

string Clave::cifrar(string mensaje){
	string sms;
	for(int i = 0; i < mensaje.size(); i++){
		int index = alfabeto.find(mensaje[i]);
		int j = index - alfabeto.size() + 1;
		j = j * -1;
		sms += alfabeto[j];
	}
	int aux = clave;
//insertar espacios en blancos
	while(sms.size() > aux){
		aux += clave -1;
	}
	aux = aux - sms.size();
	sms.insert(sms.end(),aux,'x');
//cifrado ESCALERA
	int tam = sms.size();
	string cipher;
	int top = clave*2-2;
	cout << "top: " << top << endl;
	int bot = 0;
	cout << "mensaje a insertar: " << sms << endl;
	for(int a = 0; a < clave; a++){
		cipher +=  sms[a];
		cout << "añadi la(1)" << sms[a]<< endl;
		if(top == 0){
			top = bot;
		}
		for(int i = a + top; i <= tam-1; i =i+top){
			cipher += sms[i];
			cout << "añadi la(2)" << sms[i]<< endl;
			if(i != i + bot && i + bot < tam){
				cipher += sms[i+bot];
				cout << "añadi la(3)" << sms[i+bot]<< endl;
			}
			i = i + bot;
		}
		top = top - 2;
		bot = bot + 2;
	}
	return cipher;
}

string Clave::descifrar(string mensaje){
	//descifrado ESCALERA	
	int tam = mensaje.size();
	string cipher(' ',tam);
	int top = clave*2-2;
	//cout << "top: " << top << endl;
	int bot = 0;
	int cont = 0;
	cout << "mensaje a insertar: " << mensaje << endl;
	for(int a = 0; a < clave; a++){
		cipher[a] =  mensaje[cont];
		cont++;
		//cout << "añadi la(1)" << mensaje[a]<< endl;
		if(top == 0){
			top = bot;
		}
		for(int i = a + top; i <= tam-1; i =i+top){
			cipher[i] = mensaje[cont];
			cont++;
			//cout << "añadi la(2)" << mensaje[i]<< endl;
			if(i != i + bot && i + bot < tam){
				cipher[i+bot] = mensaje[cont];
				cont++;
				//cout << "añadi la(3)" << mensaje[i+bot]<< endl;
			}
			i = i + bot;
		}
		top = top - 2;
		bot = bot + 2;
	}
	string sms;
	int n = 1;
	while(n){
		n = cipher.find_last_of("x");
		sms = cipher.substr(0,n);
		n = 0;
	}
	string original;
	for(int i = 0; i < mensaje.size(); i++){
		int index = alfabeto.find(sms[i]);
		int j = index - alfabeto.size() + 1;
		j = j * -1;
		original += alfabeto[j];
	}
	return original;
}
