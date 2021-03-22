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

class Acta{
	private:
		string nombreTrabajo, estado, tipoTrabajo, fecha, estadoTrabajo, observacionAdicionalJ1, observacionAdicionalJ2, periodo;
		int idActa, numeroTotalCriterios = 8;
		list<Calificacion> CalificacionesJurados;
		float notaFinal = -1;
		Persona jurado1, jurado2, director, codirector, autor;
    	bool codirectorEstado = false;
	public:
		Acta();
		int getId();
		int getNumeroTotalCriterios();
		string getEstado();
		string getEstadoTrabajo();
		string getTipoTrabajo();
		string getNombreActa();
		string getNombreJurado1();
		string getNombreJurado2();
		string getTipoJurado1();
		string getTipoJurado2();
		int getCodigoJurado1();
		int getCodigoJurado2();
		int getCodigoDirector();
		void setComentarioAdicional();
		void crearActa(int);
		void cerrarActa();
		void imprimirActa();
		void calcularNotaFinal();
		void agregarCalificaciones();
		void crearArchivoTXT();
		void agregarComentarioExtra();
};

#endif /* !ACTA_H */
