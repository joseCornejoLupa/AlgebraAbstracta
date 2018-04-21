#include <iostream>
#include "jora.h"
#include <string>

using namespace std;

int main(){
	/*CifradoPorCajas a(7,4);
	string name = "JoseManuelCornejoLupaGabrielEmilioCornejoLupaAlejandraCornejoLupaPasameLaTareaPorfaGuidoNoSeasMaloMeComprasUnHeladoConCincoSolesRaton";
	cout<<"size del mensaje original: "<<name.size()<<endl;
	/*string name = "lcojglimoanejrooaaiiejphauenslpboeleuemnameurcornlr";
					lCojGlimoanejroGoaiiEjpHauensaLpoeleuemnaMeburCornLr
	string b = a.cifrarM(name);
	cout << b << endl;
	cout << "ya lo cifre" << endl;
	cout << a.descifrarM(b) << endl;
	cout << "ya lo descifre" << endl;
	//cout << a.cifrarM(name)<< endl;
	string prro = a.cifrarM(name);
	cout << "este es el cifrado: "<< prro << endl;
	cout<< a.descifrarM(prro);*/
	CifradoPorCajas b(4,4);
	string name = "JoseManuelCornej";
	cout << b.cifradoTres(name);
	return 0;
}
