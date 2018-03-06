#ifndef CORDENADA_H_
#define CORDENADA_H_


class Coordenada{
	private:
		double x;
		double y;
	public:
		Coordenada(double = 0, double = 0, int = 0);
		double obtenerX();	
		double obtenerY();

};

#endif