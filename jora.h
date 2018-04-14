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
/*
string CifradoPorCajas::superCifrado(string cifrado){
	string cypher;
  	int inicio = (claveTamanio-1)/2;
	string tmp1 = cifrado.substr(0,claveTamanio*claveTamanio);
	cout<<tmp1<<"\n";
	int x = claveTamanio*2+(claveTamanio-2)-inicio;
	string tmp2 = cifrado.substr(claveTamanio*claveTamanio,x);
	cout<<tmp2<<"\n";
	string tmp3 = cifrado.substr(x+(claveTamanio*claveTamanio),claveTamanio*claveTamanio);
	cout<<tmp3<<"\n";
	string tmp4 = cifrado.substr(2*(claveTamanio*claveTamanio)+x,claveTamanio*2+(claveTamanio-2));
	cout<<tmp4<<"\n";
	int cont = 0;
	for(int i = 0 ; i < claveTamanio ; i++){
    	cypher += tmp1.substr(claveTamanio*i,claveTamanio);
		cout << "añadi: " << tmp1.substr(claveTamanio*i,claveTamanio) << endl;
    	//-----------------------------------//
		if(i == 0){
		  cypher += tmp2[cont];
			cout << "añadi: " << tmp2[cont] << endl;
		  cont++;
		}
		else if(i <inicio){
			cout << "añadi: " << tmp2.substr(cont,2) << endl;
		  cypher +=tmp2.substr(cont,2);
		  cont = cont +2;
		}
		else if (i >= inicio){
			cout << "añadi: " << tmp2.substr(cont,3) << endl;
		  cypher +=tmp2.substr(cont,3);
		  cont = cont +3;
		}
		else{
			cout << "añadi: " << tmp2.substr(cont,2) << endl;
		  cypher +=tmp2.substr(cont,2);
		  cont = cont +2;
		}
		//-----------------------------------//
		cypher += tmp3.substr(claveTamanio*i,claveTamanio);
		cout << "añadi: " << tmp3.substr(claveTamanio*i,claveTamanio) << endl;
		//-----------------------------------//
		if(i==0){
		  cypher += tmp4.substr(0,2);
			cout << "añadi: " << tmp4.substr(0,2) << endl;
		}
		else if(i == claveTamanio -1){
		  cypher += tmp4.substr(tmp4.size()-2,tmp4.size());
			cout << "añadi: " << tmp4.substr(tmp4.size()-2,tmp4.size()) << endl;
		}
		else{
		  cypher += tmp4.substr(i*2 + (i -1) ,3);
			cout << "añadi: " << tmp4.substr(i*2 + (i -1) ,3) << endl;
		}
  } 
  return cypher;	
}*/
