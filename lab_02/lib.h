#include <string>

using namespace std;

class CifradoPorCajas{
private:
	int claveTamanio;
	int claveVeces;
public:
	CifradoPorCajas(int,int);
	string cifrar(string);
	string descifrar(string);
};
