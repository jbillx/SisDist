#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include "Coordenada.h"

class Rectangulo{
	private:
		Coordenada superiorIzq;
		Coordenada inferiorDer;
	public:
		Rectangulo();
		Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
		Rectangulo(Coordenada a, Coordenada b);
		double obtenerArea();
		void imprimeEsq();
		Coordenada obtieneSupIzq();
		Coordenada obtieneInfDer();
};

#endif