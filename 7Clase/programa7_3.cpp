#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int n = 26*26*26*10;
	string srt, cadena;
    srand(time(NULL));
	for (int i = 1; i < n; i++){
		cadena = 'A' + rand() % (('Z' - 'A') + 1); 
		srt = srt + cadena;
		if( (i%3)==0){
			srt = srt + " ";
		}
	}
	//cout<<srt<<endl;
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


	return 0;
}