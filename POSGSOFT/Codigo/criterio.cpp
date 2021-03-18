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
    porcentaje = porcentaje;
    return;
}

void Criterio::mostrarCriterio(){
	cout << " ID: " << id << endl;
	cout << " Porcentaje: " << porcentaje << "%" << endl;
	cout << " Descripcion : " << descripcion << endl;
	return;
}