#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

PoligonoIrreg::PoligonoIrreg(int ver){
	srand48(time(NULL));
	v.reserve(ver);
	for (int i = 0; i<ver;i++){
		v.push_back( Coordenada( (float) (rand()%(6001)-3000.0 )/33.0 , (float) (rand()%(6001)-3000.0)/33.0 ,1)  );

	}
	numVertices = ver;
}

int PoligonoIrreg::numVertices = 0;

void PoligonoIrreg::anadeVertice(Coordenada n){
	v.push_back(n);
	v.reserve(v.size() +1 );
	numVertices=v.size() +1 ;
}

void PoligonoIrreg::anadeVertice(double x, double y){
	v.push_back(Coordenada(x, y ,1));
	v.reserve(v.size() +1 );
	numVertices=v.size() +1 ;
}

void PoligonoIrreg::imprimeVertices(){
	vector<Coordenada>::reverse_iterator ir;
	int aux = 0;
	for (ir = v.rbegin( ); ir != v.rend( ); ir++){
		cout << "P" << aux + 1 << ": x = " << (*ir).obtenerX() << ", y = " << (*ir).obtenerY() << ", distancia = "<<(*ir).obtenerDistancia()<<endl;
		aux++;
	}

}

int PoligonoIrreg::getNumVertices(){
	return numVertices;
}

vector<Coordenada> PoligonoIrreg::obtenerVertices(){
	return v;
}

bool sort_by_avg(Coordenada a1, Coordenada a2) {
	return a1.obtenerDistancia() > a2.obtenerDistancia(); // usamos ">" porque queremos orden descendente
}

void PoligonoIrreg::ordenar(){
 std::sort (v.begin(), v.end(), sort_by_avg); 
}



