#include "SocketDatagrama.h"

using namespace std;
int puerto = 7300;

int main()
{
   int noServidores = 4;
   unsigned int num[3]; //Para almacenar los numeros a sumar
   char ip[] = "127.0.0.1";
   unsigned int *respuesta[noServidores]; //apunta a un entero que puedo enviar a traves del socket
   SocketDatagrama socket[noServidores]; //notese que al inicializar se toma el argumento por default 0 que tomara el puerto que decida el SO


   num[0] = 4294967291;
   num[1] = 2;
   num[2] = 4294967291;

   num[1] = 2;
   for (int i=0;i<noServidores;i++){

      if(i!=0){
       num[1] = (num[0]/noServidores) + i;  
      }
      num[2] = (num[0]/noServidores)*(i+1); 
      if(num[0] == (num[0]/noServidores)*(i+1)){
         num[2] = num[0]-1;
      }
      cout<<"Se va a enviar= "<<num[0]<<", "<<num[1]<<", "<<num[2]<<endl;
      PaqueteDatagrama paq((char *)num, 3 * sizeof(unsigned int), ip, puerto+i);
      socket[i].envia(paq); //envia informacion global servidor

   }


   for (int i=0;i<noServidores;i++){
      PaqueteDatagrama paquete1(sizeof(int)); //inicializa la informacion del datagrama
      socket[i].recibe(paquete1); //recibe informacion del servidor
      respuesta[i] = (unsigned int *)paquete1.obtieneDatos(); //obtiene a traves de un metodo los datos que le envio el servidor
      cout<<"Respuesta["<<i<<"] = "<<*respuesta[i]<<endl;
      if(*respuesta[i]==0){
         cout<<"El numero "<<num[0]<<" no es primo "<<endl;
         return 0;
      }
   }
   cout<<"El numero "<<num[0]<<" es primo "<<endl;
   return 0;
}