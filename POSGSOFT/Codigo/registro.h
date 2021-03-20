#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>
#include <list>
#include "acta.h"
#include "persona.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Registro{
	private:
		list<Acta> actas;
	public:
		Registro();
		void agregarActa();
		void borrarActa();
		void editarActa();
		void imprimirActas();
		void crearArchivoTxt();
		void datosPosgrado();
};

#endif /* !REGISTRO_H */