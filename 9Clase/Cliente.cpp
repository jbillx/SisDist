#include "SocketDatagrama.h"

using namespace std;
int puerto = 7300;

int main()
{
   int num[2]; //Para almacenar los numeros a sumar
   char ip[] = "127.0.0.1";
   int *respuesta; //apunta a un entero que puedo enviar a traves del socket
   SocketDatagrama socket; //notese que al inicializar se toma el argumento por default 0 que tomara el puerto que decida el SO
   num[0] = 2;
   num[1] = 5;
   PaqueteDatagrama paq((char *)num, 2 * sizeof(int), ip, puerto);
   socket.envia(paq); //envia informacion global servidor
   PaqueteDatagrama paquete1(sizeof(int)); //inicializa la informacion del datagrama
   socket.recibe(paquete1); //recibe informacion del servidor
   respuesta = (int *)paquete1.obtieneDatos(); //obtiene a traves de un metodo los datos que le envio el servidor
   cout << "La respuesta viene desde:"<<paquete1.obtieneDireccion()<<":"<<paquete1.obtienePuerto()<<"  y es: " << *respuesta << endl;

   return 0;
}