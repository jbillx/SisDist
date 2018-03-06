#include "PoligonoIrreg.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main(int argc, char const *argv[])
{
	/* code */	
	PoligonoIrreg poligonos(10);

	cout << "El poligono tiene los siguientes vertices.\n";
	//poligonos.imprimeVertices();

	poligonos.ordenar();

	cout << "El poligono tiene los siguientes vertices Ordenados por la distancia.\n";
	poligonos.imprimeVertices();

	return 0;
}