#include <iostream>
#include "jora.h"
#include <string>

using namespace std;

int main(){
	CifradoPorCajas a(3,6);
	string name = "joseManuelCornejoLupaGabrielEmilioCornejoLupaN";
	/*string name = "lcojglimoanejrooaaiiejphauenslpboeleuemnameurcornlr";
					lCojGlimoanejroGoaiiEjpHauensaLpoeleuemnaMeburCornLr
	string b = a.cifrarM(name);
	cout << b << endl;
	cout << "ya lo cifre" << endl;
	cout << a.descifrarM(b) << endl;
	cout << "ya lo descifre" << endl;*/
	cout << a.cifrarM(name)<< endl;
	return 0;
}
