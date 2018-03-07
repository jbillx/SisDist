#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Cstrings.h"
using namespace std;

Cstrings::Cstrings(int tp){
  tamanioPalabra=tp;
  palabra=(char*)malloc(tamanioPalabra+1);//Tres caracteres mas un espacio
  cadenota = (char*)malloc(tamanioPalabra+1);//Tres caracteres mas un espacio
  numeroDePalabras=1;
}

void Cstrings::addPalabra(char** cadenota, char **palabra){
    //cout << "Tamaño de palabra:" << numeroDePalabras + tamanioPalabra << endl;
	strncat(*cadenota, *palabra, tamanioPalabra+1);
	numeroDePalabras++;
    *cadenota = (char*)realloc(*cadenota, ((numeroDePalabras*tamanioPalabra)+(numeroDePalabras)));    
}

void Cstrings::generarCadenota(int n){
//  cout<<"Tamnio palabra: " << sizeof(palabra);
  for(int i=0; i<n; i++){
    for(int j=0; j<tamanioPalabra; j++){
      palabra[j] = rand() % 26 + (65);
    }
	palabra[tamanioPalabra] = 32;//espacio
  addPalabra(&cadenota, &palabra);
  }
  
  cadenota[(numeroDePalabras*tamanioPalabra+numeroDePalabras)-1]='\0';
}

void Cstrings::imprimirCadenota(){
  int i=0;
  while(cadenota[i]!='\0'){
    cout << cadenota[i];
    i++;
  }
  cout << endl;
}

void Cstrings::encuentraCadena(char *cadena){
  int ocurrencias=0;
  int coincidencias=0;
  int contador=0;
  int i=0;
  char *aux =(char*)malloc(3);;
  int posicionAux = 0;
  while(cadenota[i]!='\0'){
      if(cadenota[i]==32){
        if(aux[0] == cadena[0] && aux[1] == cadena[1] && aux[2] == cadena[2]){
          ocurrencias++;
        }
        posicionAux=0;
      }else{
        aux[posicionAux] = cadenota[i];
        posicionAux++;
      }
      i++;

  }
  cout << "La cadena \"" << cadena << "\" aparece " << ocurrencias << " vez(ces)" << endl;
}

void Cstrings::liberarMemoria(){
  free(cadenota);
  free(palabra);
}
