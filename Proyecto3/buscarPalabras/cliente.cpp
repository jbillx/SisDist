#include "SocketMulticast.h"
#include "SocketDatagrama.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <pthread.h>

#include "PaqueteDatagrama.h"
#include "Archivo.h"
#include "Header.h"


using namespace std;
//int puerto = 7300;
int num_libro=0;
list<int> libros;
vector<string> ips;
SocketMulticast socket_dat;
char palabra_a_buscar[50];
int puerto;
int TTL;

void * funcion(void *){
  string ip_proc = ips[0];
  while( !libros.empty())
  {
    struct messageCS * envBus = new messageCS;
    struct messageSC * recvBus = new messageSC; 
    strcpy(envBus->palabra,palabra_a_buscar);
    vector<int> offsets(0);
    int libro; 
    envBus->num_libro = libros.front();
    libro = envBus->num_libro;
    libros.pop_front();
    envBus->solicitud = BUSQUEDA;
    cout<<"puerto:"<<puerto<<endl;
    cout<<"ip:"<<(char *)ip_proc.c_str()<<endl;

    PaqueteDatagrama enviadoBus((char *)envBus, sizeof(struct messageCS), (char *)ip_proc.c_str(), puerto);
    //cout << envBus->num_libro << " " << envBus->solicitud << " " << enviadoBus.obtieneDireccion() << endl;
    PaqueteDatagrama recibidoBus(sizeof(struct messageSC));
    socket_dat.envia(enviadoBus,TTL);

     SocketDatagrama socket_u(enviadoBus.obtienePuerto() + 1);
      socket_u.setTimeout(0,10000);
      socket_u.setBroadcast();
    while(1)
    {
      if( socket_u.recibeTimeout(recibidoBus) < 0 )
      {
        cout<<"socket_dat.recibeTimeout(recibidoBus) = "<<socket_u.recibeTimeout(recibidoBus)<<endl;
        libros.push_back(libro);
        pthread_exit(0);
      }
      memcpy(recvBus, recibidoBus.obtieneDatos(), sizeof(struct messageSC));

      offsets.push_back(recvBus->offset);
      //cout << recvBus->libro << endl;
      if( recvBus->error == TERMINA )
      {
        if(offsets.size()!=1)
          cout << recvBus->libro<< ": "<< endl;
        for (int m = 0; m < offsets.size()-1; m++){
          cout << offsets[m] << ":"<<offsets[m++]<<",";
        }
        if(offsets.size()!=1)
          cout << endl;
        break;
      }
    }
  }
  pthread_exit(0);
}

void * funcion2(void *){
  string ip_proc = ips[1];

  while( !libros.empty())
  {
    struct messageCS * envBus = new messageCS;
    struct messageSC * recvBus = new messageSC; 
    strcpy(envBus->palabra,palabra_a_buscar);
    vector<int> offsets(0);
    int libro; 
    envBus->num_libro = libros.front();
    libro = envBus->num_libro;
    libros.pop_front();
    envBus->solicitud = BUSQUEDA;
    PaqueteDatagrama enviadoBus((char *)envBus, sizeof(struct messageCS), (char *)ip_proc.c_str(), puerto);
    //cout << envBus->num_libro << " " << envBus->solicitud << " " << enviadoBus.obtieneDireccion() << endl;
    PaqueteDatagrama recibidoBus(sizeof(struct messageSC));
    socket_dat.envia(enviadoBus, TTL);

    SocketDatagrama socket_u(enviadoBus.obtienePuerto() + 1);
    socket_u.setTimeout(0,10000);
    socket_u.setBroadcast();
    while(1)
    {
      if( socket_u.recibeTimeout(recibidoBus) < 0 )
      {
        libros.push_back(libro);
        pthread_exit(0);
      }
      memcpy(recvBus, recibidoBus.obtieneDatos(), sizeof(struct messageSC));

      offsets.push_back(recvBus->offset);

      //cout << recvBus->libro << endl;
      if( recvBus->error == TERMINA )
      {
        if(offsets.size()!=1)
          cout << recvBus->libro<< ": "<< endl;
        for (int m = 0; m < offsets.size()-1; m++)
          cout << offsets[m] << ", ";
        if(offsets.size()!=1)
          cout << endl;
        break;
      }
    }
  }
  pthread_exit(0);
}

void * funcion3(void *){
  string ip_proc = ips[2];

  while( !libros.empty())
  {
    struct messageCS * envBus = new messageCS;
    struct messageSC * recvBus = new messageSC; 
    strcpy(envBus->palabra,palabra_a_buscar);
    vector<int> offsets(0);
    int libro; 
    envBus->num_libro = libros.front();
    libro = envBus->num_libro;
    libros.pop_front();
    envBus->solicitud = BUSQUEDA;
    PaqueteDatagrama enviadoBus((char *)envBus, sizeof(struct messageCS), (char *)ip_proc.c_str(), puerto);
    //cout << envBus->num_libro << " " << envBus->solicitud << " " << enviadoBus.obtieneDireccion() << endl;
    PaqueteDatagrama recibidoBus(sizeof(struct messageSC));
    socket_dat.envia(enviadoBus, TTL);


    SocketDatagrama socket_u(enviadoBus.obtienePuerto() + 1);
    socket_u.setTimeout(0,10000);
    socket_u.setBroadcast();
    while(1)
    {
      if( socket_u.recibeTimeout(recibidoBus) < 0 )
      {
        libros.push_back(libro);
        pthread_exit(0);
      }
      memcpy(recvBus, recibidoBus.obtieneDatos(), sizeof(struct messageSC));

      offsets.push_back(recvBus->offset);

      //cout << recvBus->libro << endl;
      if( recvBus->error == TERMINA )
      {
        if(offsets.size()!=1)
          cout << recvBus->libro<< ": "<< endl;
        for (int m = 0; m < offsets.size()-1; m++)
          cout << offsets[m] << ", ";
        if(offsets.size()!=1)
          cout << endl;
        break;
      }
    }
  }
  pthread_exit(0);
}



