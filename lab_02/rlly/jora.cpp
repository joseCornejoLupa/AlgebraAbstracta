#include "jora.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

CifradoPorCajas::CifradoPorCajas(int claveTamanio,int claveVeces){
	this -> claveTamanio = claveTamanio;
	this -> claveVeces = claveVeces;
	this -> comienzo = 0;
	this -> plip = 0;
}

//CIFRADO
string CifradoPorCajas::cifrarM(string original){
	int letrasMAX = calcularLetras();
	string completo = completarLetras(original,letrasMAX);
	//cout << "mi string completo" << completo << endl;
	int tamanio = original.size();
	string cipherCuasiFinal;
	for(int i = 1; i <= claveVeces; i++){
		cout << "repaso el patron: "<< i << "claveVeces: " << claveVeces <<endl;
		cipherCuasiFinal += cifradoIndividual(i,original);
		cout << "tengo avanzado hasta ahora: (" << cipherCuasiFinal << ")" << endl;
	}
//	cout << "final: (" << cipherCuasiFinal << ")" << endl;
	string cipherFinal("",tamanio);
	cipherFinal = superCifrado(cipherCuasiFinal); 
}

int CifradoPorCajas::calcularLetras(){
	int letrasMax;
	int cuenta = 1;
	while(cuenta <= claveVeces){
		if(cuenta == 1){
			letrasMax += claveTamanio * claveTamanio;
		}

		if(cuenta == 2){
			int inicio = (claveTamanio - 1) / 2;
			letrasMax += (claveTamanio*2) + (claveTamanio - 2) - inicio; 
		}

		if(cuenta == 3){
			letrasMax += claveTamanio * claveTamanio;
		}

		if(cuenta == 4){
			letrasMax += (claveTamanio*2) + (claveTamanio - 2);
		}
		cuenta++;
	}
	
	
	return letrasMax;
}

string CifradoPorCajas::completarLetras(string original, int letrasMax){
	int aux = letrasMax - original.size();
	original.insert(original.end(),aux,'x');
	return original;
}

string CifradoPorCajas::cortarMensaje(int index,string original){
	string corte;
    int fin = comienzo;
    int ini = (claveTamanio-1)/2;
    if(index == 1){fin += claveTamanio * claveTamanio;}
    else if(index == 2){
		int inicio = (claveTamanio - 1) / 2;
		fin += (claveTamanio*2) + (claveTamanio - 2) - inicio;
	}
    else if(index == 3){fin += claveTamanio * claveTamanio;}
    else {fin += (claveTamanio*3)-2;}
    for(int i = comienzo; i < fin; i++){
        corte += original[i];
    }
	/*cout << "la " << plip << " vez q corte obtuve esto: ";
	cout << corte << endl;
	cout << "ademas comienzo: " << comienzo << endl;
	plip++;*/
    return corte;
}

string CifradoPorCajas::cifradoUno(string original){
	cout << "me llego a mi(1): " << original << endl;
	string cipher("",original.size());
	int aux = claveTamanio -1;
	int	cont = 0;
	int iterator = claveTamanio -1;
	bool cambio = true;
	int tope = claveTamanio;
	while(iterator >= 0){
		//cout << "iterator: " << iterator << endl;
		if(cambio){
			//cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				if(tope ==  claveTamanio){
					cipher[aux] = original[cont];
					comienzo++;
					//cout << "añadi " << original[cont] << " en la pos " << aux << " cambio true "<< "primer for "<< endl;
					aux += claveTamanio;
					cont++;
				}
				else{
					aux += claveTamanio;
					cipher[aux] = original[cont];
					comienzo++;
					//cout << "añadi " << original[cont] << " en la pos " << aux << " cambio true "<< "primer for "<< endl;
					cont++;
				}
			}
			if(tope == claveTamanio){
				aux -= claveTamanio;
			}
//			cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				cipher[p-1-i] = original[cont];
				comienzo++;
//			cout << "añadi " << original[cont] << " en la pos " << p-1-i <<" cambio true "<< "segundo for "<< endl;
				cont++;
			}
			aux -= iterator;
			//cout << "aux: " << aux << endl;
			cambio = false;
			tope--;
		}

		else{
			//cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				aux -= claveTamanio;
				cipher[aux] = original[cont];
				comienzo++;
				//cout << "añadi " << original[cont] << " en la pos " << aux << " cambio false "<< "primer for "<< endl;
				cont++;				
			}
			//cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				cipher[p+1+i] = original[cont];
				comienzo++;
				//cout << "añadi " << original[cont] << " en la pos " << p+1+i << " cambio false "<< "segundo for "<< endl;
				cont++;
			}
			aux += iterator;
			cambio = true;
			tope--;
			//cout << "aux: " << aux << endl;
		}
		iterator--;
	}
	cout << "mensaje cifrado(1): " << cipher << endl;
	return cipher;
}

