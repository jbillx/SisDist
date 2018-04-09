#include "SocketMulticast.h"
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

SocketMulticast::SocketMulticast(int puerto){
	s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(puerto);
	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
	//timeout = 0;
}

SocketMulticast::~SocketMulticast(){
  //close(s);
}

//Recibe un paquete tipo datagrama proveniente de este socket
int SocketMulticast::recibe(PaqueteDatagrama & p, char *ipE){
	struct ip_mreq multicast;
	multicast.imr_multiaddr.s_addr = inet_addr(ipE);
	multicast.imr_interface.s_addr = htonl(INADDR_ANY);
	setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));
	unsigned int addr_len = sizeof(direccionForanea);
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	int respuesta = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, &addr_len);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	return respuesta;
}

//Envía un paquete tipo datagrama desde este socket
int SocketMulticast::envia(PaqueteDatagrama & p, unsigned char TTL){
	setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &TTL, sizeof(TTL));
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	return sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}


