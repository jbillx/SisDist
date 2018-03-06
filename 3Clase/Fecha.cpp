#include "Fecha.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa): dia(dd), mes(mm), anio(aaaa){
	if((mes < 1)|| (mes > 12)){
		cout << "Valor ilegal para el mes!\n";
		exit(1);
	}

	if((dd < 1)|| (dd > 31)){
		cout << "Valor ilegal para el día!\n";
		exit(1);
	}

	if((aaaa < 0)|| (aaaa > 2018)){
		cout << "Valor ilegal para el año!\n";
		exit(1);
	}

}
void Fecha::inicializaFecha(int dd, int mm, int aaaa){
	anio = aaaa;
	mes = mm;
	dia = dd;   
	return;
}

void Fecha::muestraFecha(){
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes<< "-" << anio << endl;
	return;   
}

bool Fecha::leapyr(){
	if( ( (anio%4)<=0 && (anio%100)>0 ) || (anio%400<=0) ){
		return true;
	}
	return false;
}

void Fecha::setAnio(int a){
	anio = a;
	return;
}

int Fecha::getAnio(){
	return anio;
}

int Fecha::getMes(){
	return mes;
}
int Fecha::getDia(){
	return dia;
}

void Fecha::fechaRand(){
	dia= 1+rand()%(32-1);
	mes= 1+rand()%(13-1);
	anio= 1+rand()%(2018-1);
}