string CifradoPorCajas::cifradoDos(string original){
  cout << "me llego a mi(2): " << original << endl;
  string cifrado("",original.size());
  int inicio = (claveTamanio - 1) /2;
  int a = claveTamanio  + inicio;
  if (claveTamanio % 2 != 0){a = a-1;}
  int tope = a;
  int c = 0;
  for(int i = 0; i < claveTamanio; i++){
    if(i >= inicio){
      cifrado+= original[c];
		comienzo++;
      c++;    
    }
    if(i == 0){
      cifrado+= original[a];
		comienzo++;
    }else{
      if(i != claveTamanio -1){
        cifrado+= original[tope];
		comienzo++;
      }
      cifrado+= original[a];
		comienzo++;
    }
    a++;
    tope--;
  }
	cout << "mensaje cifrado(2): (" << cifrado <<")"<< endl;
return cifrado;
}

string CifradoPorCajas::cifradoTres(string original){
	cout << "me llego a mi(3): " << original << endl;
	string cipher("",original.size());
	reverse(original.begin(),original.end());
	int aux = claveTamanio -1;
	int	cont = 0;
	int iterator = claveTamanio -1;
	bool cambio = true;
	int tope = claveTamanio;
	while(iterator >= 0){
		//cout << "iterator: " << iterator << endl;
		if(cambio){
			//cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				if(tope ==  claveTamanio){
					cipher[aux] = original[cont];
					comienzo++;
					//cout << "añadi " << original[cont] << " en la pos " << aux << " cambio true "<< "primer for "<< endl;
					aux += claveTamanio;
					cont++;
				}
				else{
					aux += claveTamanio;
					cipher[aux] = original[cont];
					comienzo++;
					//cout << "añadi " << original[cont] << " en la pos " << aux << " cambio true "<< "primer for "<< endl;
					cont++;
				}
			}
			if(tope == claveTamanio){
				aux -= claveTamanio;
			}
			//cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				cipher[p-1-i] = original[cont];
				comienzo++;
				//cout << "añadi " << original[cont] << " en la pos " << p-1-i <<" cambio true "<< "segundo for "<< endl;
				cont++;
			}
			aux -= iterator;
			//cout << "aux: " << aux << endl;
			cambio = false;
			tope--;
		}

		else{
			//cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				aux -= claveTamanio;
				cipher[aux] = original[cont];
				comienzo++;
				//cout << "añadi " << original[cont] << " en la pos " << aux << " cambio false "<< "primer for "<< endl;
				cont++;
			}
			//cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				cipher[p+1+i] = original[cont];
				comienzo++;
				//cout << "añadi " << original[cont] << " en la pos " << p+1+i << " cambio false "<< "segundo for "<< endl;
				cont++;
			}
			aux += iterator;
			cambio = true;
			tope--;
			//cout << "aux: " << aux << endl;
		}
		iterator--;
	}
	if(claveTamanio%2==1){
        reverse(cipher.begin(),cipher.end());
	}
	cout << "mensaje cifrado(3): " << cipher << endl;
	return cipher;
}

string CifradoPorCajas::cifradoCuatro(string original){
	cout << "me llego a mi(4): " << original << endl;
	string cifrado("",original.size());
	int a = claveTamanio - 1;
	int b = a;
	int c = claveTamanio * 2 + (claveTamanio - 3);
	for(int i = 0; i < claveTamanio; i++){
		cifrado+= original[a];
		comienzo++;
		if(i != 0 && i != claveTamanio -1){
			cifrado+= original[b];
			comienzo++;
		}
		cifrado+= original[c];
		comienzo++;
		a--;
		b++;
		c--;
	}
	cout << "mensaje cifrado(4): " << cifrado << endl;
	return cifrado;
}

