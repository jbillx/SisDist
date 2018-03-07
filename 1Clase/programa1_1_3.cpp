#include <iostream>
using namespace std;

int main( )
{
	double c = 20;
	double f;
	f = (9.0/5.0)*c+32;
	f = static_cast<double>(9)/static_cast<double>(5)*c+32;
	cout<<c<<" grados centigrados = "<<f<<" Fahrenheit"<<endl;
}