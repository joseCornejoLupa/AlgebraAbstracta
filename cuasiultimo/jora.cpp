#include "jora.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

CifradoPorCajas::CifradoPorCajas(int claveTamanio,int claveVeces){
	this -> claveTamanio = claveTamanio;
	this -> claveVeces = claveVeces;
	this -> comienzo = 0;
	this -> cont = 1;
}

//CIFRADO
string CifradoPorCajas::cifrarM(string original){
	/*int letrasMAX = calcularLetras();
	string completo = completarLetras(original,letrasMAX);
	//cout << "mi string completo" << completo << endl;
	int tamanio = completo.size();
	string cipherCuasiFinal = "";
	for(int i = 1; i <= claveVeces; i++){
		cout << "repaso el patron: "<< i << "claveVeces: " << claveVeces <<endl;
		cipherCuasiFinal += cifradoIndividual(i,original);
		cout << "tengo avanzado hasta ahora: (" << cipherCuasiFinal << ")" << endl;
	}
//	cout << "final: (" << cipherCuasiFinal << ")" << endl;
	string cipherFinal("",tamanio);
	cipherFinal = superCifrado(cipherCuasiFinal);
	comienzo = 0;
	return cipherFinal;*/
	int i = 1;
	while(cont <= claveVeces){
		string aux;
		int fin;
		if(i == 1 || i == 3){
			fin = claveTamanio * claveTamanio;
		}
		else if(i == 2){
			int inicio = (claveTamanio - 1) / 2;
			fin = (claveTamanio*2) + (claveTamanio-2) - inicio;
		}
		else{
			fin = (claveTamanio*3) - 2;
		}
		aux = original.substr(0,fin);
		cout << "el corte es: " << aux << endl;
		original.erase(0,fin);
		cout << "asi se quedo el texto: " << original << endl;
		cipher += cifradoIndividual(i,aux);
		i++;
		if(i == 5){
			i = 1;
		}
		cont++;
	}
	string re;
	cout << "antes del SuperCifrado: " << cipher << endl;
	re = superCifrado(cipher);
	return re;
}

string CifradoPorCajas::cifradoIndividual(int index,string original){
	cout << "cont: " << cont << " index: "<< index << endl;
	if(index == 1){
		/*string newOriginal = cortarMensaje(index,original);
		//cout << "tengo q cifrar con..." << index << "mi mensaje es: ";
		cout << newOriginal << endl;*/
		return cifradoUno(original);
	}

	if(index == 2){
		/*string newOriginal = cortarMensaje(index,original);
		//cout << "tengo q cifrar con..." << index << "mi mensaje es: ";
		cout << newOriginal << endl;*/
		return cifradoDos(original);
	}

	if(index == 3){
		/*string newOriginal = cortarMensaje(index,original);
		//cout << "tengo q cifrar con..." << index << "mi mensaje es: ";
		cout << newOriginal << endl;*/
		return cifradoTres(original);
	}

	if(index == 4){
		/*string newOriginal = cortarMensaje(index,original);
		//cout << "tengo q cifrar con..." << index << "mi mensaje es: ";
		cout << newOriginal << endl;*/
		return cifradoCuatro(original);
	}
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

string CifradoPorCajas::cifradoUno(string original){
	cout << "me llego a mi(1): " << original << endl;
	string cipher("",original.size());
	int aux = claveTamanio -1;
	int	contu = 0;
	int iterator = claveTamanio -1;
	bool cambio = true;
	int tope = claveTamanio;
	while(iterator >= 0){
		//cout << "iterator: " << iterator << endl;
		if(cambio){
			//cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				if(tope ==  claveTamanio){
					cipher[aux] = original[contu];
					comienzo++;
					//cout << "añadi " << original[contu] << " en la pos " << aux << " cambio true "<< "primer for "<< endl;
					aux += claveTamanio;
					contu++;
				}
				else{
					aux += claveTamanio;
					cipher[aux] = original[contu];
					comienzo++;
					//cout << "añadi " << original[contu] << " en la pos " << aux << " cambio true "<< "primer for "<< endl;
					contu++;
				}
			}
			if(tope == claveTamanio){
				aux -= claveTamanio;
			}
//			cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				cipher[p-1-i] = original[contu];
				comienzo++;
//			cout << "añadi " << original[contu] << " en la pos " << p-1-i <<" cambio true "<< "segundo for "<< endl;
				contu++;
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
				cipher[aux] = original[contu];
				comienzo++;
				//cout << "añadi " << original[contu] << " en la pos " << aux << " cambio false "<< "primer for "<< endl;
				contu++;				
			}
			//cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				cipher[p+1+i] = original[contu];
				comienzo++;
				//cout << "añadi " << original[contu] << " en la pos " << p+1+i << " cambio false "<< "segundo for "<< endl;
				contu++;
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
  string cifrado;
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
	int	contt = 0;
	int iterator = claveTamanio -1;
	bool cambio = true;
	int tope = claveTamanio;
	while(iterator >= 0){
		//cout << "iterator: " << iterator << endl;
		if(cambio){
			//cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				if(tope ==  claveTamanio){
					cipher[aux] = original[contt];
					comienzo++;
					//cout << "añadi " << original[cont] << " en la pos " << aux << " cambio true "<< "primer for "<< endl;
					aux += claveTamanio;
					contt++;
				}
				else{
					aux += claveTamanio;
					cipher[aux] = original[contt];
					comienzo++;
					//cout << "añadi " << original[cont] << " en la pos " << aux << " cambio true "<< "primer for "<< endl;
					contt++;
				}
			}
			if(tope == claveTamanio){
				aux -= claveTamanio;
			}
			//cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				cipher[p-1-i] = original[contt];
				comienzo++;
				//cout << "añadi " << original[contt] << " en la pos " << p-1-i <<" cambio true "<< "segundo for "<< endl;
				contt++;
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
				cipher[aux] = original[contt];
				comienzo++;
				//cout << "añadi " << original[contt] << " en la pos " << aux << " cambio false "<< "primer for "<< endl;
				contt++;
			}
			//cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				cipher[p+1+i] = original[contt];
				comienzo++;
				//cout << "añadi " << original[contt] << " en la pos " << p+1+i << " cambio false "<< "segundo for "<< endl;
				contt++;
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
	string cifrado;
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

