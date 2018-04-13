#include <iostream>
#include <string>
#include "grilla.h"

using namespace std;

int main(){
	cout << "cifrado-grilla" << endl;
	Clave primera(3);
	string sms = primera.cifrar("jose cornejo");
	cout << endl;
	cout << primera.descifrar(sms) << endl;
	return 0;
}