string CifradoPorCajas::cifradoIndividual(int index, string original){
	
	if(index == 1){
		string newOriginal = cortarMensaje(index,original);
		//cout << "tengo q cifrar con..." << index << "mi mensaje es: ";
		cout << newOriginal << endl;
		return cifradoUno(newOriginal);
	}

	if(index == 2){
		string newOriginal = cortarMensaje(index,original);
		//cout << "tengo q cifrar con..." << index << "mi mensaje es: ";
		cout << newOriginal << endl;
		return cifradoDos(newOriginal);
	}

	if(index == 3){
		string newOriginal = cortarMensaje(index,original);
		//cout << "tengo q cifrar con..." << index << "mi mensaje es: ";
		cout << newOriginal << endl;
		return cifradoTres(newOriginal);
	}

	if(index == 4){
		string newOriginal = cortarMensaje(index,original);
		//cout << "tengo q cifrar con..." << index << "mi mensaje es: ";
		cout << newOriginal << endl;
		return cifradoCuatro(newOriginal);
	}
}

string CifradoPorCajas::superCifrado(string cifrado){
	string cypher = "";
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
    	//-----------------------------------//
		if(i == 0){
		  cypher += tmp2[cont];
		  cont++;
		}
		else if(i <inicio){
		  cypher +=tmp2.substr(cont,2);
		  cont = cont +2;
		}
		else if (i >= inicio){
		  cypher +=tmp2.substr(cont,3);
		  cont = cont +3;
		}
		else{
		  cypher +=tmp2.substr(cont,2);
		  cont = cont +2;
		}
		//-----------------------------------//
		cypher += tmp3.substr(claveTamanio*i,claveTamanio);
		//-----------------------------------//
		if(i==0){
		  cypher += tmp4.substr(0,2);
		}
		else if(i == claveTamanio -1){
		  cypher += tmp4.substr(tmp4.size()-2,tmp4.size());
		}
		else{
		  cypher += tmp4.substr(i*2 + (i -1) ,3);
		}
		cypher+="\n";
  }  
  return cypher;	
}

//DESCIFRADO
string CifradoPorCajas::descifrarM(string cipher){
	int tamanio = cipher.size();
	string originalCuasiFinal(" ",tamanio);
	for(int i = 1; i <= claveVeces; i++){
		originalCuasiFinal += descifradoIndividual(i,cipher);
	}
	string originalFinal(" ",tamanio);
	originalFinal = superDescifrado(originalCuasiFinal);
}

string CifradoPorCajas::descifradoUno(string cipher){
	string original(" ",cipher.size());
	int aux = claveTamanio -1;
	int	cont = 0;
	int iterator = claveTamanio -1;
	bool cambio = true;
	int tope = claveTamanio;
	while(iterator >= 0){
		cout << "iterator: " << iterator << endl;
		if(cambio){
			cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				if(tope ==  claveTamanio){
					original[cont] = cipher[aux];
					comienzo++;
					cout << "añadi " << cipher[aux] << " en la pos " << cont << " cambio true "<< "primer for "<< endl;
					aux += claveTamanio;
					cont++;
				}
				else{
					aux += claveTamanio;
					original[cont] = cipher[aux];
					comienzo++;
					cout << "añadi " << cipher[aux] << " en la pos " << cont << " cambio true "<< "primer for "<< endl;
					cont++;
				}
			}
			if(tope == claveTamanio){
				aux -= claveTamanio;
			}
			cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				original[cont] = cipher[p-1-i];
				comienzo++;
				cout << "añadi " << cipher[p-1-i] << " en la pos " << cont <<" cambio true "<< "segundo for "<< endl;
				cont++;
			}
			aux -= iterator;
			cout << "aux: " << aux << endl;
			cambio = false;
			tope--;
		}

		else{
			cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				aux -= claveTamanio;
				original[cont] = cipher[aux];
				comienzo++;
				cout << "añadi " << cipher[aux] << " en la pos " << cont << " cambio false "<< "primer for "<< endl;
				cont++;				
			}
			cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				original[cont] = cipher[p+1+i];
				comienzo++;
				cout << "añadi " << cipher[p+1+i] << " en la pos " << cont << " cambio false "<< "segundo for "<< endl;
				cont++;
			}
			aux += iterator;
			cambio = true;
			tope--;
			cout << "aux: " << aux << endl;
		}
		iterator--;
	}
	return original;	
}