string CifradoPorCajas::cortarMensaje(int index,string original){
	string corte;
	int fin;/*
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
	cout << "la " << plip << " vez q corte obtuve esto: ";
	cout << corte << endl;
	cout << "ademas comienzo: " << comienzo << endl;
	plip++;*/
	if(index == 1 || index == 3){
		fin = claveTamanio * claveTamanio;
	}
	else if(index == 2){
		int inicio = (claveTamanio - 1) / 2;
		fin = (claveTamanio*2) + (claveTamanio-2) - inicio;
	}
	else{
		fin = (claveTamanio*3) - 2;
	}
	corte = original.substr(0,fin);
	cout << "el corte es: " << corte << endl;
	original.erase(0,fin);
	cout << "asi se quedo el texto: " << original << endl;
    return corte;
}

string CifradoPorCajas::superCifrado(string cifrado){
	cont = 1;
	int conti = 0;
	int i = 1,j=0;
	string cypher,tmp1;
	while(cont <= claveVeces){
		if(i == 1 || i ==3){
			tmp1 = cifrado.substr(conti,claveTamanio);
			cypher += tmp1;
			conti += claveTamanio * claveTamanio;
		}	
		if(i == 2){
			int inicio = (claveTamanio-1)/2;
			if(j == 0){
				cypher += cifrado.subtr(conti + ((claveTamanio*claveTamanio)-claveTamanio),);
				conti++;	
			}
			tmp1 = cifrado.substr(conti + ((claveTamanio*claveTamanio)-claveTamanio),);
			cypher += 
		}
		if(i == 2 && conti == claveVeces){
			
		}
	}/*
	tmp1 = cifrado.substr(0,claveTamanio*claveTamanio);
	cout<<tmp1<<"\n";
	int inicio = (claveTamanio-1)/2;
	int x = claveTamanio*2+(claveTamanio-2)-inicio;
	tmp2 = cifrado.substr(claveTamanio*claveTamanio,x);
	cout<<tmp2<<"\n";
	tmp3 = cifrado.substr(x+(claveTamanio*claveTamanio),claveTamanio*claveTamanio);
	cout<<tmp3<<"\n";
	tmp4 = cifrado.substr(2*(claveTamanio*claveTamanio)+x,claveTamanio*2+(claveTamanio-2));
	cout<<tmp4<<"\n";
	for(; i < claveTamanio ; i++){
    	cypher += tmp1.substr(claveTamanio*i,claveTamanio);
		cout << "añadi: " << tmp1.substr(claveTamanio*i,claveTamanio) << endl;
    	//-----------------------------------//
		if(i == 0){
		  cypher += tmp2[conti];
			cout << "añadi: " << tmp2[conti] << endl;
		  conti++;
		}
		else if(i <inicio){
			cout << "añadi: " << tmp2.substr(conti,2) << endl;
		  cypher +=tmp2.substr(conti,2);
		  conti = conti +2;
		}
		else if (i >= inicio){
			cout << "añadi: " << tmp2.substr(conti,3) << endl;
		  cypher +=tmp2.substr(conti,3);
		  conti = conti +3;
		}
		else{
			cout << "añadi: " << tmp2.substr(conti,2) << endl;
		  cypher +=tmp2.substr(conti,2);
		  conti = conti +2;
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
  }*/
  return cypher;	
}

