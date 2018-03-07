#include "Fecha.h"
#include <iostream>
using namespace std;
int main(){
	Fecha a, b, c(21,9, 1973);
	b.inicializaFecha(17,6,2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();

	int cont =0;
/*
	for(int i = 1 ; i <= 2018;i++){
		a.setAnio(i);
		if(a.leapyr()){
			cont++;
		}	

	}
	cout << "Exixten "<<cont<<" años bisiestos";
*/
	int anio = 2096;
	a.setAnio(anio);
	if(a.leapyr()){
		cout<<anio<<" es bisiestos"<<endl;
	}

	return 0;
}