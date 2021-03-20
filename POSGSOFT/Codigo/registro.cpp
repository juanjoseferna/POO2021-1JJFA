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

void Registro::editarActa(){
    int idActa, opc;
    do{
    	cout << "Ingrese su opcion" << endl;
    	cout << " 1. Para agregar/cambiar calificaciones" << endl;
    	cout << " 2. Para cerrar el acta" << endl;
    	cout << " 3. Para calcular nota final" << endl;
    	cout << " 0. Para volver al menu" << endl;
    	cin >> opc;
    	switch(opc){
    		case 1:
	    		cout << "Ingrese el id del acta a editar o -1 para volver:" << endl;
	        	cin >> idActa;
	            for ( list<Acta>::iterator acta2 = actas.begin(); acta2 != actas.end(); acta2++ ){
					if (idActa == acta2->getId()){
						acta2->agregarCalificaciones();
					}
				}
				break;
			case 2:
				cout << "Ingrese el id del acta a cerrar o -1 para volver:" << endl;
	        	cin >> idActa;
	        	for ( list<Acta>::iterator acta2 = actas.begin(); acta2 != actas.end(); acta2++ ){
					if (idActa == acta2->getId()){
						acta2->cerrarActa();
					}
				}
				break;
			case 3:
				cout << "Ingrese el id del acta a cerrar o -1 para volver:" << endl;
	        	cin >> idActa;
	        	for ( list<Acta>::iterator acta2 = actas.begin(); acta2 != actas.end(); acta2++ ){
					if (idActa == acta2->getId()){
						acta2->calcularNotaFinal();
					}
				}
				break;
		}
    }while (opc != 0);
    return;
}

void Registro::crearArchivoTxt(){
    for ( list<Acta>::iterator acta2 = actas.begin(); acta2 != actas.end(); acta2++ ){
		if (acta2->getEstado() == "Cerrado"){
			acta2->crearArchivoTXT();
		}
	}
    return;
}