//DESCIFRADO
string CifradoPorCajas::descifrarM(string cipher){
	int tamanio = cipher.size();
	string originalCuasiFinal(" ",tamanio);
	originalCuasiFinal = superDescifrado(cipher);	
	string originalFinal(" ",tamanio);
	for(int i = 1; i <= claveVeces; i++){
		originalFinal += descifradoIndividual(i,originalCuasiFinal);
	}
	return originalFinal;
}

string CifradoPorCajas::descifradoUno(string cipher){
	cout << "entro en (1): " << cipher << endl;
	string original(" ",cipher.size());
	int aux = claveTamanio -1;
	int	contu = 0;
	int iterator = claveTamanio -1;
	bool cambio = true;
	int tope = claveTamanio;
	while(iterator >= 0){
		cout << "iterator: " << iterator << endl;
		if(cambio){
			cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				if(tope ==  claveTamanio){
					original[contu] = cipher[aux];
					comienzo++;
					cout << "añadi " << cipher[aux] << " en la pos " << contu << " cambio true "<< "primer for "<< endl;
					aux += claveTamanio;
					contu++;
				}
				else{
					aux += claveTamanio;
					original[contu] = cipher[aux];
					comienzo++;
					cout << "añadi " << cipher[aux] << " en la pos " << contu << " cambio true "<< "primer for "<< endl;
					contu++;
				}
			}
			if(tope == claveTamanio){
				aux -= claveTamanio;
			}
			cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				original[contu] = cipher[p-1-i];
				comienzo++;
				cout << "añadi " << cipher[p-1-i] << " en la pos " << contu <<" cambio true "<< "segundo for "<< endl;
				contu++;
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
				original[contu] = cipher[aux];
				comienzo++;
				cout << "añadi " << cipher[aux] << " en la pos " << contu << " cambio false "<< "primer for "<< endl;
				contu++;				
			}
			cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				original[contu] = cipher[p+1+i];
				comienzo++;
				cout << "añadi " << cipher[p+1+i] << " en la pos " << contu << " cambio false "<< "segundo for "<< endl;
				contu++;
			}
			aux += iterator;
			cambio = true;
			tope--;
			cout << "aux: " << aux << endl;
		}
		iterator--;
	}
	cout << "salio de (1): " << original << endl;
	return original;	
}

string CifradoPorCajas::descifradoDos(string cifrado){
	cout << "entro en (2): " << cifrado << endl;
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
			comienzo++;
			c++;
			ind++;    
		}
		if(i == 0){
			original[a] = cifrado[ind];
			comienzo++;
			ind++;
		}
		else{
			if(i != claveTamanio -1){
				original[tope] = cifrado[ind];
				comienzo++;
				ind++;
			}
			original[a] = cifrado[ind];
			comienzo++;
			ind++;
		}
		a++;
		tope--;
	}
	cout << "salio de (2): " << original << endl;
	return original;
}

string CifradoPorCajas::descifradoTres(string cipher){
	cout << "primer cipher " << cipher << endl;
	char unaLetra = cipher[0];
	for(int i = 0; i < cipher.size();i++){
		cout << "cambio " << cipher[i+1] << "por " << cipher[i]<< endl;
		cipher[i] = cipher[i+1];
	}
	cipher.insert(cipher.size()-4,1,unaLetra);
	cout << "entro en (3): " << cipher << endl;
	string original(" ",cipher.size());
	reverse(cipher.begin(),cipher.end());
	int aux = claveTamanio -1;
	int	contt = 0;
	int iterator = claveTamanio -1;
	bool cambio = true;
	int tope = claveTamanio;
	while(iterator >= 0){
		//cout << "iterator: " << iterator << endl;
		if(cambio){
			//cout << "tope: " << tope << endl;
			for(int i = 0; i < tope; i ++){
				if(tope ==  claveTamanio){
					original[contt] = cipher[aux];
					comienzo++;
					//cout << "añadi " << cipher[aux] << " en la pos " << contt << " cambio true "<< "primer for "<< endl;
					aux += claveTamanio;
					contt++;
				}
				else{
					aux += claveTamanio;
					original[contt] = cipher[aux];
					comienzo++;
					//cout << "añadi " << cipher[aux] << " en la pos " << contt << " cambio true "<< "primer for "<< endl;
					contt++;
				}
			}
			if(tope == claveTamanio){
				aux -= claveTamanio;
			}
			//cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				original[contt] = cipher[p-1-i];
				comienzo++;
				//cout << "añadi " << cipher[p-1-i] << " en la pos " << contt <<" cambio true "<< "segundo for "<< endl;
				contt++;
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
				original[contt] = cipher[aux];
				comienzo++;
				//cout << "añadi " << cipher[aux] << " en la pos " << contt << " cambio false "<< "primer for "<< endl;
				contt++;
			}
			//cout << "aux: " << aux << endl;
			for(int i = 0; i < iterator;i++){
				int p = aux;
				original[contt] = cipher[p+1+i];
				comienzo++;
				//cout << "añadi " << cipher[p+1+i] << " en la pos " << contt << " cambio false "<< "segundo for "<< endl;
				contt++;
			}
			aux += iterator;
			cambio = true;
			tope--;
			//cout << "aux: " << aux << endl;
		}
		iterator--;
	}
	if(claveTamanio%2==0){
        reverse(original.begin(),original.end());
	}
	cout << "salio de (3): " << original << endl;
	return original;
}

