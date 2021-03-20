#include <iostream>
#include "calificacion.h"

Calificacion::Calificacion(){}

void Calificacion::crearCalificacion(int indice){
	criterio.crearCriterio(indice);
	cout << "Ingrese la nota del primer jurado:" << endl;
	cin >> notaj1;
	cout << "Ingrese los comentarios del primer jurado:" << endl;
	fflush(stdin);
	getline(cin, comentarioj1);
	fflush(stdin);
	cout << "Ingrese la nota del segundo jurado:" << endl;
	cin >> notaj1;
	cout << "Ingrese los comentarios del segundo jurado:" << endl;
	fflush(stdin);
	getline(cin, comentarioj2);
	fflush(stdin);
	return;
}

float Calificacion::getNotaJ1(){
	return notaj1;
}

float Calificacion::getNotaJ2(){
	return notaj2;
}

string Calificacion::getComentarioJ1(){
	return comentarioj1;
}

string Calificacion::getComentarioJ2(){
	return comentarioj2;
}

string Calificacion::getDescripcionCriterio(){
	return criterio.getDescripcion();
}

int Calificacion::getIdCriterio(){
	return criterio.getId();
}

float Calificacion::getPorcentajeNota(){
	return criterio.getPorcentaje();
}

void Calificacion::mostrarCalificacion(){
	criterio.mostrarCriterio();
	cout << " Nota jurado 1: " << notaj1 << endl;
	cout << " Comentarios jurado 1:\n" << " " << comentarioj1 << endl;
	cout << " Nota jurado 2: " << notaj2 << endl;
	cout << " Comentarios jurado 2:\n" << " " << comentarioj2 << endl;
	return;
}