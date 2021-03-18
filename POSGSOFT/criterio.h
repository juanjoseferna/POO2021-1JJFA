#ifndef CRITERIO_H
#define CRITERIO_H
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Criterio{
	private:
		int id = -1;
		float porcentaje;
		string descripcion;
	public:
		Criterio();
        void crearCriterio(int);
};

#endif /* !CRITERIO_H */