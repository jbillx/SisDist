#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>
#include <stdlib.h>
#include "math.h"

using namespace std;


int main( )
{
	//Rectangulo rectangulo1(Coordenada(sqrt(13),atan(3.0/2.0)),Coordenada(sqrt(26),atan(1.0/5.0)));
	Rectangulo rectangulo1(Coordenada(sqrt(13),atan(3.0/2.0),1),Coordenada(5,1));

	double ancho, alto;
	cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";
	rectangulo1.imprimeEsq();
	alto = rectangulo1.obtieneSupIzq().obtenerY() -
	rectangulo1.obtieneInfDer().obtenerY();
	ancho = rectangulo1.obtieneInfDer().obtenerX() -
	rectangulo1.obtieneSupIzq().obtenerX();
	cout << "El área del rectángulo es = " << rectangulo1.obtenerArea() << endl;
	return 0;
}