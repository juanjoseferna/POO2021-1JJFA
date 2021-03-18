#include <iostream>
#include "registro.h"

Registro::Registro(){
	//Constructor vacío
}

void Registro::agregarActa(){
	Acta acta; //Crea el acta vacía
	acta.crearActa(1); //Le añade datos al acta
	actas.push_back(acta); //Agrega el acta a la lista de actas
	return;
}

void Registro::borrarActa(){
	/*
	int i, idActa;
	cout << "Ingrese el ID del acta a eliminar" << endl;
	cin >> idActa;
	for ( i = 0; i < actas.size(); ++i ){
		if (idActa == i){
			actas.remove(actas<i>);
		}
	}
	*/
}