string CifradoPorCajas::descifradoCuatro(string cipher){
	char unaLetra = cipher[0];
	for(int i = 0; i < cipher.size();i++){
		cipher[i] = cipher[i+1];
	}
	cipher.insert(cipher.size()-2,1,unaLetra);
	cout << "entro en (4): " << cipher << endl;
	string original(" ", cipher.size());
	int a = claveTamanio - 1;
	int b = a;
	int c = claveTamanio * 2 + (claveTamanio - 3);
	int ind = 0;
	for(int i = 0; i < claveTamanio; i++){
		original[a] = cipher[ind];
		comienzo++;
		ind++;
		if(i != 0 && i != claveTamanio -1){
			original[b] = cipher[ind];
			comienzo++;
			ind++;
		}
		original[c] = cipher[ind];
		comienzo++;
		ind++;
		a--;
		b++;
		c--;
	}
	cout << "salio de (4): " << original << endl;
	return original;
}

string CifradoPorCajas::descifradoIndividual(int index, string cipher){
	if(index == 1){
		string newCipher = cortarMensaje(index,cipher);
		cout << "mi clave es: " << index << "mi mensaje cortado: " << newCipher << endl;
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
	string cypher;
  	int inicio = (claveTamanio-1)/2;
	string tmp1;
	int x = claveTamanio*2+(claveTamanio-2)-inicio;
	string tmp2;
	string tmp3;
	string tmp4;
	int cont = 0;
	for(int i = 0 ; i < claveTamanio ; i++){
		cout << "cont: " << cont << endl;
    	tmp1 += cipher.substr(cont,claveTamanio);
		cout << "añadi al 1: " << cipher.substr(cont,claveTamanio) << endl;
		cont += claveTamanio;
    	//-----------------------------------//
		if(i == 0){
		  tmp2 += cipher[cont];
			cout << "añadi al 2: " << cipher[cont] << endl;
		  cont++;
		}
		else if(i < inicio){
			cout << "añadi al 2: " << cipher.substr(cont,2) << endl;
		  tmp2 += cipher.substr(cont,2);
		  cont = cont +2;
		}
		else if (i >= inicio){
			cout << "añadi al 2: " << cipher.substr(cont,3) << endl;
		  tmp2 += cipher.substr(cont,3);
		  cont = cont +3;
		}
		else{
			cout << "añadi al 2: " << cipher.substr(cont,2) << endl;
		  tmp2 += cipher.substr(cont,2);
		  cont = cont +2;
		}
		//-----------------------------------//
		tmp3 += cipher.substr(cont,claveTamanio);
		cout << "añadi al 3: " << cipher.substr(cont,claveTamanio) << endl;
		cont += claveTamanio;
		//-----------------------------------//
		if(i==0){
		  tmp4 += cipher.substr(cont,2);
			cout << "añadi al 4: " << cipher.substr(cont,2) << endl;
			cont += 2;
		}
		else if(i == claveTamanio -1){
		  tmp4 += cipher.substr(cont,2);
			cout << "añadi al 4: " << cipher.substr(cont,2) << endl;
			cont += 2;
		}
		else{
		  tmp4 += cipher.substr(cont ,3);
			cout << "añadi al 4: " << cipher.substr(cont,3) << endl;
			cont += 3;
		}
  }
	cypher += tmp1;
	cout << "de tmp1"<< cypher << endl;
	cypher += tmp2;
	cout << "de tmp2"<< cypher << endl;
	cypher += tmp3;
	cout << "de tmp3"<< cypher << endl;
	cypher += tmp4;
	cout << "de tmp4"<< cypher << endl;
  return cypher;
}
