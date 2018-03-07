#include "Fecha.h"
#include <iostream>

using namespace std;


int masVieja(Fecha fecha1, Fecha fecha2){
	if(fecha1.getAnio()>fecha2.getAnio()){
		return 1;
	}

	if(fecha1.getAnio()==fecha2.getAnio()){

		if(fecha1.getMes()>fecha2.getMes()){
			return 1;
		}

		if(fecha1.getMes()==fecha2.getMes()){
			if(fecha1.getDia()>fecha2.getDia()){
				return 1;
			}
		}		

	}

	return 0;

}

int masVieja2(Fecha& fecha1, Fecha& fecha2){
	if(fecha1.getAnio()>fecha2.getAnio()){
		return 1;
	}

	if(fecha1.getAnio()==fecha2.getAnio()){

		if(fecha1.getMes()>fecha2.getMes()){
			return 1;
		}

		if(fecha1.getMes()==fecha2.getMes()){
			if(fecha1.getDia()>fecha2.getDia()){
				return 1;
			}
		}		

	}

	return 0;

}


int masVieja3(Fecha *fecha1, Fecha *fecha2){
	if(fecha1->getAnio()>fecha2->getAnio()){
		return 1;
	}

	if(fecha1->getAnio()==fecha2->getAnio()){

		if(fecha1->getMes()>fecha2->getMes()){
			return 1;
		}

		if(fecha1->getMes()==fecha2->getMes()){
			if(fecha1->getDia()>fecha2->getDia()){
				return 1;
			}
		}		

	}

	return 0;

}

int main(){
	Fecha a, b;
	int n = 10000000;
	cout<<"Tamaño de la fecha a = "<<sizeof(a)<<endl;
	cout<<"Tamaño de la fecha b = "<<sizeof(b)<<endl;
	for (int i = 0; i<=n;i++){
		a.fechaRand();
		b.fechaRand();
		int res = masVieja2(a,b);
	}
	return 0;
	
}
