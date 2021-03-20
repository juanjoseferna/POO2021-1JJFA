#include <iostream>
#include "registro.h"

Registro::Registro(){
	//Constructor vacío
}

void Registro::agregarActa(){
	Acta acta; //Crea el acta vacía
	acta.crearActa(actas.size()); //Le añade datos al acta
	actas.push_back(acta); //Agrega el acta a la lista de actas
	return;
}

void Registro::borrarActa(){ //Borra un acta
	int idActa;
	cout << "Ingrese el ID del acta a eliminar" << endl;
	cin >> idActa;
	for ( list<Acta>::iterator acta2 = actas.begin(); acta2 != actas.end(); acta2++ ){
		if (idActa == acta2->getId()){
			actas.erase(acta2);
		}
	}
	return;
}

void Registro::imprimirActas(){
	for ( list<Acta>::iterator acta2 = actas.begin(); acta2 != actas.end(); acta2++ ){
		acta2->imprimirActa();
	}
	return;
}

void Registro::editarActa(){ //Cambia las calificaciones de acta
    int idActa;
    do{
    	cout << "Ingrese el id del acta a editar o -1 para salir:" << endl;
        cin >> idActa;
            for ( list<Acta>::iterator acta2 = actas.begin(); acta2 != actas.end(); acta2++ ){
				if (idActa == acta2->getId()){
					acta2->agregarCalificaciones();
				}
		}
    }while (idActa != -1);
    return;
}
