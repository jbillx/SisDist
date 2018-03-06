#ifndef FECHA_H_
#define FECHA_H_

class Fecha
{
private:
	int dia;
	int mes;
	int anio;
	unsigned long int aux[250];

public:
	Fecha(int = 3, int =4, int = 2014);
	void inicializaFecha(int, int, int);
	void muestraFecha();
	bool leapyr();
	void setAnio(int);
	int getDia();
	int getMes();
	int getAnio();
	void fechaRand();
};

#endif