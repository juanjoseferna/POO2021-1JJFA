#ifndef CRITERIO_H
#define CRITERIO_H
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Criterio{
	private:
		int id;
		float porcentaje;
		string descripcion;
	public:
		Criterio();
        void crearCriterio(int);
        void mostrarCriterio();
        float getPorcentaje();
        string getDescripcion();
        int getId();
};

#endif /* !CRITERIO_H */