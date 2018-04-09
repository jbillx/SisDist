#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <vector>

using namespace std;

class Archivo
{
	public:
		Archivo(const char *, int);
		Archivo();
		Archivo(const char *, int, mode_t);
		~Archivo();
		size_t lee(size_t);
		size_t filesize();		
		size_t escribe(const void*, size_t);
		char *get_contenido();
		vector<int> buscaPalabra(char*);
		void cerrar();
	protected:
		string nombreArchivo; //Almacena el nombre del archivo
		int fd; //Almacena el descriptor de archivo
		char *contenido; //Almacena temporalmente contenido parcial o total del archivo
		FILE* newfile;
		const char *name;
};