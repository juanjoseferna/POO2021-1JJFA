#include <iostream>
#include "criterio.h"

Criterio::Criterio(){}

void Criterio::crearCriterio(int id){
    this->id = id;
    cout << "Ingrese la descripcion del criterio" << endl;
    getline(cin, descripcion);
    cout << "Ingrese el porcentaje del criterio" << endl;
    cin >> porcentaje;
    return;
}