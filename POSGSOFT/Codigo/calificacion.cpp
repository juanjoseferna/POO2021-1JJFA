#include <iostream>
#include "calificacion.h"

Calificacion::Calificacion(){}

void Calificacion::setCriterio(Criterio criterio){
	this->criterio = criterio;
	return;
}

void Calificacion::crearCalificacion(){
	criterio.crearCriterio(1);
	cout << "Ingrese la calificacion" << endl;
	cin >> nota;
	cout << "Ingrese los comentarios:" << endl;
	fflush(stdin);
	getline(cin, comentario);
	fflush(stdin);
	return;
}

void Calificacion::mostrarCalificacion(){
	criterio.mostrarCriterio();
	cout << " Nota: " << nota << endl;
	cout << " Comentarios:\n" << " " << comentario << endl;
	return;
}