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
	for ( list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++ ){
		if (idActa == actaIt->getId()){
			if (actaIt->getEstado() == "Abierta"){
				actas.erase(actaIt);
			}
		}
	}
	return;
}

void Registro::imprimirActas(){
	for ( list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++ ){
		actaIt->imprimirActa();
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
    	cout << " 4. Para agregar comentarios adicionales" << endl;	
    	cout << " 0. Para volver al menu" << endl;
    	cin >> opc;
    	switch(opc){
    		case 1:
	    		cout << "Ingrese el id del acta a editar o -1 para volver:" << endl;
	        	cin >> idActa;
	            for ( list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++ ){
					if (idActa == actaIt->getId()){
						actaIt->agregarCalificaciones();
					}
				}
				break;
			case 2:
				cout << "Ingrese el id del acta a cerrar o -1 para volver:" << endl;
	        	cin >> idActa;
	        	for ( list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++ ){
					if (idActa == actaIt->getId()){
						actaIt->cerrarActa();
					}
				}
				break;
			case 3:
				cout << "Ingrese el id del acta a cerrar o -1 para volver:" << endl;
	        	cin >> idActa;
	        	for ( list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++ ){
					if (idActa == actaIt->getId()){
						actaIt->calcularNotaFinal();
					}
				}
				break;
		}
    }while (opc != 0);
    return;
}

void Registro::datosPosgrado(){
	int opc, idActa, contador = 0, codigoPersona;
	do{
		cout << "Ingrese su opcion a consultar:" << endl;
		cout << " 1. Trabajos relacionados con la industria" << endl; //Cuales y cuantos
		cout << " 2. Trabajos de investigacion" << endl; //Cuales y cuantos
		cout << " 3. Trabajos de grado dirigidos por un profesor" << endl; //Cuantos
		cout << " 4. Trabajos de los cuales ha sido jurado una persona" << endl; //Cuales
		cout << " 5. Todos los jurados" << endl; //Cuales y sin repetir
		cout << " 6. Actas rechazadas/pendientes" << endl; //Cuales
		cout << " 7. Crear informacion de los jurados" << endl; //Si es interno es profesor
		cout << " 8. Jurados internos y externos" << endl; //Cuales
		cout << " 9. Criterios de evaluacion" << endl; //Cuales
		cin >> opc;
		switch(opc){
			case 1:
				for(list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++){
					if (actaIt->getTipoTrabajo() == "Investigacion"){
						contador++;
						actaIt->imprimirActa();
					}
				}
				cout << "Total de actas relacionadas con la industria: " << contador << endl;
				break;
			case 2:
				for(list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++){
					if (actaIt->getTipoTrabajo() == "Aplicado"){
						contador++;
						actaIt->imprimirActa();
					}
				}
				cout << "Total de actas relacionadas con la industria: " << contador << endl;
				break;
			case 3:
				cout << "Ingrese el codigo del director a buscar: " << endl;
				cin >> codigoPersona;
				cout << "El director con el codigo " << codigoPersona << " ha dirigido las siguientes actas: " << endl;
				for(list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++){
					if (actaIt->getCodigoDirector() == codigoPersona){
						contador++;
						cout << "Nombre - ID " << actaIt->getNombreActa() << " - " << actaIt->getId() << endl;
					}
				}
				cout << "Total de actas relacionadas con la industria: " << contador << endl;
				break;
		}
	}while (opc != 0);
}

void Registro::crearArchivoTxt(){
    for ( list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++ ){
		if (actaIt->getEstado() == "Cerrado"){
			actaIt->crearArchivoTXT();
		}
	}
    return;
}

