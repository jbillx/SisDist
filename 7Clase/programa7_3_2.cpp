#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>



using namespace std;

int main(int argc, char const *argv[])
{
	
	char car;
	int n = 10;
	char *cadena=NULL;
	
	printf("Resultado %s\n", cadena);


    srand(time(NULL));
	for (int i = 1; i < n; i++){
		char aux[] = "A" + rand() % (("Z" - "A") + 1); 
		cadena = (char*)realloc(cadena,i);
		memcpy(cadena,aux,strlen(aux)+1);

		if( (i%3)==0){ 

			cadena = (char*)realloc(cadena,1);
			memcpy(cadena," ",1);
		}
	}
	return 0 ;

	/*
	cout<<srt<<endl;
	size_t fount=0;
	int cont=0;
	for( ; ; ){
		fount=srt.find("IPN",fount);

		if(fount==string::npos){
			break;
		}else{
			cont++;
			fount++;
		}
	}
	cout<<"Se encontro la palabra IPN "<<cont<<" veces"<<endl;

*/
	return 0;
}