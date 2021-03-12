#include <iostream>
#include "calificacion.h"

Calificacion::Calificacion(){}

void Calificacion::setNotaDesarrollo( float nota ){
	this->notaDesarrollo = nota;
	return;
}

void Calificacion::setNotaDesafio( float nota ){
	this->notaDesafio = nota;
	return;
}

void Calificacion::setNotaCumplimiento( float nota ){
	this->notaCumplimiento = nota;
	return;
}

void Calificacion::setNotaInnovacion( float nota ){
	this->notaInnovacion = nota;
	return;
}

void Calificacion::setNotaResultados( float nota ){
	this->notaResultados = nota;
	return;
}

void Calificacion::setNotaInformacion( float nota ){
	this->notaInformacion = nota;
	return;
}

void Calificacion::setNotaCalidadDoc( float nota ){
	this->notaCalidadDoc = nota;
	return;
}

void Calificacion::setNotaPresentacion( float nota ){
	this->notaPresentacion = nota;
	return;
}

void Calificacion::calcularNotaFinal(){
	this->notaFinal = (notaDesarrollo * 0.2) + (notaDesafio * 0.15) + (notaCumplimiento * 0.1) + (notaInnovacion * 0.1) + (notaResultados * 0.2) + (notaInformacion * 0.1) + (notaCalidadDoc * 0.75) + (notaPresentacion * 0.75);
	return;
}