string CifradoPorCajas::descifradoDos(string cifrado){
	string original (" ", cifrado.size());
	int inicio = (claveTamanio - 1) /2;
	int a = claveTamanio  + inicio;
	if (claveTamanio % 2 != 0){
		a = a-1;
	}
	int tope = a;
	int c = 0;
	int ind = 0;
	for(int i = 0; i < claveTamanio; i++){
		if(i >= inicio){
			original[c] = cifrado[ind];
			c++;
			ind++;    
		}
		if(i == 0){
			original[a] = cifrado[ind];
			ind++;
		}
		else{
			if(i != claveTamanio -1){
				original[tope] = cifrado[ind];
				ind++;
			}
			original[a] = cifrado[ind];
			ind++;
		}
		a++;
		tope--;
	}
	return original;
}

string CifradoPorCajas::descifradoTres(string cipher){
	string original(" ",cipher.size());
	reverse(cipher.begin(),cipher.end());
	int aux = claveTamanio -1;
	int	cont = 0;
	int iterator = claveTamanio -1;
	bool cambio = true;
	int tope = claveTamanio;
	while(iterator >= 0){
		cout << "iterator: " << iterator << endl;
		if(cambio){
			cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				if(tope ==  claveTamanio){
					original[cont] = cipher[aux];
					comienzo++;
					cout << "añadi " << cipher[aux] << " en la pos " << cont << " cambio true "<< "primer for "<< endl;
					aux += claveTamanio;
					cont++;
				}
				else{
					aux += claveTamanio;
					original[cont] = cipher[aux];
					comienzo++;
					cout << "añadi " << cipher[aux] << " en la pos " << cont << " cambio true "<< "primer for "<< endl;
					cont++;
				}
			}
			if(tope == claveTamanio){
				aux -= claveTamanio;
			}
			cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				original[cont] = cipher[p-1-i];
				comienzo++;
				cout << "añadi " << cipher[p-1-i] << " en la pos " << cont <<" cambio true "<< "segundo for "<< endl;
				cont++;
			}
			aux -= iterator;
			cout << "aux: " << aux << endl;
			cambio = false;
			tope--;
		}

		else{
			cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				aux -= claveTamanio;
				original[cont] = cipher[aux];
				comienzo++;
				cout << "añadi " << cipher[aux] << " en la pos " << cont << " cambio false "<< "primer for "<< endl;
				cont++;
			}
			cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				original[cont] = cipher[p+1+i];
				comienzo++;
				cout << "añadi " << cipher[p+1+i] << " en la pos " << cont << " cambio false "<< "segundo for "<< endl;
				cont++;
			}
			aux += iterator;
			cambio = true;
			tope--;
			cout << "aux: " << aux << endl;
		}
		iterator--;
	}
	if(claveTamanio%2==1){
        reverse(original.begin(),original.end());
	}
	return original;
}

string CifradoPorCajas::descifradoCuatro(string cipher){
	string original(" ", cipher.size());
	int a = claveTamanio - 1;
	int b = a;
	int c = claveTamanio * 2 + (claveTamanio - 3);
	int ind = 0;
	for(int i = 0; i < claveTamanio; i++){
		original[a] = cipher[ind];
		ind++;
		if(i != 0 && i != claveTamanio -1){
			original[b] = cipher[ind];
			ind++;
		}
		original[c] = cipher[ind];
		ind++;
		a--;
		b++;
		c--;
	}
	return original;
}

string CifradoPorCajas::descifradoIndividual(int index, string cipher){
	if(index == 1){
		string newCipher = cortarMensaje(index,cipher);
		return descifradoUno(newCipher);
	}
	if(index == 2){
		string newCipher = cortarMensaje(index,cipher);
		return descifradoDos(newCipher);
	}
	if(index == 3){
		string newCipher = cortarMensaje(index,cipher);
		return descifradoTres(newCipher);
	}
	if(index == 4){
		string newCipher = cortarMensaje(index,cipher);
		return descifradoCuatro(newCipher);
	}	
}

string CifradoPorCajas::superDescifrado(string cipher){
	
}
