#include "Archivo.h"
#include <stdlib.h>
#include <unistd.h>//for close
#include <fcntl.h>
#include <iostream>


Archivo::Archivo(std::string filename){
	nombreArchivo=filename;
	if((fd = open(nombreArchivo.c_str(), O_RDONLY)) == -1){
       perror(nombreArchivo.c_str());
       exit(-1);
	}
	contenido=NULL;
	num_bytes=0;
	
}
Archivo::Archivo(std::string filename, int banderas, mode_t modo){
	nombreArchivo=filename;
	if((fd = open(nombreArchivo.c_str(), banderas, modo)) == -1){
       perror(nombreArchivo.c_str());
       exit(-1);
	}
	contenido=NULL;
	num_bytes=0;
	
} 
size_t Archivo::lee(size_t n_bytes){
	contenido = (char *)realloc(contenido, num_bytes+n_bytes);
	size_t bytes_leidos;
	bytes_leidos = read(fd, (contenido+num_bytes), n_bytes);
	num_bytes+=bytes_leidos;
	return bytes_leidos;
} 
size_t Archivo::escribe(void *contenido, size_t num_bytes){
	return write(fd, contenido, num_bytes);
	
} 
size_t Archivo::obtieneNum_bytes(){
	return num_bytes;
	
}
const char* Archivo::get_contenido(){
	return contenido;
}
Archivo::~Archivo(){
	close(fd);
	free(contenido);
} 

