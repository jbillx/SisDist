#include "Archivo.h"

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

Archivo::Archivo(string filename){
	nombreArchivo = filename;
	if((fd = open(nombreArchivo, O_RDONLY)) == -1){
       exit(-1);
   }

   num_bytes = lee(sizeof contenido);
}

Archivo::Archivo(string filename, int banderas, mode_t modo){
	nombreArchivo = filename;
	if((fd = open(nombreArchivo, banderas, modo)) == -1){
       exit(-1);
   }
   num_bytes = lee(sizeof contenido);
}

Archivo::~Archivo(){
	close(fd);
}


size_t Archivo::lee(size_t nbytes){
	return read(fd, contenido, nbytes);
}

size_t Archivo::escribe(char &buffer, size_t nbytes){
	write(fd, buffer, nbytes);
}


size_t Archivo::obtieneNum_bytes(){
	return num_bytes;
}

const char Archivo::get_contenido(){
	return contenido;
}

