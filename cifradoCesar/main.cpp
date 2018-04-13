#include <iostream>
#include <string>
#include "cesar.h"

using namespace std;

int main(){
	cout << "Haremos el cifrado de cesar" << endl;
	Cesar primero(3);
	string mensaje;
	mensaje = primero.cifrar("abc");
	cout << mensaje << endl;
	return 0;
}
