#include <string>

using namespace std;

class Clave{
private:
	string alfabeto;
	int clave;
public:
	Clave(int=0);
	string cifrar(string);
	string descifrar(string);
};
