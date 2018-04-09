#include "Archivo.h"
#include <iostream>
#include <fcntl.h>
using namespace std;
int main(int argc, char *argv[]){
	if(argc!=3){
		cout << "La ejecucion debe de ser:./" << argv[0] <<" Archivo_Origen Archivo_Destino" << endl;		
		exit(-1);
	}else{
		Archivo archivoLectura(argv[1]);
		Archivo archivoEscritura(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0666);
		int bytes_leidos;		
		while((bytes_leidos = archivoLectura.lee(BUFSIZ)) > 0);
		cout << archivoLectura.get_contenido() << endl;
		archivoEscritura.escribe((void *)archivoLectura.get_contenido(), archivoLectura.obtieneNum_bytes());
	}
}
