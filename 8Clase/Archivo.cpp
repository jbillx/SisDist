#include "Archivo.h"
#include <iostream>

Archivo::Archivo(string filename){
	nombreArchivo = filename;
}

Archivo::Archivo(string filename, int banderas, mode_t modo){
	nombreArchivo = filename;
}

size_t Archivo::lee(size_t nbytes){

}

size_t Archivo::escribe(void &buffer, size_t nbytes){
	
}


size_t Archivo::obtieneNum_bytes(){
	return num_bytes;
}

const char Archivo::get_contenido(){
	return contenido;
}