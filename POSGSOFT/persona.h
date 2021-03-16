//#ifndef PERSONA_H
//#define PERSONA_H
#include <iostream>

class Persona{ //nombre, identificación, email, celular, etc (datos básicos)
	private:
		std::string nombre;
		int CC, celular;
		std::string email;
	public:
		Jurado();
		void editarNota();
};

//#endif /* !PERSONA_H */