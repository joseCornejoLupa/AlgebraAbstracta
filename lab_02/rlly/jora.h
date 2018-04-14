#include <string>

using namespace std;

class CifradoPorCajas{
private:
	int claveTamanio;
	int claveVeces;
	int comienzo;
	int plip;
public:
	CifradoPorCajas(int,int);
	//CIFRAR
	string cifrarM(string);
	
	int calcularLetras();
	string completarLetras(string,int);
	string cortarMensaje(int,string);

	string cifradoUno(string);
	string cifradoDos(string);
	string cifradoTres(string);
	string cifradoCuatro(string);

	string cifradoIndividual(int,string);	
	string superCifrado(string);

	//DESCIFRAR
	string descifrarM(string);

	string descifradoUno(string);
	string descifradoDos(string);
	string descifradoTres(string);
	string descifradoCuatro(string);

	string descifradoIndividual(int,string);	
	string superDescifrado(string);
};
