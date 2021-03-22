#include <iostream>
#include "registro.h"

Registro::Registro(){//constructor de Registro vacio
}

void Registro::agregarActa(){
	Acta acta; //Crea el acta vacía
	acta.crearActa(idActas); //Le añade datos al acta
	idActas++;
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

void Registro::imprimirActas(){//Imprime todas las actas
	for ( list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++ ){
		actaIt->imprimirActa();
	}
	return;
}

void Registro::editarActa(){//Edita un acta segun la opcion que se elija
    int idActa, opc;
    do{
    	cout << "Ingrese su opcion" << endl;
    	cout << " 1. Para agregar/cambiar calificaciones" << endl;
    	cout << " 2. Para cerrar el acta" << endl;
    	cout << " 3. Para calcular nota final" << endl;
    	cout << " 4. Para agregar comentarios adicionales" << endl;
    	cout << " 0. Para volver al menu" << endl;
    	cin >> opc;
    	switch(opc){ //setComentarioAdicional()
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
			case 4:
				cout << "Ingrese el id del acta a cerrar o -1 para volver:" << endl;
	        	cin >> idActa;
	        	for ( list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++ ){
					if (idActa == actaIt->getId()){
						actaIt->setComentarioAdicional();
					}
				}
				break;
		}
    }while (opc != 0);
    return;
}

void Registro::datosPosgrado(){//Imprime los datos seleccionados
	int opc, idActa, contador = 0, codigoPersona, intTipoJurado, salida;
	bool bandera1 = false, bandera2 = false;
	list<int> codigosLista;
	do{
		cout << "Ingrese su opcion a consultar:" << endl;
		cout << " 1. Trabajos relacionados con la industria" << endl; //Cuales y cuantos
		cout << " 2. Trabajos de investigacion" << endl; //Cuales y cuantos
		cout << " 3. Trabajos de grado dirigidos por un profesor" << endl; //Cuantos
		cout << " 4. Trabajos de los cuales ha sido jurado una persona" << endl; //Cuales
		cout << " 5. Todos los jurados" << endl; //Cuales y sin repetir
		cout << " 6. Actas rechazadas/pendientes" << endl; //Cuales
		cout << " 7. Jurados internos y externos" << endl; //Cuales
		cout << " 8. Criterios de evaluacion" << endl; //Cuales
		cout << " 0. Para volver al menu principal" << endl;
		cin >> opc;
		switch(opc){
			case 1:
				contador = 0;
				for(list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++){
					if (actaIt->getTipoTrabajo() == "Aplicado"){
						contador++;
						actaIt->imprimirActa();
					}
				}
				cout << "Total de actas relacionadas con la industria: " << contador << endl;
				break;
			case 2:
				contador = 0;
				for(list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++){
					if (actaIt->getTipoTrabajo() == "Investigacion"){
						contador++;
						actaIt->imprimirActa();
					}
				}
				cout << "Total de actas de investigacion: " << contador << endl;
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
				break;
			case 4:
				cout << "Ingrese el numero del jurado a buscar: " << endl;
				cin >> codigoPersona;
				cout << "El jurado con el codigo " << codigoPersona << " ha sido jurado de:" << endl;;
				for(list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++){
					if (actaIt->getCodigoJurado1() == codigoPersona || actaIt->getCodigoJurado2() == codigoPersona){
						cout << "Nombre - ID " << actaIt->getNombreActa() << " - " << actaIt->getId() << endl;
					}
				}
				break;
			case 5:
				cout << "Jurados:" << endl;
				for(list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++){
					bandera1 = true;
					bandera2 = true;
					for (list<int>::iterator codigoIt = codigosLista.begin(); codigoIt != codigosLista.end(); codigoIt++){
						if (*codigoIt == actaIt->getCodigoJurado1()){
							bandera1 = false;
						}
						if (*codigoIt == actaIt->getCodigoJurado2()){
							bandera2 = false;
						}
					}
					if(bandera1){
						codigosLista.push_back(actaIt->getCodigoJurado1());
						cout << "Nombre - Codigo: " << actaIt->getNombreJurado1() << " - " << actaIt->getCodigoJurado1() << endl;
					}
					if(bandera2){
						codigosLista.push_back(actaIt->getCodigoJurado2());
						cout << "Nombre - Codigo: " << actaIt->getNombreJurado2() << " - " << actaIt->getCodigoJurado2() << endl;
					}
				}
				codigosLista.clear();
				break;
			case 6:
				for(list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++){
					if (actaIt->getEstadoTrabajo() == "Rechazado" || actaIt->getEstadoTrabajo() == "Pendiente"){
						contador++;
						actaIt->imprimirActa();
					}
				}
				break;
			case 7:
				salida = 1;
				cout << "Ingrese su opcion" << endl;
				cout << " 1. Jurados Externos" << endl;
				cout << " 2. Jurados Internos" << endl;
				do{
					cin >> intTipoJurado;
					for(list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++){
						if (intTipoJurado == 1){
							if (actaIt->getTipoJurado1() == "JuradoExterno"){
								cout << "Nombre - Codigo: " << actaIt->getNombreJurado1() << " - " << actaIt->getCodigoJurado1() << endl;
								salida = 0;
							}
							if (actaIt->getTipoJurado2() == "JuradoExterno"){
								cout << "Nombre - Codigo: " << actaIt->getNombreJurado2() << " - " << actaIt->getCodigoJurado2() << endl;
								salida = 0;
							}
						}
						else if (intTipoJurado == 2){
							if (actaIt->getTipoJurado1() == "JuradoInterno"){
								cout << "Nombre - Codigo: " << actaIt->getNombreJurado1() << " - " << actaIt->getCodigoJurado1() << endl;
								salida = 0;
							}
							if (actaIt->getTipoJurado2() == "JuradoInterno"){
								cout << "Nombre - Codigo: " << actaIt->getNombreJurado2() << " - " << actaIt->getCodigoJurado2() << endl;
								salida = 0;
							}
						}
					}
				}while(salida == 1);
				break;
			case 8:
				list<Acta>::iterator actaIt = actas.begin();
				Criterio criterioImprimir;
				for (int i = 0; i < actaIt->getNumeroTotalCriterios(); ++i){
					criterioImprimir.crearCriterio(i);
					criterioImprimir.mostrarCriterio();
				}
				break;
		}
	}while (opc != 0);
	return;
}

void Registro::crearArchivoTxt(){//Manda a crear un archivo .txt si el acta se encuentra cerrado
    for ( list<Acta>::iterator actaIt = actas.begin(); actaIt != actas.end(); actaIt++ ){
		if (actaIt->getEstado() == "Cerrado"){
			actaIt->crearArchivoTXT();
		}
	}
    return;
}