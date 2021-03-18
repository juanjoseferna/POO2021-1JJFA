#ifndef CALIFICACION_H
#define CALIFICACION_H
#include <iostream>
#include "criterio.h"

using std::string;

class Calificacion{
	private:
		float nota;
		Criterio criterio;
		string comentarios;
	public:
		Calificacion();
		void crearCalificacion();
};

#endif /* !CALIFICACION_H */