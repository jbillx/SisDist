#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <iostream>
#include <string>
#include <sys/stat.h>

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


using namespace std;

class Archivo{
	private:
		string nombreArchivo;
		int fd;
		char * contenido;
		size_t num_bytes;
public:
	Archivo(string filename); 
	Archivo(string filename, int banderas, mode_t modo); 
	size_t lee(size_t nbytes); 
	size_t escribe(char &buffer, size_t nbytes); 
	size_t obtieneNum_bytes();
	const char *get_contenido();
	~Archivo(); 
};


#endif