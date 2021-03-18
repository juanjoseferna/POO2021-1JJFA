#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using std::string;

class Persona{
	private:
		string nombre, email, rol;
		int cedula, telefono;
	public:
		Persona();
		void crearPersona();
		void verPersona();
		void editarPersona();
};

#endif /* !PERSONA_sH */