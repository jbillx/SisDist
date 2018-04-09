#include "SocketDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/time.h>

using namespace std;

SocketDatagrama::SocketDatagrama(int puerto){
	s = socket(AF_INET, SOCK_DGRAM, 0);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(puerto);
	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
	timeout = 0;
}

SocketDatagrama::~SocketDatagrama(){
  //close(s);
}

void SocketDatagrama::setBroadcast(){
	int yes = 1;
	setsockopt(s, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int));
}

void SocketDatagrama::unsetBroadcast(){
	int yes = 0;
	setsockopt(s, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int));
}

void SocketDatagrama::setTimeout(time_t segundos, suseconds_t microsegundos){
	time.tv_sec = segundos;
	time.tv_usec = microsegundos;
	timeout = 1;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&time, sizeof(time));
}

void SocketDatagrama::unsetTimeout(){
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, 0, 0);
	timeout = 0;
}

//Recibe un paquete tipo datagrama proveniente de este socket
int SocketDatagrama::recibe(PaqueteDatagrama & p){
	unsigned int addr_len = sizeof(direccionForanea);
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	int respuesta = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, &addr_len);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	return respuesta;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama & p){
	struct timeval tiempo_ini;
	struct timeval tiempo_fin;
	gettimeofday(&tiempo_ini, NULL);
	unsigned int addr_len = sizeof(direccionForanea);
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	int respuesta = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, &addr_len);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	if (respuesta  < 0) {
 		if (errno == EWOULDBLOCK){}
 			//fprintf(stderr, "Tiempo para recepción transcurrido\n");
 		else{}
 			//fprintf(stderr, "Error en recvfrom\n");
	}
  gettimeofday(&tiempo_fin, NULL);
	double secs = (double)(tiempo_fin.tv_sec + (double)tiempo_fin.tv_usec/1000000) - (double)(tiempo_ini.tv_sec + (double)tiempo_ini.tv_usec/1000000);
  //printf("Tiempo: %.16g milliseconds\n", secs * 1000.0);
	return respuesta;
}

//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::envia(PaqueteDatagrama & p){
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	return sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}
