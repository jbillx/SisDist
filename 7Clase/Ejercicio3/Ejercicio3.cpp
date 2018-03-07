#include <iostream>
#include <cstring>
#include "Cstrings.h"
using namespace std;

int main(){
  //srand (time(NULL));
  char cadena[] = "IPN";
  Cstrings stringTipoC = Cstrings(3);
  stringTipoC.generarCadenota(26*26);
  stringTipoC.imprimirCadenota();
  stringTipoC.encuentraCadena(cadena);
  stringTipoC.liberarMemoria();
  return 0;
}
