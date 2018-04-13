#include <iostream>
#include <string>
#include "lib.h"

using namespace std;

int main(){
	cout << "Hello world!" << endl;
	string o = "abcdefghijklmnop";
	CifradoPorCajas primero(4,5);
	cout << primero.cifrar(o) << endl;
	return 0;
}
