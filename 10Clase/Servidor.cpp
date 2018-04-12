#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include "SocketDatagrama.h"

using namespace std;
int puerto = 7303;

int main()
{
	SocketDatagrama socket(puerto); //Se inicializa el puerto del socket del servidor.
	unsigned int *num; 
	while (1) { //Se dedica a escuchar
		PaqueteDatagrama paquete(sizeof(num)*3);
		cout << "Se ha conectado desde:" <<paquete.obtieneDireccion() <<":"<<paquete.obtienePuerto()<<endl;
		socket.recibe(paquete);
		num = (unsigned int *)paquete.obtieneDatos(); //Obtiene los datos del paquete
		unsigned int i=num[1];
		unsigned int respuesta=1;
		for (i;i<=num[2];i++){
			if(num[0]%i==0){
				respuesta=0;
				break;
			}
			
		}
		cout <<  " El numero primo :  " << num[0] << "  es  " << respuesta << endl;
		PaqueteDatagrama paquete1((char *) &respuesta, sizeof(unsigned int), paquete.obtieneDireccion(), paquete.obtienePuerto());//Crea un datagrama para cada respuesta tal como se hace en c :D
		socket.envia(paquete1);
	}

	return 0;
}