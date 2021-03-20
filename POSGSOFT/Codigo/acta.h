#ifndef ACTA_H
#define ACTA_H
#include <iostream>
#include <list>
#include <fstream>
#include "Persona.h"
#include "Calificacion.h"

using std::string;
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;

enum class tipoProyecto{
    INVESTIGACION,
    APLICADO
};

class Acta{
	private:
		string nombreTrabajo, estado, tipoTrabajo, fecha;
		int idActa;
		list<Calificacion> CalificacionesJurados;
		float notaFinal = -1;
		Persona jurado1, jurado2, director, codirector, autor;
    	bool codirectorEstado = false;
	public:
		Acta();
		void crearActa(int);
		void cerrarActa();
		void imprimirActa();
		int getId();
		string getEstado();
		void calcularNotaFinal();
		void agregarCalificaciones();
		void crearArchivoTXT();
		void crearArchivoTXTPersona(Persona);
};

#endif /* !ACTA_H */
