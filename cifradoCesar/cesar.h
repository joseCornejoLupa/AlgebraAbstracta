#include <string>

using namespace std;

class Cesar{
	int desplazamiento;
public:
	Cesar(int=0);
	string cifrar(string);
	string descifrar(string);
};
