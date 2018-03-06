#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class Coordenada{
	private:
		double x;
		double y;
		double distancia;
	public:
		Coordenada(double = 0, double = 0);
		double obtenerX();
		double obtenerY();
		double obtenerDistancia();
		void ordenar(*vector<Coordenada>);
};

class PoligonoIrreg{
	private:
		static int numVertices;
		vector <Coordenada> v;
	public:
		static int getNumVertices();
		PoligonoIrreg();
		void anadeVertice(Coordenada n);
		void anadeVertice(double x, double y);
		void imprimeVertices();
		vector<Coordenada> obtenerVertices();
};

int main(){
	//int n = rand() % 1000000;
	srand48(time(NULL));
	PoligonoIrreg poligonos;
	int j, m, x, y;
	m=10;
	for(j = 0; j < m; j++){
		x = rand() % 100;
		y = rand() % 100;
		poligonos.anadeVertice(x, y);
	}

	poligonos.imprimeVertices();

	vector<Coordenada> myvector = poligonos.obtenerVertices();



	return 0;
}

int PoligonoIrreg::numVertices = 0;

int PoligonoIrreg::getNumVertices(){
	return numVertices;
}

vector<Coordenada> PoligonoIrreg::obtenerVertices(){
	return v;
}


Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy){
	distancia = sqrt( pow(xx,2) + pow(yy,2));
}

Coordenada::ordenar(vector<Coordenada>){

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


PoligonoIrreg::PoligonoIrreg(){}

void PoligonoIrreg::anadeVertice(Coordenada n){
	v.push_back(n);
	numVertices++;
}

void PoligonoIrreg::anadeVertice(double x, double y){
	v.push_back(Coordenada(x, y));
	numVertices++;
}
void PoligonoIrreg::imprimeVertices(){
	cout << "El poligono tiene los siguientes vertices.\n";
	vector<Coordenada>::reverse_iterator ir;
	int aux = 0;
	for (ir = v.rbegin( ); ir != v.rend( ); ir++){
		cout << "P" << aux + 1 << ": x = " << (*ir).obtenerX() << ", y = " << (*ir).obtenerY() << ", distancia = "<<(*ir).obtenerDistancia()<<endl;
		aux++;
	}


	/*for(aux = 0; aux < v.size(); aux++){
	}
*/

}