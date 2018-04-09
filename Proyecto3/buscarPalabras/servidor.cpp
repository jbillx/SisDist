#include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

#include "Archivo.h"
#include "Header.h"

#include <iostream>
#include <cmath>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <time.h>
#include <vector>
#include <fcntl.h>


#include <inttypes.h>

#include <pthread.h>
#include <sys/time.h>
#include <errno.h>
#include <time.h>
#include <inttypes.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){
  if (argc != 5){
    cout << "Tiene que escribir: " << argv[0] << " IP PUERTO TTL UBICACION" << endl;
    return 0;
  }
  DIR *d;
  struct dirent *dir;
  int s, num, size;
  char ext[5];  
  socklen_t clilen;
  SocketMulticast socket_mult(atoi(argv[2]));
  PaqueteDatagrama recibePaquete(sizeof(messageCS));
  // struct sockaddr_in server_addr, msg_to_client_addr;
  struct messageCS * recv = new messageCS;
  struct messageSC * env = new messageSC;
  d = opendir(argv[4]);
  vector<string> libros(0);

  if( d )
  {
    while( (dir=readdir(d)) != NULL )
    {
      size = strlen(dir->d_name);
      strncpy(ext,dir->d_name+(size-4),4);
      ext[4] = '\0';
      if(strcmp(".txt",ext) == 0)
      {
        string aux(dir->d_name);
        libros.push_back(aux);
      }
    }
  }
  closedir(d);

  srand(time(NULL));
   Archivo *a;
   Archivo *b;
  while(1)
  {
    socket_mult.recibe(recibePaquete,argv[3]);
    memcpy(recv, recibePaquete.obtieneDatos(), sizeof(struct messageCS));
    switch(recv->solicitud)
    {
      case 1:{
        env->offset = libros.size();
        cout<<libros.size()<<endl;
        SocketDatagrama socket_u;
        PaqueteDatagrama paquete1((char *)env, sizeof(struct messageSC), recibePaquete.obtieneDireccion(), (atoi(argv[2]) + 1));
        socket_u.envia(paquete1);
        cout<<"Se envio respuesta a "<<recibePaquete.obtieneDireccion()<<endl;
      }
        break;
      case 2:{
        cout<<"Entro a case2"<<endl;
        string path(argv[4]);
        path.append(libros[recv->num_libro]);
        a = new Archivo(path.c_str(),O_RDONLY);
        b = new Archivo(path.c_str(),O_RDONLY);
        a->lee(b->filesize());  
        vector<int> o = a->buscaPalabra(recv->palabra);
        //memset(env->libro,'\0',100);
        cout<<"Encontrados: "<<o.size()<<endl;
        memcpy(env->libro,(libros[recv->num_libro]).c_str(),99);
        SocketDatagrama socket_u;
        for(int k=0;k<o.size();k++){
          env->offset = o[k];
          env->error =0;
          PaqueteDatagrama paquete1((char *)env, sizeof(struct messageSC), recibePaquete.obtieneDireccion(), (atoi(argv[2]) + 1));
          socket_u.envia(paquete1);
        }
        env->offset =-1;
        env->error =TERMINA;
        PaqueteDatagrama paquete1((char *)env, sizeof(struct messageSC), recibePaquete.obtieneDireccion(), (atoi(argv[2]) + 1));
        socket_u.envia(paquete1);
        a->cerrar();
        b->cerrar();
        break;
      }
      default:
        break;
    }
  } 
}
