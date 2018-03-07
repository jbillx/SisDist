#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_

#include "Coordenada.h"
#include <vector>

using namespace std;

class PoligonoIrreg{
	private:
		static int numVertices;
		vector <Coordenada> v;
	public:
		PoligonoIrreg(int ver);
		void anadeVertice(Coordenada n);
		void anadeVertice(double x, double y);
		void imprimeVertices();
		static int getNumVertices();
		vector<Coordenada> obtenerVertices();
		void ordenar(void);
};
#endif