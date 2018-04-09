#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include "SocketDatagrama.h"

using namespace std;
int puerto = 7300;

int main()
{
	SocketDatagrama socket(puerto); //Se inicializa el puerto del socket del servidor.
	int *num; 
	while (1) { //Se dedica a escuchar
	PaqueteDatagrama paquete(sizeof(num)*2);
		cout << "Se ha conectado desde:" <<paquete.obtieneDireccion() <<":"<<paquete.obtienePuerto()<<endl;
		socket.recibe(paquete);
		num = (int *)paquete.obtieneDatos(); //Obtiene los datos del paquete
		int respuesta = num[0] + num[1]; 
		cout << num[0] << " + " << num[1] << " = " << respuesta << endl;
		PaqueteDatagrama paquete1((char *) &respuesta, sizeof(int), paquete.obtieneDireccion(), paquete.obtienePuerto());//Crea un datagrama para cada respuesta tal como se hace en c :D
		socket.envia(paquete1);
	}

	return 0;
}