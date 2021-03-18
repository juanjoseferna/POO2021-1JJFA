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
		float nota;
		Criterio criterio;
		string comentario;
	public:
		Calificacion();
		void setCriterio(Criterio);
		void crearCalificacion();
		void mostrarCalificacion();
};

#endif /* !CALIFICACION_H */