int main(int argc, char *argv[]){
  if (argc != 5){
    cout << "Tiene que escribir: " << argv[0] << " IP PUERTO TTL PALABRA" << endl;
    return 0;
  }


  char ip[16], * pch;
  int num, libros_disp = 1;
  struct messageCS * env = new messageCS;
  struct messageSC * recv = new messageSC;
  pid_t pid;
  puerto = atoi(argv[2]);
  TTL = atoi(argv[3]);
  env->solicitud = BROADCAST;

  PaqueteDatagrama enviado((char *)env, sizeof(struct messageCS), argv[1], puerto);
  PaqueteDatagrama recibido(sizeof(struct messageSC));
  strcpy(palabra_a_buscar,argv[4]);
  socket_dat.envia(enviado, atoi(argv[3]));


  SocketDatagrama socket_u(enviado.obtienePuerto() + 1);
  socket_u.setTimeout(0,10000);
  socket_u.setBroadcast();

  int i;
  for(i = 100; i < 255; i++){
    while(1){
       if( socket_u.recibeTimeout(recibido) < 0 )
          break;
      cout << recibido.obtieneDireccion() << endl;
      string aux(recibido.obtieneDireccion());
      ips.push_back(aux);
      memcpy(recv, recibido.obtieneDatos(), sizeof(struct messageSC));
      cout<<recv->offset<<endl;
    }
    for (int i = 0; i < recv->offset; i++){
      libros.push_back(i);
    }

    pthread_t th1, th2, th3;
    if(ips.size()>=1)
      pthread_create(&th1,NULL,funcion,NULL);
    if(ips.size()>=2)
      pthread_create(&th2,NULL,funcion2,NULL);
    if(ips.size()>=3)
      pthread_create(&th3,NULL,funcion3,NULL);

    if(ips.size()>=1)
      pthread_join(th1,NULL);
    if(ips.size()>=2)
      pthread_join(th2,NULL);
    if(ips.size()>=3)
      pthread_join(th3,NULL);
    exit(0);


  }
  return 0;
}
/*

int main(int argc, char* argv[])
{
  char ip[16], * pch;
  int num, libros_disp = 1;
  struct messageCS * env = new messageCS;
  struct messageSC * recv = new messageSC;
  pid_t pid;



  env->solicitud = BROADCAST;
  PaqueteDatagrama enviado((char *)env, sizeof(struct messageCS), ip, puerto);
  PaqueteDatagrama recibido(sizeof(struct messageSC));
  strcpy(palabra_a_buscar,argv[1]);
  socketsin.envia(enviado);
  while(1)
  {
    if( socketsin.recibeTimeout(recibido) < 0 )
      break;
    cout << recibido.obtieneDireccion() << endl;
    string aux(recibido.obtieneDireccion());
    ips.push_back(aux);
    memcpy(recv, recibido.obtieneDatos(), sizeof(struct messageSC));
  }
  for (int i = 0; i < recv->offset; i++)
    libros.push_back(i);

  pthread_t th1, th2, th3;
  if(ips.size()>=1)
    pthread_create(&th1,NULL,funcion,NULL);
  if(ips.size()>=2)
    pthread_create(&th2,NULL,funcion2,NULL);
  if(ips.size()>=3)
    pthread_create(&th3,NULL,funcion3,NULL);

  if(ips.size()>=1)
    pthread_join(th1,NULL);
  if(ips.size()>=2)
    pthread_join(th2,NULL);
  if(ips.size()>=3)
    pthread_join(th3,NULL);
  exit(0);
  /*for (int i = 0; i < recv->offset; i++)
    libros.push_back(i);


  for (int i = 0; i < ips.size(); i++)  
  {
    if( (pid = fork()) )
    { 
      string ip_proc = ips[i];
      while( !libros.empty() )
      {
        struct messageCS * envBus = new messageCS;
        struct messageSC * recvBus = new messageSC; 
        strcpy(envBus->palabra,argv[1]);
        vector<int> offsets(0);
        int libro; 
        envBus->num_libro = libros.front();
        libro = envBus->num_libro;
        libros.pop_front();
        envBus->solicitud = BUSQUEDA;
        PaqueteDatagrama enviadoBus((char *)envBus, sizeof(struct messageCS), (char *)ip_proc.c_str(), puerto);
        cout << envBus->num_libro << " " << envBus->solicitud << " " << enviadoBus.obtieneDireccion() << endl;
        PaqueteDatagrama recibidoBus(sizeof(struct messageSC));
        socketsin.envia(enviadoBus);
        while(1)
        {
          if( socketsin.recibeTimeout(recibidoBus) < 0 )
          {
            libros.push_back(libro);
            exit(0);
          }
          memcpy(recvBus, recibidoBus.obtieneDatos(), sizeof(struct messageSC));
    
          offsets.push_back(recvBus->offset);

          cout << recvBus->libro << endl;
          if( recvBus->error == TERMINA )
          {

            for (int m = 0; m < offsets.size(); m++)
              cout << offsets[m] << ", ";
            cout << endl;
            break;
          }
        }
      }
      exit(0);
    }
    else
      wait(NULL);
  }
}

*/
