#include <string>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>//for close
#include <fcntl.h>
#include <iostream>
#include <cstdio> 
#ifndef ARCHIVO_H_
	#define ARCHIVO_H_
		class Archivo{ 
			private:
				std::string nombreArchivo;
				int fd;
				char *contenido;
				size_t num_bytes;
			public: 
				Archivo(std::string filename); 
				Archivo(std::string filename, int banderas, mode_t modo); 
				size_t lee(size_t nbytes); 
				size_t escribe(void *buffer, size_t nbytes); 
				size_t obtieneNum_bytes();
				const char *get_contenido();
				~Archivo(); 
		};
#endif
