#include <iostream>
#include "criterio.h"

Criterio::Criterio(){}

void Criterio::crearCriterio(int id){
    this->id = id;
    cout << "Ingrese la descripcion del criterio" << endl;
    fflush(stdin);
    getline(cin, descripcion);
    fflush(stdin);
    cout << "Ingrese el porcentaje del criterio" << endl;
    cin >> porcentaje;
    porcentaje = porcentaje / 100;
    return;
}

float Criterio::getPorcentaje(){
    return porcentaje;
}

string Criterio::getDescripcion(){
    return descripcion;
}

int Criterio::getId(){
    return id;
}

void Criterio::mostrarCriterio(){
	cout << " ID: " << id << endl;
	cout << " Peso en la nota final (total = 1): " << porcentaje << endl;
	cout << " Descripcion : " << descripcion << endl;
	return;
}