#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Persona{
	private:
		string nombre, email, rol;
		int cedula, telefono;
	public:
		Persona();
		void crearPersona(int);
		void verPersona();
		string getNombre();
		string getEmail();
		string getRol();
		int getCedula();
		int getTelefono();
};

#endif /* !PERSONA_H */