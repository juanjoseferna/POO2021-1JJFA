#ifndef CALIFICACION_H
#define CALIFICACION_H
#include <iostream>
#include <string>
#include "criterio.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Calificacion{
	private:
		float notaj1, notaj2;
		Criterio criterio;
		string comentarioj1, comentarioj2;
	public:
		Calificacion();
		float getNotaJ1();
		float getNotaJ2();
		float getPorcentajeNota();
		void crearCalificacion(int);
		void mostrarCalificacion();
};

#endif /* !CALIFICACION_H */