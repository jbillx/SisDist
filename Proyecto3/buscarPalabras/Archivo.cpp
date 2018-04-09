#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <fstream>
#include <string.h>
#include "Archivo.h"

using namespace std;

Archivo::Archivo(const char *filename, int banderas){
	if((fd = open(filename,banderas)) == -1){
		perror(filename);
		newfile = fopen(filename,"w+");	
		fd = open(filename,banderas);	
		name=filename;
   	}
   	name=filename;
	//cout<<fd<<endl;
}
Archivo::Archivo(){
}
Archivo::Archivo(const char *filename, int banderas, mode_t modo){
	if((fd = open(filename,banderas,modo)) == -1){
		newfile = fopen(filename,"w+");
		fd = open(filename,banderas,modo);
		//perror(filename);
		//exit(-1);
	}	
}

Archivo::~Archivo(){

}

size_t Archivo::lee(size_t nbytes){
	contenido = (char*)malloc(nbytes*sizeof(char));
	return read(fd,contenido,nbytes);
}

size_t Archivo::filesize(){
	return (size_t)lseek(fd,0,SEEK_END);
}

size_t Archivo::escribe(const void *buffer, size_t nbytes){
	return write(fd, buffer, nbytes);
}

char* Archivo::get_contenido(){
	return contenido;
}

vector<int> Archivo::buscaPalabra(char* palabra){	
	//cout<<"Palabra que se buscara: "<<palabra<<endl;
	string s ;
	vector<int> offsets;	
   	ifstream fichero(name);
   char cadena[500];
   int nlinea = 1;
   	while(fichero){
   		fichero.getline(cadena,500);
		std::string str(cadena);
		s=cadena;
	 	int found = 0;
	 	/*while( (found=s.find_first_of(palabra) )>0){
	 		cout<<found<<endl;
	 		offsets.push_back(found);
	 		offsets.push_back(nlinea);
	 	}	*/	 	
		while((found = s.find(palabra,found)) != -1){	
			found = (found > 0) ? found - 1 : found;
			offsets.push_back(found);
			offsets.push_back(nlinea);	
			//cout<<"("<<found<<":"<<nlinea<<")"<<endl;

			found+=2;		
		}
		nlinea++;
   	}
	return offsets;
}

void Archivo::cerrar(){
	close(fd);
}