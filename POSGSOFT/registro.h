#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>
#include <list>
#include "acta.h"

using std::string;
using std::list;

class Registro{
	private:
		list<Acta> Actas;
	public:
		Registro();
		void verPersona();
		void editarPersona();
};

#endif /* !REGISTRO_H */