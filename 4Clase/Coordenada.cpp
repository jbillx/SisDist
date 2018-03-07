#include "Coordenada.h"
#include <iostream>
#include <stdlib.h>
#include "math.h"

using namespace std;


Coordenada::Coordenada(double xx, double yy, int ban) 
{
	if(ban ==1){
		x = xx*cos(yy);
		y = xx*sin(yy);
	}else{
		x = xx;
		y = yy;
	}
}

double Coordenada::obtenerX(){
	return x;
}

double Coordenada::obtenerY(){
	return y;
}
