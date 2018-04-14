#include <iostream>
#include "jora.h"
#include <string>

using namespace std;

int main(){
	CifradoPorCajas a(4,4);
	//string name = "joseManuelCornejoLupaGabrielEmilioCornejoLupaHerman";
	string name = "lcojglimoanejrooaaiiejphauenslpboeleuemnameurcornlr";
	string b = a.descifrarM(name);
	cout << b << endl;
	cout << "ya lo descifre" << endl;
//	cout << a.descifradoTres(b) << endl;
//	cout << "ya lo descifre" << endl;
	return 0;
}
