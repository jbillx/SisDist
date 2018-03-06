#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada{
	private: 
		double x;
		double y;
		double distancia;
public:
	Coordenada(double = 0, double = 0, int = 0);
	double obtenerX(void);
	double obtenerY(void);
	double obtenerDistancia();
	
};


#endif