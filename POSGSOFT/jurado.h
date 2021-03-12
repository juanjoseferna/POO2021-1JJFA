//#ifndef JURADO_H
//#define JURADO_H
#include <iostream>

class Jurado{
	private:
		std::string tipo;
		Calificacion calificacionesJurado;
		std::string observaciones [10];
	public:
		Jurado();
		void editarNota();
};

//#endif /* !JURADO_H */