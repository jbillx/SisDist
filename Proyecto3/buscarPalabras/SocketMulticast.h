#ifndef __SocketMulticast__
#define __SocketMulticast__
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include "PaqueteDatagrama.h"
#include <arpa/inet.h>

class SocketMulticast{
	public:
		SocketMulticast(int puesto = 0);
		~SocketMulticast();

		int recibe(PaqueteDatagrama & p, char *ipE);
		int envia(PaqueteDatagrama & p, unsigned char TTL);
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		//struct timeval time;
		//bool timeout;
		int s; //ID socket
};
#endif
