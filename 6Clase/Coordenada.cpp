#include "Coordenada.h"
#include <iostream>
#include <math.h>
#include <vector>

Coordenada::Coordenada(double xx, double yy, int bandera){
	if(bandera==0){
		//Coordenadas Polares
		x = xx * cos(yy);
		y = xx * sin(yy);
	}else{
		x = xx;
		y = yy;
	}
	distancia = sqrt( pow(x,2) + pow(y,2));

}

double Coordenada::obtenerX(){
	return x;
} 

double Coordenada::obtenerY(){
	return y;
}

double Coordenada::obtenerDistancia(){
	return distancia;
}

