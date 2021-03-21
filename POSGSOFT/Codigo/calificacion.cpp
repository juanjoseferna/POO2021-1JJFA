#include <iostream>
#include "calificacion.h"

Calificacion::Calificacion(){} //Constructor vacio

void Calificacion::crearCalificacion(int indice){//Rellena los datos del calificacion
	int salida = 0;
	criterio.crearCriterio(indice);
	cout << "Ingrese la nota del primer jurado:" << endl;
	do{
		cin >> notaj1;
		if (notaj1 <= 5.0 &&  notaj1 >= 0.0){
			salida = 1;
		} else{
			cout << "Tiene que ser una nota entre 0 y 5" << endl;
		}
	}while(salida == 0);
	salida = 0;
	cout << "Ingrese los comentarios del primer jurado:" << endl;
	fflush(stdin);
	getline(cin, comentarioj1);
	fflush(stdin);
	cout << "Ingrese la nota del segundo jurado:" << endl;
	do{
		cin >> notaj2;
		if (notaj2 <= 5.0 &&  notaj2 >= 0.0){
			salida = 1;
		} else{
			cout << "Tiene que ser una nota entre 0 y 5" << endl;
		}
	}while(salida == 0);
	salida = 0;
	cout << "Ingrese los comentarios del segundo jurado:" << endl;
	fflush(stdin);
	getline(cin, comentarioj2);
	fflush(stdin);
	return;
}

float Calificacion::getNotaJ1(){//retorna la nota del jurado1
	return notaj1;
}

float Calificacion::getNotaJ2(){//retorna la nota del jurado2
	return notaj2;
}

string Calificacion::getComentarioJ1(){//retorna el comentario del jurado1
	return comentarioj1;
}

string Calificacion::getComentarioJ2(){//retorna el comentario del jurado2
	return comentarioj2;
}

string Calificacion::getDescripcionCriterio(){//retorna la descripcion de criterio
	return criterio.getDescripcion();
}

int Calificacion::getIdCriterio(){//retorna el id de criterio
	return criterio.getId();
}

float Calificacion::getPorcentajeNota(){//retorna el porcentaje del criterio
	return criterio.getPorcentaje();
}

void Calificacion::mostrarCalificacion(){//imprime la informacion tanto del criterio como de la calificacion
	criterio.mostrarCriterio();
	cout << " Nota jurado 1: " << notaj1 << endl;
	cout << " Comentarios jurado 1:\n" << " " << comentarioj1 << endl;
	cout << " Nota jurado 2: " << notaj2 << endl;
	cout << " Comentarios jurado 2:\n" << " " << comentarioj2 << endl;
	return;
}