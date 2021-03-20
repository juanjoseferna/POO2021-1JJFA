#ifndef ACTA_H
#define ACTA_H
#include <iostream>
#include <list>
#include "Persona.h"
#include "Calificacion.h"

using std::string;
using std::list;
using std::cout;
using std::cin;
using std::endl;

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
		void calcularNotaFinal();
		void agregarCalificaciones();
};

#endif /* !ACTA_H */
